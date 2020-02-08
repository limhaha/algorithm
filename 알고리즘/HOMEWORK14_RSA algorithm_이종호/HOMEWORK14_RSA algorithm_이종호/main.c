/*
This program names RSA algorithm.
It uses several algorithms that Euclid Algorithm, RSA algorithm and Squaring algorirhm.
So, It encrypts message, and It decrypts again cipher message.
*/
#include <stdio.h>

int findSecretKey(int e, int n){	//It finds secret key.
	int x = 1;
	while(1){
		if((e*x)%n==1)
			return x;
		else
			x++;
	}
	return -1;
}
int mod(int a,int b,int mod){ //It uses Squaring algorithm, So it returns a pow b mod n.
	int bits[100];
	int num = 0;
	int c = 0;
	int d = 1;
	int k;

	for(num = 0; b > 0; num++){
		bits[num] = b%2;
		b = b/2;
	}
	for(k = num-1; k >= 0; k--){
		c = 2*c;
		d = (d*d)%mod;
		if(bits[k] == 1){
			c = c+1;
			d = (d*a) % mod;
		}
	}
	return d;
}

int encrypt(int e, int publicKey,long double input){ //It returns result of ecryption using RSA algorithm.
	int result;
	result = mod(input,e,publicKey);
	return result;
}

int decrypt(int secretKey, int publicKey,long double cipher){ //It returns result of decryption using RSA algorithm.
	long double result;
	result = mod(cipher,secretKey,publicKey);
	return result;
}
void main(){
	int p,q;
	int n;
	long double input;
	long double cipher, origin;
	int e=3;
	int publicKey,secretKey;
	printf("Enter the two prime number : "); //Receive P and Q
	scanf("%d %d",&p,&q);
	printf("Enter the message : "); //Receive message.
	scanf("%lf",&input);
	publicKey = p*q;
	n = (p-1)*(q-1);
	while(1){ //Find e
		if(n%e ==0)
			e+=2;
		else
			break;
	}
	secretKey = findSecretKey(e,n);
	cipher = encrypt(e,publicKey,input);
	printf("	#P (e,n) = (%d, %d)\n",e,publicKey);
	printf("	#S (d,n) = (%d, %d)\n",secretKey,publicKey);
	printf("cipher : %.0lf\n",cipher);
	origin = decrypt(secretKey,publicKey,cipher);
	printf("origin : %.0lf\n",origin);
}