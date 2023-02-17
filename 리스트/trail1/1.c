#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List {
    int len;
    Node *head, *tail;
} List;


// completed   
Node * initNode(char data);
List * initList();
void printList(List *list);
void add(List *list, int kth, char data);


void delete(List* list, int kth);
int searchKth(List* list, int kth);
int searchNum(List *list, int data);

int main(){
    List *list = initList();
    printf("=== dbg in...main...\n");
    add(list, 0, 's');
    printList(list);
}

Node * initNode(char data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode ->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

List * initList(){
    printf("=== dbg in ... initList...");
    List *newList = (List *) malloc(sizeof(List));
    newList->len = 0;
    newList->head->prev = NULL;
    newList->tail->next = NULL;
    newList->head->next = newList->tail;
    newList->tail->prev = newList->head;
    return newList;
}

void printList(List *list){
    printf("== dbg... printList method is started!\n");
    Node *p = list->head->next;
    while (p->next!=NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    // printf("%c\n", p->data);
}

void add(List *list, int kth, char data){
    // TODO. edge case check

    printf("---dbg in... add method\n");
    Node *newNode = initNode(data);
    Node *p = list->head->next;
    for(int i = 0; i<kth; i++) p = p->next;
    newNode->next = p;
    newNode->prev = p->prev;

    p->prev->next = newNode;
    p->prev = newNode;
}


// Node * newNode(char data){
//     Node *newNode = (Node *) malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->prev = newNode->next = NULL;
//     return newNode;
// }

// List * newList(){
//     List *list = (List *) malloc(sizeof(List));
//     list->len = 0;
//     list-> head = list-> tail = NULL;
//     return list;
// }

// void printList(List *list){
//     Node *p = list->head;
//     while (p->next != NULL){
//         printf("%c", p->data);
//         p = p->next;
//     }
//     printf("%c\n",p->data);
// }

// void add(List *list, int kth, char data){
//     if(kth > list->len) {
//         printf("index error!\n");
//         return ;
//     }
//     list->len ++;
//     Node *node = newNode(data);
//     if(list->head == NULL && list->tail == NULL){
//         list->head = list->tail = node;
//     }else{
//         Node *p = list->head;
//         for(int i = 0; i<kth && p->next != NULL; i++)p=p->next;
        
//     }
// }
