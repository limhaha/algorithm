#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INFINITE 9999

void dijkstra (int, int);
int findCost (int, int, int, int);
int findCity (char[], char[]);
void makeCostTable (int);

struct CITY
{
	char name[30];
};
struct DEPARTURE
{
	int arrive;
	int depart;
};
struct PATH
{
	int count;
	struct DEPARTURE d[100];
};

struct CITY city[101];
struct PATH path[101][101];
//Adjacency list
int list[101][101];
int idx[101];
int visited[101];
//The number of cities
int c;

int main (void)
{
	int test_count, i, T, j, t;
	int source, target;
	char info[30], a[10], d[10];
	int start, end;

	scanf("%d%*c", &test_count);
	while (test_count > 0)
	{
		//Read the number of cities And Read the name of each city
		scanf("%d%*c", &c);
		for (i = 1; i <= c; ++ i)
			gets(city[i].name);

		//Read the train description
		scanf("%d%*c", &T);
		for (i = 0; i < T; ++ i)
		{
			scanf("%d%*c", &t);
			for (j = 0; j < t; ++ j)
			{
				gets(info);
				if (j == 0)
					start = findCity(info, d);
				else
				{
					end = findCity(info, a);
					path[start][end].d[path[start][end].count].depart = atoi(d);
					path[start][end].d[path[start][end].count].arrive = atoi(a);
					//Make an adjacency list
					if (path[start][end].count == 0)
						list[start][idx[start] ++] = end;

					path[start][end].count ++;
					start = end; strcpy(d, a);
				}
			}
		}
		
		scanf("%d%*c", &start);
		gets(a); gets(d);
		for (i = 1; i <= c; ++ i)
		{
			if (strcmp(a, city[i].name) == 0)
				source = i;
			if (strcmp(d, city[i].name) == 0)
				target = i;
		}
		path[0][source].d[0].arrive = start;
		dijkstra(source, target);
		
		test_count --;
	}

	return 0;	
}
/*
Description : Devide the time and city name. and then, return matching city index
Input : (String)Input and Time
Output : Index of matching city
*/
int findCity (char info[30], char time[10])
{
	char *token;
	char delimit[] = " \n";
	int i;

	i = 0;
	token = strtok(info, delimit);
	while (token)
	{
		if (i == 0)
		{
			strcpy(time, token);
			i ++;
		}
		else
		{
			while (i <= c)
			{
				if (strcmp(city[i].name, token) == 0)
					return i;
				++ i;
			}
		}
		token = strtok(NULL, delimit);
	}
}
/*
Description : Using dijkstra algorithm, Find minimum path
Input : start point and target point numbers
Output : None
*/
void dijkstra (int source, int target)
{
	int dist[101], prev[101], prev_idx[101];
	int i, j, start, d, min, m;

	for (i = 1; i <= c; ++ i)
		dist[i] = INFINITE;

	start = source;
	visited[start] = 1;

	prev[start] = 0;
	prev_idx[prev[start]] = 0;
	while (visited[target] == 0)
	{
		min = INFINITE; m = 0;
		for (i = 0; i < idx[start]; ++ i)
		{
			for (j = 0; j < path[start][list[start][i]].count; ++ j)
			{
				d = findCost(prev[start], start, list[start][i], prev_idx[prev[start]], j);
				if (d < dist[list[start][i]] && visited[list[start][i]] == 0)
				{
					dist[list[start][i]] = d;
					prev[list[start][i]] = start;
				}
				if (min > dist[list[start][i]] && visited[list[start][i]] == 0)
				{
					min = dist[list[start][i]];
					m = list[start][i];
					prev_idx[start] = j;
				}
			}
		}
		if (m != 0)
			start = m;
		else
		{
			printf("No Connection\n");
			return;
		}
		visited[start] = 1;
	}

	while(prev[start] != source)
		start = prev[start];
	printf("\n");
	if (path[source][start].d[prev_idx[prev[start]]].depart < 1000)
		printf("Departure	0%d	%s\n", path[source][start].d[prev_idx[prev[start]]].depart, city[source].name);
	else
		printf("Departure	%d	%s\n", path[source][start].d[prev_idx[prev[start]]].depart, city[source].name);
	if (path[prev[target]][target].d[prev_idx[prev[target]]].arrive < 1000)
		printf("Arrival		0%d	%s\n", path[prev[target]][target].d[prev_idx[prev[target]]].arrive, city[target].name);
	else
		printf("Arrival		%d	%s\n", path[prev[target]][target].d[prev_idx[prev[target]]].arrive, city[target].name);
}
/*
Description : Check that current node can reach the next node
			  If can not, return INFINITE
			  Else can reach, return arrival time
Input : Node numbers (previous, current, next) and idx value (previous idx and current idx)
Output : Next node's arrival time
*/
int findCost (int prev, int current, int next, int prev_idx, int idx)
{
	if (path[prev][current].d[prev_idx].arrive > path[current][next].d[idx].depart)
		return INFINITE;
	else
		return (path[current][next].d[idx].arrive);
}
