//This program computes that the minimum amount of money.
//Change hands in order to equalize all the students.
#include <stdio.h>
void main(){
	int n , i;
	int cost[100];
	int total;
	int avg;
	int result;
	while(1){	//if n value equals zero, loop will break.
		scanf("%d",&n);
		if(n==0)		// follows the information for the last trip. it means last trip.
			break;
		while(n<0 || n>100){	// the number of student range error handles.
			printf("input range error.[ 0 - 100]  enter again : \n");
			scanf("%d",&n);
		}
		total = 0;
		avg = 0;
		for(i = 0; i < n; i++){
			scanf("%d",&cost[i]);
			while(cost[i]<0 || cost[i] >100000){	//cost range error handles.
				printf("input range error. [ 0 - 100]  enter again : \n");
				scanf("%d",&cost[i]);
			}
			total += cost[i];
		}
		avg = total / n;
		result = 0;
		for(i = 0; i < n; i++){	//calculates total difference.
			if(cost[i] < avg)
				result += avg - cost[i];
		}
		printf("\\%d \n",result);
	}
}