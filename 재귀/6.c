#include <stdio.h>

int gcd(int a, int b);

int main(){
    int a, b; scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
}

int gcd(int a, int b){
    if( b <= 0 ) return a;
    else{
        int r = a % b;
        a = b;
        b = r;
        return gcd(a, b);
    }
}
