#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int element;
    struct Node *next;
} Node ;

Node *getNode(int element);
void linkNode(Node* L, int element);
void print(Node *L);
int isMember(Node *B, int element);
int isSubset(Node *A, Node *B);
int subset(Node *A, Node *B);
void freeList(Node *P);


int main(){
    Node *A = NULL;
    Node *B = NULL;

    int n;scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int element; scanf("%d", &element);
        if(i == 0) A = getNode(element);
        else linkNode(A, element);
    }
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int element; scanf("%d", &element);
        if(i == 0) B = getNode(element);
        else linkNode(B, element);
    }

    printf("%d\n", subset(A, B));

    freeList(A);
    freeList(B);
}

Node *getNode(int element){
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode->element = element;
    newNode->next = NULL;

    return newNode;
}

void linkNode(Node* L, int element){
    Node *newNode = getNode(element);
    Node *p = NULL;
    for(p = L; p->next!=NULL; p = p->next);
    // from now on, p is L's trailing Node.
    p->next = newNode;
}

void print(Node *L){
    Node *p = NULL;
    for(p = L; p!=NULL; p = p->next) printf("%d ", p->element);
    printf("\n");
}

int isMember(Node *B, int element){
    // return 0 if false, 1 if true.
    if(B==NULL)
        return 0;
    Node *b = B;
    while(b!=NULL){
        if(b->element == element)
            return 1;
        else if(b->element > element)
            return 0;
        else 
            b = b->next;
    }
    return 0;
}

int isSubset(Node *A, Node *B){
    // return 0 if false, 1 if true.
    if(A == NULL)
        return 1;
    Node *a = A;
    while(a!= NULL){
        if(isMember(B, a->element))
            a = a->next;
        else
            return 0;
    }
    return 1;
}

int subset(Node *A, Node *B){
    Node *a = A;
    if(isSubset(A, B))
        return 0;
    else {
        while(isMember(B, a->element)) a = a->next;
    }
    return a->element;
}

void freeList(Node *P){
    Node *prevNode = NULL;
    Node *currentNode = NULL;

    currentNode = P;
    if(!currentNode) return;

    while(currentNode->next){
        prevNode = currentNode;
        currentNode = currentNode->next;
        free(prevNode);
    }
    free(currentNode);
}


/*
3
7 10 53
4         
7 10 15 45

0
3          
9 20 77

3
4 6 13
6
1 3 4 6 8 13
*/