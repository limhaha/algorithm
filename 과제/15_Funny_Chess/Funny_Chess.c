#include <stdio.h>
#define MAX 101

void initTable ();
void initSelect (int, int);
void allocateArea (int, int);
void deallocateArea (int, int);
void walk (int, int);

int table[MAX][MAX];
int selected[MAX][MAX];
int n, k;
int count, ways;

int main ()
{
	int i, j;
	while (1)
	{
		initTable();
		scanf("%d %d", &n, &k);
		if (n == 0&& k == 0)
			break;
		for (i = 0; i < n; ++ i) {
			for (j = 0; j < n; ++ j){
					walk(i, j);
			}
		}
		printf("%d\n\n", ways);
	}

	return 0;
}
void initSelect (int x, int y)
{
	int i, j;

	if(y == n-1){
		x ++;
		y = 0;
	}
	else
		y ++;
	for (i = x ; i < n; ++ i)
	{
		if(i > x)
			y = 0;
		for (j = y; j < n; ++ j) {
			selected[i][j] = 0;
		}
	}
}
void initTable ()
{
	int i, j;

	for (i = 0; i < n; ++ i)
	{
		for (j = 0; j < n; ++ j)
			table[i][j] = selected[i][j] = 0;
	} ways = count = 0;
}
void allocateArea (int x, int y)
{
	int i, j;

	i = x; j = y;
	while (i >= 1 && j >= 1)
		table[-- i][-- j] ++;
	i = x; j = y;
	while (i <= n - 2 && j <= n - 2)
		table[++ i][++ j] ++;
	i = x; j = y;
	while (i >= 1 && j <= n - 2)
		table[-- i][++ j] ++;
	i = x; j = y;
	while (i <= n - 2 && j >= 1)
		table[++ i][-- j] ++;
}
void deallocateArea (int x, int y)
{
	int i, j;

	table[x][y] --;
	i = x; j = y;
	while (i >= 1 && j >= 1)
		table[-- i][-- j] --;
	i = x; j = y;
	while (i <= n - 2 && j <= n - 2)
		table[++ i][++ j] --;
	i = x; j = y;
	while (i >= 1 && j <= n - 2)
		table[-- i][++ j] --;
	i = x; j = y;
	while (i <= n - 2 && j >= 1)
		table[++ i][-- j] --;
}
void walk (int x, int y)
{
	int i, j;

	count ++;
	if (count == k)
	{
		count --;
		ways ++;
	}
	else
	{
		table[x][y] ++;
		allocateArea(x, y);
		for (i = 0; i < n; ++ i)
		{
			for (j = 0; j < n; ++ j)
			{
				if (selected[i][j] == 0 && table[i][j] == 0)
					walk(i, j);
			}
		}
		count --;
		deallocateArea(x, y);
		selected[x][y] = 1;
		initSelect(x, y);
	}
}