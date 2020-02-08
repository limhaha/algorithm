//This progrma names distinct subsequence.
//It receives two string, s1,s2. It finds subsequence s2 in s1.
//It prints all subsequence and the number of subsequences.

#include <stdio.h>
#include <stdlib.h>

int count1=0,count2 = 0;
int **table;

int subseq(char *str1, char *str2){//Find the number of subsequences.
	{
		int i , j;
		
		count1=0;
		count2=0;

		while(str1[count1] != '\0')
			count1++;
		while(str2[count2] != '\0')
			count2++;

		if(count1 < count2)		//case: s1's length smaller than s2's length.
			return 0;

		table = (int **)malloc(sizeof(int *) * (count2+1));
		for (i = 0; i < count2+1; i++)
			table[i] = (int*)malloc(sizeof(int)*(count1+1));
		for (i = 0; i < count2+1; i++)		//Initiallize first column values.
			table[i][0] = 0;
		for (i = 0; i < count1+1; i++)		//Initiallize first row values.
			table[0][i] = 1;

		for (i = 1; i < count2+1; i++)		//make up all table's value.
		{
			for (j = 1; j < count1+1; j++)
			{
				if (str1[j-1] == str2[i-1])
					table[i][j] = table[i-1][j-1] + table[i][j-1];
			
				else
					table[i][j] = table[i][j-1];
			}
		}
	}
	return table[count2][count1];		//return result.
}
void printSequence(int* sequence){		// print sequence array reversly.
	int i;
	printf("#####");
	for(i = count2-1; i>=0 ; i--)
		printf("	%d",sequence[i]);
	printf("\n");
}
void findRoad(int i, int j, int index, int sequence[]){		//find possible all routes reculsively.
	int tempJ= j;
	if(count2 == index){		//if sequence array is full, print sequence.
		printSequence(sequence);
		return;
	}
	if(i == 0)		//end of case.
		return;
		
	while(tempJ>=1){		//while loop will end to check all row.
		if(table[i][tempJ] != table[i][tempJ-1]){
			sequence[index] = tempJ;
			findRoad(i-1, tempJ-1,index+1,sequence);
			tempJ--;
		}
		else
			tempJ--;
	}
}
void backTracking(int* sequence){
  findRoad(count2,count1,0,sequence);
}

void main(){
	int i, j;
	int num;
	int result;
	int * sequence;
	char str1[1000], str2[1000];

	printf("Enter the number of case:\n");
	scanf("%d",&num);

	for(i = 0; i < num; i++){
		printf("First String:\n");
		fflush(stdin);
		gets(str1);
		printf("Second String:\n");
		gets(str2);
		result = subseq(str1,str2);
		printf("\n##result##	%d----------\n",result);
		sequence = (int *)malloc(sizeof(int)*count2);
		backTracking(sequence);
		for(j = 0; j < count2+1; j++)
			free(table[j]);
		free(table);
		free(sequence);
	}
	
}
