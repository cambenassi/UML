#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include "avl.h"

void ckb(void);
int main(void){
  
  GENERIC_VECTOR array[31];
  FILE* fp = fopen("dictionary.txt", "r");
  MY_STRING temp = my_string_init_default();
  int size, numGuesses;
  char show;
  
  for(int i = 0; i <= 30; i++){
    array[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
  }
  
  while(my_string_extraction(temp, fp)){
    size = my_string_get_size(temp);
    generic_vector_push_back(array[size], temp);
  }

  printf("How many letters are in your word?\n");
  scanf("%d", &size);
  ckb();
  printf("How many guesses would you like?\n");
  scanf("%d", &numGuesses);
  ckb();
  printf("Would you like to show remaining words? (y/n)\n");
  scanf("%c", &show);
  ckb();

  //game portion

  char guess;
  MY_STRING word_family = my_string_init_default(), new = my_string_init_default();
  GENERIC_VECTOR MWL = generic_vector_init_default(my_string_assignment, my_string_destroy), newList = generic_vector_init_default(my_string_assignment, my_string_destroy);
  tNode *Node = NULL;
  //GENERIC_VECTOR newest = generic_vector_init_default(my_string_assignment, my_string_destroy);

  for(int i = 0; i < size; i++)
    my_string_push_back(word_family, '_');
  for(int i = 0; i < generic_vector_get_size(array[size]); i++)
    generic_vector_push_back(MWL, generic_vector_at(array[size], i));
  for(int i = 0; i <= 30; i++)
    generic_vector_destroy(&array[i]);

  printf("You have %d remaining guesses.\n", numGuesses);
  printf("Word: ");
  my_string_insertion(word_family, stdout);
  printf("\n");
  
  while(numGuesses > 0){
    printf("Enter guess: ");
    scanf("%c", &guess);
    ckb();

    printf("You have %d remaining guesses.\n", numGuesses - 1);
    
    for(int j = 0; j < generic_vector_get_size(MWL); j++){      
      get_word_key_value(word_family, new, generic_vector_at(MWL, j), guess);
      Node = createNode(new, generic_vector_at(MWL, j));
      Node = insertNodes(Node, new, generic_vector_at(MWL, j));
      my_string_insertion(generic_vector_at(MWL, j), stdout);
      printf(": ");
      my_string_insertion(new, stdout);
      printf("\n");

      my_string_destroy(&new);
      new = my_string_init_default();
    }

    
    numGuesses--;
  }

  /*
  for(i = 0; i < generic.size(MWL); i++){//after guess
    getkey(word_family, new, generic[i]), guess)
    AVL my_tree;
    my_tree = insert(my_tree, new, word);
    generic2 = find_greatest(my_tree);//store greatest in another generic vector
    get_key(generic2);
    tree_destroy(my_tree);
    word_family = generic2;
  }

  */
  fclose(fp);

  generic_vector_destroy(&MWL);
  my_string_destroy(&word_family);
  my_string_destroy(&new);
  my_string_destroy(&temp);
  
  return 0;
}

void ckb(void){
  char c;
  scanf("%c",&c);
  while(c!='\n'){
     scanf("%c",&c);
  }
  
}
