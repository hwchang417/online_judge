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

int nqueens, sol;
char** map, *horizontal, *pos, *neg;
char *H, *P, *N;

void queen(char** map, int nth){
    int j;
    j = 0;
    
    if(nth == nqueens) return;
    
    //guess all possible solution
    while(j < nqueens){
        if(H[j] + P[nth + j] + N[j - nth] == 0){
            H[j] = P[nth + j] = N[j - nth] = 1;
            
            // exist solutions
            queen(map, nth + 1);
            if(nth == nqueens - 1)
                sol++;
            
            H[j] = P[nth + j] = N[j - nth] = 0;
        }
        j++;
    }
}

int totalNQueens(int n) {
    int row, col;
    
    sol = 0; nqueens = n;
    
    //memory allocation
    map = newArray2D(n);
    horizontal = newArray1D(char, n << 1);
    pos = newArray1D(char, n << 1);
    neg = newArray1D(char, n << 1);
    
    //take the center of array as pointer
    H = &horizontal[n];
    P = &pos[0];
    N = &neg[n];
    
    //n queens
    queen(map, 0);
    
    //memory free
    deleteArray1D(pos);
    deleteArray1D(neg);
    deleteArray1D(horizontal);
    deleteArray2D(map, n);
    
    return sol;
}