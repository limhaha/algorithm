/*
This program names marketing strategy.
It finds the minimum value in points. 
It divides two part and finds their each the minimum value.
Finally, It takes one more test that finds in range mid-d < x <mid+d
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{	//Structure of Point
	double x;
	double y;
}Point;

Point points[10000];
int num;

void swap(int i, int j){	//It swaps two pointses postion.
	Point temp;
	temp = points[i];
	points[i] = points[j];
	points[j] = temp;
}

void sorting(){ //It sorts ascending by x
	int i,j;
	for(i = 0; i < num-1; i++){
		for(j = 0; j < num- i-1;j++){
			if(points[j].x > points[j+1].x)
				swap(j,j+1);
		}
	}
}
void sortingY(Point arr[], int num){ //It sorts stack ascending by y
	int i,j;
	for(i = 0; i < num-1; i++){
		for(j = 0; j < num- i-1;j++){
			if(arr[j].y > arr[j+1].y)
				swap(j,j+1);
		}
	}
}

double findMin(double a, double b){ //It returns smaller value.
	if(a > b)
		return b;
	else
		return a;
}

double computeDistance(Point p1, Point p2){ //It returns distance between two points.
	double temp = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y - p2.y)*(p1.y-p2.y);
	return sqrt(temp);
}

double bruteForce(int start, int end){
	int i,j;
	double temp;
	double min = 999999;
	for( i = start; i <end; i++){
		for( j = start; j< end; j++){
			if( i == j)
				continue;
			else{
				temp = computeDistance(points[i],points[j]);	
				if(min > temp)
					min = temp;
			}
		}
	}
	return min;
}

double closetPair(int start, int end){ //It finds the minimum value between start and end.
	int i, j;
	double min = 999999;
	double temp;
	double dl,dr;
	double d;
	Point stack[10000];
	int q;
	int top = -1;

	if(end - start <3)
		return bruteForce(start,end);
	q = (start+end)/2;

	dl = closetPair(start,q-1);
	dr = closetPair(q,end);
	d = findMin(dl,dr);

	for(i = 0; i < num; i++){
		if(points[q].x - d <= points[i].x && points[i].x <= points[q].x+d)
			stack[++top] = points[i];
	}

	sortingY(stack,top+1);
	for(i =0; i < top; i++){
		for(j =0; j < top; j++){
			if(i==j)
				continue;
			else{
				temp = computeDistance(points[i],points[j]);
				if(d > temp)
					d = temp;
			}
		}
	}
	return d;
}
void main(){
	int i;
	double result;
	printf("Enter the number of points : ");
	scanf("%d",&num);
	for(i = 0; i < num; i++)
		scanf("%lf %lf",&points[i].x,&points[i].y);
	sorting();
	result = closetPair(0, num);
	if(result > 10000)
		printf("INFINITE!\n");
	else
		printf("		#result : %.2lf\n",result);
}