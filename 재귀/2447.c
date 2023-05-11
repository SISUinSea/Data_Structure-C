#include <stdio.h>
#include <stdlib.h>
void printStar(char **a, int n);
int main(){
    int n;scanf("%d", &n);
    char **a = (char **) calloc(n, sizeof(char *));
    if(!a) return -1;
    for(int i = 0; i<n; i++){
        a[i] = (char *) calloc(n , sizeof(char));
        if(!a[i]) return -1;
    }

    // initiate array
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = ' ';
        }
    }

    printStar(a, n);

    // print
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    // free
    for(int i = 0; i<n; i++) free(a[i]);
    free(a);

}

void printStar(char **a, int n){
    if(n == 3){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(i != 1 || j != 1) a[i][j] = '*';
            }
        }
    } else {
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(i != 1 || j != 1) printStar(, n/3);
            }
        }
    }
}
