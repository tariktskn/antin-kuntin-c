#include <stdio.h>

#define N 9

void printChart(int chart[][N]);

int main(){
	int chart[][N] = {{5,3,0,0,7,0,0,0,0},
					  {6,0,0,1,9,5,0,0,0},
					  {0,9,8,0,0,0,0,6,0},
					  {8,0,0,0,6,0,0,0,3},
					  {4,0,0,8,0,3,0,0,1},
					  {7,0,0,0,2,0,0,0,6},
					  {0,6,0,0,0,0,2,8,0},
					  {0,0,0,4,1,9,0,0,5},
					  {0,0,0,0,8,0,0,7,9},
	};
	printChart(chart);
	return 0;
}

void printChart(int chart[][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ", chart[i][j]);
		}
		printf("\n");
	}
}
