#include <stdio.h>
#include <string.h>
#define SIZE 10001

void find (int, int);

char x[SIZE];//Sequence String
char z[101];//SubSequence String
int memo[SIZE];
int occurrence;//Count the number of occurrence in the Sequence

int main ()
{
	int i, test_count, idx = 0;
	//Read Input
	scanf("%d%*c", &test_count);
	for (i = 0; i < test_count; ++ i)
	{
		occurrence = 0;
		gets(x); gets(z);
	
		find (0, 0);
		memo[idx ++] = occurrence;
	}
	//Print Output
	for (i = 0; i < idx; ++ i)
		printf("%d\n", memo[i]);

	return 0;
}

/*
Description : Count the number of occurrence of subsequence in the sequence
Input : Current idx value of x(sequence), current idx value of z(subsequence) 
Output : None
*/
void find (int current_x, int current_z)
{
	int i;

	for (i = current_x; i < strlen(x); ++ i)
	{
		if (x[i] == z[current_z])
		{
			if ((current_z + 1) == strlen(z))
				occurrence ++;
			else
				find (i + 1, current_z + 1);
		}
	}
}
