#include <stdio.h>

int main(){
	int N,i,j=3,result=0;
	scanf("%d",&N);
	int dizi[N];
	
	int times = ((N-1)*(N-2)*(N-3)) / 6;
	
	for(i=0;i<N;i++){
		scanf("%d",&dizi[i]);
		result += dizi[i];
	}
	
	result = result * times;
	printf("%d",result);
	
	
	return 0;
}
