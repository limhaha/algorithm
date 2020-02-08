/*
This program names Clean campus.
It uses Jarvis algorithm. So, It finds the maximum convex hull which is conisisted of points that user's input.
*/


#include <stdio.h>
#include <math.h>
//Sturcture of point
typedef struct Point{
	double x, y;
	double degree; //degree of points to zero point.
}Point;

Point points[1000];
Point stack[1000];
int num;
int top = -1;
//It returns degree value between two points.
double computeAngle(Point A, Point B){
	double Dx, Dy;
	double absDx,absDy;
	double angle;
	Dx = B.x - A.x;
	Dy = B.y - A.y;
	absDx = Dx;
	absDy = Dy;
	if((Dx>=0)&&(Dy==0))
		angle = 0;
	else{
		if(absDx < 0)
			absDx =-absDx;
		if(absDy < 0)
			absDy = -absDy;
		angle = absDy/(absDx+absDy);
		if((Dx<0)&&(Dy>=0))
			angle = 2-angle;
		else if((Dx<=0)&&(Dy<0))
			angle = 2+angle;
		else if((Dx>0)&&(Dy <0))
			angle = 4-angle;
	}
	return (angle*90.0);
}

//It returns distance between two values.
double calculateDistance(Point p1, Point p2){
	double temp = (p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y);
	return sqrt(temp);
}
//It returns boolean value if or not that's point is in stack
int isIn(Point A){
	int i;
	if(top<0)
		return 0;
	else{
		for(i = 1; i <= top; i++){
			if(stack[i].x == A.x && stack[i].y == A.y){
				return 1;
			}
		}
		return 0;
	}
}
//It calculates total distance using Jarvis algorithnm.
void calculate(){
	int i;
	double min;
	double total = 0;
	int min_index=0;
	int pos;


	pos = 0;
	stack[++top] = points[pos];

	do{
		min = 360;
		for(i = 0; i < num; i++){
			if(pos == i || isIn(points[i])){
				continue;
			}
			else{
				if(min > computeAngle(stack[top],points[i])){
					min = computeAngle(stack[top],points[i]);
					min_index = i;
				}
			}
		}
		pos = min_index;
		stack[++top] = points[pos];
	}while(pos!=0);

	for(i = 0; i <top; i++){
		if(i ==0)
			total = total + calculateDistance(stack[i],stack[i+1])+1;
		else
			total = total + calculateDistance(stack[i],stack[i+1]);
		
	}
	total = total+1;
	printf("		#total : %.2lf\n",total);
}
void main(){
	int i;
	printf("Enter the number of Point : ");
	scanf("%d",&num);
	points[0].x = 0;
	points[0].y = 0;
	num++;
	for( i = 1; i < num; i++)
		scanf("%lf %lf",&points[i].x,&points[i].y);
	calculate();
}
