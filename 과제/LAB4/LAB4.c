#include <stdio.h>
#define MAX 1000

void reverseTable ();
int check ();
int promising (int);
void moveBlack (int, int);
void moveWhite (int, int);
void PrintTable ();

int table[MAX];
int n, size;

int main ()
{
	int i;
	/* Table Setting : Black = -1 Empty = 0 White = 1 */
	scanf("%d", &n);
	printf("Setting : ");
	size = (2 * n) + 1;
	for (i = 0; i < size; ++ i)
	{
		if (i < n)
			table[i] = -1;
		else if (i > n)
			table[i] = 1;
	} PrintTable();

	reverseTable();
	printf("Result : ");
	PrintTable();

	return 0;
}

void reverseTable ()
{
	int i = 0;

	while (check())
	{
		if (promising(i))
		{
			if (table[i] == -1)
			{
				if (table[i + 1] == 0)
					moveBlack(i, 0);
				else
				{
					moveBlack(i, 1);
					i = -1;
				}
			}
			else
			{
				if (table[i - 1] == 0)
				{
					moveWhite(i, 0);
					i = -1;
				}
				else
					moveWhite(i, 1);
			}
		}
		i = (i + 1) % size;
	}
}
int promising (int current)
{
	int promising = 0;

	if (table[current] == -1)
	{
		if (current + 1 < size && table[current + 1] == 0)
			promising = 1;
		else if (current + 2 < size && table[current + 1] == 1 && table[current + 2] == 0)
			promising = 1;
	}
	else if (table[current] == 1)
	{
		if (current - 1 >= 0 && table[current - 1] == 0)
			promising = 1;
		else if (current - 2 >= 0 && table[current - 1] == -1 && table[current - 2] == 0)
			promising = 1;
	}
	else
		promising = 0;

	return promising;
}
int check ()
{
	int i, valid = 0;

	for (i = 0; i < size; ++ i) {
		if (promising(i) == 1)
			valid = 1;
	} return valid;
}
void moveBlack(int current, int isJump)
{
	if (isJump)
	{
		table[current] = 0;
		table[current + 2] = -1;
	}
	else
	{
		table[current] = 0;
		table[current + 1] = -1; 
	}
}
void moveWhite(int current, int isJump)
{
	if (isJump)
	{
		table[current] = 0;
		table[current - 2] = 1;
	}
	else
	{
		table[current] = 0;
		table[current - 1] = 1; 
	}
}

void PrintTable ()
{
	int i;

	for (i = 0; i < size; ++ i)
	{
		if (table[i] == -1)
			printf("Black ");
		else if (table[i] == 1)
			printf("White ");
		else
			printf("Empty ");
	} printf("\n");
}