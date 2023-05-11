// verify random number can saved to allocated array.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int countOnesButSlow(bool **A, int n);
int countOnes(bool **A, int n);


int main(){
    // get integer from user.
    int n = 20;
    // scanf("%d", &n);

    // allocate memory to array 'a'.
    bool **a = (bool **) calloc(n, sizeof(bool *));
    if(!a) return -1;
    for(int i = 0; i<n; i++){
        a[i] = (bool *) calloc(n, sizeof(bool));
        if(!a[i]) return -1;
    }

    // randomize seed.
    srand(time(NULL));
    int rowLen = n;
    int kTotal = 0;
    for(int i = 0; i<n; i++){
    // set row's one number to random value .
    if(rowLen != 0)
         rowLen = (rand() % rowLen)*0.1 + rowLen*0.9;
        kTotal += rowLen;
        int j;
        for(j = 0; j < rowLen; j++){
            a[i][j] = 1;
        }
        for(;j<n; j++){
            a[i][j] = 0;
        }
    }

    // call function countOnes
    int ones = countOnes(a, n);
    printf("%d %d %d", kTotal, ones, -1);


    // call functions countOnesButSlow
    int slowOnes = countOnesButSlow(a, n);
    printf("%d %d %d", kTotal, slowOnes, -1);


    // // print result.
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++)
    //         printf("%d ", a[i][j]);
    //     printf("\n");
    // }


    // free
    for(int i = 0; i<n;i++) free(a[i]);
    free(a);
}

int countOnesButSlow(bool **A, int n){
    int c = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(A[i][j] == 1){
                c++;
            }
        }
    }
    return c;
}

int countOnes(bool **A, int n){
    int c = 0;
    for(int i = 0, j = n-1; i<n && j >= 0;){
        if(A[i][j] == 1){
            c += j+1;
            i++;
        }else { // case 0:
            j--;
        }
    }
    return c;
}

