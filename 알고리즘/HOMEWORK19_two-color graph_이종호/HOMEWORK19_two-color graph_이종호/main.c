/*
This program names two color graph.
It paints two color, but they are adjancented, it can't paint same color.
*/

#include <stdio.h>
int graph[30][30];
int color[30];
int result = 0;
int num;
int max;
void init(){ //It initializes all variables.
	int i,j;
	result = 0;
	max = 0;
	for(i= 0; i < 30; i++){
		color[i] = 0;
		for(j =0; j <30; j++){
			graph[i][j] = 0;
		}
	}
}
int isPossible(int i){ //It checks they are adjacented
	int j = 0;
	while(j < i){
		if(graph[i][j] && color[i] ==color[j])
			return 0;
		j++;
	}
	return 1;
}
void coloring(int k){ //It found they are two color graph
	int i;
	if(isPossible(k)){
		if(k == max){
			result = 1;
			return;
		}
		for(i = 0; i <2; i++){
			color[k+1] = i;
			coloring(k+1);
		}
	}
}
int checkPlanarmap(){ //checks it is planar graph
	int i;
	for(i = 0; i < max; i++){
		if(graph[i][i])
			return 0;
	}
	return 1;
}
void main(){
	int x,y;
	int i;
	while(1){
		init();
		scanf("%d",&num);
		if(num == 0)
			break;
		for(i = 0; i < num; i++){
			scanf("%d %d",&x,&y);
			graph[x][y] = graph[y][x] = 1;
			if(x > max)
				max = x;
			if(y > max)
				max = y;
		}
		if(checkPlanarmap()){
			coloring(0);
			if(result)
				printf("	#It is two-color graph\n");
			else
				printf("	#It is not two-color graph\n");
		}
		else
			printf("	#It is not planar map\n");
	}
}