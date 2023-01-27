#include <stdio.h>
void printDigit(int n) ;
int main(){
    int n;
    scanf("%d", &n);
    printDigit(n);
}
void printDigit(int n){
    if (n < 10) printf("%d\n",n);
    else {
        printDigit(n/10);
        printf("%d\n", n%10);
    }
}