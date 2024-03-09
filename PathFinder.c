#include <stdio.h>

#define N 6

void findPath(int matrix[N][N], int x, int y, int path[2][N*N], int order, int *count);

int main(){
	int path[2][N*N];
	int matrix[N][N] = {
		{1,1,1,0,0,0},
		{1,0,1,0,1,1},
		{0,1,1,1,1,1},
		{0,0,1,0,1,0},
		{0,1,1,0,1,1},
		{0,0,1,1,1,1}
	};
	int count = 0;
	findPath(matrix, 0, 0, path, 0, &count);
	printf("\nTotal paths: %d", count);
	
	return 0;
}

void findPath(int matrix[N][N], int x, int y, int path[2][N*N], int order, int *count){
	if(x == N-1 && y == N-1){
		path[0][order] = x;
		path[1][order++] = y;
		(*count)++;
		int i;
		for(i=0;i<order;i++){
			printf("(%d, %d) ",path[0][i], path[1][i]);
		}
		printf("\n");
		return;
	}
	if(x<0 || y<0 || x>=N || y>=N || !matrix[x][y]){
		return;
	}
	matrix[x][y] = 0;
	path[0][order] = x;
	path[1][order++] = y;	
	findPath(matrix, x+1, y, path, order, count);
	findPath(matrix, x, y+1, path, order, count);
	findPath(matrix, x-1, y, path, order, count);
	findPath(matrix, x, y-1, path, order, count);
	matrix[x][y] = 1;
}

