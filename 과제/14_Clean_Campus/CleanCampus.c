/* Graham Algorithm */
#include <stdio.h>
#include <math.h>
#define MAX 101

struct POINT
{
	float x;
	float y;
};
typedef struct POINT Point;

void mergeSort(int, int);
void merge (int, int);
int isEmpty ();
void Push (Point);
Point Pop ();
float computeAngle (Point, Point);
float computeDis (Point, Point);
float getTotalDis ();
int ccw(Point, Point, Point);
void Graham ();

Point p[MAX];
Point tmp[MAX];
Point S[MAX];
int m, top = -1;

int main (void)
{
	int i, t_c;
	float total;

	scanf("%d", &t_c);
	while (t_c > 0)
	{
		scanf("%d", &m);
		for (i = 1; i <= m; ++ i)
			scanf("%f %f", &p[i].x, &p[i].y);

		Graham();
		total = getTotalDis();
		printf("\n%0.2f\n", total);

		t_c --;
	}
	return 0;
}

/*
Description : Compute the angle between Point1 and Point2
Input : Point1 and Point2
Output : (float)Computed Angle
*/
float computeAngle (Point p1, Point p2)
{
	float Dx, Dy;
	float angle;

	Dx = p2.x - p1.x;
	Dy = p2.y - p1.y;

	if (Dx >= 0 && Dy == 0)
		angle = 0;
	else
	{
		angle = abs(Dy) / (abs(Dx) + abs(Dy));
		if ((Dx < 0) && (Dy >= 0))
			angle = 2 - angle;
		else if ((Dx <= 0) && (Dy < 0))
			angle = 2 + angle;
		else if ((Dx > 0) && (Dy < 0))
			angle = 4 - angle;
	}
	return (angle * 90);
}

/*
Description : Compute the distance between Point1 and Point2
Input : Point1 and Point2
Output : (float)Computed distance
*/
float computeDis (Point p1, Point p2)
{
	float dis;

	dis = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

	return dis;
}

/*
Description : Check if CCW or CW or COLINEAR
Input : Three Points (p1, p2, p3)
Output : if CCW -1
			CW 1
			Colinear 0
*/
int ccw(Point p1, Point p2, Point p3)
{
	int temp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	temp = temp - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;

	if (temp > 0)
		return 1;
	else if (temp < 0)
		return -1;
	else
		return 0;
}
/*
Description : Apply Graham Algo. to given points lists
Input : None.
Output : None.
*/
void Graham ()
{
	int i;

	p[0].x = p[0].y = 0;
	mergeSort(1, m);

	Push(p[0]); Push(p[1]); Push(p[2]);
	for (i = 3; i <= m; ++ i)
	{
		while (ccw(S[top - 1], S[top], p[i]) <= 0)
			Pop();
		Push(p[i]);
	}
}

/*
Description : Get total distance between points in Stack
Input : None.
Output : None.
*/
float getTotalDis ()
{
	Point tmp;
	float total = 2.0;

	tmp = Pop();
	total += computeDis(p[0], tmp);
	while (!isEmpty())
	{
		total += computeDis(S[top], tmp);

		tmp = Pop();
		if (isEmpty())
			break;
	}

	return (total);
}

/*
Description : Check if Stack is empty or not
Input : None.
Output : if Empty 1
			Not   0
*/
int isEmpty ()
{
	if (top < 0)
		return 1;
	else
		return 0;
}

/*
Description : Push given point in Stack
Input : A point
Output : None.
*/
void Push(Point key)
{
	S[++ top] = key;
}

/*
Description : Pop the last component from stack
Input : None.
Output : Popped points
*/
Point Pop ()
{
	Point tmp;

	tmp = S[top --];

	return tmp;
}

/*
Description : Split and Merge given list to sort it
Input : Start and end value of given list
Output : None.
*/
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

/*
Description : Merge the splited list
Input : Start and end value of given list
Output : None.
*/
void merge (int start, int end)
{
	int mid = (start + end) / 2;
	int left, right, idx = 0, i;

	left = start; right = mid + 1;
	while (left <= mid && right <= end)
	{
		if (computeAngle(p[0], p[left]) < computeAngle(p[0], p[right]))
			tmp[idx ++] = p[left ++];
		else if (computeAngle(p[0], p[left]) > computeAngle(p[0], p[right]))
			tmp[idx ++] = p[right ++];
		else
		{
			if (p[left].x < p[right].x)
				tmp[idx ++] = p[left ++];
			else
				tmp[idx ++] = p[right ++];
		}
	}

	while (left <= mid)
		tmp[idx ++] = p[left ++];
	while (right <= end)
		tmp[idx ++] = p[right ++];

	for (i = 0; i < idx; ++ i)
		p[i + start] = tmp[i];
}

void mergeSort (int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, start);
		merge(start, end);
	}
}