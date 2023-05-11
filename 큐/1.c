#include <stdio.h>
#include <stdlib.h>

void queueFullException();
void queueEmptyException();


// return 0 if no exception, else -1.
int enqueue(int* queue, int d);
// return 0 if no exception, else -1.
int dequeue(int* queue);

void print(int* queue);


    int front, rear; // to control queue. set to global variable.
    int size_of_q, n;
int main(){
    scanf("%d", &size_of_q);
    scanf("%d", &n);  // n : number of commands
    getchar();
    int *q = (int *) calloc(size_of_q, sizeof(int));
    if(q == NULL) {
        return -1;
    }

    front = rear = 0; // front& rear pointint

    for(int i = 0; i<size_of_q; i++) q[i] = 0;  // initialize the allocated queue.

    char command;
    int insertvalue;
    int check; // value to check if the request is 200.
    for(int i = 0; i<n; i++){
        scanf("%c", &command); getchar();
        switch(command){
            case 'I':
                scanf("%d", &insertvalue);
                getchar();
                check = enqueue(q, insertvalue);
                if(check == -1){
                    free(q);
                    return 0;
                }
                break;
            case 'P':
                print(q);
                break;
            case 'D':
                check = dequeue(q);
                if(check == -1){
                    free(q);
                    return 0;
                }
                break;
        }
    }

    free(q);
    

    return 0;
}

void queueFullException(){
    printf("overflow");
    return;
}

void queueEmptyException(){
    printf("underflow");
    return;
}

int enqueue(int* queue, int d){
    if((rear+1)%size_of_q == front){
        queueFullException();
        print(queue);
        return -1;
    }

    // normal routine
    rear = (rear+1) % size_of_q;
    queue[rear] = d;

    return 0;
}


int dequeue(int* queue){
    if(rear == front){
        queueEmptyException();
        return -1;
    }

    front = (front+1)%size_of_q;
    int targetvalue = queue[front];
    queue[front] = 0;

    return targetvalue;
}



void print(int* queue){
    for(int i = 0; i<size_of_q; i++) printf(" %d", queue[i]);
    printf("\n");

    return;
}
