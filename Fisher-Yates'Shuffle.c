#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int array[], int N);
void printArray(int* array, int N);
int* setArray(int N);
void freeArray(int *array);

int main(){
	int N = 10, i;
	int* array = setArray(N);
	
	printf("Original Array: ");
	printArray(array, N);
	for(i=0;i<10;i++){
		shuffle(array, N);
		printArray(array, N);
		sleep(1); // if it doesn't sleep, after N times it becomes first state
	}
	
	freeArray(array);
	return 0;
}

void shuffle(int array[], int N){
	srand(time(NULL));
	int index, temp;
		
	int i;
	for(i=N-1;i>0;i--){
		index = rand()%i;
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
}

void freeArray(int *array){
	free(array);
}

void printArray(int* array, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

int* setArray(int N){
	int *array = (int*) malloc(N*sizeof(int));
	int i;
	for(i=0;i<N;i++){
		array[i] = i;
	}
	return array;
}

