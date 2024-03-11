#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int array[], int N);
int compare(int *array, int* originalArray, int N);
void printArray(int* array, int N);
int* setArray(int N);
void freeArray(int *array);

int main(){
	int N = 10, i;
	int* array = setArray(N);
	int* originalArray = setArray(N);
	
	srand(time(NULL));
	
	printf("Original Array: ");
	printArray(originalArray, N);
	
//	for(i=0;i<10;i++){
//		shuffle(array, N);
//		printArray(array, N);
////		sleep(1); // if it doesn't sleep, after N times it becomes first state -> #FIX# because of srand() in shuffle function not in main function
//	}

	int count = 0;	
	do{
		count++;
		shuffle(array, N);
//		printf("Shuffled Array: ");
//		printArray(array, N);
	}while(!compare(array, originalArray, N));
	printf("Shuffled array equals original array after %d shuffles.", count);
	
	freeArray(originalArray);
	freeArray(array);
	return 0;
}

void shuffle(int array[], int N){
	int index, temp;
		
	int i;
	for(i=N-1;i>0;i--){
		index = rand()%i;
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
}

int compare(int *array, int* originalArray, int N){
	int i=0;
	while(i<N && array[i] == originalArray[i]){
		i++;
	}
	
	if(i==N){
		return 1;
	}else{
		return 0;
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

