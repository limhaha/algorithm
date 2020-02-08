#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeNapTime (int);
void convertInt (char[10], int[2], int[2], int);
void computeMaxTime (struct DURATIONTIME);
void mergeSort (int, int);
void merge (int, int);

struct DURATIONTIME
{
	int hour;
	int minute;
	char start_time[10];
};
struct DURATIONTIME max = {-1, -1, "null"};

struct EVENT
{
	char start[10];
	char end[10];
};
struct EVENT e[100];
// Need for merge sorting
struct EVENT tmp_e[100];

int main ()
{
	int i, j, day;
	int s;
	char line[255];
	char *token;
	char delimit[] = " \n";
	int start, end;

	for (day = 1; day <= 3; ++ day)
	{
		scanf("%d%*c", &s);
		for (i = 0; i < s; ++ i)
		{
			gets(line);	

			j = 0;
			token = strtok(line, delimit);
			while (token)
			{
				switch (j)
				{
				case 0:
					strcpy(e[i].start, token);
					break;
				case 1:
					strcpy(e[i].end, token);
					break;
				}
				++ j;

				if (j < 2)
					token = strtok(NULL, delimit);
				else
					break;
			}
		}

		start = 0; end = s - 1;
		mergeSort (start, end);
		
		for (i = 0; i < (s - 1); ++ i)
		{
			if (strcmp(e[i].end, e[i + 1].start) != 0)
				computeNapTime(i);
		}

		if (max.hour < 1)
			printf("Day #%d : the longest nap starts at %s and will last for %d minutes\n", day, max.start_time, max.minute);
		else
			printf("Day #%d : the longest nap starts at %s and will last for %d hours and %d minutes\n", day, max.start_time, max.hour, max.minute);
		
		max.hour = max.minute = -1;
		strcpy(max.start_time, "null");
	}

	return 0;
}

/*
Description : Compute duration time using converInt function.
Input : Current index value
Output : none
*/
void computeNapTime (int idx)
{
	struct DURATIONTIME tmp_t;
	char t1[10], t2[10];
	char *token;
	char delimit[] = ":\n";
	int i;
	int h[2], m[2];
	int time;

	strcpy(t1, e[idx].end);
	strcpy(t2, e[idx + 1].start);
	
	for (i = 0; i < 2; ++ i)
	{
		if (i == 0)
			convertInt(t1, h, m, i);
		else
			convertInt(t2, h, m, i);
	}

	time = ((h[1] * 60) + m[1]) - ((h[0] * 60) + m[0]);
	tmp_t.hour = time / 60;
	tmp_t.minute = time % 60;
	
	strcpy(tmp_t.start_time, e[idx].end);

	computeMaxTime(tmp_t);
}

/*
Description : Convert passed input(time string) to integer
Input : String(time), 2 integer array(hour, minute), current index value.
Output : none
*/
void convertInt (char t[], int h[], int m[], int idx)
{
	int i;
	char *token;
	char delimit[] = ":\n";

	i = 0;
	token = strtok(t, delimit);
	while (token)
	{
		if (i == 0)
			h[idx] = atoi(token);
		else
			m[idx] = atoi(token);

		token = strtok(NULL, delimit);
		++ i;
	}
}

/*
Description : Compare each computed duration time and decide maximum time
Input : struct time variable
Output : none
*/
void computeMaxTime (struct DURATIONTIME current)
{
	if (strcmp(max.start_time, "null") == 0)
	{
		max.hour = current.hour;
		max.minute = current.minute;
		strcpy(max.start_time, current.start_time);
	}
	else if (current.hour >= max.hour && current.minute > max.minute)
	{
		max.hour = current.hour;
		max.minute = current.minute;
		strcpy(max.start_time, current.start_time);
	}
}

/*
Description : split the list to be sorted
Input : start, end value
Output : none
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
Description : merge list's splited compoment.
Input : start and end value
Output : none
*/
void merge (int start, int end)
{
	int i, idx = 0;
	int mid = (start + end) / 2;
	int left, right;

	left = start; right = mid + 1;

	while (left <= mid && right <= end)
	{
		if (strcmp(e[left].start, e[right].start) < 0)
			tmp_e[idx ++] = e[left ++];
		else
			tmp_e[idx ++] = e[right ++];
	}

	while (left <= mid)
		tmp_e[idx ++] = e[left ++];
	while (right <= end)
		tmp_e[idx ++] = e[right ++];

	for (i = 0; i < idx; ++ i)
		e[start + i] = tmp_e[i];
}