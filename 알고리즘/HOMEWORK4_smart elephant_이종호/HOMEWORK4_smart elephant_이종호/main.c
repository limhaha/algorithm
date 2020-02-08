//This program names smart elephant.
//It finds longest sequence that disproves the bigger an elephant is, the smarter it is.

#include <stdio.h>
int iq[1000], weight[1000];
void sort(int weight[], int iq[],int n){ // Descending sort by iq.
	int  i ,j;
	int temp;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(iq[j]<iq[j+1]){
				temp = iq[j];
				iq[j] = iq[j+1];
				iq[j+1] = temp;
				temp = weight[j];
				weight[j] = weight[j+1];
				weight[j+1] = temp;
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
	int tempCount = 0;
	int temp[1000];
	int temp2[1000];
	int copyWeight[1000],copyIq[1000];
	int  i = 0,j,k;
	int max = 0, maxIndex = 0;
	for(i= 0 ; i < n; i++){
		copyWeight[i] = weight[i];
		copyIq[i] = iq[i]; 
	}
	sort(copyWeight,copyIq,n); // sort copy array. because program should remember original index.
	for(i = 0; i < n; i++){
		temp[count++] = findIndex(copyIq[i],copyWeight[i],n);
		tempCount = 0;
		for( j = i; j < n; j++){
			if((copyIq[j]<iq[temp[count-1]])&&(copyWeight[j] >weight[temp[count-1]]))
				temp2[tempCount++] = j;
		}
		printf("#############%d\n",tempCount);
		if(tempCount ==1){
			for( j = i; j < n; j++){
				if((copyIq[j]<iq[temp[count-1]])&&(copyWeight[j] >weight[temp[count-1]]))
					temp[count++] = findIndex(copyIq[j],copyWeight[j],n);
			}
			if(max<count){
					max = count;
					maxIndex = i;
				}
			count = 0;
		}
		else{
			for(k = 0; k < tempCount; k++){
				temp[count++] = findIndex(copyIq[temp2[k]],copyWeight[temp2[k]],n);
				for( j = temp2[k]; j < n; j++){
					if((copyIq[j]<iq[temp[count-1]])&&(copyWeight[j] >weight[temp[count-1]]))
						temp[count++] = findIndex(copyIq[j],copyWeight[j],n);
				}
				if(max<count){
					max = count;
					maxIndex = i;
				}
				count = 1;
			}
		}
		
	}

	//Finally, long common sequence insert in array.
	count = 0;
	temp[count++] = findIndex(copyIq[maxIndex],copyWeight[maxIndex],n);
	for( i = maxIndex; i < n; i++){
		if((copyIq[i]<iq[temp[count-1]])&&(copyWeight[i] >weight[temp[count-1]]))
			temp[count++] = findIndex(copyIq[i],copyWeight[i],n);
	}

	printf("-------%d\n",count);
	for(i = 0; i < count; i++){
		printf("%d\n",temp[i]+1);
	}
}
void main(){
	int n;
	int i;

	printf("Enter the number of elphants : \n");
	scanf("%d",&n);

	for(i = 0; i < n; i++)
		scanf("%d %d",&weight[i],&iq[i]);
	findLong(n);
}