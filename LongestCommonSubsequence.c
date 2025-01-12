#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
	return a<b ? b : a;
}

int** initialize(int n, int m){
	int** dp = (int**) calloc(n, sizeof(int*));
	int i, j;
	for(i=0; i<n; i++){
		dp[i] = (int*) calloc(m, sizeof(int));
	}
	return dp;
}

int LCS(char* str1, char* str2){
	int len1 = strlen(str1), len2 = strlen(str2);
	int** dp = initialize(++len1, ++len2);
	int ans = -1, i, j;
	
	for(i=1; i<len1; i++){
		for(j=1; j<len2; j++){
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}		
		}
	}
	ans = dp[len1-1][len2-1];
	
	char* lcs = (char*) malloc((ans+1)*sizeof(char));
	int index = ans;
	i = len1;
	j = len2;
	while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            lcs[index--] = str1[i-1];
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    printf("%s\n", lcs);
	
	free(dp);
	return ans;
}

int main(){
	char* str1 = "BACDB";
	char* str2 = "BDCB";
	
	printf("Answer: %d", LCS(str1, str2));
	return 0;
}

