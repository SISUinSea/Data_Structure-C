#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isEmpty(int f, int r) {
    return f == r;
}

int isFull(int q, int f, int r) {
    return (r + 1) % q == f;
}
void enqueue(int* que, int q, int* f, int* r, int input, int* quit) {
    if (isFull(q, *f, *r)) {//만원 큐
        *quit = 1;
        printf("overflow ");
        for (int i = 0; i < q; i++)
            printf("%d ", que[i]);
        return;
    }
    else {//만원 큐 x
        *r = (*r + 1) % q;
        que[*r] = input;
        return;
    }
}
void dequeue(int* que, int q, int* f, int* r, int* quit) {
    if (isEmpty(*f, *r)) {//빈 큐
        *quit = 1;
        printf("underflow ");
        for (int i = 0; i < q; i++)
            printf("%d ", que[i]);
        return;
    }
    else {//빈 큐 x
        *f = (*f + 1) % q;
        que[*f] = 0;
        return;
    }
}
void print(int* que, int q) {
    for (int i = 0; i < q; i++)
        printf(" %d", que[i]);
    printf("\n");
    return;
}

int main() {
    int q; scanf("%d", &q);//원형 큐 크기 
    int n; scanf("%d", &n);//명령의 개수 

    int* que = (int*)malloc(sizeof(int) * q);//큐 동적할당
    if (q == NULL) return -1;
    for (int i = 0; i < q; i++) que[i] = 0;
    int f = 0, r = 0;

    char order; int input, quit = 0;//quit으로 프로그램 종료 control
    for (int i = 0; i < n; i++) {
        getchar();//
        scanf("%c", &order);//명령 입력

        switch (order) {
        case 'I'://insert
            scanf("%d", &input); 
            enqueue(que, q, &f, &r, input, &quit);
            break;
        case 'D'://delete
            dequeue(que, q, &f, &r, &quit);
            break;
        case 'P'://print
            print(que, q);
            break;
        }

        if (quit == 1) break;
    }


    free(que);//큐 메모리 해제
    return 0;
}

/*

6
10
I 10
I 20
P
I 30
I 40
D
P
I 50
I 60
I 70


*/