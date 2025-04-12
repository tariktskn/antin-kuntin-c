#include <stdio.h>
#include <stdlib.h>

struct Hash{
    int* key;
    int* val;
    int cap;
};

struct Hash* hashInit(int cap){
    struct Hash* hash = (struct Hash*) malloc(sizeof(struct Hash));
    hash->key = (int*) calloc(cap, sizeof(int));
    hash->val = (int*) calloc(cap, sizeof(int));
    hash->cap = cap;
    return hash;
}

int hashGetIndex(struct Hash* hash, int key){
    int idx = key % hash->cap;

    while(hash->key[idx] != 0 && hash->key[idx] != key){
        idx = (idx+1) % hash->cap;
    }
    hash->key[idx] = key;
    return idx;
}

int hashSet(struct Hash* hash, int key, int val){
    int idx = hashGetIndex(hash, key);
    return hash->val[idx] = val;
}

int hashGet(struct Hash* hash, int key){
    int idx = hashGetIndex(hash, key);
    return hash->val[idx];
}

void hashPrint(struct Hash* hash){
	int i;
    for(i=0; i<hash->cap; ++i){
        printf("Key: %4d, Value: %5d\n", hash->key[i], hash->val[i]);
    }
    printf("\n");
}

void hashFree(struct Hash** hash){
    free((*hash)->key);
    free((*hash)->val);
    free(*hash);
    *hash = NULL;
}

int main(){
	struct Hash* hash = hashInit(15);
	int i;
	
	for(i=0; i<hash->cap; ++i){
		hashSet(hash, i*i, i*i*i - i*i - i);
	}
	
	hashPrint(hash);
	hashFree(&hash);
	
	return 0;
}
