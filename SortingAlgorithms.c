#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* setArray(int N);
void printArray(int* array, int N);
void shuffle(int* array, int N);
void primalShuffle(int array[], int N);
void swap(int* x, int* y);
void freeArray(int *array);
void bubbleSort(int *array, int N);
void selectionSort(int *array, int N);
void insertionSort(int* array, int N);
void mergeSort(int *array, int N);
void merge(int *leftArray, int *rightArray, int *array, int N);
void doMergeSort(int *array, int N);
void heapify(int* array, int N, int i);
void heapSort(int* array, int N);
// quick 

int main(){
	int N = 10;
	int* array = setArray(N);
	
	srand(time(NULL));
	
	bubbleSort(array, N);
	selectionSort(array, N);
	insertionSort(array, N);
	doMergeSort(array, N);
	heapSort(array, N);
	
	freeArray(array);
	return 0;
}

void heapify(int* array, int N, int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if(left<N && array[left] > array[largest]){
		largest = left;
	}
	
	if(right<N && array[right] > array[largest]){
		largest = right;
	}
	
	if(largest != i){
		swap(&array[largest], &array[i]);
		heapify(array, N, largest);
	}
}

void heapSort(int* array, int N){
	shuffle(array, N);
	printf("before: ");
	printArray(array, N);
	
	int i = N/2 - 1;
	
	for(i;i>=0;i--){
		heapify(array, N, i);
	}
	
	
	for(i=N-1;i>0;i--){
		swap(&array[i], &array[0]);
		heapify(array, i, 0);
	}
	
	printf(" after: ");
	printArray(array, N);
}

void doMergeSort(int *array, int N){
	shuffle(array, N);
	printf("before: ");
	printArray(array, N);
	
	mergeSort(array, N);
	
	printf(" after: ");
	printArray(array, N);
}

void mergeSort(int *array, int N){
	if(N <= 1){
		return;
	}
	
	int middle = N/2;
	int leftArray[middle];
	int rightArray[N - middle];
	
	int i,j=0;
	for(i=0;i<N;i++){
		if(i<middle){
			leftArray[i] = array[i];
		}else{
			rightArray[j++] = array[i];
		}
	}
	mergeSort(leftArray, middle);
	mergeSort(rightArray, N - middle);
	merge(leftArray, rightArray, array, N);
}

void merge(int *leftArray, int *rightArray, int *array, int N){
	int middle = N/2;
	int i=0,l=0,r=0;
	while(l < middle && r < N - middle){
		if(leftArray[l] < rightArray[r]){
			array[i++] = leftArray[l++];
		}else{
			array[i++] = rightArray[r++];
		}
	}
	
	while(l < middle){
		array[i++] = leftArray[l++];
	}
	
	while(r < N - middle){
		array[i++] = rightArray[r++];
	}
}

void insertionSort(int* array, int N){
	shuffle(array, N);
	printf("before: ");
	printArray(array, N);
	
	int i,j;
	for(i=1;i<N;i++){
		j = i;
		while(j>0 && array[j]<array[j-1]){
			swap(&array[j], &array[j-1]);
			j--;
		}
	}
	
	printf(" after: ");
	printArray(array, N);
}
	

void selectionSort(int *array, int N){ //ascending
	shuffle(array, N);
	printf("before: ");
	printArray(array, N);
	
	int i,j;
	int min;
	for(i=0;i<N-1;i++){
		min = i;
		for(j=i+1;j<N;j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		if(min != i){
			swap(&array[i], &array[min]);
		}
	}
	
	printf(" after: ");
	printArray(array, N);
}

void bubbleSort(int *array, int N){
	shuffle(array, N);
	printf("before: ");
	printArray(array, N);
	
	int i,j;
	
	for(i=0;i<N-1;i++){
		for(j=0;j<N-i-1;j++){
			if(array[j] > array[j+1]){
				swap(&array[j], &array[j+1]);
			}
		}
	}
	
	printf(" after: ");
	printArray(array, N);
}

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int* setArray(int N){
	int *array = (int*) malloc(N*sizeof(int));
	int i;
	for(i=0;i<N;i++){
		array[i] = i;
	}
	return array;
}

void printArray(int* array, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
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

void primalShuffle(int array[], int N){
	srand(time(NULL));
	int rand1, rand2, temp, i;
	
	for(i=0;i<2*N;i++){
		rand1 = rand()%N;
		rand2 = rand()%N;
		temp = array[rand1];
		array[rand1] = array[rand2];
		array[rand2] = temp;
	}
}

void freeArray(int *array){
	free(array);
}
