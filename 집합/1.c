#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int element;
    struct Node * prev, *next;
}Node;
typedef struct set {
    Node *header, *trailer;
}Set;


Node *getNode(int element);
Set *getSet();
void add(Set *set, int element);
void print(Set *set);
int isSubset(Set *A, Set *B);
int member(Set *A, int element);
int subset(Set *A, Set *B);

int main(){
    Set *A = getSet();
    Set *B = getSet();
    int n;scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int element;
        scanf("%d", &element);
        add(A, element);
    }
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int element;
        scanf("%d", &element);
        add(B, element);
    }
    printf("%d\n", subset(A, B));
    
    // Set *set = getSet();
    // add(set, 1);
    // add(set, 2);
    // add(set, 3);
    // print(set);

    // Set *setB = getSet();
    // add(setB, 1);
    // add(setB, 2);
    // add(setB, 3);
    // add(setB, 4);

    // printf("%d\n", subset(set, setB));
}

Node *getNode(int element){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->element = element;
    newNode->prev = newNode->next = NULL;

    return newNode;
}
Set *getSet(){
    Set *newSet = (Set *) malloc(sizeof(Set));
    newSet->header = getNode(0);
    newSet->trailer = getNode(0);

    newSet->header->next = newSet->trailer;
    newSet->trailer->prev = newSet->header;

    return newSet;
}

void add(Set *set, int element){
    Node *newNode = getNode(element);
    Node *p = set->trailer;
    newNode->next = p;
    newNode->prev = p->prev;

    p->prev->next = newNode;
    p->prev = newNode;
}

void print(Set *set){
    Node *p = set->header->next;
    while (p->next != NULL)
    {
        printf("%d ", p->element);
        p = p->next;
    }
    printf("\n");
}

int member(Set *A, int element){
    // return 0 if false, 1 if true
    if(A->header->next == A->trailer) return 0;

    Node *p = A->header->next;
    while(1){
        if(p->element == element){
            return 1;
        }else{
            if(p->next == NULL) {
                return 0;
            }
        }

        p = p->next;
    }


}


int isSubset(Set *A, Set *B) {
    // return 0 if false, 1 if true
    if(A->header->next == A->trailer) // if A is empty set
        return 1;
    Node *p = A->header->next;
    while(p->next != NULL){
        if(!member(B,p->element)){
            return 0;
        }else {
            p = p->next;
        }
    }
    return 1;
}


int subset(Set *A, Set *B){
    Node *a = A->header->next;
    if(isSubset(A, B)){
        return 0;
    }else {
        while(a->next!= NULL){
            if(member(B, a->element)){
                a = a->next;
            } else {
                return a->element;
            }
        }
    }
    return -1;
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