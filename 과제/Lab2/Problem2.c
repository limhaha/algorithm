/** Floyd-Warshall Algorithm **/
#include <stdio.h>
#define INFINITY 999

int main ()
{
	int D[7][7], matrix[7][7];
	int i, j, k;
	int u, v, w, n, m;

	/* Read node count */
	scanf("%d", &n);
	/*Initialize Matrix Table*/
	for (i = 1; i <= n; ++ i)
	{
		for (j = 1; j <= n; ++ j)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = INFINITY;
		}
	}
	/* Read Adjacency Information */
	scanf("%d", &m);
	for (i = 1; i <= m; ++ i)
	{//Format : source U destination V weight W
		scanf("%d %d %d", &u, &v, &w);
		matrix[u][v] = w;
	}

	for (i = 1; i <= n; ++ i)
	{
		for (j = 1; j <= n; ++ j)
			D[i][j] = matrix[i][j];
	}
	/* Floyd-Warshall */
	for (k = 1; k <= n; ++ k)
	{
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= n; ++ j)
			{
				if (D[i][j] > D[i][k] + D[k][j])
					D[i][j] = D[i][k] + D[k][j];
			}
		}
		printf("Step %d\n", k);
		for (i = 1; i <= n; ++ i)
		{
			for (j = 1; j <= n; ++ j)
				printf("%3d ", D[i][j]);
			printf("\n");
		}
	}

	return 0;
}