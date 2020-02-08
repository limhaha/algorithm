//This program named the cheapest way.
//It finds the cheapest cost way in table.
//It saves cost in cost table.
//Finally, it finds the cheapest route in cost table using Back Tracking.
#include <stdio.h>
#include <stdlib.h>
int row,col;
int **mat;
int **cost;

void makeCostTable(){	// This fuction makes the cost table.
	int i,j;
	int temp;

	for(i = 0; i < row; i++)
		cost[i][0] = mat[i][0];

	for(i = 0; i < col-1; i++){
		for(j = 0; j<row;j++){
			if(j == 0){//case :  position in top.
				cost[row-1][i+1] = mat[row-1][i+1]+cost[j][i];
				cost[j][i+1] = mat[j][i+1]+cost[j][i];
				cost[j+1][i+1] = mat[j+1][i+1]+cost[j][i];
			}
			else if(j == row-1){//case : position in bottom.
				temp = mat[j-1][i+1]+cost[j][i];
				if(temp<cost[j-1][i+1])
					cost[j-1][i+1] = temp;
				temp = mat[j][i+1]+cost[j][i];
				if(temp<cost[j][i+1])
					cost[j][i+1] = temp;
				temp = mat[0][i+1] + cost[j][i];
				if(temp < cost[0][i+1])
					cost[0][i+1]= temp;
			}
			else{//case : position in top between bottom
				temp = mat[j-1][i+1]+cost[j][i];
				if(temp<cost[j-1][i+1])
					cost[j-1][i+1] = temp;
				temp = mat[j][i+1] + cost[j][i];
				if(temp<cost[j][i+1])
					cost[j][i+1] = temp;
				if(j == row-2){
					temp = mat[j+1][i+1] + cost[j][i];
					if(temp<cost[j+1][i+1])
						cost[j+1][i+1] = temp;
				}
				else{
					cost[j+1][i+1] = mat[j+1][i+1]+cost[j][i];
				}	
			}
		}
	}
}
int findMin(){		//This fuction returns the minimum cost among last column.
	int i;
	int min=0;
	for(i = 1; i < row; i++){
		if(cost[i][col-1] < cost[min][col-1])
			min = i;
	}
	return min;
}

int findMinValue(int x, int y, int z,int n){		//This fuction returns the minimum value among three values.
	int i;
	int min;
	int temp[3];
	temp[0] = x;
	temp[1] = y;
	temp[2] = z;
	for( i = 0; i < 3; i++){
		if(i ==0)
			min = temp[i];
		else{
			if(cost[min][n] > cost[temp[i]][n])
				min = temp[i];
		}
	}

	return min;
}

void findCheapest(){		//This function uses back tracking and then, finds the cheapest way.
	int *route;
	int posX;
	int i;
	int temp[3];
	route = (int *)malloc(sizeof(int)*col);
	posX = findMin();
	printf("\n####Total Cost:	%d\n",cost[posX][col-1]);
	route[col-1] = mat[posX][col-1];
	for(i = col-2; i >= 0; i--){
		if(posX==0){
			temp[0] = row-1;
			temp[1] = posX;
			temp[2] = posX+1;
		}
		else if(posX==row-1){
			temp[0] = 0;
			temp[1] = posX;
			temp[2] = posX-1;
		}
		else{
			temp[0] = posX-1;
			temp[1] = posX;
			temp[2] = posX+1;
		}
		posX = findMinValue(temp[0],temp[1],temp[2],i);
		route[i] = mat[posX][i];
		 
	}
	printf("\n####Route\n		");
	for(i=0; i < col; i++)
		printf("%d ",route[i]);
	printf("\n");
	free(route);
}


void main(){
	int i,j;
	printf("Enter the row and column:\n");
	scanf("%d %d",&row,&col);

	mat = (int **)malloc(sizeof(int*)*row);
	for(i = 0; i < row; i++)
		mat[i] = (int *)malloc(sizeof(int)*col);
	cost = (int **)malloc(sizeof(int*)*row);
	for(i = 0; i < row; i++)
		cost[i] = (int *)malloc(sizeof(int)*col);
	
	for(i = 0; i < row; i++){
		for(j = 0; j< col; j++)
			scanf("%d",&mat[i][j]);
	}
	makeCostTable();
	
	printf("\n\nCostTable===========\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++)
			printf("%d ",cost[i][j]);
		printf("\n");
	}
	printf("====================\n\n");
	findCheapest();

	for(i=0; i< row; i++)
		free(mat[i]);
	free(mat);
	for(i=0; i< row; i++)
		free(cost[i]);
	free(cost);
}