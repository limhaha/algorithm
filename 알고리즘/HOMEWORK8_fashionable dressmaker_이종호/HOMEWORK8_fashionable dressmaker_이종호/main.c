//This program names fashionalbe dressmaker.
//It recieves two integers, time and fine.
//So, It finds the best order of tasks. 
//It uses greedy algorithm, So It calculates efficienty.
#include <stdio.h>
#include <stdlib.h>
int *time, *fine;

void sort(float *rate,int *index ,int n){	//This uses bubble sorting. It sorts ascending order.
	int i, j;
	float temp;
	int intTemp;
	int cost1, cost2;
	for(i =0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(rate[j] <rate[j+1]){
				temp = rate[j]; rate[j] = rate[j+1]; rate[j+1] = temp;
				intTemp = index[j]; index[j] = index[j+1]; index[j+1] = intTemp;
				intTemp = time[j]; time[j] = time[j+1]; time[j+1] = intTemp;
				intTemp = fine[j]; fine[j] = fine[j+1]; fine[j+1] = intTemp;
			}
			else if(rate[j] == rate[j+1]){		//case: when some rates are equal.
				cost1 = time[j]*fine[j+1];
				cost2 = time[j+1]*fine[j];
				if(cost1 == cost2){
					if(time[j] > time[j+1]){
						temp = rate[j]; rate[j] = rate[j+1]; rate[j+1] = temp;
						intTemp = index[j]; index[j] = index[j+1]; index[j+1] = intTemp;
						intTemp = time[j]; time[j] = time[j+1]; time[j+1] = intTemp;
						intTemp = fine[j]; fine[j] = fine[j+1]; fine[j+1] = intTemp;
					}
				}
			}
		}
	}
}

void findBest(int n){		//Calculates and sorts ,Finally It finds solution
	float *rate;
	int *index;
	int i;
	rate = (float *)malloc(sizeof(float)*n);
	index = (int *)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++){
		rate[i] = (float)fine[i]/time[i];
		index[i] = i;
	}
	sort(rate,index,n);

	printf("Result-------------\n");
	for(i = 0; i < n; i++)
		printf("%d ",index[i]+1);
	printf("\n");

	free(rate);
	free(index);
}

void main(){
	int i,j;
	int num,test;

	printf("Enter the number of test cases: \n");
	scanf("%d",&test);

	for(i=0; i < test; i++){
		printf("Enter the number of tasks: \n");
		scanf("%d",&num);

		time = (int *)malloc(sizeof(int)*num);
		fine = (int *)malloc(sizeof(int)*num);
		for( j = 0; j < num; j++)
			scanf("%d %d",&time[j],&fine[j]);

		findBest(num);

	}


	free(time);
	free(fine);
}