#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 255

void initTable ();
int LCS (int, int);

char x[BUFFERSIZE], y[BUFFERSIZE];
//Used for memo the value of lcs
int table[BUFFERSIZE][BUFFERSIZE];

int main ()
{
	int test_count;
	int max_length;

	//Read the number of test you want
	scanf("%d%*c", &test_count);
	while (test_count > 0)
	{
		//Read sequence X and Y
		gets(x); gets(y);

		initTable();
		//Call LCS function to compute max length of common subsequence
		max_length = LCS(strlen(x), strlen(y));
		printf("Longest common subsequence is of length %d\n\n", max_length);

		test_count --;
	}

	return 0;
}

/*
Description : Initialize all value of table to 0
Input : None
Output : None
*/
void initTable ()
{
	int i, j;

	for (i = 0; i < BUFFERSIZE; ++ i)
	{
		for (j = 0; j < BUFFERSIZE; ++ j)
			table[i][j] = 0;
	}
}

/*
Description : Compute lcs value and store it into the table, comparing two sequences
Input : (int)Length of X sequence and Length of Y sequence
Output : (int)Max length of common subsequence between two sequences
*/
int LCS (int length_x, int length_y)
{
	int i, j;

	for (i = 1; i <= length_x; ++ i)
	{
		for (j = 1; j <= length_y; ++ j)
		{
			if (x[i - 1] == y[j - 1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
			{//table[i][j] = max {table[i][j - 1], table[i - 1][j]}
				if (table[i][j - 1] > table[i - 1][j])
					table[i][j] = table[i][j - 1];
				else
					table[i][j] = table[i - 1][j];
			}
		}
	}
	return (table[length_x][length_y]);
}