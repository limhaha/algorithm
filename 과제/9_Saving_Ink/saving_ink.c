#include <stdio.h>
#include <math.h>

struct DOT
{
	float x;
	float y;
};
struct DOT dot[31];

int list[31][31];
int visited[31], idx[31];
int count, n;
double total = 0;

void walk (int);
double calDis (int, int);

int main (void)
{
	int i, j;
	//Read data
	scanf("%d", &n);
	for (i = 1; i <= n; ++ i)
		scanf("%f %f", &dot[i].x, &dot[i].y);
	//Make the adjacency list
	for (i = 1; i <= n; ++ i)
	{
		for (j = 1; j <= n; ++ j)
		{
			if (i != j)
				list[i][idx[i] ++] = j;
		}
	}

	walk(1);
	printf("%0.2lf\n", total);

	return 0;
}

/*
Description : Calculate distance between two dots
Input : Two dot numbers
Output : Distance between two dots
*/
double calDis (int start, int end)
{
	double dis;
	
	dis = sqrt(pow(dot[start].x - dot[end].x, 2) + pow(dot[start].y - dot[end].y, 2));

	return dis;
}

/*
Description : Find the minimum cost by using Prim's Algorithm
Input : Current dot number
Output : None
*/
void walk (int current)
{
	int i, j, next, prev;
	double min = 0, dis;

	visited[current] = 1;
	count += visited[current];

	if (count < n)
	{
		for (i = 1; i <= n; ++ i)
		{
			if (visited[i] == 1)
			{
				current = i;
				for (j = 0; j < idx[current]; ++ j)
				{
					if (visited[list[current][j]] == 0)
					{
						dis = calDis(current, list[current][j]);
						if (min == 0)
						{
							min = dis;
							next = list[current][j];
						}
						else if (dis < min)
						{
							min = dis;
							next = list[current][j];
							prev = current;
						}
					}
				}
			}
		}
		total += min;
		walk(next);
	}
}