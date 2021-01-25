// AVL tree (Dynamic Balancing using AVL)
#include<stdio.h>
#include<stdlib.h>
#include "generic_vector.h"
#include "my_string.h"
 
 //forward declarations
 typedef struct Node tNode;
// An AVL tree node (we have just added a height attribute to a normal BST)
struct Node
{
    // associative array is the keY
    GENERIC_VECTOR hWord_list;
    MY_STRING key;
    tNode *lChild;
    tNode *rChild;
    int nodeHeight; // recall height of node as number of edges to the farthest leaf.
};

//Function declarations
tNode* insertNodes(tNode* node, MY_STRING key,MY_STRING hWord);
tNode* createNode(MY_STRING key,MY_STRING word);
int getHeight(tNode *node);
int getBalancefactor(tNode* node);
int findmax(int x, int y);
tNode *rightRotation(tNode* nodey);
tNode* leftRotation(tNode* nodex);
void inorderTraversal(tNode* root);
void preorderTraversal(tNode* root,int* max);
 
