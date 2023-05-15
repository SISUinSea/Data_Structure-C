#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *q;
    int N, r, f;
}queue;

int isEmpty(queue *Q);
int isFull(queue *Q);
queue *initQueue(int size);
void enqueue(queue *Q, int e);
int dequeue(queue *Q);
void print(queue *Q);
void fullQueueException();
void emptyQueueException();

int main(){
    int size, n, e;
    char ch;
    queue *Q;

    scanf("%d", &size);
    Q = initQueue(size);
    scanf("%d", &n);
    while (n>0){
        getchar();
        scanf("%c", &ch);
        if(ch == 'I'){
            scanf("%d", &e);
            if(isFull(Q)){
                fullQueueException();
                print(Q);
                return -1;
            }
            enqueue(Q, e);
        }
        else if(ch == 'D'){
            if(isEmpty(Q)){
                emptyQueueException();
                return -1;
            }
            dequeue(Q);
        }
        else if(ch == 'P')
            print(Q);
        --n;
    }
    free(Q->q);
    free(Q);
    return 0;
}

int isEmpty(queue *Q){
    if(Q->f == Q->r)
        return 1;
    return 0;
}
int isFull(queue *Q){
    if(Q->f == (Q->r+1)%Q->N)
        return 1;
    return 0;
}
queue *initQueue(int size){
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->q = (int *)malloc(sizeof(int)*size);
    Q->f = 0;
    Q->r = 0;
    Q->N = size;
    return Q;
}
void enqueue(queue *Q, int e){
    Q->r = (Q->r+1)%Q->N;
    Q->q[Q->r] = e;
    return;
}
int dequeue(queue *Q){
    int e = Q->q[(Q->f+1)%Q->N];
    Q->q[(Q->f+1)%Q->N] = 0;
    Q->f = (Q->f+1)%Q->N;
    return e;
}
void print(queue *Q){
    for(int i = 0; i < Q->N; ++i)
        printf(" %d", Q->q[i]);
    printf("\n");
}
void fullQueueException(){
    printf("overflow");
}
void emptyQueueException(){
    printf("underflow");
}