#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {//노드 정의
   char data;
   struct Node* next;
}Node;

Node* getnode(char data);
void push(Node* t, char x);
int isEmpty(Node* t);
char pop(Node* t);
int Counterpart(char s, char t);
int isBalanced(Node* t,char*arr, char* result);

int main() {
   int N=0;
   char arr[1001] = { 0 }, result[7]={0};
   Node* t = NULL;

   gets(arr);//수식문장 입력

   for (char* p = arr; p < arr + strlen(arr); p++) {//괄호의 개수 세기
      if (*p == '{' || *p == '[' || *p == '(') {
         N++;
      }
      else if (*p == '}' || *p == ']' || *p == ')') {
         N++;
      }
   }


   if (isBalanced(&t, arr, result, &N)) strcpy(result, "OK");
   else strcpy(result, "Wrong");
   printf("%s_%d", result, N);
   free(t);

   return 0;
}

Node* getnode(char data) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->data = data;
   node->next = NULL;
}

void push(Node** t, char x) {
   Node* p = getnode(x);
   p->next = *t;
   *t = p;
   return;
}

int isEmpty(Node** t) {
   return *t == NULL;
}

char pop(Node** t) {
   if (isEmpty(t)) {
      printf("Stack empty\n"); return 0;
   }
   char e = (*t)->data;
   Node* p = *t;
   *t = (* t)->next;
   free(p);
   return e;
}
int Counterpart(char s, char t) {
   if (s == '{' && t == '}') return 1;
   else if (s == '[' && t == ']') return 1;
   else if (s == '(' && t == ')') return 1;
   else return 0;

}
int isBalanced(Node* t, char* arr, char* result) {
   int i = 1;
   for (char* p = arr; p < arr + strlen(arr); p++, i++) {
      //printf("%d", i);//
      if (*p == '{' || *p == '[' || *p == '(') {
         push(t, *p);
      }
      if (*p == '}' || *p == ']' || *p == ')') {
         if (isEmpty(t)) {
            //printf("여기");//
            return 0; 
         }
         char k = pop(t);
         if (!Counterpart(k, *p)) {
            //printf("저기");//
            return 0; 
         }
      }
   }
   //printf("마지막");//
   return isEmpty(t);
}
