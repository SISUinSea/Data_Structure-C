#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if (!arr) return -1;

    int i;
    for(i = 0; i< n; i++){
        scanf("%d", arr+i);
    }
    int r;scanf("%d", &r);
    for (i = 0; i<r; i++){
        int head, tail;
        scanf("%d %d", &head, &tail);
        while (head < tail)
        {
            int tmp;
            tmp = arr[head];
            arr[head] = arr[tail];
            arr[tail] = tmp;

            head++; tail--;
        }
    }

    for(i = 0; i<n; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");

}