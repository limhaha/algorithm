#include <stdio.h>

struct EUCLID
{
	int d;
	int x;
	int y;
};
typedef struct EUCLID E;

E Extended_Euclid(int, int);

int main ()
{
	int A, B;
	E result;

	printf("Input: ");
	scanf("%d %d", &A, &B);
	result = Extended_Euclid(A, B);
	printf("Output: %d %d %d\n", result.x, result.y, result.d);

	return 0;
}

E Extended_Euclid(int a, int b)
{
	E tmp, result;
	if (b == 0)
	{
		result.x = 1;
		result.y = 0;
		result.d = a;
		return result;
	}

	tmp = Extended_Euclid(b, a % b);
	result.d = tmp.d;
	result.x = tmp.y;
	result.y = tmp.x - (a / b) * tmp.y;

	return result;
}