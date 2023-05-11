#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(){
    int n;
    scanf("%d", &n);

    int *x = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++){
        scanf("%d", &x[i]);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    swap(x+a, x+b);

    for (int i = 0; i<n; i++){
        printf(" %d", x[i]);
    }
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


/*
6
3 2 0 1 4 6
2 4
*/