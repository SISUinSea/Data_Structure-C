#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
   char *elements;
   int t;
   int len;
} stack;



void stackFullException();
void stackEmptyException();

stack * getStack(int n);
void push(stack *stack, char element);
char pop(stack *stack);
void peek(stack *stack);
void duplicate(stack *stack);
void upRotate(stack *stack, int n);
void downRotate(stack *stack, int n);
void print(stack *stack);


int main(){
   int n;
   scanf("%d", &n);
   stack *stack = getStack(n);

   push(stack, 'a');
   push(stack, 'p');
   duplicate(stack);
   push(stack, 'l');
   push(stack, 'e');


   print(stack);

   // free stack
}

void stackFullException(){
   printf("Stack FULL\n");
}
void stackEmptyException(){
   printf("Stack Empty\n");
}

void push(stack* stack, char element){
   if(stack->len-1<=stack->t){
      stackFullException();
      return;
   }
   stack->t++;
   stack->elements[stack->t] = element;

   return ;
}

stack * getStack(int n){
   stack *s = (stack *) malloc(sizeof(stack));
   s->len=n;
   s->t = -1;

   s->elements = (char *) malloc(n * sizeof(char));


   return s;
}


char pop(stack *stack){
   if(stack->t < 0){
      stackEmptyException();
      return 0;
   }
   char target = stack->elements[stack->t];
   stack->t--;

   return target;
}


void peek(stack *stack){
   if(stack->t < 0){
      stackEmptyException();
      return ;
   }

   printf("%c\n", stack->elements[stack->t]);
   return ;
}


void duplicate(stack *stack){
   char c;
   c = pop(stack);
   push(stack, c);
   push(stack, c);
}


void upRotate(stack *stack, int n){
   char last;
   int i;
   last = stack->elements[stack->t];
   for(i = stack->t-1; i>= 0; i--){
      stack->elements[i+1] = stack->elements[i];
   }
   stack->elements[0] = last;

   return ;
}


void print(stack *stack){
   for(int i = 0; i<=stack->t; i++){
      printf("%c", stack->elements[i]);
   }
   printf("\n");
}
