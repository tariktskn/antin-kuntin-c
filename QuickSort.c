#include <stdio.h>

void printArray(int* array, int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* array, int left, int right){
	int pivot = array[right];
	int i = left - 1, j;

	for(j=left; j<right; j++){
		if(array[j] < pivot){
			i++;
			swap(&array[i], &array[j]);
		}
	}
	i++;
	swap(&array[i], &array[right]);
	
	return i;
}

void quickSort(int* array, int left, int right){
	if(right <= left)
		return;
	
	int pivot = partition(array, left, right);

	quickSort(array, left, pivot-1); //pivot already in correct place
	quickSort(array, pivot+1, right);
}

int main(){
	int array[] = {123,532,4,345,345,2,34,234,346,3,25,32};
	int size = sizeof(array)/sizeof(int);

	quickSort(array, 0, size-1);
	printArray(array, size);
	
	return 0;
}

