#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int n;scanf("%d", &n);

    int **a = (int **) calloc(n, sizeof(int *));
    if(!a) return -1;
    int row = n;
    for(int i = 0; i<n; i++){
        a[i] = (int *) calloc(n, sizeof(int));
        if(!a[i]) return -1;
        int count = ((rand()%row)*0.1) + row*0.9;
        int j;
        for(j = 0; j<count;j++){
            a[i][j] = 1;
        }
        for(; j<n;j++){
            a[i][j] = 0;
        }
        row = row * 0.9;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n;j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }


    for(int i = 0; i<n; i++) free(a[i]);
    free(a);

}