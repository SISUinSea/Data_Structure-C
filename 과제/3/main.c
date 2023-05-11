#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    int elem;
    struct node* next;
    int minsofar;
} node;

typedef struct stack
{
    node* header;
    int len;
} stack;





node* getnode(int d);
stack* initstack();


void stackEmptyException();
// int peek(node* header);


void push(stack* stack, int d);
int pop(stack* stack); 

void pushMillion(stack *stack);
int popMillion(stack *stack);
int findMin(stack* stack);
void freeStack(stack* stack);



int main(){
    stack* stack = initstack();

    int  d;
    double start, end;
    char command;


    while(1){
        scanf("%c", &command); getchar();
        if (command == 'p') {
            scanf("%d", &d);
            getchar();

            start = (double)clock() / CLOCKS_PER_SEC;              // record start
            push(stack, d);
            end = (((double)clock()) / CLOCKS_PER_SEC);            // record end


            printf("push ");
            printf("%d ", d);
            printf("(%d), ", stack->len);

            printf("cputime = %.10lf", (end-start) );
        }
        else if (command == 'o') {

            start = (double)clock() / CLOCKS_PER_SEC;              // record start
            d = pop(stack);
            end = (((double)clock()) / CLOCKS_PER_SEC);            // record end


            printf("pop ");
            if(d == -1)
                printf("Stack Empty ");
            else 
                printf("%d ", d);
            printf("(%d), ", stack->len);

            printf("cputime = %.10lf", (end-start) );
        }
        else if (command == 'P') {

            start = (double)clock() / CLOCKS_PER_SEC;              // record start
            pushMillion(stack);
            end = (((double)clock()) / CLOCKS_PER_SEC);            // record end


            printf("pushMillion ");
            printf("(%d), ", stack->len);

            printf("cputime = %.10lf", (end-start) );
        }
        else if (command == 'O') {

            start = (double)clock() / CLOCKS_PER_SEC;              // record start
            popMillion(stack);
            end = (((double)clock()) / CLOCKS_PER_SEC);            // record end


            printf("popMillion ");
            printf("(%d), ", stack->len);

            printf("cputime = %.10lf", (end-start) );
        }
        else if (command == 'f') {

            start = (double)clock() / CLOCKS_PER_SEC;              // record start
            d = findMin(stack);
            end = (((double)clock()) / CLOCKS_PER_SEC);            // record end


            printf("min ");
            printf("%d ", d);
            printf("(%d), ", stack->len);

            printf("cputime = %.10lf", (end-start) );
        } else if(command == 'q'){
            freeStack(stack);
            free(stack);
            printf("(프로그램 종료)");
            return 0;
        }
        

    }
}


node* getnode(int d){
    node* n = (node *) malloc(sizeof(node));
    n->elem = d;
    n->next = NULL;

    return n;
}


stack* initstack(){
    stack* s = (stack*) malloc(sizeof(stack));
    s->header = getnode(-1);
    s->len = 0;
    return s;
}

// int peek(node* header){
//     if(header->next == NULL){
//         stackEmptyException();
//         return 100000;
//     }
//     return header->next->elem;
// }

void push(stack* stack, int d){
    stack->len++;
    // 새 노드 만들기
    node* newnode = getnode(d);
    // 비어있는지 확인 -> 비어있다면 d를 minsofar로 넣기
    node* top = stack->header->next;
    if(top == NULL) { // header의 next가 NULL 이라면
        newnode->minsofar = d;
    }
    // 차 있다면 top의 minsofar과 d를 비교. 더 작은 값을 새 노드의 minsofar로 넣기
    else {
        if(d < top->minsofar){
            newnode->minsofar = d;
        } else {
            newnode->minsofar = top->minsofar;
        }
    }
    // 새 노드를 stack의 top으로 연결
    newnode->next = top;
    stack->header->next = newnode;

    return ;
}


int pop(stack* stack){
    // targeting the top node.
    node* targetnode = stack->header->next;
    if(targetnode == NULL || stack->len <= 0) {
        stackEmptyException();
        return -1;
    }

    stack->len -= 1;
    // decoupling with the target node.
    stack->header->next = targetnode->next;


    int targetvalue = targetnode->elem;
    
    // free the target node.
    free(targetnode);
    
    return targetvalue;
}


int findMin(stack* stack){
    if(stack->header->next == NULL) {
        stackEmptyException();
        return -1;
    }

    return stack->header->next->minsofar;
}


void pushMillion(stack *stack){
    srand(time(NULL));
    for(int i = 0; i<1000000; i++){
        push(stack, rand()%9000+1000);
    }
}


int popMillion(stack* stack) { // return 0 if the routine fail, else return 1.
    if ( stack->len >= 1000000){
        for(int i = 0; i<1000000; i++){
            pop(stack);
        }

        return 1;
    }
    return 0;
}


void stackEmptyException(){
    return ;
}

void freeStack(stack* stack){
    node *p, *boom;
    p = stack->header;
    while(p){
        boom = p;
        p = p->next;
        free(boom);
    }

}
