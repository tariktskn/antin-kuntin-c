#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a<b ? b : a;
}

void printMatrix(int** matrix, int n, int m){
	int i, j;

	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int** initialize(int n, int w){
	int** dp = (int**) calloc(n, sizeof(int*));
	int i, j;
	for(i=0; i<n; i++){
		dp[i] = (int*) calloc(w, sizeof(int));
	}
	return dp;
}

int knapsack(int* values, int* weights, int n, int w){
	int** dp = initialize(++n, ++w);
	int ans = -1, i, j;
	
	for(i=1; i<n; i++){
		for(j=1; j<w; j++){
			if(weights[i-1] <= j){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
			}else{
				dp[i][j] = dp[i-1][j];
			}			
		}
	}
	
	printMatrix(dp, n, w);
	
	ans = dp[n-1][w-1];
	free(dp); 
	return ans;
}

int main(){
	int values[4] = {12,10,20,15};
	int weights[4] = {2,1,3,2};
	
	printf("Answer: %d", knapsack(values, weights, 4, 5));
	return 0;
}

