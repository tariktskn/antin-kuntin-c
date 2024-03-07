#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int* setArray(int N);
void printArray(int *array, int N);
void freeArray(int *array);
void linearSearch(int *array, int N, int x);
void binarySearch(int *array, int N, int x);
void jumpSearch(int *array, int N, int x);
void interpolationSearch(int *array, int N, int x);

int main(){
	int N = 16;
	int x = 8;
	int *array = setArray(N);
	//printArray(array, N);
	linearSearch(array, N, x);
	binarySearch(array, N, x);
	jumpSearch(array, N, x);
	interpolationSearch(array, N, x);
	
	
	/*/
	printf("\n*********");
	int i;
	for(i=1;i<N+10;i++){
		linearSearch(array, N, i);
	}
	/*/
	
	freeArray(array);
	return 0;
}

void interpolationSearch(int *array, int N, int x){
	int high = N-1;
	int low = 0;
	int pos;
	
	while(low <= high && x >= array[low] && x <= array[high]){
		pos = low + (((double)(high - low) / (array[high] - array[low])) * (x - array[low]));
		
		if(x == array[pos]){
			low = high + 1;
		}else if(x > array[pos]){
			low = pos + 1;
		}else{
			high = pos - 1;
		}
	}
	
	if(x == array[pos]){
		printf("\n%d found at index %d",x,pos);
	}else{
		printf("\n%d not found",x);
	}
}

void jumpSearch(int *array, int N, int x){
	int stepSize = sqrt(N);
	int step = stepSize, prev = 0;
	int upperBound;
	
	while(step<N && array[step] <= x){
		prev = step;
		step += stepSize;
	}
	
	upperBound = (step<N) ? step : N;
	while(prev<upperBound && array[prev++] != x);
	if(array[prev-1] == x){
		printf("\n%d found at index %d",x,prev-1);
	}else{
		printf("\n%d not found",x);
	}
}

void binarySearch(int *array, int N, int x){
	int first = 0;
	int last = N-1;
	int mid = last/2;
	
	while(first<=last && array[mid] != x){
		if(array[mid] < x){
			first = mid + 1;
		}else{
			last = mid - 1;
		}
		mid = (last + first) / 2;
	}
	
	if(array[mid] == x){
		printf("\n%d found at index %d",x,mid);
	}else{
		printf("\n%d not found",x);
	}
}

void linearSearch(int *array, int N, int x){
	int i = 0;
	while(i<N && array[i++] != x);
	if(x != array[i-1]){
		printf("\n%d not found",x);
	}else{
		printf("\n%d found at index %d",x,i-1);
	}
}

int* setArray(int N){
	int *array = (int*) malloc(N*sizeof(int));
	int i;
	for(i=0;i<N;i++){
		array[i] = i+1;
	}
	return array;
}

void printArray(int *array, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",array[i]);
	}
}

void freeArray(int *array){
	free(array);
}
