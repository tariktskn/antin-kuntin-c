#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int N,i,j;
	int action,num=0;
	char bookName[12];
	scanf("%d",&N);
	char books[N][12];
	for(i=0;i<N;i++){
		scanf("%d %s",&action,bookName);
		if(action == 1){
			j=0;
			while(j<num && strcmp(books[j], bookName)){
				j++;
			}
			if(j==num){
				printf("NO\n");
			}else{
				printf("YES\n");
				strcpy(books[j], "");
			}
		}else{
			strcpy(books[num++], bookName);
		}
	}
	return 0;
}


/*
int main(){
	int N,i,j;
	int action,num=0;
	char bookName[11];
	
	scanf("%d",&N);
	
	char books[N][11];
	
	for(i=0;i<N;i++){
		scanf("%d %s",&action,bookName);
		if(action == 1){
			j=0;
			while(j<num && strcmp(books[j], bookName)){
				j++;
			}
			if(j==num){
				printf("NO\n");
			}else{
				printf("YES\n");
				strcpy(books[j], "");
			}
		}else if(action == 2){
			strcpy(books[num++], bookName);
		}
	}
	
	return 0;
}
*/

/*
int main(){
	int N,i,j;
	int action, num=0;
	char bookName[11];
	
	scanf("%d",&N);
	
	char **books = (char**) malloc(1*sizeof(char*));
	
	for(i=0;i<N;i++){
		scanf("%d %s",&action,bookName);
		if(action == 1){
			j=0;
			while(j<num && strcmp(books[j], bookName) != 0){
				j++;
			}
			if(j==num){
				printf("NO\n");
			}else{
				printf("YES\n");
				free(books[j]);
			}
		}else{
			books = realloc(books, (num+2)*sizeof(char*));
			books[num] = (char*) malloc(strlen(bookName)*sizeof(char));
			strcpy(books[num++], bookName);
		}
	}
	
	return 0;
}
*/


/*
int main(){
	int N,i,j;
	int action, num=0;
	char *bookName = (char*) malloc(11*sizeof(char));
	
	printf("Number of individuals (N): ");
	scanf("%d",&N);
	
	char **books = (char**) malloc(1*sizeof(char*));
	
	for(i=0;i<N;i++){
		scanf("%d %s",&action,bookName);
		if(action == 1){
			j=0;
			while(j<i && strcmp(books[j], bookName) != 0){
				j++;
			}
			if(j==i){
				printf("NO\n");
			}else{
				printf("YES\n");
				strcpy(books[j], "");
			}
		}else if(action == 2){
			
			strcpy(books[i], bookName);
		}
	}
	
	return 0;
}
*/

