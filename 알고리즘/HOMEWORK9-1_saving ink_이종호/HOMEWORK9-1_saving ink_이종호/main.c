/**
This program names saving ink. It finds the minimum spanding cost in graph using kruskal algorithm.
It receives the number of dots and receives all of dot's values.
And then, It calculates the minimum cost.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 30

//Structure of Point
typedef struct POINT{
	int x;
	int y;
}Point;

Point *dots;
int n;

double calculateDistance(Point point1, Point point2){			//It returns distance value between point1 and point2
	double result = (point1.x-point2.x)*(point1.x-point2.x) + (point1.y-point2.y)*(point1.y-point2.y);
	return sqrt(result);
}
int isSet(int i, int j, int *arr){		//It returns two points are already seted. It also distingushes they are circled.
	if(arr[i] == arr[j])
		return 1;
	else
		return 0;
}
void makeSet(int i, int j, int *arr){		//It connects set and set.
	if(arr[i] < arr[j])
		arr[j] = arr[i];
	else
		arr[i] = arr[j];
}

void kruskal(){		//It calculates the minimum cost spanning tree.
	int i, j;
	int min_i, min_j;
	int count = 0;
	int *arr;		//It saves set record.
	double temp;
	double cost=0;
	double min;
	arr = (int *)malloc(sizeof(int)*n);

	for(i = 0; i < n; i++)
		arr[i] = i;

	while(count < n-1){
		min = 9999;		//initiallize enough big number.
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if( i == j)		//case: compares between same point.
					continue;
				temp = calculateDistance(dots[i],dots[j]);
				if(min > temp){ 
					if(!isSet(i,j,arr)){ //case: they aren't seted
						min = temp;
						min_i = i;
						min_j = j;
					}
				}
			}
		}
		
		makeSet(min_i,min_j,arr);	// connects two point.
		count++;
		cost += min;
	}
	printf("---------Minimum cost : %lf\n",cost);
	free(arr);
}

void main(){
	int i;
	printf("Enter the number of dots:\n");
	scanf("%d",&n);
	dots = (Point*)malloc(sizeof(Point)*n);
	for(i = 0; i < n; i++)
		scanf("%d %d",&dots[i].x,&dots[i].y);
	kruskal();
	free(dots);
}