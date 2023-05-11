#ifndef __LinkedList
#define __LinkedList

typedef struct __node {
    char             data;
    struct __node   *next;
} Node;

typedef struct {
    Node *head;
    Node *crnt;
} List;

void Initialize(List *list);

Node *Search(List *list, const char *x, int compare(const char *x, const char *y));

void InsertFront(List *list, const char *x);

void InsertRear(List *list, const char *x);

void RemoveFront(List *list);

void RemoveRear(List *list);

void RemoveCurrent(List *list);

void Clear(List *list);

void PrintCurrent(const List *list);

void PrintLnCurrent(const List *list);

void Print(const List *list);

void Terminate(List *list);

#endif