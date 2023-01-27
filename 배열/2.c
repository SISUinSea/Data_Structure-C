#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;scanf("%d", &n);
    int *arr = NULL;
    arr = malloc(n * sizeof(int));
    if (!arr) return -1;

    int i;
    for(i = 0; i<n; i++) scanf("%d", arr+i);

    int len; scanf("%d", &len);
    int *command = NULL;
    command = malloc(len*sizeof(int));
    if(!command) return -1;
    for(i = 0; i<len;i++) scanf("%d", command+i);

    int tmp, start = arr[command[0]];
    int head, tail;
    for(i = len-1-1; i>=1;i--){
        head = command[i], tail = command[i+1];
        arr[tail] = arr[head];
    }
    arr[head] = start;


    for(i = 0; i<n;i++) printf(" %d", arr[i]);
    printf("\n");
}