//This program is a one kind of sorting stack program. It names delicious pancakes.
//Pancakes must sort order. The biggest pancake must go to bottom in stack.
#include <stdio.h>
#define SIZE 30

int stack[SIZE];
int top;
int current;
int push(int key){		//input in the stack.
	if(top != SIZE-1){
		stack[++top] = key;
		return 1;
	}
	else
		return 0;
}
void flip(int n){	//it reverses number 0 to n
	int i;
	int count = 0;
	int temp[SIZE];
	for(i = n; i>=0; i--)
		temp[count++] = stack[i];
	for(i=0;i<=n;i++)
		stack[i] = temp[i];
}

void main(){
	int i,n;
	int temp;
	
	int max;
	top = -1;
	
	printf("Enter the number of input:\n");
	scanf("%d",&n);
	current = n-1;
	for(i = 0;  i < n; i++){
		scanf("%d",&temp);
		push(temp);
	}
	while(current!=0){
		for(i = 0;  i <= current; i++){//finding index of maximum value in stack
			if(i ==0)
				max = i;
			else if(stack[max]<stack[i])
				max = i;
		}
		if(max == current)//case : index of maximum value already locates correct index.
			current--;
		else{
			if(max==0){//case: should do to 1 flips.
				flip(current);
				printf("filp(%d) ",n-current);
			}
			else{ // case: should do to 2 flips.
				flip(max);
				printf("filp(%d) ",n-max);
				flip(current);
				printf("filp(%d) ",n-current);
			}
			current--;
		}
	}
	printf("flip(%d)",current);
	printf("		##########	");
	for(i = 0; i < n; i++){
		printf("%d ", stack[i]);
	}
	printf("\n");
}