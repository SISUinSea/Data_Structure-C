#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *x = (int *) malloc(n * sizeof(int));
    int *y = (int *) malloc(n * sizeof(int));

    for(int i = 0; i<n; i++) scanf("%d", x+i);
    for(int i = 0; i<n; i++) scanf("%d", y+i);

    for(int i = 0, j = n-1; i < n; i++, j--){
        x[i] += y[j];
    }

    for(int i = 0; i<n; i++)printf(" %d", x[i]);
    printf("\n");

    free(x);
    free(y);
}

/*
3
1 2 3
5 10 15

4
3 8 9 5
0 1 -5 6
*/