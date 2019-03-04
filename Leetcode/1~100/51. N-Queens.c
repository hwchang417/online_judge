/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define newArray1D(type, size) (type*) calloc(size, sizeof(type))
#define deleteArray1D(pointer) free(pointer)

char** newArray2D(int n){
    int row;
    char** map;
    map = newArray1D(char*, n);
    for(row = 0;row < n;row++)
        map[row] = newArray1D(char, n);
    return map;
}

void deleteArray2D(char** map, int n){
    int row;
    for(row = 0;row < n;row++)
        free(map[row]);
    free(map);
}

typedef struct ListChar{
    char*** data;
    int size;
    int capacity;
}List;

void ListChar(List* list){
    list->size = 0;
    list->capacity = 16;
    list->data = (char***) calloc(list->capacity, sizeof(char**));
}

void addList(List* list, char** element, int n){

    //copy to new array
    int row;
    char** map;
    map = newArray2D(n);
    for(row = 0;row < n;row++)
        memcpy(map[row], element[row], sizeof(char) * n);

    list->data[list->size++] = map;
    if(list->size == list->capacity - 1){
        list->capacity <<= 1;
        list->data = (char***) realloc(list->data, sizeof(char**) * list->capacity);
    }
    list->data[list->size] = '\0';
}

char*** returnList(List* list){
    return list->data;
}

int nqueens;
List result;
char** map, *horizontal, *pos, *neg;
char *H, *P, *N;


void queen(char** map, int nth){
    int j;
    j = 0;
    
    if(nth == nqueens) return;
    
    while(j < nqueens){
        if(H[j] + P[nth + j] + N[j - nth] == 0){
            H[j] = P[nth + j] = N[j - nth] = 1;
            map[nth][j] = 'Q';
            
            // exist solutions
            queen(map, nth + 1);
            if(nth == nqueens - 1){
                addList(&result, map, nqueens);
            }
            
            H[j] = P[nth + j] = N[j - nth] = 0;
            map[nth][j] = '.';
        }
        j++;
    }
    
}

void resetToDot(char** map, int n){
    int row;
    for(row = 0;row < n;row++)
        memset(map[row], '.', n * sizeof(char));
}

char*** solveNQueens(int n, int* returnSize) {
    int row, col;
    
    nqueens = n;
    map = newArray2D(n);
    horizontal = newArray1D(char, n << 1);
    pos = newArray1D(char, n << 1);
    neg = newArray1D(char, n << 1);
    
    H = &horizontal[n];
    P = &pos[0];
    N = &neg[n];
    ListChar(&result);
    
    resetToDot(map, n);
    
    queen(map, 0);
    
    deleteArray1D(pos);
    deleteArray1D(neg);
    deleteArray1D(horizontal);
    deleteArray2D(map, n);
    
    *returnSize = result.size;
    return returnList(&result);
}
