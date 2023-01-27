#include <stdio.h>
#include <stdlib.h>


int max(int *arr,int n, int max);

int main(){
    int n;scanf("%d", &n);

    // 동적 할당
    int *arr = malloc(n*sizeof(int));
    if(!arr) return -1;
    for(int i = 0 ; i<n; i++) scanf("%d", arr+i);

    // max 함수 호출
    printf("%d", max(arr, n,*(arr+n-1)));

}

int max(int *arr,int len, int last){
    if(len <= 1) return last < *arr ? *arr : last;
    else {
        last = *(arr+ (--len));
        int lower = max(arr, len, last);
        return last < lower ? lower : last;
    }
    // return max(arr)
}
