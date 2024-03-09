#include <stdio.h>

#define N 10

void floodFill(int matrix[N][N], int x, int y, int sourceColor, int newColor);
void printMatrix(int matrix[N][N]);

int main(){
	int matrix[N][N] = {
		{7,7,7,7,7,7,7,5,5,5},
		{7,7,7,7,7,7,7,5,5,5},
		{7,7,7,8,8,8,7,8,5,5},
		{7,7,8,8,8,8,7,8,8,8},
		{7,8,8,8,7,7,7,8,8,8},
		{7,8,8,8,8,8,8,8,4,4},
		{7,7,7,7,6,6,4,4,4,4},
		{7,7,6,6,6,6,6,4,4,4},
		{7,7,6,6,6,6,6,4,4,4},
		{7,7,7,6,4,4,4,4,4,4}
	};
	
	printMatrix(matrix);
	int x = 3;
	int y = 7;
	floodFill(matrix, x, y, matrix[x][y], 0);
	printMatrix(matrix);
	
	
	return 0;
}

void floodFill(int matrix[N][N], int x, int y, int sourceColor, int newColor){
	if(x<0 || x>=N || y<0 || y>=N || matrix[x][y]!=sourceColor){
		return;
	}
	matrix[x][y] = newColor;
	floodFill(matrix, x+1, y, sourceColor, newColor);
	floodFill(matrix, x-1, y, sourceColor, newColor);
	floodFill(matrix, x, y+1, sourceColor, newColor);
	floodFill(matrix, x, y-1, sourceColor, newColor);
}

void printMatrix(int matrix[N][N]){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
