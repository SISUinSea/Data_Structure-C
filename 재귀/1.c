#include <stdio.h>

int sum(int n);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
}

int sum(int n){
    if (n <= 1) return 1;
    else return n + sum(n-1);
}