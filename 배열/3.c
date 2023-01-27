#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;scanf("%d", &n);
    int **arr = malloc(n*sizeof(int*));
    if(!arr) {
        printf("malloc error!\n");
        return -1;
    }
    
    int i;
    for(i = 0; i<n;i++) {
        *(arr + i) = malloc(n * sizeof(int));
        if(!arr[i])  {
            printf("malloc error!\n");
            return -1;
        }
    }

    int j = 0, count = 1;
    i = 0;
    while (i < n)
    {
        if(j==0) {
            while(j < n) arr[i][j++] = count++;
            j--;
        }else {
            while(j >= 0) arr[i][j--] = count++;
            j++;
        }
        i++;
    }

    for (i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}