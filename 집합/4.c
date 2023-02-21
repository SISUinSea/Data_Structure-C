#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int element;
    struct Node *next;
} Node;
typedef struct Set {
    Node *header;
}Set;

Node *getNode(int element);
Set *getSet();
void addLast(Set *header, int element);
void print(Set *set);
Set *uni(Set *A, Set *B);
Set *intersect(Set *A, Set *B);

int main(){
    Set *A = getSet();
    // addLast(A, 1);
    // addLast(A, 2);
    // addLast(A, 3);
    // print(A);
    Set *B = getSet();
    // addLast(B, 2);
    // addLast(B, 3);
    // addLast(B, 4);
    // print(B);

    // print(intersect(A, B));
    int n;scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int element;scanf("%d", &element);
        addLast(A, element);
    }
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int element;scanf("%d", &element);
        addLast(B, element);
    }
    print(uni(A, B));
    print(intersect(A, B));

}

Node *getNode(int element){
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->element = element;
    newNode->next = NULL;

    return newNode;
}

Set *getSet(){
    Set *newSet = (Set *) malloc(sizeof(Set));
    newSet->header = getNode(0);
    newSet->header->next = NULL;

    return newSet;
}

void addLast(Set *set, int element){
    Node *p = set->header;
    for(;p->next != NULL; p = p->next);
    // from now on, p is set's trailing node.

    Node *newNode = getNode(element);
    p->next = newNode;
}

void print(Set *set){
    if(set->header->next == NULL) {
        printf(" 0\n");
        return ;
    }
    Node *p = set->header->next;
    while(p->next != NULL){
        printf(" %d", p->element);
        p = p->next;
    }
    printf(" %d\n", p->element);
}

Set *uni(Set *A, Set *B){
    Set *C = getSet();
    Node *a = A->header->next;
    Node *b = B->header->next;
    while(a!=NULL && b!=NULL){
        if(a->element == b->element){
            addLast(C, a->element);
            a = a->next;
            b = b->next;
        }else if(a->element < b->element){
            addLast(C, a->element);
            a = a->next;
        }else {// a > b
            addLast(C, b->element);
            b = b->next;
        }
    }
    while(a!=NULL){
        addLast(C, a->element);
        a = a->next;
    }
    while(b!=NULL){
        addLast(C, b->element);
        b = b->next;
    }
    return C;
}

Set *intersect(Set *A, Set *B){
    Set *C = getSet();
    Node *a = A->header->next;
    Node *b = B->header->next;
    while(a!=NULL && b!=NULL){
        if(a->element == b->element){
            addLast(C, a->element);
            a = a->next;
            b = b->next;
        }else if(a->element < b->element){
            a = a->next;
        }else {// a > b
            b = b->next;
        }
    }
   
    return C;
}

/*
6
3 7 45 88 99 101
4
7 10 15 45

0
3 
9 20 77

0
0
*/