#include <stdio.h>
#include <stdlib.h>
enum direction {North, South, East, West};
int main(){
    int n, m;
    n = 3, m = 4;
    // scanf("%d %d", &n, &m);
    int row = n, column = m;
    int i, j;
    int **arr = (int **) malloc(n*sizeof(int*));
    if(!arr) {
        printf("malloc error\n");
        return -1;
    }
    for(i = 0; i<n;i++) {
        *(arr+i) = (int *) malloc(m * sizeof(int));
        if(!arr[i]) {
            printf("malloc error\n");
            return -1;
        }
    }

    
    // enum direction direction = East;
    int count = 1;
    i=0,j=0;
    int t;
    while (1)
    {
        if(column > j && row > i) {
            while(column > j) arr[i][j++] = count ++;
            row --;
        }
        else if (row > i) {
            i--;
            while(row > i) arr[i++][j] = count ++;
            column--;
        }
        else if (column > j){
            i++;
            while(i>n-row) arr[i--][j] = count ++;
            column--;
        }
        else {
            j++;
            while(j>m-column) arr[i][j--] = count ++;
            row--;
        }
        
        if(row<1 ||  column < 1) break;

        
         
    }
    
   

    for(i = 0; i<n;i++)   {
        for(j = 0; j<m;j++) printf(" %d", arr[i][j]);
        printf("\n");
    }

    for(i = 0 ;i <n; i++) free(arr[i]);
    free(arr);

    return 0;
}