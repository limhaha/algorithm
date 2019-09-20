#include <stdio.h>
#include <stdlib.h>

void findLCS(int n);

void sort(int weight[], int iq[], int n);

struct ELEPHANT{
    int weight;
    int iq;
};

struct ELEPHANT e[1000];


int main(){
    int s_weight, s_IQ;
    int i = 0;
    FILE *fp;
    fp = fopen("input2.txt", "r");

    if(fp == NULL){
        printf("FILE is not found.");
        exit(1);
    }    
    while(fscanf(fp, "%d %d\n", &s_weight, &s_IQ) != EOF){
        
        e[i].weight = s_weight;
        e[i].iq = s_IQ;
        i ++;
    }

    findLCS(i+1);

    return 0;
}



//sorting descending order witg weight value
void sort(int weight[], int iq[], int n){
    int temp;
    int i, j;
    
    for(i =0; i < n-1; i ++){
        for(j=0; j < n-1; j++){
            if(weight[j] < weight[j+1]){
                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;

                temp = iq[j];
                iq[j] = iq[j+1];
                iq[j+1] = temp;
            }
        }
    }
}



int findIndex(int Weight, int iq, int n){
    int i = 0;
    for(i =0; i<n; i++){
        if(Weight == e[i].weight && iq == e[i].iq ){
        return i;
        }   
    }
    return -1;
}



void findLCS(int n){
    int count = 0;
    int temp[1000];
    int t_weight[1000], t_iq[1000];
    int i = 0;
    int j;

    int max = 0, maxIndex = 0;

    for(i=0; i<n; i++){
        t_weight[i] = e[i].weight;
        t_iq[i] = e[i].iq;
    }

    sort(t_weight, t_iq, n);

    for(i=0; i<n; i++){
        temp[count++] = findIndex(t_weight[i], t_iq[i], n);
        for(j=i; j<n; j++){
            if( (t_weight[j] < e[temp[count-1]].weight) && (t_iq[j] > e[temp[count-1]].iq)){
                
                temp[count++] = findIndex(t_iq[j], t_weight[j], n);
            }
            }
            if(max < count){
                max = count;
                maxIndex = i;
                }
                count = 0;
            }   

temp[count++] = findIndex(t_weight[maxIndex], t_iq[maxIndex], n);
for(i=maxIndex; i<n; i++){
    if( (t_weight[i] < e[temp[count-1]].weight) &&  (t_iq[i] > e[temp[count-1]].iq)){
        temp[count++] = findIndex(t_weight[i], t_iq[i], n);
        }
        }

        printf("Length : %d \n",count);

	    for(i = count-1; i >= 0; i--){
		printf("%d\n",temp[i]+1);
        }
    }