#include <stdio.h>
#include <stdlib.h>

int isExist(int i, int j, int row, int column);

int main(){
    int n, m;scanf("%d %d", &n, &m);
    int **arr = (int **) malloc(n*sizeof(int*));
    if(!arr) {
        printf("malloc error!\n");
        return -1;
    }
    int i, j;
    for (i = 0; i<n;i++) {
        *(arr+i) = (int *) malloc(m*sizeof(int));
        if(!arr[i]){
            printf("malloc error!\n");
            return -1;
        }
    }

    int start_i = 0, start_j = 0;
    int count = 1;
    while (1)
    {
        i = start_i, j = start_j;
        while(1){
            arr[i++][j--] = count++;
            if(!isExist(i,j,n, m)) break;
        }

        if(start_j < m-1)
            start_j++;
        else // start_j가 벽에 부딪힘.
            start_i++;
        
        if(!isExist(start_i, start_j, n, m)) break;

    }
    
    


    for(i = 0; i<n;i++){
        for(j = 0;  j<m;j++) printf(" %d", arr[i][j]);
        printf("\n");
    }

    for(i = 0; i<n; i++) free(arr[i]);
    free(arr);

    return 0;
}
int isExist(int i, int j, int row, int column){
    return i>=row||j>=column || i<0 || j<0 ? 0 : 1 ;
}
