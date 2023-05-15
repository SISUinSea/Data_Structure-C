#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    char elem;
    struct node *next;
    int priority;
} node;

typedef struct stack 
{
    node *header;
    // int size;
} stack;


node* getnode(char c);
stack* initstack();
void push(stack* stack, char *c, char *instruction);
char pop(stack* stack);
char peek(stack* stack);
int peekPriority(stack* stack);
int isEmpty(stack* stack);


int isOperand(char c); // return 1 if the character is operand. else return 0 (operator).



int operatorPriority(char *c, char *instruction);

int main(){
    stack *s = initstack();

    char instruction[100+1] = {0};

    int n;
    n = 1;
    scanf("%d", &n);getchar();
    for(int i = 0; i<n;i++){
        scanf("%s", instruction);

        for(char *p = instruction; *p; p++){
            if(isOperand(*p)){
                printf("%c", *p);
            } else if( *p == '('){
                push(s, p, instruction);
            } else if( *p == ')'){
                while(peek(s) != '('){
                    char printedResult = pop(s);
                    printf("%c", printedResult);
                    if(printedResult == '&' || printedResult == '|'){
                        printf("%c", printedResult);
                    }
                }
                pop(s);
            } else { // *p is an operator
                while(!isEmpty(s) && operatorPriority(p, instruction) <= peekPriority(s)){
                    char printedResult = pop(s);
                    printf("%c", printedResult);
                    if(printedResult == '|' || printedResult == '&'){
                        printf("%c", printedResult);
                    }
                }
                push(s, p, instruction);
            }

            if(*p == '|' || *p == '&') {
                p++;
            }
        }
            while(!isEmpty(s)){
                char printedResult = pop(s);
                printf("%c", printedResult);
                if(printedResult == '|' || printedResult == '&'){
                    printf("%c", printedResult);
                }            
            }
            printf("\n");

    }


}
node* getnode(char c){
    node *newnode = (node*) malloc(sizeof(node));
    newnode->elem = c;
    newnode->next = NULL;

    return newnode;
}

stack* initstack(){
    stack* s = (stack*) malloc(sizeof(stack));
    s->header = getnode(0);
    // s->size = 0;

    return s;
}
 // return 1 if the character is operand. Else return 0 (operator +-*/ etc).
int isOperand(char c){
    if(c == '(' || c == '*' || c == '/' || c == '+' || c == '-' || c == ')' || c == '!' || c == '&' || c == '|' || c == '<' || c == '>'){
        return 0;
    }
    else return 1;
}



int operatorPriority(char *c, char *instruction){
    int priority;
    switch(*c){
        case '!':
            priority = 6;
            break;
        case '*':
        case '/':
            priority = 5;
            break;
        case '+':
        case '-':
            priority = 4;
            break;
        case '<':
        case '>':
            priority = 3;
            break;
        case '&':
            priority = 2;
            break;
        case '|':
            priority = 1;
            break;
        case '(':
            priority = 0;
            break;
    }
    if(c == instruction  && (*c=='+' || *c=='-')){
        priority = 6;
    }
    else if(isOperand(*(c-1)) == 0 && (*c == '+' || *c == '-') && *(c-1)!= ')') {
        priority = 6;
    }

    return priority;
}

// return 1 if empty, else return 0.
int isEmpty(stack* stack){
    return stack->header->next == NULL;
}

void push(stack* stack, char *c, char *instruction){
    node* newnode = getnode(*c);

    newnode->next = stack->header->next;
    stack->header->next = newnode;
    newnode->priority = operatorPriority(c, instruction);

    return ;
}




char pop(stack* stack){
    node* targetnode  = NULL;
    targetnode = stack->header->next;
    if(targetnode == NULL) return '\0';

    char targetvalue = targetnode->elem;

    // decoupling target node
    stack->header->next = targetnode->next;
    free(targetnode);

    return targetvalue;
}

char peek(stack* stack){
    if(isEmpty(stack)) return '\0';

    return stack->header->next->elem;
}

int peekPriority(stack* stack){
    if(isEmpty(stack)) return '\0';

    return stack->header->next->priority;
}