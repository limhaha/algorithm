/*
This program names funny chess.
It finds the number of cases their bishops coexist.
*/
#include <stdio.h>
typedef struct Point{ //struct of point
	int x;
	int y;
}Point;


Point a[100];
int n,b;
int totalCount;

int isSolution(int k){ //checks it is finished
	return k==b;
}
int isIn(Point temp,int k){ //If or not point temp already in stack
	int i;
	if(k == 0)
		return 0;
	else{
		for( i = 0; i < k; i ++){
			if(a[i].x ==temp.x && a[i].y == temp.y)
				return 1;
		}
		return 0;
	}
}
int isPossible(Point temp,int k){ //if or not point temp position  could be located
	int i;
	int tempX,tempY;
	if(k == 0)
		return 1;
	for(i =0; i < k; i++){
		tempX = a[i].x - temp.x;
		tempY = a[i].y - temp.y;
		if(tempX < 0)
			tempX = -tempX;
		if(tempY < 0)
			tempY = - tempY;

		if(tempX == tempY)
			return 0;
	}
	return 1;
}
void backtrack(int k){ //It finds solution reculsively
	Point temp;
	int i,j;
	if (isSolution(k)){
		totalCount++;
		return;
	}
	else{
		if( k != 0){
			i = a[k-1].x;
			j = a[k-1].y;
		}
		else{
			i = 0;
			j = 0;
		}
		for(i; i < n; i++){
			for(j; j < n; j++){
				temp.x = i;
				temp.y = j;
				if(isIn(temp,k)){
					continue;
				}
				else{
					if(k == 0 || isPossible(temp,k)){
						a[k] = temp;
						backtrack(k+1);
					}
				}
			}
			j = 0;
		}
	}
}
void main(){
	totalCount = 0;
	scanf("%d %d",&n,&b);
	backtrack(0);
	printf("	#result : %d\n",totalCount);
}