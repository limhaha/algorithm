#include <stdio.h>
#include <math.h>

struct DOT
{
	float x;
	float y;
};
struct DOT dot[31];
struct EDGE
{
	double dis;
	int a;
	int b;
};
struct EDGE edge[435];
struct EDGE tmp[435];

int list[31][31], idx[31];
int visited[31], idx_edge;
int n;

double calDis (int, int);
void mergeSort (int, int);
void merge (int, int);
double select ();

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
	//Make the edge list
	for (i = 1; i <= n; ++ i)
	{
		for (j = 0; j < idx[i]; ++ j)
		{
			edge[idx_edge].dis = calDis(i, list[i][j]);
			edge[idx_edge].a = i; edge[idx_edge].b = list[i][j];
			idx_edge ++;
		}
	}
	//Sort the edge list by ascending order of distance
	mergeSort(0, idx_edge - 1);

	printf("%0.2lf\n", select());

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

void mergeSort (int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, end);
	}
}
void merge (int start, int end)
{
	int mid = (start + end) / 2;
	int left, right, index, i;
	
	left = start; right = mid + 1;

	index = 0;
	while (left <= mid && right <= end)
	{
		if (edge[left].dis < edge[right].dis)
			tmp[index ++] = edge[left ++];
		else
			tmp[index ++] = edge[right ++];
	}

	while (left <= mid)
		tmp[index ++] = edge[left ++];
	while (right <= end)
		tmp[index ++] = edge[right ++];

	for (i = 0; i < index; ++ i)
		edge[start + i] = tmp[i];
}
double select ()
{
	int i, count = 0;
	double total = 0;
	
	for (i = 0; i < idx_edge; ++ i)
	{
		if (visited[edge[i].a] == 0 || visited[edge[i].b] == 0)
		{
			total += edge[i].dis;
			if (visited[edge[i].a] == 0 && visited[edge[i].b] == 0)
				count += 2;
			else
				count += 1;
			visited[edge[i].a] = visited[edge[i].b] = 1;
		}
		if (count >= n)
			break;
	}

	return total;
}