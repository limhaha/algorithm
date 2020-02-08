#include <stdio.h>
#include <math.h>
#define MAX 101

struct POINT
{
	float x;
	float y;
};
typedef struct POINT Point;

float computeDis(Point, Point);
int ccw(Point, Point, Point);
float jarvis ();

Point p[MAX];
int next[MAX];
int n;

int main ()
{
	int i;

	printf("Input : \n");
	scanf("%d", &n);
	for (i = 0; i < n; ++ i)
		scanf("%f %f", &p[i].x, &p[i].y);
	
	printf("OutPut : %0.2f\n", jarvis());

	return 0;
}

float jarvis ()
{
	int current, nxt, i, start, min = 99999;
	float total = 0.0;

	for (i = 1; i < n; ++ i)
	{
		if (p[min].y > p[i].y)
			min = i;
		else if (p[min].y == p[i].y)
		{
			if (p[min].x > p[i].x)
				min = i;
		}
	}start = min;

	current = start;
	do {

		//nxt = (current + 1) % n;
		for (i = 0; i < n; ++ i)
		{
			angle = computeAngle(current, i)
			if (min > angle)
				nxt = i;
		}
		next[current] = nxt;
		current = nxt;

	}while (current != start);

	while (next[current] != start)
	{
		total += computeDis(p[current], p[next[current]]);
		current = next[current];
	}total += computeDis(p[current], p[next[current]]);

	return total;
}
int ccw (Point p1, Point p2, Point p3)
{
	int area;

	area = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
	if (area < 0)
		return -1;
	else if (area > 0)
		return 1;
	else
		return 0;
}
float computeDis (Point p1, Point p2)
{
	float dis;

	dis = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

	return dis;
}
