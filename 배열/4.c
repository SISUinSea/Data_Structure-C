#include <stdio.h>
#include <stdlib.h>
enum direction {North, South, East, West};
int main(){
    int n, m;scanf("%d %d", &n, &m);
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

    
    enum direction direction = East;
    int count = 1;
    i=0,j=0-1;
    int t;
    while (1)
    {
        switch (direction)
        {
        case East:
            for(t=0,j++;t<m;j++,t++) arr[i][j] = count++;
            j--,n--;
            direction = South;
            break;
        case South:
            for(t=0,i++;t<n;i++,t++) arr[i][j] = count++;
            m--,i--;
            direction = West;
            break;
        case West:
            for(t=0,j--;t<m;j--,t++) arr[i][j] = count++;
            n--,j++;
            direction = North;
            break;
        case North:
            for(t=0,i--;t<n;i--,t++) arr[i][j] = count++;
            m--,i++;
            direction = East;
        default:
            break;
        }
        if(n<1 ||  m < 1) break;
         
    }
    
   

    for(i = 0; i<row;i++)   {
        for(j = 0; j<column;j++) printf(" %d", arr[i][j]);
        printf("\n");
    }

    for(i = 0 ;i <n; i++) free(arr[i]);
    free(arr);

    return 0;
}