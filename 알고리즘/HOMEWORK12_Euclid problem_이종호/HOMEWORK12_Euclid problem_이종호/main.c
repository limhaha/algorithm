/**
This program names Euclid problem.
It calcultates ax+by = d, d is gcd a and b.
*/
#include <stdio.h>
int x,y;
int gcd(int a,int b){		//It returns gcd a and b
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

void euclid(int a, int b){ //It calculates x and y.
	int i = 0;
	int temp;
	if(b==0){
		x =1;
		y = 0;
		return;
	}
	else{
		euclid(b,a%b);
		temp = y;
		y = x - (a/b)*y;
		x =temp;
	}
}

void main(){
	int a,b;
	int d;
	printf("Enter the two number : \n");
	scanf("%d %d",&a,&b);
	if(a > b)
		d = gcd(a,b);
	else
		d = gcd(b,a);
	euclid(a,b);
	printf("%d %d %d\n",x,y,d);

}