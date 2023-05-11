#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size =0;
typedef struct Node {
   char data;
   struct Node* next;
}Node;

Node* getnode(char data) {
   Node* node = (Node*)malloc(sizeof(Node));
   if (node == NULL) return -1;
   node->data = data;
   node->next = NULL;
   return node;
}

typedef struct Stack {
   Node* top;
}Stack;

Stack* initialize() {
   Stack* s = (Stack*)malloc(sizeof(Stack));
   if (s == NULL) return -1;
   s->top = NULL;
   return s;
}

void push(Stack* s, char data) {
   Node* n = getnode(data);
   if (s->top == NULL) {
      s->top = n;
   }
   else {
      n->next = s->top;
      s->top = n;
   }
   size++;
}

int top(Stack* s) {
   if (s->top == NULL) return -1;
   else return s->top->data;
}

void pop(Stack* s) {
   if (s->top == NULL) return -1;
   Node* p = s->top;
   s->top = s->top->next;
   free(p);
   size--;
}

int isOperand(char o) {
   if (o == '!' || o == '*' || o == '/' || o == '+' || o == '-' || o == '>' || o == '<' || o == '&' || o == '|' ||o=='('||o==')') return 0; //not operand
   else return 1; //operand
}

int isOperator(char* input, char* p, char o) {
   if (o == '!') return 6;
   else if ((o == '+' || o == '-') && input < p && !isOperand(*(p - 1)))return 6;
   else if (o == '*' || o == '/')return 5;
   else if (o == '+' || o == '-')return 4;
   else if (o == '>' || o == '<')return 3;
   else if (o == '&') return 2;
   else if (o == '|') return 1;
   else if (o == '(') return 0;
}


int main() {
   Stack* s = initialize();
   int n;
   char input[101] = { 0 }, *p;


   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      scanf("%s", input); getchar();
      p = input;

      while (*p) {//식의 끝까지


         if (isOperand(*p)) {
            //printf("operand\n");
            printf("%c", *p);
            p++;
         }

         else if( *p == '(') {
            //printf("else if(\n");
            push(s, *p);
            p++;
         }
         else if ( *p == ')') {
            //printf("else if)\n");
            while (top(s) != '(') {
               if (top(s) == '&') {
                  printf("&&");  pop(s);
               }
               else if (top(s) == '|') {
                  printf("아아||");  pop(s);
               }
               else {
                  printf("%c", top(s)); pop(s);
               }
            }
            pop(s);
            p++;
         }
         else {
            //printf("else\n");
            while (s->top != NULL && isOperator(input, p, *p) <= isOperator(input, 0, top(s))) {//연산자 우선순위 중요
               if (top(s) == '&') {
                  printf("&&");  pop(s);
               }
               else if (top(s) == '|') {
                  printf("||");  pop(s);
               }
               else {
                  printf("%c", top(s)); pop(s);
               }
            }
            push(s,*p);
            if (*p == '&' || *p == '|') p += 2;
            else p++;
         }


      }


      while (s->top != NULL) {
         if (top(s) == '&') {
            printf("&&");  pop(s);
         }
         else if (top(s) == '|') {
            printf("||");  pop(s);
         }
         else {
            printf("%c", top(s)); pop(s);
         }
      }
      printf("\n");

   }

   free(s);
   return 0;
}

/*



5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)


*/