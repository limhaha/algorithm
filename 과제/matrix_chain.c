#include <stdio.h>

int matrix[5][5] = { 0 };

int mat[6] = { 4, 3, 2, 10, 6, 5 };
int memo[4][4] = { 0 };
void print_(int, int);
int main() {

	
	int i, j, k=1, p = 0;


	for (i = 0; i < 4; ++i){
		for (j = i; j < 4; ++j){
			matrix[j - i][j + 1] = cal(j-i, j+1);
		}
	}

	for (i = 0; i < 4; ++i){
		for (j = 0; j < 4; ++j){
			printf(" %d ", memo[i][j]);
		}printf("\n");
	}
	
	print_(0,4);
	return 0;
}

int cal(int a, int b) {
	int i, j,k;
	int min;

	for (i = a; i < b; ++i){
		if (i == a){
			min = matrix[a][i] + matrix[i + 1][b] + mat[a] * mat[i + 1] * mat[b + 1];
			memo[a][b-1] = i+1;
		}
		else if (min > matrix[a][i] + matrix[i + 1][b] + mat[a] * mat[i+1] * mat[b + 1]){
	
			min = matrix[a][i] + matrix[i + 1][b] + mat[a] * mat[i+1] * mat[b + 1];
			memo[a][b-1] = i+1;
		}
	}	
	return min;
}

void print_(int i, int j) {
	if (i == j)
		printf("A%d", i+1);
	else{
		printf("(");
		print_(i,memo[i][j-1]-1);
		print_(memo[i][j-1], j);
		printf(")");
	}
}