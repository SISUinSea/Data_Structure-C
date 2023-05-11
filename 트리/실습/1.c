#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;



treeNode* insertNode(int data, treeNode* left, treeNode* right);


void printNodeData(treeNode* targetNode);

int main(){
    treeNode* F[8];
    F[8 -1] = insertNode(80, NULL, NULL);
    F[7 -1] = insertNode(130, NULL, NULL);
    F[6 -1] = insertNode(120, F[7 -1], F[8 -1]);

    F[4 -1] = insertNode(70, NULL, NULL);
    F[5 -1] = insertNode(90, NULL, NULL);
    F[2 -1] = insertNode(30, F[4 -1], F[5 -1]);

    F[3 -1] = insertNode(50, NULL, F[6 -1]);

    F[1 -1] = insertNode(20, F[2 -1], F[3 -1]);


    



    // free tree 
    for(int i = 8-1; i>= 0; i--) free(F[i]);


}

treeNode* insertNode(int data, treeNode* left, treeNode* right){
    treeNode* newNode = (treeNode*) malloc(sizeof(treeNode));

    newNode->data = data;
    newNode->left = left;
    newNode->right = right;

    return newNode;
}




void printNodeData(treeNode* targetNode){

}
