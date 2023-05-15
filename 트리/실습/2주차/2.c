#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int elem, id;
    struct node *left, *right;
} node;


node* getnode(int d, int id, node* left, node* right);
node* buildTree();
void freeNode(node* entryNode);


node* findNodeByID(int nodeID, node* nodeP);
int postOrderToCalculateTotalVolume(node* entryNode);


int main(){
    node* tree = buildTree();
    int nodeID;
    scanf("%d", &nodeID);

    node* entryNode = findNodeByID(nodeID, tree);
    if(!entryNode) {
        printf("-1");
        freeNode(tree);
        return 0;
    }

    printf("%d", postOrderToCalculateTotalVolume(entryNode));
    freeNode(tree);

    return 0;
}

node* getnode(int d, int id, node* left, node* right){
    node* newnode = (node*) malloc(sizeof(node));
    newnode->elem = d;
    newnode->id = id;
    newnode->left = left;
    newnode->right = right;

    return newnode;
}


node* buildTree(){
    node* t;

    node* n8 = getnode(80, 8, NULL, NULL);
    node* n7 = getnode(130, 7, NULL, NULL);
    node* n6 = getnode(120, 6, n7, n8);

    node* n4 = getnode(70, 4, NULL, NULL);
    node* n5 = getnode(90, 5, NULL, NULL);
    node* n2 = getnode(30, 2, n4, n5);
    node* n3 = getnode(50, 3, NULL, n6);

    node* n1 = getnode(20, 1, n2, n3);

    t = n1;
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

int postOrderToCalculateTotalVolume(node* entryNode){
    int totalSum = 0;
    if(entryNode){
        totalSum += postOrderToCalculateTotalVolume(entryNode->left);
        totalSum += postOrderToCalculateTotalVolume(entryNode->right);
        totalSum += entryNode->elem;
    } 

    return totalSum;
}



void freeNode(node* entryNode){
    if(entryNode){
        freeNode(entryNode->left);
        freeNode(entryNode->right);
        free(entryNode);
    }
}
