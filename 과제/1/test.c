#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 4;

    int **a = (int **) calloc(n, sizeof(int *));
    if(a== NULL){
        printf("someting went wrong\n");
        return -1;
    }
    //

    for(int i = 0; i<n; i++) 
        // a[i] = (int *) calloc(n, sizeof(int ));
        * (a+i) = (int *) calloc(n, sizeof(int ));
    //

    for(int i = 0; i<n; i++){
        for(int j = 0; i<n; j++){
            scanf("%d", *(a+i)+j);
        }
    }
}