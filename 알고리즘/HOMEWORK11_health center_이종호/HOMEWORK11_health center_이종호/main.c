//This program names health center.
//It uses the Floyd-Warshal algorithm and then calculates optimal new center's location.
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 999

int **costTable; //It saves all costs among all of intersections.
int *exsist; //It saves information about centers which already exsist center.
int num_center,num_inter;

void initTable(){ //It initializes costTabel.
	int i, j;
	for(i = 0; i < num_inter; i++){
		for(j = 0; j < num_inter; j++){
			if( i == j)
				costTable[i][j] = 0;
			else
				costTable[i][j] = LIMIT;
		}
	}
}
int isLimit(){	//It checks that utill costTable has limit value.
	int i, j;
	for(i = 0; i < num_inter; i++){
		for(j = 0; j < num_inter; j++){
			if(costTable[i][j] == LIMIT)
				return 1;
		}
	}
	return 0;
}
int findMin(int i, int j){ //It returns minimum value that is D(i,k)+D(k+j)
	int k;
	int min;
	int temp;
	for(k = 0; k < num_inter; k++){
		if(costTable[i][k] == LIMIT || costTable[k][j] == LIMIT)
			temp = LIMIT;
		else
			temp = costTable[i][k] + costTable[k][j];
		if(k == 0)
			min = temp;
		else{
			if(min > temp)
				min = temp;
		}
	}
	return min;
}
void makeTable(){	// It makes full costTable.
	int i,j;
	while(isLimit()){
		for( i = 0; i < num_inter; i++){
			for(j = 0; j < num_inter; j++){
				if(costTable[i][j] == LIMIT)
					costTable[i][j] = findMin(i,j);
			}
		}
	}
}


void findSolution(){ //It finds solution using the floyd-warshal algorithm.
	int i,j;
	int k;
	int count= 0;
	int temp;
	double sum , min;
	int index;
	int isSame = 0;
	
	makeTable();

	for( i = 0; i < num_inter; i ++){
		sum = 0;
		count = 0;
		isSame = 0;
		while(count != num_center){ // It distinguishs if or not i equals index of already exsist centers.
			if(exsist[count]-1 == i)
				isSame = 1;
			count++;
		}
		if(isSame)
			continue;
		for( j = 0; j < num_inter; j++){
			count = 0;
			while(count != num_center){
				if(count==0)
					temp = costTable[j][exsist[count]-1];
				else{
					if(temp > costTable[j][exsist[count]]-1)
						temp = costTable[j][exsist[count]-1];
				}
				count++;
			}
			if(temp > costTable[i][j])
				temp = costTable[i][j];
			sum+= temp;
		}
		sum = sum/num_inter;
		if( i == 0){
			index = 0;
			min = sum;
		}
		else{
			if(min > sum){
				min = sum;
				index = i;
			}
		}
	}
	printf("------------Result : %d\n",index+1);
}

void main(){
	int temp_i,temp_j,temp;
	int i;
	int path;
	printf("Enter the number of health center and intersection:\n");
	scanf("%d %d",&num_center,&num_inter);

	exsist = (int *)malloc(sizeof(int)*num_center);
	costTable = (int **)malloc(sizeof(int*)*num_inter);
	for(i = 0; i < num_inter; i ++)
		costTable[i] = (int *)malloc(sizeof(int)*num_inter);

	printf("Enter the number of intersection which exsists health center:\n");
	for(i = 0; i < num_center; i++)
		scanf("%d",&exsist[i]);

	printf("Enter the number of pathes:\n");
	scanf("%d",&path);
	initTable();

	for(i = 0; i  < path; i++){
		scanf("%d %d %d",&temp_i,&temp_j,&temp);
		costTable[temp_i-1][temp_j-1] = temp;
		costTable[temp_j-1][temp_i-1] = temp;
	}
	findSolution();

	free(exsist);
	for(i = 0; i < num_center; i++)
		free(costTable[i]);
	free(costTable);

}