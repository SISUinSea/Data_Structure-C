#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *next;
    struct node *prev;
    int elem;
}node;

typedef struct deque{
    node *front;
    node *rear;
}deque;

deque *initDeque();
node *getnode(int e);
void add_front(deque *D, int e);
void add_rear(deque *D, int e);
int delete_front(deque *D);
int delete_rear(deque *D);
void print(deque *D);
int isEmpty(deque *D);

int main(){
    int n, e;
    char ch;
    deque *D = initDeque();
    scanf("%d", &n);

    while (n>0){
        --n;
        getchar();
        scanf("%c", &ch);
        if(ch == 'A'){
            scanf("%c", &ch);
            scanf("%d", &e);
            if(ch == 'F')
                add_front(D,e);
            else
                add_rear(D,e);
        }
        else if(ch == 'D'){
            if(isEmpty(D)){
                printf("underflow\n");
                return -1;
            }
            else{
                scanf("%c", &ch);
                if(ch == 'F')
                    delete_front(D);
                else
                    delete_rear(D);
            }
        }
        else if(ch == 'P')
            print(D);
    }
    
    return 0;
}

deque *initDeque(){
    deque *D = (deque *)malloc(sizeof(deque));
    D->front = NULL;
    D->rear = NULL;
    return D;
}
node *getnode(int e){
    node *p = (node *)malloc(sizeof(node));
    p->elem = e;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void add_front(deque *D, int e){
    node *p = getnode(e);
    if (isEmpty(D))
        D->rear = p;
    else{
        node *q = D->front;
        p->next = q;
        q->prev = p;
    }
    D->front = p;
}
void add_rear(deque *D, int e){
    node *p = getnode(e);
    if(isEmpty(D))
        D->front = p;
    else{
        node *q = D->rear;
        p->prev = q;
        q->next = p;
    }
    D->rear = p;
}
int delete_front(deque *D){
    node *p = D->front;
    int e = p->elem;
    if(D->front != D->rear)
        D->front = D->front->next;
    else{
        D->front = NULL;
        D->rear = NULL;
    }
    free(p);
    return e;
}
int delete_rear(deque *D){
    node *p = D->rear;
    int e = p->elem;
    if(D->front != D->rear)
        D->rear = D->rear->prev;
    else{
        D->front = NULL;
        D->rear = NULL;
    }
    free(p);
    return e;
}
void print(deque *D){
    node *p = D->front;
    while (p != D->rear){
        printf(" %d", p->elem);
        p = p->next;
    }
    printf(" %d", p->elem);
    printf("\n");
}
int isEmpty(deque *D){
    if(D->front == NULL && D->front == D->rear)
        return 1;
    else
        return 0;
}
