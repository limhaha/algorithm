#include <stdio.h>
#include <stdlib.h>

void mergeSort (int, int);
void merge (int, int);

struct JOB
{
	int idx;
	int day;
	int fine;
};
typedef struct JOB Job;

Job j[1000], tmp[1000];
int tmp_idx;

int main ()
{
	int test_count, n, i;

	scanf("%d", &test_count);
	printf("\n");

	while (test_count > 0)
	{
		scanf("%d", &n);
		if (n < 1 || n > 1000)
		{
			printf("ERROR : Invalid input");
			exit(1);
		}
		//Read each job's day and fine
		for (i = 0; i < n; ++ i)
		{
			scanf("%d %d", &j[i].day, &j[i].fine);
			j[i].idx = i + 1;
		}
		mergeSort(0, n - 1);

		for (i = 0; i < n; ++ i)
			printf("%d ", j[i].idx);
		printf("\n");

		test_count --;
	}

	return 0;
}

/*
Description : Split the list into a list and then, merge them.
Input : (int)start and end of the list.
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
Description : Merge the two sorted list by weight descending order.
Input : (int)start and end of list.
Output : None.
*/
void merge (int start, int end)
{
	int mid = (start + end) / 2;
	int left, right, i;

	left = start; right = mid + 1;

	tmp_idx = 0;
	while (left <= mid && right <= end)
	{
		if ((j[left].fine / j[left].day) > (j[right].fine / j[right].day))
			tmp[tmp_idx ++] = j[left ++];
		else if ((j[left].fine / j[left].day) < (j[right].fine / j[right].day))
			tmp[tmp_idx ++] = j[right ++];
		else
		{
			if (j[left].idx < j[right].idx)
				tmp[tmp_idx ++] = j[left ++];
			else
				tmp[tmp_idx ++] = j[right ++];
		}
	}

	while (left <= mid)
		tmp[tmp_idx ++] = j[left ++];
	while (right <= end)
		tmp[tmp_idx ++] = j[right ++];

	for (i = 0; i < tmp_idx; ++ i)
		j[start + i] = tmp[i];
}