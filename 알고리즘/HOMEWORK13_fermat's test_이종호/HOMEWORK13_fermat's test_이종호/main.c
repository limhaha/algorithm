/* 
This program names fermat's test.
It uses Miller Rabin Algorithm.
It prints if or not the number is carmichael number.
*/

#include <stdio.h>
#include <math.h>

int isItPrime( int num )		//return is it Prime number
{
	int i;
	int temp = sqrt((double)num);
	for ( i = 3; i <= temp; i += 2 )
		if ( !(num % i) )
			return 0;
	return 1;
}

int mod(int a, int b, int n){  //It returns case moduler result.
	int temp;
	if(b==0) // end of case
		return 1;
	if(b==1)
		return a;
	
	if(b%2) // case : it is even number
		return (mod(a,b-1,n)*a)%n;
	else{ // case : it is odd number
		temp = mod(a,b/2,n);
		return (temp*temp)%n;
	}
}

int isItFermat(int a,int num){ //It uses Miller Rabin Algorithm. 
	int cnt;
	int tempCnt;
	int mod;
	int tempMod;
	int temp;
	int i;
	tempCnt = 0;
	tempMod = 1;
	temp = num;
	while ( tempCnt < num-1 )
	{
		temp = num - tempCnt;
		cnt = 2;
		mod = (a * a) % num;
		while ( cnt * 2 <= temp )
		{
			cnt *= 2;
			mod = (mod * mod) % num;
		}

		tempCnt += cnt;
		tempMod = (tempMod * mod) % num;
	}
	if ( tempCnt != num )
		for ( i = tempCnt+1; i <= num; ++i )
			tempMod = (tempMod * a) % num;
	if ( tempMod == a )
		return 1;

	return 0;
}

int isItCarmichael(int num){ // test 2 to num - 1
	int i,k;
	for(k = 2; k < num; k++){
		if(!isItFermat(k,num))
			return 0;
	}
	return 1;
}

void main(){
	int num;
	int result;
	while(1){
		scanf("%d",&num);
		if(num==0)
			break;
		if(isItPrime(num) || num%2==0)
			result = 0;
		else
			result = isItCarmichael(num);
		if(result)
			printf("It is a Carmicahel number.\n");
		else
			printf("It is normal.\n");
	}
}
