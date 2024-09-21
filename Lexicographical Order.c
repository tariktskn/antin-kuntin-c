#include <stdio.h>
#include <stdlib.h>

int* lexicalOrder(int n) {
    int* ans = (int*) malloc(n*sizeof(int));

    int i, current = 1;
    for(i=0; i<n; i++){
        ans[i] = current;
        if(current*10 <= n)
            current *= 10;
        else{
            while(current%10==9 || current >= n)
                current /= 10;
            current++;
        }
    }

    return ans;
}

void printArray(int* array, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", array[i]);
	}
}

int main(){
	int n = 111;
	int* array = lexicalOrder(n);
	printArray(array, n);
	
	free(array);
	return 0;
}

