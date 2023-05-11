#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   char element;
   struct Node *prev, *next;
} Node;

typedef struct List {
   Node *header, *trailer;
   int len;
} List;


// methods
Node *initNode(char data);
List *initList();

void add(List *list, int r, char e);
void print(List *list);
char get(List *list, int r);
void delete(List *list, int r);
int isValid(List *list, int r);


int main(){
   List *list = initList();
   int n;scanf("%d", &n);
   getchar();
            int r;
            char element;
            int check;
   for(int i = 0; i<n; i++){
      // printf("%d starts\n", i);
      char command; scanf("%c", &command);
      switch(command){
         case 'A':
            scanf("%d %c", &r, &element);
            if(list->len >= r-1){
               add(list, r, element);
            } else {
               printf("invalid position\n");
            }
            break;
            
         case 'P':
            print(list);
            break;
         case 'D':
            scanf("%d", &r);
            if(list->len >= r){
               delete(list, r);
            } else {
               printf("invalid position\n");
            }
            break;
            
         case 'G':
            scanf("%d", &r);
            if(list->len >= r){
               printf("%c\n", get(list, r));
            } else {
               printf("invalid position\n");
            }
            break;
   
         default:
            break;
      }
      getchar();

      // printf("%d ends\n", i);
   }
}

Node *initNode(char data){
   Node *newNode = (Node*) malloc(sizeof(Node));
   newNode->prev = NULL;
   newNode->next = NULL;
   newNode->element = data;

   return newNode;
}

List *initList(){
   List *newList = (List *)malloc(sizeof(List));
   Node *headerNode = initNode('\0');
   Node *trailerNode = initNode('\0');
   headerNode->next = trailerNode;
   trailerNode->prev = headerNode;
   newList->header = headerNode;
   newList->trailer = trailerNode;
   newList->len = 0;

   return newList;
}

void add(List *list, int r, char e){
   list->len ++;
   Node *newNode = initNode(e);

   Node *p = list->header;
   for(int i = 0; i< r; i++) p = p->next;

   newNode->prev = p->prev;
   newNode->next = p;

   p->prev->next = newNode;
   p->prev = newNode;
}

void print(List *list){
   Node *p = list->header->next;

   while (p->next != NULL)
   {
      printf("%c",p->element);
      p = p->next;
   }

   printf("\n");
}

void delete(List *list, int r){
   list->len --;
   Node *p = list->header;
   for(int i = 0; i < r; i++) p = p->next;
   p->prev->next = p->next;
   p->next->prev = p->prev;

   free(p);
}

char get(List *list, int r){

   Node *p = list->header;
   for(int i = 0; i<r; i++) p = p->next;

   return p->element;
}


/*
9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
*/