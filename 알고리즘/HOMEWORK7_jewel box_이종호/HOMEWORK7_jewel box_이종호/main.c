//This program named jewel box.
//It uses greedy algorithem. It distingushes capacity between two box.
//So, box that has higher capacity is used mainly.

#include <stdio.h>
int result[2];
int findBestWay(int c1,int n1,int c2,int n2,int num){ //Calculates capacity and then distinguishes they are optimal.
	float capacity1 = (float) n1/c1;
	float capacity2 = (float) n2/c2;

	result[0] = 0;
	result[1] = 0;

	if(capacity1 > capacity2){		//case : box1 has higher capacity than box2
		while(1){
			if(result[0]*n1<num)
				result[0]++;
			else
				break;
		}
		if(result[0]*n1 !=num){
		while(result[0] != 0){
			if(num - result[0]*n1 < n2)
				result[0]--;
			else if((num-result[0]*n1)%n2==0){
				result[1] = (num-result[0]*n1)/n2;
				return 1;
			}
			else
				result[0]--;
		}
		return -1;
		}
		else
			return 1;
	}
	else{		//case : box2 has higher capacity than box1
	while(1){
			if(result[1]*n2<num)
				result[1]++;
			else
				break;
		}
		if(result[1]*n2 !=num){
		while(result[1] != 0){
			if(num - result[1]*n2 < n1)
				result[1]--;
			else if((num-result[1]*n2)%n1==0){
				result[0] = (num-result[1]*n2)/n1;
				return 1;
			}
			else
				result[1]--;
		}
		return -1;
		}
		else
			return 1;
	}
}
void main(){
	int num;
	int c1,c2,n1,n2;

	while(1){
		printf("Enter the number of jewel:\n");
		scanf("%d",&num);
		if(num==0)
			break;
		printf("First box's cost and the number of hold jewels:\n");
		scanf("%d %d",&c1,&n1);
		printf("Second box's cost and the number of hold jewels:\n");
		scanf("%d %d",&c2,&n2);
		if(findBestWay(c1,n1,c2,n2,num)==1){
			printf("%d	%d\n",result[0],result[1]);
			printf("---------cost : %d\n",result[0]*c1+result[1]*c2);
		}
		else
			printf("Fail\n");
	}
}