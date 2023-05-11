#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    int elem;
    struct node *prev, *next;
} node;

typedef struct deque
{
    node *front, *rear;
} deque;


node* getnode(int d);
deque* initDeque();
void dequeEmptyException();

int isEmpty(deque* d);


void add_front(deque *d, int elem);
void add_rear(deque *d, int elem);
int delete_front(deque* d);
int delete_rear(deque* d);
void print(deque *d);
void freeDeque(deque* d);

int main(){
    deque* d = initDeque();

    
    int number_of_commands;
    scanf("%d", &number_of_commands); getchar();

    int element, check;
    char command[2+1];
    for(int i = 0; i<number_of_commands; i++){
        scanf("%s", command); 

        if(strcmp(command, "AF") == 0){
            scanf("%d", &element); getchar();
            add_front(d, element);
        } else if(strcmp(command, "AR") == 0){
            scanf("%d", &element); getchar();
            add_rear(d, element);
        } else if(strcmp(command, "DF") == 0){
            check = delete_front(d);
            if(check == -1) {
                freeDeque(d);
                free(d);
                return 0;
                }
        } else if(strcmp(command, "DR") == 0){
            check = delete_rear(d);
            if(check == -1) {
                freeDeque(d);
                free(d);
                return 0;
                }

        } else if(strcmp(command, "P") == 0){
            print(d);
        }
    }
    
    // free()
    freeDeque(d);
    free(d);

}

node* getnode(int d){
    node* newnode = (node*) malloc(sizeof(node));
    
    newnode->elem = d;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

deque* initDeque(){
    deque* newDeque = (deque*) malloc(sizeof(deque));
    newDeque->front = NULL;
    newDeque->rear = NULL;

    return newDeque;
}


int isEmpty(deque* d){
    return d->front == NULL;
}


void add_front(deque *d, int elem){
    node* newnode = getnode(elem);

    if(isEmpty(d)){
        d->front = newnode;
        d->rear = newnode;
    }
    else {
        newnode->next = d->front;
        d->front->prev = newnode;

        d->front = newnode;
    }

}


void add_rear(deque *d, int elem){
    node* newnode = getnode(elem);

    if(isEmpty(d)){
        d->front = newnode;
        d->rear = newnode;

    }
    else {
        d->rear->next = newnode;
        newnode->prev = d->rear;
        d->rear = newnode;
    }
}


void print(deque *d){
    // printf("p is executed\n");
    node* p = d->front;
    while(p){
        printf(" %d", p->elem);
        p = p->next;
    }
    printf("\n");
}

/* return 0 if no exception, else -1. */
int delete_front(deque* d){
    if(isEmpty(d)){
        dequeEmptyException();
        return -1;
    }

    node* targetnode;
    int targetvalue;
    // 덱에 하나의 원소만 있는 경우와 두 개 이상의 원소가 있는 경우를 구분해야 한다.
    // 하나의 원소만 있다면
    if(d->front == d->rear){
        targetnode = d->front;
        targetvalue = targetnode->elem;
        d->front = NULL;
        d->rear = NULL;
        free(targetnode);
    }
    else { // 두 개 이상의 원소가 있다면
            
        targetnode = d->front;  // pointing target node
        targetvalue = targetnode->elem; // saving target value


        // decoupling
        d->front = targetnode->next;    
        targetnode->next->prev = NULL;
        free(targetnode);
    }
    return targetvalue;
}


int delete_rear(deque* d){
    if(isEmpty(d)){
        dequeEmptyException();
        return -1;
    }

    node* targetnode;
    int targetvalue;
    // 덱에 하나의 원소만 있는 경우와 두 개 이상의 원소가 있는 경우를 구분해야 한다.
    // 하나의 원소만 있다면
    if(d->front == d->rear){
        targetnode = d->front;
        targetvalue = targetnode->elem;
        d->front = NULL;
        d->rear = NULL;
        free(targetnode);
    }
    else { // 두 개 이상의 원소가 있다면
            
        targetnode = d->rear;  // pointing target node
        targetvalue = targetnode->elem; // saving target value


        // decoupling
        d->rear = targetnode->prev;    
        targetnode->prev->next = NULL;
        free(targetnode);
    }
    return targetvalue;
}


void dequeEmptyException(){
    printf("underflow\n");
}


void freeDeque(deque* d){
    node* p = d->front;
    node* boom = NULL;
    while(p){
        boom = p;
        p = p->next;
        free(boom);
    }
}
