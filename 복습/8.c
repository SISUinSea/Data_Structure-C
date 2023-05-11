#include <stdio.h>
#include <stdlib.h>
typedef struct student {
    char name[7+1];
    int kor, eng, mth;
    double avg;
}student ;

int main(){
    int n;scanf("%d", &n);
    student *students = (student *) malloc(n * sizeof(student));
    
    for(int i = 0; i<n; i++) {
        scanf("%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].mth);
        students[i].avg = (students[i].mth + students[i].kor + students[i].eng) / 3.0;
    }

    for(int i = 0; i<n; i++){
        printf("%s %.1f", students[i].name, students[i].avg);
        if(students[i].eng >= 90 || students[i].kor >= 90 || students[i].mth >= 90 ) printf(" GREAT");
        if(students[i].eng < 70 || students[i].kor < 70 || students[i].mth < 70 ) printf(" BAD");
        printf("\n");
    }
}