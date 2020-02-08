/*
This program names Clean campus.
It uses Graham scan algorithm. So, It finds the maximum convex hull which is conisisted of points that user's input.
*/


#include <stdio.h>
#include <math.h>
//Sturcture of point
typedef struct Point{
	double x, y;
	double degree; //degree of points to zero point.
}Point;

Point points[1000];
int num;

 //It returns points are clockwise or counterclockwise. 
//If they are clockwise, it returns > 0.  if they are counterclockwise, it returns < 0. otherwise return 0. It means they are in same line.
double clockwise(Point p1, Point p2, Point p3){
	return (p2.x-p1.x)*(p3.y-p1.y)- (p2.y - p1.y)*(p3.x-p1.x);
}
//It is swap function.
void swap(int i, int j){
	Point temp;
	temp = points[i];
	points[i] = points[j];
	points[j] = temp;
}

//It sorts ascending order by degree value.
void sorting(){
	int i, j;
	for( i = 0; i < num; i++){
		if(atan2(points[i].y,points[i].x) < 0)
			points[i].degree = atan2(0.0,-1.0)*2+atan2(points[i].y,points[i].x);
		else
			points[i].degree = atan2(points[i].y,points[i].x);
	}
	for(i = 0; i < num-1; i ++){
		for(j = 0; j < num-1-i; j++){
			if(points[j].degree > points[j+1].degree)
				swap(j,j+1);
		}
	}
}
//It returns distance between two values.
double calculateDistance(Point p1, Point p2){
	double temp = (p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y);
	return sqrt(temp);
}

//It calculates total distance using Graham scan algorithnm.
void calculate(){
	Point stack[10000];
	Point zero;
	int top = -1;
	int i;
	int cnt=3;
	double total = 0;
	zero.x = 0; zero.y = 0;
	stack[++top] = points[0];
	stack[++top] = points[1];
	stack[++top] = points[2];
	for( i = 3; i < num; i++){
		if(clockwise(stack[top],zero,points[i])>0)
			top--;
			
		stack[++top] = points[i];
	}
	cnt = top;
	for(i = 0; i < cnt+1; i++){
		if(i == 0)
			total = total + calculateDistance(stack[i],zero) + 1;
		else
			total = total + calculateDistance(stack[i-1],stack[i]);
	}
	total = total + calculateDistance(stack[top],zero)+1;
	printf("	#total = %.2lf\n", total);
}
void main(){
	int i;
	printf("Enter the number of Point : ");
	scanf("%d",&num);
	for( i = 0; i < num; i++)
		scanf("%lf %lf",&points[i].x,&points[i].y);

	sorting();
	calculate();
}
