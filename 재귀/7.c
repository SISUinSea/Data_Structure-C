#include <stdio.h>

int count (char *arr, char searching);

int main(){
    char string[100+1];
    char searching;
    gets(string);
    scanf("%c", &searching);
    printf("%d\n", count(string, searching));
}


int count (char *arr, char searching){
    if(!*arr) return 0;
    else {
        if(*arr == searching) return 1 + count(arr+1, searching);
        else return count(arr+1, searching);
    }
}