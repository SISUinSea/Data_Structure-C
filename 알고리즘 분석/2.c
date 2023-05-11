#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;scanf("%d", &n);

    int a[100][100];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int max = 0;
    int flag = 0;
    for (int i = 0, j = 0; i<n;){
        if(a[i][j]==1){
            j++;
            flag = 1;
        }else { // met 0
        if(flag == 1){
            max = i;
            flag = 0;
        }
        i++;
        }
    }

    printf("%d\n", max);
}

/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/