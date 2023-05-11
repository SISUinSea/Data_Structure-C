#include <stdio.h>
void circulate(char *string);
int main(){
    char string[100];scanf("%s", string);
    int len = 0;

    for(char *p = string; *p; p++) len++;

    for(int i = 0; i<len;i++){
        printf("%s\n",string);
        circulate(string);
    }

    
}

void circulate(char *string){
    char tmp = *string;
    char *p;
    for(p = string+1; *p; p++){
        *(p-1) = *p;
    }
    *(p-1) = tmp;
}
