#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int id;
    struct node *left, *right;
} node;


node* getnode(int id);
node* findNodeByID(int id, node* entrynode);

void postOrderToFree(node* tree);

int main(){
    int n; scanf("%d", &n);
    n--;
    int targetID, leftID, rightID;
    scanf("%d %d %d", &targetID, &leftID, &rightID);

    node* tree = getnode(targetID);
    tree->left = getnode(leftID);
    tree->right = getnode(rightID);



    node* targetnode = NULL;
    for(int i = 0; i<n; i++){
        scanf("%d %d %d", &targetID, &leftID, &rightID);

        targetnode = findNodeByID(targetID, tree);
        if(leftID>0) targetnode->left = getnode(leftID);
        if(rightID>0) targetnode->right = getnode(rightID);
    }

    int numberOfCommands;
    char command[100+1], *p;
    node* currentNode;
    scanf("%d", &numberOfCommands); getchar();

    for(int i = 0; i<numberOfCommands; i++){
        currentNode = tree;
        gets(command);
        for(p = command; *p; p++){
            printf(" %d", currentNode->id);
            if(*p == 'L') currentNode = currentNode->left;
            if(*p == 'R') currentNode = currentNode->right;
        }
        printf(" %d", currentNode->id);
        printf("\n");
    }

    postOrderToFree(tree);
}

node* getnode(int id){
    node* newnode = (node*) malloc(sizeof(node));
    newnode->id = id;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node* findNodeByID(int id, node* entrynode){
    node* targetnode = NULL;
    if(entrynode == NULL) return NULL;
    if(entrynode->id == id) return entrynode;

    targetnode = findNodeByID(id, entrynode->left);
    if(targetnode!=NULL) return targetnode;
    targetnode = findNodeByID(id, entrynode->right);
    if(targetnode!=NULL) return targetnode;


    return targetnode;

}


void postOrderToFree(node* entrynode){
    if(!entrynode){
        postOrderToFree(entrynode->left);
        postOrderToFree(entrynode->right);
        free(entrynode);
    }
}


/*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
*/