#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int elem;
    struct node *left, *right;
    int id;
} node;

typedef struct tree {
    node* root;
} tree;


node* getnode(int d, int id, node* left, node* right);
tree* buildTree();
void freeNode(node* entryNode);


node* findNodeByID(int nodeID, node* nodeP);
void preOrder(node* entryNode);
void postOrder(node* entryNode);
void inOrder(node* entryNode);


int main(){
    tree* tree = buildTree();
    int targetID, orderNumber;
    scanf("%d %d", &orderNumber, &targetID);

    node* entrynode = findNodeByID(targetID, tree->root);
    if(!entrynode) {
        printf("-1\n");
        freeNode(tree->root);
        free(tree);
        return 0;
    }
    switch (orderNumber)
    {
    case 1:
        preOrder(entrynode);
        break;
    case 2:
        inOrder(entrynode);
        break;
    case 3:
        postOrder(entrynode);
        break;
    
    default:
        break;
    }
    freeNode(tree->root);
    free(tree);
}


node* getnode(int d, int id, node* left, node* right){
    node* newnode = (node*) malloc(sizeof(node));
    newnode->elem = d;
    newnode->id = id;
    newnode->left = left;
    newnode->right = right;

    return newnode;
}


tree* buildTree(){
    tree *t = (tree*) malloc(sizeof(tree));

    node* n8 = getnode(80, 8, NULL, NULL);
    node* n7 = getnode(130, 7, NULL, NULL);
    node* n6 = getnode(120, 6, n7, n8);

    node* n4 = getnode(70, 4, NULL, NULL);
    node* n5 = getnode(90, 5, NULL, NULL);
    node* n2 = getnode(30, 2, n4, n5);
    node* n3 = getnode(50, 3, NULL, n6);

    node* n1 = getnode(20, 1, n2, n3);

    t->root = n1;
    return t;
}


node* findNodeByID(int nodeID, node* nodeP){
    node* targetnode = NULL;
    if(nodeP != NULL){
        if(nodeP->id == nodeID) return nodeP;

        targetnode = findNodeByID(nodeID, nodeP->left); // searching left child
        if(targetnode != NULL) return targetnode;
        targetnode = findNodeByID(nodeID, nodeP->right); // searching right child
        if(targetnode != NULL) return targetnode;
    }
    return NULL;
}



void preOrder(node* entryNode){
    if(entryNode){
        printf(" %d", entryNode->elem);
        preOrder(entryNode->left);
        preOrder(entryNode->right);
    }
}

void postOrder(node* entryNode){
    if(entryNode){
        postOrder(entryNode->left);
        postOrder(entryNode->right);
        printf(" %d", entryNode->elem);
    }
}


void inOrder(node* entryNode){
    if(entryNode){
        inOrder(entryNode->left);
        printf(" %d", entryNode->elem);
        inOrder(entryNode->right);
    }
}


void freeNode(node* entryNode){
    if(entryNode){
        freeNode(entryNode->left);
        freeNode(entryNode->right);
        free(entryNode);
    }
}
