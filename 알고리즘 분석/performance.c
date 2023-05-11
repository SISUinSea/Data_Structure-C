#include<stdio.h>
#include<stdlib.h>
int modulo(int a, int b);
int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = modulo(a, b);
    printf("%d\n", result);
}

int modulo(int a, int b){

    while (1){
        if (a < b) break;

        a -= b;
    }

    return a;
}

/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/