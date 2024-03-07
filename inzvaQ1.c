#include <stdio.h>
int main() {
	int n,m,i,j,pairs=0,num;
	scanf("%d %d",&n,&m);
	int dizi[n];
	scanf("%d",&dizi[0]);
	for(i=1;i<n;i++){
		scanf("%d",&dizi[i]);
		num = 1;
		for(j=i-1;j>=0;j--){
			if((num++ * m) + dizi[j] == dizi[i]){
				pairs++;
			}
		}
	}
	printf("%d",pairs);
	return 0;
}

/*

int main() {
	int n,m,i,j,pairs=0,num;
	scanf("%d %d",&n,&m);
	int dizi[n];
	for(i=0;i<n;i++){
		scanf("%d",&dizi[i]);
	}
	
	for(i=0;i<n-1;i++){
		num = 1;
		for(j=i+1;j<n;j++){
			if((num * m) + dizi[i] == dizi[j]){
				pairs++;
			}
			num++;
		}
	}
	printf("%d",pairs);
	
	return 0;
}
*/

/* 
int main() {
	int n,m;
	int i,j;
	int pairs=0;
	scanf("%d %d",&n,&m);
	int dizi[n];
	for(i=0;i<n;i++){
		scanf("%d",&dizi[i]);
	}
	
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(((dizi[j] - dizi[i]) / (j - i)) == m){
				pairs++;
			}
		}
	}
	printf("%d",pairs);
	
	return 0;
}
*/
