#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

MY_STRING my_string_init_default(void)
{
    string *pString;

    pString = (string *) malloc (sizeof (string));
    if (pString) {
        pString->size = 0;
        pString->capacity = 1;
        pString->data = (char *) malloc (sizeof(char) * pString->capacity);
        if (!pString->data) {
            free (pString);
            return NULL;
        }
    }
    return (MY_STRING) pString;
}

void my_string_destroy(ITEM* pItem)
{
  string *pString = (string *) *pItem;

  free(pString->data);
  free(pString);
  *pItem = NULL;

  
  /*
  //OLD
  string *pString = (string *) *phMy_string;
 
  free(pString->data);
  free(pString);
  *phMy_string = NULL;
  */
}

MY_STRING my_string_init_c_string(const char*c_string)
{
  int length = strlen(c_string);
  string *newString;

  newString = (string *) malloc (sizeof (string));
  if (newString) {
    newString->size = 0;
    newString->capacity = length + 1;
    newString->data = (char *) malloc (sizeof(char) * newString->capacity);
    if(!newString->data) {
      free (newString);
      return NULL;
    }
    for (int i = 0; i < length; i++){
      newString->data[i] = c_string[i];
      newString->size++;
    }
  }
  return (MY_STRING) newString;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  string *newString = (string *) hMy_string;
  return newString->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
  string *newString = (string *) hMy_string;
  return newString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{  
  string* pLeft = (string*)hLeft_string;
  string* pRight = (string*)hRight_string;

  for(int i = 0; i < pLeft->size && i < pRight->size; i++){
    if (pLeft->data[i] < pRight->data[i]) {
      return -1;
      break;
    }
    else if (pLeft->data[i] > pRight->data[i]) {
      return 1;
      break;
    }
  }

  return 0;
}

int my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
  int num_of_conversions, i, count = 0;
  char c;
  char* tempArray;
  string* pMy_string = (string*)hMy_string;

  num_of_conversions = fscanf(fp, " %c", &c);
  if (num_of_conversions == 1 && num_of_conversions != EOF) {
    while (c != ' ' && c != EOF && c != '\n') {
      pMy_string->data[count] = c;
      pMy_string->size = count + 1;
      count++;
      if (pMy_string->capacity <= pMy_string->size) {
	tempArray = (char*)malloc(sizeof(char) * 2 * pMy_string->capacity);
	if (tempArray == NULL) {
	  free(tempArray);
	}
	for (i = 0; i< pMy_string->capacity; i++) {
	  tempArray[i] = pMy_string->data[i];
	}
	free(pMy_string->data); pMy_string->data = NULL;
	pMy_string->data = tempArray;
	tempArray = NULL;
	pMy_string->capacity *= 2;
      }
      c = fgetc(fp);
    }
    ungetc(c, fp);
    return 1;
  }
  return 0;
}

int my_string_insertion(MY_STRING hMy_string, FILE* fp){
  string *newString = (string *) hMy_string;
  int numOfConv = 0;

  for(int i = 0; i < newString->size; i++){
    numOfConv += fprintf(fp, "%c", newString->data[i]);
  }
  if (numOfConv == newString->size)
    return 1;
  return 0;

}

int my_string_push_back(MY_STRING hMy_string, char item){
  string *newString = (string *) hMy_string;
  
  if(newString->size + 2 >= newString->capacity){
      
      char* temp;
      newString->capacity *= 2;

      temp = (char *) malloc(sizeof(char) * newString->capacity);
      if (!temp)
	return 0;
      for (int i = 0; i < newString->size; i++){
	temp[i] = newString->data[i];
      }
      
      free(newString->data);
      newString->data = temp;

    }

  
  newString->data[newString->size] = item;
  newString->size++;

  return 1;
}

int my_string_pop_back(MY_STRING hMy_string){
  string *newString = (string *) hMy_string;

  if (newString->size == 1)
    return 0;
  if (newString->data[newString->size] == '\0'){
    newString->size--;
    newString->data[newString->size] = '\0';
    return 1;
  }
    
  newString->data[newString->size] = '\0';
  newString->size--;

  return 1;
}

char* my_string_at(MY_STRING hMy_string, int index){
  string *newString = (string *) hMy_string;

  if (newString->size >= index){
    if (newString->data[index] == '\0')
      return NULL;
    return &newString->data[index];
  }
  else
    return NULL;
}

char* my_string_c_str(MY_STRING hMy_string){
  string *newString = (string *) hMy_string;
   
  if(newString->size >= newString->capacity){
      
      char* temp;
      newString->capacity++;

      temp = (char *) malloc(sizeof(char) * newString->capacity);
      for (int i = 0; i < newString->size; i++){
	temp[i] = newString->data[i];
      }
      
      free(newString->data);
      newString->data = temp;

    }

  newString->data[newString->size] = '\0';
  

  return newString->data;
}


int my_string_concat(MY_STRING hResult, MY_STRING hAppend){
  string *resultString = (string *) hResult;
  string *appendString = (string *) hAppend;

  if ( (resultString->size + appendString->size) >= resultString->capacity){

    char* temp;
    resultString->capacity = resultString->capacity + appendString->capacity;

    temp = (char *) malloc(sizeof(char) * resultString->capacity);
    for (int i = 0; i < resultString->size; i++){
      temp[i] = resultString->data[i];
    }
      
    free(resultString->data);
    resultString->data = temp;

  }
  int numLoops = 0;
  for (int i = 0; i < appendString->size; i++){
    resultString->data[resultString->size + i] = appendString->data[i];
    numLoops++;
  }
  resultString->size = resultString->size + numLoops;
  
  
  return 1;
}


Boolean my_string_empty(MY_STRING hMy_string){

  int size =  my_string_get_size(hMy_string);

  if (size == 0)
    return TRUE;
  else
    return FALSE;
}

void my_string_assignment(ITEM* pLeft, ITEM Right)
{
  string* pMy_string_left = (string*)*pLeft;
  string* pMy_string_right = (string*)Right;
  int i;
  const char* temp;
  
  temp = my_string_c_str((MY_STRING)Right);
  if (pMy_string_left == NULL) {
    pMy_string_left = my_string_init_c_string(temp);
  }
  else {
    pMy_string_left->size = 0;
    for (i = 0; i < pMy_string_right->size + 1; i++) {
      my_string_push_back(pMy_string_left, pMy_string_right->data[i]);
    }
  }
  *pLeft = pMy_string_left; 
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{  
  for(int i=0;i<my_string_get_size(word);i++){
    if(*(my_string_at(word,i)) == guess){
      my_string_push_back(new_key,guess);
    }
    else{
      my_string_push_back(new_key,*(my_string_at(current_word_family,i)));
    }
  }
  return SUCCESS;

}



