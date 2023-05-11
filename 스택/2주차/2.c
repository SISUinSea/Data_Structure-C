#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node* next;
} node;

typedef struct stack{
    node* header;
} stack;


node* getnode(int d);
stack* initStack();

void push(stack* s, int d);
int pop(stack *s);


int characterHandler(char c);  // return 0 if the character is operand. return 1 if the character is operation.
int charToInt(char c);  // convert char to int. the input should be '0' - '9'.
int calculator(int a, int b, char c);

int main(){
    int n;
    n = 1;
    scanf("%d", &n);getchar();
    char str[100+1] = {0};
    char *p;

    int a, b;


    //
    for(int i = 0; i<n; i++){
        gets(str);

        stack* s = initStack();

        for(p = str; *p; p++){
            switch(characterHandler(*p)){
                case 0:
                    // printf("[IN_SWITCH]: %c is operand\n", *p);
                    // case if the character is operand.(0-9)
                    push(s, charToInt(*p));
                    break;
                case 1:
                    // printf("[IN_SWITCH]: %c is operator\n", *p);
                    // case if the character is operator (+-*/)
                    a = pop(s);
                    b = pop(s);
                    push(s, calculator(a, b, *p));
                    break;
                default:
                    break;
            }
        }
        printf("%d\n", pop(s));
    }
    
}

node* getnode(int d){
    node* n = (node *) malloc(sizeof(node));
    n->elem = d;
    n->next = NULL;

    return n;
}

stack* initStack(){
    stack* s = (stack*) malloc(sizeof(stack));

    s->header = getnode(-1);

    return s;
}


void push(stack* s, int d){
    node* newnode = getnode(d);
    newnode->next = s->header->next;
    s->header->next = newnode;

    return;
}

int pop(stack *s){
    node* targetnode = NULL;
    targetnode = s->header->next;
    if(!targetnode) {
        return -1;
    }
    int targetvalue = targetnode->elem;
    s->header->next = targetnode->next;
    free(targetnode);


    return targetvalue;
}


int characterHandler(char c){
    if(c-'0'>= 0 && c-'0'<=9) return 0;
    else return 1;
}

int charToInt(char c){
    return c-'0';
}

int calculator(int a, int b, char c){
    int result;
    switch (c)
    {
    case '+':
        result = a+b;
        break;
    case '-':
        result = b-a;
        break;
    case '*':
        result = a*b;
        break;
    case '/':
        result = b/a;
        break;
    default:
        break;
    }

    return result;
}

/*
53*2+63+2*+ 
*/