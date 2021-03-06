#include <stdio.h>
#include <string.h>
#include "unit_test.h"
#include "generic.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  
  if(hString == NULL)
    {
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
	      "my_string_init_default returns NULL", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
      return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  if(my_string_get_size(hString) != 0)
    {
      status = FAILURE;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	      "Did not recieve 0 from get_size after init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_cbenassi_destroy_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  
  my_string_destroy(&hString);

  if(hString == NULL){
    strncpy(buffer, "test_cbenassi_destroy_test\n", length);
    return SUCCESS;
  }
  else{
    strncpy(buffer, "test_cbenassi_destroy_test\n"
	    "After running my_string_destroy, string did not equal NULL\n", length);
    return FAILURE;
  }
}

Status test_cbenassi_get_capacity_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if(my_string_get_capacity(hString) == 1){
    my_string_destroy(&hString);
    strncpy(buffer, "test_cbenassi_get_capacity_test\n", length);
    return SUCCESS;
  }
  else{
    my_string_destroy(&hString);
    strncpy(buffer, "test_cbenassi_get_capacity_test\n"
	    "After my_string_init_default, string->capacity did not equal 1\n", length);
    return FAILURE;
  }
}

Status test_cbenassi_get_size_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if(my_string_get_size(hString) == 0){
    my_string_destroy(&hString);
    strncpy(buffer, "test_cbenassi_get_size_test\n", length);
    return SUCCESS;
  }
  else{
    my_string_destroy(&hString);
    strncpy(buffer, "test_cbenassi_get_size_test\n"
	    "After init_default, string->size did not equal 0\n", length);
    return FAILURE;
  }

}

Status test_cbenassi_init_c_string_test(char* buffer, int length)
{
  MY_STRING hString = NULL;
  char compare[6] = "hello";

  hString = my_string_init_c_string("hello");
  
  string *pString = (string *) hString;
  
  for(int i = 0; i < 5; i++){
    if(pString->data[i] != compare[i]){
      my_string_destroy(&hString);
      strncpy(buffer, "test_cbenassi_init_c_string_test\n"
	      "Implemation of string \"hello\" failed\n", length);
      return FAILURE;
    }
  }
  my_string_destroy(&hString);
  strncpy(buffer, "test_cbenassi_init_c_string_test\n", length);
  return SUCCESS;

}

Status test_cbenassi_compare_test(char* buffer, int length)
{
  MY_STRING stringOne = NULL;
  MY_STRING stringTwo = NULL;

  stringOne = my_string_init_c_string("hello");
  stringTwo = my_string_init_c_string("hello");

  string *psOne = (string *) stringOne;
  string *psTwo = (string *) stringTwo;

  for (int i = 0; i < psOne->size; i++)
    if (psOne->data[i] != psTwo->data[i]){
      strncpy(buffer, "test_cbenassi_compare_test\n"
	      "Comparing two strings with \"hello\" failed", length);
      my_string_destroy(&stringOne);
      my_string_destroy(&stringTwo);
      return FAILURE;
    }
  strncpy(buffer, "test_cbenassi_compare_test\n", length);
  my_string_destroy(&stringOne);
  my_string_destroy(&stringTwo);
  return SUCCESS;

}

Status test_cbenassi_extraction_test(char* buffer, int length)
{
  MY_STRING newString = NULL;
  FILE* fp = fopen("dictionary.txt", "r");
  
  newString = my_string_init_default();
  my_string_extraction(newString, fp);

  if (newString != NULL){
    strncpy(buffer, "test_cbenassi_extraction_test\n", length);
    my_string_destroy(&newString);
    free(fp);
    return SUCCESS;
  }
  my_string_destroy(&newString);
  free(fp);
  strncpy(buffer, "test_cbenassi_extraction_test\n"
	  "my_string_extraction returned NULL when extracting from dictionary.txt\n", length);
  return FAILURE;


}

Status test_cbenassi_insertion_test(char* buffer, int length)
{
  MY_STRING newString = NULL;
  int bool;
  
  newString = my_string_init_c_string("hello");
  
  bool = my_string_insertion(newString, stdout);
  printf("\b\b\b\b\b");
  
  if (bool){
    strncpy(buffer, "test_cbenassi_insertion_test\n", length);
    my_string_destroy(&newString);
    return SUCCESS;
  }
  my_string_destroy(&newString);
  strncpy(buffer, "test_cbenassi_insertion_test\n"
	 "my_string_insertion failed to output to the screen properly\n", length);
  return FAILURE;
}

Status test_cbenassi_push_back_test(char* buffer, int length)
{
  MY_STRING newString = NULL;
  MY_STRING compare = NULL;
  char push = 'o';

  newString = my_string_init_c_string("hell");
  compare = my_string_init_c_string("hello");
  
  if(my_string_push_back(newString, push))
    if(my_string_compare(newString, compare) == 0){
      strncpy(buffer, "test_cbenassi_push_back_test\n", length);
      my_string_destroy(&newString);
      my_string_destroy(&compare);
      return SUCCESS;
    }
  strncpy(buffer, "test_cbenassi_push_back_test\n"
	  "push_back failed when compared to a control string\n", length);
  my_string_destroy(&newString);
  my_string_destroy(&compare);
  return FAILURE;
  

}

Status test_cbenassi_pop_back_test(char* buffer, int length)
{
  MY_STRING newString = NULL;
  MY_STRING compare = NULL;

  newString = my_string_init_c_string("helloh");
  compare = my_string_init_c_string("hello");
  my_string_c_str(compare);

  if(my_string_pop_back(newString))
    if(my_string_compare(newString, compare) == 0){
      strncpy(buffer, "test_cbenassi_pop_back_test\n", length);
      my_string_destroy(&newString);
      my_string_destroy(&compare);
      return SUCCESS;
    }
  strncpy(buffer, "test_cbenassi_pop_back_test\n"
	  "pop_back failed when compared to a control string\n", length);
  my_string_destroy(&newString);
  my_string_destroy(&compare);
  return FAILURE;
  
}

Status test_cbenassi_string_at_test(char* buffer, int length)
{
  MY_STRING newString = NULL;

  newString = my_string_init_c_string("hello");

  if(my_string_at(newString, 0) == 'h'){
    my_string_destroy(&newString);
    strncpy(buffer, "test_cbenassi_string_at_test\n", length);
    return SUCCESS;
  }
  my_string_destroy(&newString);
  strncpy(buffer, "test_cbenassi_string_at_test\n"
	  "string_at test failed to return 'h' as first character in 'hello' string\n", length);
  return FAILURE;

}

Status test_cbenassi_c_str(char* buffer, int length)
{
  MY_STRING newString = NULL;

  newString = my_string_init_c_string("hello");
  
  
  if(my_string_c_str(newString)){
    string *pString = (string *) newString;
    if(pString->data[pString->size] == '\0'){
      strncpy(buffer, "test_cbenassi_c_str\n", length);
      my_string_destroy(&newString);
      return SUCCESS;
    }
  }
  strncpy(buffer, "test_cbenassi_c_str\n"
	  "my_string_c_str did not add NULL terminator onto test string\n", length);
  my_string_destroy(&newString);
  return FAILURE;
  
}

Status test_cbenassi_concat_test(char* buffer, int length)
{
  MY_STRING stringOne = NULL;
  MY_STRING stringTwo = NULL;
  char compare[11] = "Hello there";

  stringOne = my_string_init_c_string("Hello");
  stringTwo = my_string_init_c_string(" there");
  
  if(my_string_concat(stringOne, stringTwo))
  {
    string *pString = (string *) stringOne;
    for(int i = 0; i < pString->size; i++)
    {
      if(pString->data[i] != compare[i])
      {
	strncpy(buffer, "test_cbenassi_concat_test\n"
		"my_string_concat failed to join two strings and compare against a control\n", length);
	my_string_destroy(&stringOne);
	my_string_destroy(&stringTwo);
	return FAILURE;
      }
    }
  }
  strncpy(buffer, "test_cbenassi_concat_test\n", length);
  my_string_destroy(&stringOne);
  my_string_destroy(&stringTwo);
  return SUCCESS;
}

Status test_cbenassi_string_empty_test(char* buffer, int length)
{
  MY_STRING stringOne = NULL;

  stringOne = my_string_init_default();

  if(my_string_empty(stringOne) == TRUE){
    my_string_destroy(&stringOne);
    strncpy(buffer, "test_cbenassi_string_empty_test\n", length);
    return SUCCESS;
  }
  my_string_destroy(&stringOne);
  strncpy(buffer, "test_cbenassi_string_empty_test\n"
	  "my_string_empty failed to recognize an empty string\n", length);
  return FAILURE;
  
}

Status test_cbenassi_empty_with_string(char* buffer, int length)
{
  MY_STRING stringOne = NULL;

  stringOne = my_string_init_c_string("hello");

  if(my_string_empty(stringOne) == FALSE){
    my_string_destroy(&stringOne);
    strncpy(buffer, "test_cbenassi_empty_with_string\n", length);
    return SUCCESS;
  }
  my_string_destroy(&stringOne);
  strncpy(buffer, "test_cbenassi_empty_with_string\n"
	  "my_string_empty failed to recognize a string with data\n", length);
  return FAILURE;
  
}

Status test_cbenassi_concat_with_nothing(char* buffer, int length)
{
  MY_STRING stringOne = NULL;
  MY_STRING stringTwo = NULL;
  char compare[5] = "hello";
  
  stringOne = my_string_init_c_string("hello");
  stringTwo = my_string_init_default();

  if(my_string_concat(stringOne, stringTwo))
  {
    string *pString = (string *) stringOne;
    for(int i = 0; i < pString->size; i++)
    {
      if(pString->data[i] != compare[i])
      {
	strncpy(buffer, "test_cbenassi_concat_test\n"
		"my_string_concat failed to recognize string 2 was empty\n", length);
	my_string_destroy(&stringOne);
	my_string_destroy(&stringTwo);
	return FAILURE;
      }
    }
  }
  strncpy(buffer, "test_cbenassi_concat_test\n", length);
  my_string_destroy(&stringOne);
  my_string_destroy(&stringTwo);
  return SUCCESS;

}

Status test_cbenassi_pop_back_at_null_terminator(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("hello");
  my_string_c_str(hString);
  my_string_pop_back(hString);

  if(my_string_get_size(hString) == 4){
    my_string_destroy(&hString);
    strncpy(buffer, "test_cbenassi_pop_back_at_null_terminator\n", length);
    return SUCCESS;
  }
  else{
    my_string_destroy(&hString);
    strncpy(buffer, "test_cbenassi_pop_back_at_null_terminator\n"
	    "After attempting to pop the NULL terminator, the function did not skip it\n", length);
    return FAILURE;
  }
}

Status test_cbenassi_my_string_at_invalid(char* buffer, int length)
{
  MY_STRING newString = NULL;

  newString = my_string_init_c_string("Hello");

  if(my_string_at(newString, -1) == NULL){
    my_string_destroy(&newString);
    strncpy(buffer, "test_cbenassi_my_string_at_invalid\n", length);
    return SUCCESS;
  }

  my_string_destroy(&newString);
  strncpy(buffer, "test_cbenassi_my_string_at_invalid\n"
	  "After trying to access a character that is out of bounds, NULL was not returned\n", length);
  return FAILURE;
}

Status test_cbenassi_concat_first_string_empty(char* buffer, int length)
{
  MY_STRING stringOne = NULL;
  MY_STRING stringTwo = NULL;
  char compare[5] = "hello";
  
  stringTwo = my_string_init_c_string("hello");
  stringOne = my_string_init_default();

  if(my_string_concat(stringOne, stringTwo))
  {
    string *pString = (string *) stringOne;
    for(int i = 0; i < pString->size; i++)
    {
      if(pString->data[i] != compare[i])
      {
	strncpy(buffer, "test_cbenassi_concat_first_string_empty\n"
		"my_string_concat failed to recognize string 1 was empty\n", length);
	my_string_destroy(&stringOne);
	my_string_destroy(&stringTwo);
	return FAILURE;
      }
    }
  }
  strncpy(buffer, "test_cbenassi_concat_first_string_empty\n", length);
  my_string_destroy(&stringOne);
  my_string_destroy(&stringTwo);
  return SUCCESS;

}

Status test_cbenassi_destroy_empty_list(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("\0");

  my_string_destroy(&hString);

  if(hString == NULL){
    strncpy(buffer, "test_cbenassi_destroy_empty_list\n", length);
    return SUCCESS;
  }
  else{
    strncpy(buffer, "test_cbenassi_destroy_empty_list\n"
	    "After running my_string_destroy, string did not equal NULL\n", length);
    return FAILURE;
  }
}

