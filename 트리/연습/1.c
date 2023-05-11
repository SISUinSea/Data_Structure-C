/* Implementing Proper binary tree */

#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    char elem;
    struct treenode* left;
    struct treenode* right;
} treenode;

treenode* insertNode(char elem, treenode* left, treenode*right);
treenode* treeBuild();

int main(){
    treenode* root = treeBuild();
}

treenode* insertNode(char elem, treenode* left, treenode*right){
    treenode* newnode = (treenode*) malloc(sizeof(treenode));
    // if(!newnode) {
    //     return -1;
    // }

    newnode->elem = elem;
    newnode->left = left;
    newnode->right = right;

    return newnode;
}

 

treenode* treeBuild(){
    treenode* n1 = insertNode('H', NULL, NULL);
    treenode* n2 = insertNode('I', NULL, NULL);
    treenode* n3 = insertNode('E', n1, n2);
    treenode* n4 = insertNode('D', NULL, NULL);
    treenode* n5 = insertNode('B', n3, n4);
    treenode* n6 = insertNode('F', NULL, NULL);
    treenode* n7 = insertNode('G', NULL, NULL);
    treenode* n8 = insertNode('C', n6, n7);
    treenode* n9 = insertNode('A', n5, n8);
}
