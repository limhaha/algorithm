/*
This program names calculating the number of trees in cunvex hull.
It receives points ordering by anticlockwise and calculates the number of trees.
*/


#include <stdio.h>
#include <math.h>
//Sturcture of point
typedef struct Point{
	int x, y;
}Point;

Point points[1000];
int num;


//It returns gcd a and b
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int max(int x, int y){
	if(x>y)
		return x;
	else
		return y;
}

int min(int x, int y){
	if(x>y)
		return y;
	else
		return x;
}
//It returns the number of boundary points.
int findBoundary(){
	int i;
	int divider;
	int totalCount = 0;
	int differX,differY;

	for( i = 0; i < num; i++){
		if(i == num-1){
			differX = points[i].x - points[0].x;
			differY = points[i].y - points[0].y;
		}
		else{
			differX = points[i].x - points[i+1].x;
			differY = points[i].y - points[i+1].y;
		}

		if(differX < 0)
			differX = -differX;
		if(differY < 0)
			differY = -differY;

		if(differX == 0)
			totalCount += differY;
		else if(differY == 0)
			totalCount += differX;
		else{
			divider = gcd(max(differX,differY),min(differX,differY));
			totalCount = totalCount + differX/(differX/divider);
		}
	}
	return totalCount;
}
// It calculates the number of trees
void calculate(){
	int i;
	int total1=0,total2=0;
	double total;
	int boundaryPoint;
	double result;
	for(i = 0; i < num; i++){
		if(i == num-1){
			total1 += points[i].x*points[0].y;
			total2 += points[i].y*points[0].x;
		}
		else{
			total1 += points[i].x*points[i+1].y;
			total2 += points[i].y*points[i+1].x;
		}
	}
	boundaryPoint = findBoundary();
	total = (total1-total2)/2;
	printf("#Boundary	%d\n",boundaryPoint);
	printf("#Area	%lf\n",total);
	result = total- boundaryPoint/2 +1;
	printf("#The number of Trees	%.0lf\n",result);
}
void main(){
	int i;
	printf("Enter the number of Point : ");
	scanf("%d",&num);
	for( i = 0; i < num; i++)
		scanf("%d %d",&points[i].x,&points[i].y);

	calculate();
}
