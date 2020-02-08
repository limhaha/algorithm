//This program names smart elephant.
//It finds longest sequence that disproves the bigger an elephant is, the smarter it is.
//It uses addition array dinamically, so, it saves result of subproblems. Finally, it calculates result using addtion array.

#include <stdio.h>
#include <stdlib.h>
int iq[1000], weight[1000];
int sequence[1000], dynamic[1000];
int copyWeight[1000],copyIq[1000];
void sort(int n){ // Ascending sort by weight
	int  i ,j;
	int temp;
	for(i = 0; i < n-1; i++){
		for(j =0; j < n-i-1; j++){
			if(copyWeight[j]>copyWeight[j+1]){
				temp = copyWeight[j];
				copyWeight[j] = copyWeight[j+1];
				copyWeight[j+1] = temp;
				temp = copyIq[j];
				copyIq[j] = copyIq[j+1];
				copyIq[j+1] = temp;
			}
		}
	}
}
int findIndex(int fIq,int fWeight,int n){//Find original index.
	int i = 0;
	for(i = 0; i <n; i++){
		if(fIq == iq[i] && fWeight == weight[i])
			return i;
	}
	return -1;
}
void findLong(int n){ // Find longest common sequence
	int count = 0;
	int index;
	int  i,j;
	for(i= 0 ; i < n; i++){
		copyWeight[i] = weight[i];
		copyIq[i] = iq[i]; 
	}
	sort(n); // sort copy array. because program should remember original index.

	for(i = 0; i < n; i++){
		if(i == 0){
			dynamic[i] = 1;
			sequence[i] = -1;
		}
		else{
			count = 1;
			index = -1;
			for( j = 0; j <i; j++){
				if(copyIq[i] <copyIq[j] && dynamic[j]+1 > count && copyWeight[i]!=copyWeight[j]){
					count = dynamic[j]+1;
					index = j;
				}
			}
			dynamic[i] = count;
			sequence[i] =index;
		}
	}
	printf("#######################\n");
	printf("	*Dynamic array\n");
	for(i = 0; i < n; i++){
		printf("%d ",dynamic[i]);
	}
	printf("\n");
	printf("	*Sequence index array\n");
	for(i = 0; i < n; i++){
		printf("%d ",sequence[i]);
	}
	printf("\n#######################\n");
}
void backTracking(int n){		//It tracks at end. finds maximum value and back tracking.
	int i;
	int max=0;
	int count;
	int temp;
	int *sol;
	for(i =1; i < n; i++){
		if(dynamic[max]<dynamic[i])
			max = i;
	}
	sol = (int *)malloc(sizeof(int)*dynamic[max]);
	printf("===========Result : %d\n",dynamic[max]);
	temp = max;
	count = dynamic[max]-1;
	while(count>=0){
		sol[count--] = findIndex(copyIq[temp],copyWeight[temp],n);
		temp = sequence[temp];
	}
	for(i = 0; i < dynamic[max]; i++){
		printf("%d\n",sol[i]+1);
	}

	free(sol);
}
void main(){
	int n;
	int i;

	printf("Enter the number of elphants : \n");
	scanf("%d",&n);

	for(i = 0; i < n; i++)
		scanf("%d %d",&weight[i],&iq[i]);
	findLong(n);
	backTracking(n);
}