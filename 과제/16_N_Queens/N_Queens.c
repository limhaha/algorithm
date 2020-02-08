#include <stdio.h>
#include <math.h>
#define MAX 101

int promising(int);
void walk(int);
void nQueens();

int col[MAX];
int n, count;

int main ()
{
	printf("Input : ");
	scanf("%d", &n);

	nQueens();

	printf("Output : ");
	printf("%d\n", count);

	return 0;
}

/*
Description : Call walk function to compute output
Input : None
Output : None
*/
void nQueens()
{
	walk(-1);
}

/*
Description : Check if next node is promising or not
Input : Current Index
Output : If promising, return 1
		 If not promising, return 0
*/
int promising (int current)
{
	int i;

	for (i = 0; i < current; ++ i)
	{
		if (col[i] == col[current] || abs(current - i) == abs(col[current] - col[i]))
			return 0;
	} return 1;
}

/*
Description : Walk node and Comput Output 
Input : Current Index
Output : None
*/
void walk (int current)
{
	int i;

	if (current == n - 1)
		count ++;
	else
	{
		for (i = 0; i < n; ++ i)
		{
			col[current + 1] = i;
			if (promising(current + 1))
				walk(current + 1);
		}
	}
}