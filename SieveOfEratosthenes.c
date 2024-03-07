#include <stdio.h>
#include <math.h>

int main(){
	int i,j;
	
	int N;
	printf("N: ");
	scanf("%d",&N);
	
	int dizi[N];
	for(i=0;i<N;i+=2){
		dizi[i] = 0;
	}
	
	for(i=1;i<N;i+=2){
		dizi[i] = 1;
	}
	
	int NN = sqrt(N);
	for(i=3;i<NN;i+=2){
		if(dizi[i]){
			for(j=i*i;j<N;j+=2*i){
				dizi[j] = 0;
			}
		}
	}
	
	for(i=3;i<N;i+=2){
		if(dizi[i]){
			printf("%d\n",i);
		}
	}
	
	return 0;
}
