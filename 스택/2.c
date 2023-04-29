#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    char element;
    struct node* next;
}node;

typedef struct stack{
    node* header;
} stack;

node *getnode(char c){
    node* newnode = (node *) malloc(sizeof(node));
    newnode->next = NULL;
    newnode->element = c;
    return newnode;
}

stack* initStack(){
    stack* newstack = (stack *) malloc(sizeof(stack));
    newstack->header = getnode(0);

    return newstack;
}

void push(stack* s, char c); /* header will always pointing the top of the stack.*/
char pop(stack *s);
char peek(stack* s);
void traverse(stack *s);

int openOrCloseOrNone(char c); /* open : 1, close : -1, none : 0 */
int closeCharacterHandler(stack *stack, char c); /* if return value is -1, break program with printing 'Wrong_N'.*/


int main(){
    stack *s = initStack();
    // push(s, 'a');
    // push(s, 'a');
    // push(s, 'a');
    // pop(s);
    // pop(s);
    // pop(s);
    /* get string from user*/
    char str[1000+1];

    gets(str);
    // puts(str);

    int counter = 0;/* counter will be used for counting open/close characters. */

    char *c = NULL;
    for(c = str; *c; c++){
        switch(openOrCloseOrNone(*c)){
            case 1:
                counter++;
                push(s, *c);
                break;
            case -1:
                counter++;
                if(closeCharacterHandler(s, *c) == -1){
                    printf("Wrong_%d\n", counter);
                    return 0;
                }
                break;
            default:
                break;
        }
    }

    if(s->header->next == NULL){
        printf("OK_%d\n", counter);
    }else {
        printf("Wrong_%d\n", counter);
    }
}

void push(stack* s, char c){
    node *h = s->header;
    node *newnode = getnode(c);
    newnode->next = h->next;
    h->next = newnode;

    return ;
}


char pop(stack *s){
    if(s->header->next == NULL){
        return 0;
    }
    node *targetnode = s->header->next;
    char targeValue = targetnode->element;
    s->header->next = targetnode->next;
    free(targetnode);

    return targeValue;
}

char peek(stack* s){
    if(s->header->next == NULL) return 0;
    return s->header->next->element;
}

void traverse(stack *s){
    node *p = s->header->next;
    while(p){
        printf("%c", p->element);
        p = p->next;
    }
}


int openOrCloseOrNone(char c){
    if(c == '(' || c == '[' || c =='{'){
        return 1;
    }else if(c == ')' || c == ']' || c =='}'){
        return -1;
    } else {
        return 0;
    }
}

int closeCharacterHandler(stack *stack, char c){
    if(stack->header->next == NULL){ /* return -1 if stack is empty. */
        return -1;
    }

    char top = stack->header->next->element;
    if( /* end method with exit code 1 if the characters are matched. */
        c==')' && top=='(' ||
        c==']' && top=='[' ||
        c=='}' && top=='{'
    ) {
        pop(stack);
        return 1; 
    } else { /* if characters are not matched, exit program with code -1. */
        return -1;
    }
}

