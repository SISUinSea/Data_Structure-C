#include <stdio.h>

typedef struct time {
    int hor, min, sec;
    int convertToSec;
} time;

int main(){
    time firstTime, secondTime;
    scanf("%d %d %d", &firstTime.hor, &firstTime.min, &firstTime.sec);
    scanf("%d %d %d", &secondTime.hor, &secondTime.min, &secondTime.sec);
    firstTime.convertToSec = firstTime.sec + 60*firstTime.min + 3600*firstTime.hor;
    secondTime.convertToSec = secondTime.sec + 60*secondTime.min + 3600*secondTime.hor;

    time diffTime;
    diffTime.convertToSec = secondTime.convertToSec - firstTime.convertToSec;
    diffTime.hor = diffTime.convertToSec/3600;
    diffTime.convertToSec %= 3600;
    diffTime.min = diffTime.convertToSec / 60;
    diffTime.convertToSec %= 60;
    diffTime.sec = diffTime.convertToSec;
    


    printf("%0d %0d %0d\n", diffTime.hor, diffTime.min, diffTime.sec);
}