#include <stdio.h>

int sum(int k);

int main(){
    int n;
    scanf("%d", &n);
    int result = 0;
    for (int i = 1; i<=n; i++) {
        result += sum(i);
    }
    printf("%d\n", result);
}

int sum(int k){
    int result = 0;
    for (int i = 1; i <= k; i++){
        result += i;
    }

    return result;
}
