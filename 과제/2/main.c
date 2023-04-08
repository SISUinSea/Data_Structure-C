// no integer type 'int' will be used in this program. only character 'char'.
// implemented with Header&Trailer Doubly Linked List.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char group;
    char element;
    struct node *prevElement, *nextElement;
    struct node *prevGroup, *nextGroup;
} node;

typedef struct attribute {
    char title;
    node *header, *trailer;
} attribute;


// methods
node *getnode(char elementName, char groupName);
void a(char elementName, char groupName, attribute element, attribute group);
void e(attribute group);
void g(attribute element);
void r(char elementName, char groupName, attribute element, attribute group);

int main(){
    char groupsName[5] = {'A','B','C','D','E'};
    int elementsName[4] = {'1','2','3','4'};

    attribute groups[5];
    for(int i = 0; i<5; i++){
        groups[i].title = groupsName[i];
        // create header&trailer with passing null to its information as to make it header.
        groups[i].header = getnode('h', 'h'); 
        groups[i].trailer = getnode('t', 't');

        (groups[i].header)->nextElement = groups[i].trailer;
        (groups[i].trailer)->prevElement = groups[i].header;
    }

    attribute elements[4];
    for(int i = 0; i<4;i++){
        elements[i].title = elementsName[i];
        elements[i].header = getnode('h','h');
        elements[i].trailer = getnode('t','t');

        (elements[i].header)->nextGroup = elements[i].trailer;
        (elements[i].trailer)->prevGroup = elements[i].header;
    }

    //
    while(1){
        char command;
        char elementData, groupData;
        scanf("%c", &command);
        getchar();
        switch(command){
            case 'a':
                scanf("%c %c", &elementData, &groupData);
                a(elementData, groupData, elements[elementData-'1'], groups[groupData-'A']);
                break;
            case 'r':
                scanf("%c %c", &elementData, &groupData);
                r(elementData, groupData, elements[elementData-'1'], groups[groupData-'A']);
                break;
            case 'e':
                scanf("%c", &groupData);
                e(groups[groupData-'A']);
                break;
            case 'g':
                scanf("%c", &elementData);
                g(elements[elementData-'1']);
                break;
            case 'q':
                return 0;
        }
        getchar();

    }

    // a('1','A',elements['1'-'1'],groups[0]);
    // a('2','A',elements['2'-'1'],groups[0]);
    // a('4','A',elements[0+3],groups[0]);

    // a('4','C',elements['4'-'1'], groups['C'-'A']);
    // a('4','D',elements['4'-'1'], groups['D'-'A']);

    // e(groups['A'-'A']);
    // g(elements['4'-'1']);

    // r('4','A',elements['4'-'1'], groups['A'-'A']);

    // e(groups['A'-'A']);
    // g(elements['4'-'1']);
}


node *getnode(char elementName, char groupName){
    node *newNode = malloc(sizeof(node));
    newNode->group = groupName;
    newNode->element = elementName;

    newNode->prevElement = NULL;
    newNode->nextElement = NULL;
    newNode->prevGroup = NULL;
    newNode->nextGroup = NULL;

    return newNode;
}

/* The right group and element shouold be passed to a when it is being called.*/
void a(char elementName, char groupName, attribute element, attribute group){
    // create node
    node *newnode = getnode(elementName, groupName);
    // connect node
        // connect it with group
    node * T = group.trailer;
    T->prevElement->nextElement = newnode;
    newnode->prevElement = T->prevElement;
    T->prevElement = newnode;
    newnode->nextElement = T;
        // connect it with element
    T = element.trailer;
    T->prevGroup->nextGroup = newnode;
    newnode->prevGroup = T->prevGroup;
    T->prevGroup = newnode;
    newnode->nextGroup = T;
}


void e(attribute group){
    node *p = group.header->nextElement;
    while (p->nextElement != NULL){
        printf("%c ", p->element);
        p = p->nextElement;
    }
    printf("\n");
}


void g(attribute element){
    node *p = element.header->nextGroup;
    while(p->nextGroup != NULL){
        printf("%c ", p->group);
        p = p->nextGroup;
    }
    printf("\n");
}

/* char 'groupName' argument will never be used. But Included as the consistency and readability of code.*/
void r(char elementName, char groupName, attribute element, attribute group){
    node* p = group.header->nextElement;
    // find target node
    node *targetnode = NULL;
    while(p->nextElement != NULL){
        if(p->element == elementName){
            targetnode = p;
            break;
        }
        p = p->nextElement;
    }

    // unconnect
        // unconnect with group first.
    targetnode->prevElement->nextElement = targetnode->nextElement;
    targetnode->nextElement->prevElement = targetnode->prevElement;
        // unconnect with element.
    targetnode->prevGroup->nextGroup = targetnode->nextGroup;
    targetnode->nextGroup->prevGroup = targetnode->prevGroup;

    // remove targenode
    free(targetnode);
}


/*
a 1 C
a 4 A
a 4 E
a 4 D
e A
g 4
a 2 A
e A
r 4 A
g 4
e A
g 1
r 1 C
e C
g 1
g 3
*/