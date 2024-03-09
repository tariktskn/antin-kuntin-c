#include <stdio.h>

#define N 9

void printChart(int chart[][N]);
int solve(int chart[][N]);
int findEmptyLocation(int chart[][N], int *x, int *y);
int checkLocation(int chart[][N], int x, int y, int num);
void testCheckLocation(int chart[][N], int x, int y, int num); // for bugfixing

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
	solve(chart);
	printChart(chart);
	
//	testCheckLocation(chart, 8, 7, 7);
	return 0;
}

int solve(int chart[][N]){
	int x,y,num;
	if(!findEmptyLocation(chart, &x, &y)){
		return 1;
	}
	
	for(num=1;num<10;num++){
		if(checkLocation(chart, x, y, num)){
			chart[x][y] = num;
			if(solve(chart)){
				return 1;
			}
			chart[x][y] = 0;
		}
	}
	return 0;
}

int findEmptyLocation(int chart[][N], int *x, int *y){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(chart[i][j] == 0){
				*x = i;
				*y = j;
				return 1;
			}
		}
	}
	return 0;
}

int checkLocation(int chart[][N], int x, int y, int num){
	int i = 0;
	while(i<N && chart[i][y]!=num && chart[x][i]!=num){
		i++;
	}
	if(i==N){
		int j, xArea = x/3 * 3, yArea = y/3 * 3;
		for(i=xArea; i<xArea+3; i++){
			for(j=yArea; j<yArea+3; j++){
				if(chart[i][j] == num){
					return 0;
				}
			}
		}
		return 1;
	}
	return 0;
}

void printChart(int chart[][N]){
	int i,j;
	for(i=0;i<N;i++){
		if(i%3 == 0){
			for(j=0;j<N+4;j++){
				printf("- ");
			}
			printf("\n");
		}
		for(j=0;j<N;j++){
			if(j%3 == 0){
				printf("| ");
			}
			printf("%d ", chart[i][j]);
			
		}
		
		printf("|\n");
	}
	for(j=0;j<N+4;j++){
		printf("- ");
	}
	printf("\n\n");
}

void testCheckLocation(int chart[][N], int x, int y, int num){
	int i,j, xArea = x/3, yArea = y/3;
	printf("xArea: %d, yArea: %d\n",xArea, yArea);
	for(i=xArea*3; i<xArea*3+3; i++){
		printf("hi\n");
		for(j=yArea*3; j<yArea*3+3; j++){
			printf("--%d ", chart[i][j]);
			if(chart[i][j] == num){
				return;
			}
		}
	}
}
