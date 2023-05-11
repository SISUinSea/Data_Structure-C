#include <stdio.h>
#include <stdlib.h>

int countOnesButSlow(int **A, int n);
int countOnes(int **A, int n);

int main(){
    int n;scanf("%d", &n);
    int **a = (int **) calloc(n, sizeof(int *));
    if(!a) return -1;
    for(int i = 0; i<n; i++){
        a[i] = (int *) calloc(n, sizeof(int));
        if(!a[i]) return -1;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int countOnesButSlowResult = countOnesButSlow(a, n);
    int countOnesResult = countOnes(a, n);
    printf("%d\n", countOnesButSlowResult);
    printf("%d\n", countOnesResult);

    for(int i = 0; i<n; i++) free(a[i]);
    free(a);
}

int countOnesButSlow(int **A, int n){
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

int countOnes(int **A, int n){
    int c = 0;
    for(int i = 0, j = n-1; i<n && j >= 0;){
        if(A[i][j] == 1){
            i++;
            c += j+1;
        }else { // case 0:
            j--;
        }
    }
    return c;
}


/*
8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/