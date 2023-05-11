#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[9+1];
    int score;
} student;

double getAvg(student * data);

int main() {
    student *data = (student *) malloc(5*sizeof(student *));
    for (int i = 0; i<5; i++){
        scanf("%s %d", data[i].name, &data[i].score);
    }
    
    double avg = getAvg(data);

    for (int i = 0; i<5; i++){
        if(data[i].score <= avg)
            printf("%s\n", data[i].name);
    }
}

double getAvg(student * data){
    double rst = 0;

    for(int i = 0; i<5; i++){
        rst += data[i].score;
    }

    rst /= 5;

    return rst;
}


/*
akim 75
bkim 85
ckim 65
dkim 95
ekim 100
*/