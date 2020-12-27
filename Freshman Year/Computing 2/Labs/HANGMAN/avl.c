#include "avl.h"

/*
insert key in subtree rooted with node and returns new root of subtree.
*/
tNode* insertNodes(tNode* node,MY_STRING key,MY_STRING hWord) 
{
  int i=0;
    /*BST insertion -usual technique , refer to notes */

  if (node == NULL){

    return (createNode(key,hWord));
  }

  if (my_string_compare(node->key,key)<0){
      node->lChild  = insertNodes(node->lChild, key,hWord);
	}

  else if (my_string_compare(node->key,key)>0){
      node->rChild = insertNodes(node->rChild, key,hWord);
    }
  else if(my_string_compare(node->key,key)==0){
    // my_string_insertion(hWord,stdout);
    generic_vector_push_back(node->hWord_list,hWord);
    return node;
  }
   
  
   node->nodeHeight = 1 + findmax(getHeight(node->lChild),getHeight(node->rChild));
    
//  B. calculate balance factor (hLeft-hRigh)
      int balance = getBalancefactor(node);
 
// *IF Node is unbalance, i.e balance is >1 or <-1, then it could be: 
 
// 1. LEFT LEFT CASE (In this case, just rotate once on the RIGHT)
    if (balance > 1 && my_string_compare(key,node->lChild->key)<0)
      return rightRotation(node);
 
//  2. RIGHT RIGHT CASE (In this case, just rotate once on the left)
   if (balance < -1 && my_string_compare(key,node->rChild->key) > 0)
     return leftRotation(node);
 
    if (balance > 1 &&  my_string_compare(key,node->lChild->key) > 0)
      {
    node->lChild =  leftRotation(node->lChild); //To make it a LEFT LEFT CASE
        return rightRotation(node);
    }
 
//  4. RIGHT - LEFT CASE
     if (balance < -1 &&  my_string_compare(key,node->rChild->key) < 0)
       {
	 node->rChild = rightRotation(node->rChild);//To make it a RIGHT RIGHT CASE
	      return leftRotation(node);
       }


 
    /* return the (unchanged) node pointer */
    return node;
 
}
/* Create a new node with the given key and NULL lChild and rChild pointers */
tNode* createNode(MY_STRING key,MY_STRING word)
{
    tNode* node = (tNode*) malloc(sizeof(tNode));
    if(node==NULL){
      printf("failed to allocate memory\n");
      exit(-1);
    }
    //   key = my_string_init_default();
    node->key = NULL;
    node->hWord_list = NULL;
    my_string_assignment(&node->key,key);
    //my_string_insertion(node->key,stdout);
    node->hWord_list = generic_vector_init_default(my_string_assignment,my_string_destroy);
    generic_vector_push_back(node->hWord_list,word);
    node->lChild   = NULL;
    node->rChild  = NULL;
    node->nodeHeight = 1;  //assume that node is added at leaf
    return(node);
}
// A get method for height of the node
int getHeight(tNode *node)
{
    if (node == NULL)
        return 0;
    return node->nodeHeight;
}

// Calculates and returns the balance factor
int getBalancefactor(tNode* node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->lChild) - getHeight(node->rChild);
}

// This should show a sorted out tree(recall from last class)
void inorderTraversal(tNode *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->lChild);
         
	//my_string_insertion(my_string_at(root->key,i),stdout);
	 
        inorderTraversal(root->rChild);
    }
}
// This should show tree with root first (recall from last class)
void preorderTraversal(tNode *root,int* max)
{

    if(root != NULL)
    {
      
      
      /*  if(generic_vector_get_size(root->hWord_list)>*max){
      *max =  generic_vector_get_size(root->hWord_list);
     //  MAX_VECTOR =&(root->hWord_list);
     } */
      printf("%d\n",generic_vector_get_size(root->hWord_list));
      my_string_insertion(root->key,stdout);
      preorderTraversal(root->lChild,max);
      preorderTraversal(root->rChild,max);
    }
}
 
// Rotate Right
tNode *rightRotation(tNode* nodey)
{
    tNode* nodex = nodey->lChild;
    tNode* T2 = nodex->rChild;
 
    // Rotate RIGHT
    nodex->rChild = nodey;
    nodey->lChild = T2;
 
    // Update heights
    nodey->nodeHeight = findmax(getHeight(nodey->lChild), getHeight(nodey->rChild))+1;
    nodex->nodeHeight = findmax(getHeight(nodex->lChild), getHeight(nodex->rChild))+1;
 
    // Return new root
    return nodex;
}
 
// rotate LEFT subtree rooted with a nodex
tNode* leftRotation(tNode* nodex)
{
    tNode* nodey = nodex->rChild;
    tNode* T2 = nodey->lChild;
 
    // Rotate LEFT
    nodey->lChild = nodex;
    nodex->rChild = T2;
 
    //  Update height of nodes
    nodex->nodeHeight = findmax(getHeight(nodex->lChild), getHeight(nodex->rChild))+1;
    nodey->nodeHeight = findmax(getHeight(nodey->lChild), getHeight(nodey->rChild))+1;
 
    // Return new root
    return nodey;
}

// return the largest value (used for height comparison)
int findmax(int x, int y)
{
    return (x > y)? x : y;
}
void search(tNode *root,MY_STRING new_key){

  
  
}


 
