#include <stdio.h>

void ABC(int x[], int k);

int main(){
    int x[10];
    for (int i = 0; i<10; i++)
        scanf("%d", &x[i]);
    for(int i = 0; i<9; i++){
        ABC(x, i);
    }

    for(int i = 0; i<10; i++)
        printf(" %d", x[i]);
    printf("\n");
 }

void ABC(int x[], int k){
    int max = x[k], maxIndex = k;
    for(int i = k; i<10;i++){
        if(max < x[i]){
            max = x[i];
            maxIndex = i;
        }
    }

    int tmp = x[k];
    x[k] = max;
    x[maxIndex] = tmp;
}


/*
1 3 5 7 9 2 4 6 8 10
13 56 27 89 43 76 32 68 91 8
*/