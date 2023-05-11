#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

   int numberOfCommands;
   scanf("%d", &numberOfCommands);
   getchar();


   for (int i = 0; i < stack->len; i++){
      stack->elements[i] = 0;
   }
   

   char command[5+1];
   int rotateNumber;
   for(int i = 0;i <numberOfCommands; i++){
      scanf("%s", command);
      getchar();
      if(strcmp(command, "POP") == 0){
         pop(stack);
      } else if(strcmp(command, "PUSH") == 0){
         char element;
         scanf("%c", &element);
         getchar();
         push(stack, element);
      } else if(strcmp(command, "PRINT") == 0){
         print(stack);
      } else if(strcmp(command, "UpR") == 0){
         scanf("%d", &rotateNumber);
         getchar();
         upRotate(stack, rotateNumber);
      } else if(strcmp(command, "DownR") == 0){
         scanf("%d", &rotateNumber);
         getchar();
         downRotate(stack, rotateNumber);
      } else if(strcmp(command, "PEEK") == 0){
         peek(stack);
      } else if(strcmp(command, "DUP")==0){
         duplicate(stack);
      }
   }

   // free stack
   free(stack->elements);
   free(stack);
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

   if(stack->t >= stack->len-1){
      stackFullException();
      return;
   }
   if(stack->t < 0) {
      stackEmptyException();
      return ;
   }
   char c;
   c = pop(stack);
   push(stack, c);
   push(stack, c);
}


void upRotate(stack *stack, int n){
   if(n>stack->t+1){
      return ;
   }
   char *bus = (char *) calloc(n, sizeof(char));
   if(!bus){
      return ;
   }

   for(int i = 0; i<n; i++){
      bus[i] = pop(stack);
   }

   push(stack, bus[0]);
   for(int i = n-1; i>0; i--){
      push(stack, bus[i]);
   }

   free(bus);

}


void downRotate(stack *stack, int n){
   if(n>stack->t+1){
      return ;
   } 
   char *bus = (char *) calloc(n, sizeof(char));
   if(!bus){
      return ;
   }

   for(int i = 0; i<n; i++){
      bus[i] = pop(stack);
   }

   for(int i = n-2; i>=0 ; i--){
      push(stack, bus[i]);
   }
   push(stack, bus[n-1]);

   free(bus);
}



void print(stack *stack){
   for(int i = stack->t; i>= 0; i--){
      printf("%c", stack->elements[i]);
   }
   printf("\n");
}
