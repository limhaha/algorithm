/**
This program names saving ink. It finds the minimum spanding cost in graph.
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
	int bit;
}Point;

Point *stack[MAX];	//It saves points those visited.
Point *dots;
int n;
int top = 0;
double min;

double prim(Point *start){	//Use Prim Algorithm, It has parameter which starting point. So, it returns the minimum cost.
	int cnt = 0;
	int possible_direct = 0;
	int isFirst = 1;
	int i;
	double total = 0;
	double min_distance=0;
	int min_index;
	double temp;
	Point *pos;
	pos = start;
	pos->bit =1;
	while(cnt < n-1){
		isFirst = 1;
		possible_direct = 0;
		min_index = 0;
		min_distance = 0;
		for(i = 0; i < n; i++){
			if(pos->x == dots[i].x && pos->y == dots[i].y){	//case: compares same point
				continue;
			}
			if(dots[i].bit==1){	//case: compares visited points.
				continue;
			}
			else{
				possible_direct++;
				temp = (pos->x-dots[i].x)*(pos->x-dots[i].x)+(pos->y-dots[i].y)*(pos->y-dots[i].y);
				temp = sqrt(temp);
				if(isFirst == 1){	//case: firstly calculates edge.
					min_distance = temp;
					min_index = i;
					isFirst = 0;
				}
				else{
					if(min_distance > temp){ //case : finds other smaller edge.
						min_distance = temp;
						min_index = i;
					}
				}
			}
		}
		if(possible_direct > 0){	//case : it finds other edge.
			cnt ++;
			total += min_distance;
			stack[top++] = pos;
			dots[min_index].bit = 1;
			pos = &dots[min_index];
		}
		else	//case : it didn't find other edge.
			pos = stack[top--];
	}
	return total;
}

void main(){
	int i,j;
	double temp;
	printf("Enter the number of dots:\n");
	scanf("%d",&n);
	dots = (Point*)malloc(sizeof(Point)*n);
	for(i = 0; i < n; i++){
		scanf("%d %d",&dots[i].x,&dots[i].y);
		dots[i].bit = 0;
	}
	for(i = 0; i < n; i++){
		for(j = 0; j <n;j++)
			dots[j].bit = 0;
		top = 0;
		temp = prim(&dots[i]);
		if(i == 0)
			min = temp;
		else{	
			if(min > temp) // if found other smaller cost, it chages the minimum cost.
				min = temp;
		}
	}
	printf("---------Minimum cost : %lf\n",min);
	free(dots);
}