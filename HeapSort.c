#include <stdio.h>

void swap(int* x, int* y);
void heapify(int* array, int N, int i);
void printArray(int* array, int N);
void printTree(int* array, int N);
void heapSort(int* array, int N);

int main(){
	int array[] = {5,1,3,7,9,4,6,2,8};
	int N = sizeof(array) / sizeof(int);
	int i;
	printTree(array, N);
	heapSort(array, N);
	printTree(array, N);
	return 0;
}

void printTree(int* array, int N){
	int i = 0;
	int log = N;
	int space = 1;
	int preSpace = 0;
	int j,k;
	int count = 1;
	
	while(log > 1){
		space = space*2;
		log = log/2;
	}
	space--;
	
	while(i<N){
		for(j=0;j<space;j++){
			printf(" ");
		}
		j=0;
		while(j<count && i<N){
			printf("%d", array[i]);
			i++;
			for(k=0;k<preSpace;k++){
				printf(" ");
			}
			j++;
		}
		printf("\n");
		preSpace = space;
		space = space / 2;
		count = count * 2;
	}
}

void printArray(int* array, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
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
	int i = N/2 - 1;
	
	for(i;i>=0;i--){
		heapify(array, N, i);
	}
	
	printTree(array, N);
	
	for(i=N-1;i>0;i--){
		swap(&array[i], &array[0]);
		heapify(array, i, 0);
	}
}
