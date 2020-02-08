#include <stdio.h>
#include <stdlib.h>

int LIS (int);
void mergeSort (int, int);
void merge (int, int);

struct ELEPHANT
{
	int pos;
	int w;
	int s;
};
struct ELEPHANT e[1000];
//Used in merge sort
struct ELEPHANT tmp_e[1000];
//lis value array
int lis[1000];
int subsquence[1000];
//index value for temporary elephants array and subsequence
int idx;

int main ()
{
	FILE *fp;
	int tmp_w, tmp_s;
	int i, max;

	fp = fopen("elephants3.txt", "r");
	if (fp == NULL)
	{
		printf("File is not found\n");
		exit(1);
	}
	//Read data from file
	i = 0;
	while (fscanf(fp, "%d %d\n", &tmp_w, &tmp_s) != EOF)
	{
		if (!(0 <= tmp_s && tmp_s <= 10000) || !(0 <= tmp_w && tmp_w <= 10000))
		{
			printf("ERROR : Invalid value\n");
			exit(1);
		}
		else
		{
			e[i].pos = i;
			e[i].w = tmp_w;
			e[i].s = tmp_s;
			i ++;
		}
	}

	mergeSort(0 , (i - 1));
	max = LIS(i);
	printf("%d\n", max);
	for (i = 0; i < idx; ++ i)
		printf("%d\n", e[subsquence[i]].pos + 1);

	fclose(fp);

	return 0;
}

/*
Description : Compute lis value and find subsequence
Input : The number of elephants
Output : Max length of subsuquence among the elephants list
*/
int LIS (int n)
{
	int i, j;
	int max = 0;
	
	idx = 0;

	for (i = 0; i < n; ++ i)
		lis[i] = 1;

	for (i = 1; i < n; ++ i)
	{
		for (j = 0; j < i; ++ j)
		{
			if ((e[j].w < e[i].w && e[j].s > e[i].s) && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				if (idx == 0)
				{
					subsquence[idx ++] = j;
					subsquence[idx ++] = i;
				}
				else if (subsquence[idx - 1] == j)
					subsquence[idx ++] = i;
			}
		}
	}

	for (i = 0; i < n; ++ i)
	{
		if (max < lis[i])
			max = lis[i];
	}

	return max;
}

/*
Description : Split the list to be sorted
Input : Start, end value
Output : None
*/
void mergeSort (int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort (start, mid);
		mergeSort (mid + 1, end);
		merge (start, end);
	}
}

/*
Description : Merge list's splited compoment.
Input : Start and end value
Output : None
*/
void merge (int start, int end)
{
	int mid = (start + end) / 2;
	int left, right, i;

	left = start; right = mid + 1;

	idx = 0;
	while (left <= mid && right <= end)
	{
		if (e[left].w < e[right].w)
			tmp_e[idx ++] = e[left ++];
		else if (e[left].w > e[right].w)
			tmp_e[idx ++] = e[right ++];
		else
		{
			if (e[left].s < e[right].s)
				tmp_e[idx ++] = e[left ++];
			else
				tmp_e[idx ++] = e[right ++];
		}
	}

	while (left <= mid)
		tmp_e[idx ++] = e[left ++];
	while (right <= end)
		tmp_e[idx ++] = e[right ++];

	for (i = 0; i < idx; ++ i)
		e[start + i] = tmp_e[i];
}
