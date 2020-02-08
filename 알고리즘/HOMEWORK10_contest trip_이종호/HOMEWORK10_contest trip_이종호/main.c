/**
This program names contest Trip.
It uses dijkstra algorithm. And then, It finds the minimum and the fastest arrival time.
*/

#include <stdio.h>
#include <string.h>

char city[100][20];
int num_city,num_train;
int train_num[1000];
int train[1000][100][2];
int time;
int start,end;

int getIndex(char str[]){		//Finds city's index and Returns city's index
	int i;
	for( i = 0; i < num_city; i++){
		if(strcmp(str, city[i]) == 0)
			return i;
	}
	return -1;
}

void initArr(int min[100][2], int temp[]){			//initializes two arrays.
	int i;
	for(i =0; i < num_city; i++){
		min[i][0] = 2400;		//sets enough big number
		min[i][1] = -1;
		temp[i] = 0;
	}
	min[start][0] = time;
}
void printResult(int min[100][2]){			//Prints result.
	int hour,minutes;
	
		hour = min[start][1]/100;
		minutes = min[start][1]%100;
		if(hour<10){
			if( minutes<10) //case : hour's value and minutes' value smaller than 10
				printf("	#Departure 0%d:0%d %s\n", hour,minutes, city[start]);
			else //case : hour's value smaller than 10
				printf("	#Departure 0%d:%d %s\n", hour,minutes, city[start]);
		}
		else{
			if( minutes<10)		//case : minitues' value smaller than 10
				printf("	#Departure %d:%0d %s\n", hour,minutes, city[start]);
			else	// case : hour's value and minitues' value bigger than 10
				printf("	#Departure %d:%d %s\n", hour,minutes, city[start]);
		}
		hour = min[end][0]/100;
		minutes = min[end][0]%100;
		if(hour<10){
			if( minutes<10)
				printf("	#Arrival 0%d:0%d %s\n",hour,minutes, city[end]);
			else
				printf("	#Arrival 0%d:%d %s\n",hour,minutes, city[end]);
		}
		else{
			if( minutes<10)
				printf("	#Arrival %d:0%d %s\n",hour,minutes, city[end]);
			else
				printf("	#Arrival %d:%d %s\n",hour,minutes, city[end]);
		}
}


void findMin(){			//It finds the minimum and the fastest routes.
	int min[100][2], temp[100];
	int i,j,k,pos;

	initArr(min,temp);

	for(i = 0; i < num_city; i++){
		pos = -1;
		for(j = 0; j < num_city; j++){
			if(temp[j] == 1)
				continue;
			else{
				if(pos == -1 || min[pos][0] > min[j][0])
					pos = j;
			}
		}
		if(min[pos][0] == 2400)
			break;
		temp[pos] = 1;

		for(j = 0; j < num_train; j++){
			for(k = 0; k < train_num[j]-1; k++){
				if(train[j][k][1] == pos && min[pos][0] <= train[j][k][0]){
					if(min[train[j][k+1][1]][0] > train[j][k+1][0])
						min[train[j][k+1][1]][0] = train[j][k+1][0];			
				}
			}
		}
	}
	
	for(i = 0; i < num_city; i++)
		temp[i] = 0;

	min[end][1] = min[end][0];

	for(i = 0; i < num_city; i++){
		pos = -1;
		for(j = 0; j < num_city; j++){
			if(temp[j] == 1)
				continue;
			else{
				if(pos == -1 || min[pos][1] < min[j][1])
					pos = j;
			}
		}

		temp[pos] = 1;
		for(j = 0; j < num_train; j++){
			for(k = 1; k < train_num[j]; k++){
				if(train[j][k][1] == pos && min[pos][1] >= train[j][k][0]){
					if(min[train[j][k-1][1]][1] < train[j][k-1][0])
						min[train[j][k-1][1]][1] = train[j][k-1][0];
				}
			}
		}
	}
	printf("\n\nRESULT:\n");
	if(temp[end] ==1)
		printResult(min);
	else
		printf("No Result!\n");

}

void main(){
	int i, j;
	char temp[20];

	printf("Enter the number of cities:\n");
	scanf("%d",&num_city);

	for(i =0; i < num_city; i++){
		printf("Enter %dth city: ",i+1);
		scanf("%s",city[i]);
	}

	printf("Enter the number of trains:\n");
	scanf("%d",&num_train);

	for(i = 0; i < num_train; i++){
		printf("Enter the number of %d trains sets  : ",i+1);
		scanf("%d",&train_num[i]);
		for(j = 0; j < train_num[i]; j++){
			printf("Enter %dth time and city: ",j+1);
			scanf("%d %s", &train[i][j][0],temp);
			train[i][j][1] = getIndex(temp);
		}
	}
	printf("Enter the time of start:\n");
	scanf("%d",&time);

	printf("Enter the name of start:\n");
	scanf("%s",temp);
	start = getIndex(temp);
	printf("Enter the name of end:\n");
	scanf("%s",temp);
	end = getIndex(temp);

	findMin();
}