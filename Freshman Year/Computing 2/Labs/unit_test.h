#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdio.h>
#include "my_string.h"

typedef enum status { FAILURE, SUCCESS } Status;

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_cbenassi_destroy_test(char* buffer, int length);
Status test_cbenassi_get_capacity_test(char* buffer, int length);
Status test_cbenassi_get_size_test(char* buffer, int length);
Status test_cbenassi_init_c_string_test(char* buffer, int length);
Status test_cbenassi_compare_test(char* buffer, int length);
Status test_cbenassi_extraction_test(char* buffer, int length);
Status test_cbenassi_insertion_test(char* buffer, int length);
Status test_cbenassi_push_back_test(char* buffer, int length);
Status test_cbenassi_pop_back_test(char* buffer, int length);
Status test_cbenassi_string_at_test(char* buffer, int length);
Status test_cbenassi_c_str(char* buffer, int length);
Status test_cbenassi_concat_test(char* buffer, int length);
Status test_cbenassi_string_empty_test(char* buffer, int length);
Status test_cbenassi_empty_with_string(char* buffer, int length);
Status test_cbenassi_concat_with_nothing(char* buffer, int length);
Status test_cbenassi_pop_back_at_null_terminator(char* buffer, int length);
Status test_cbenassi_my_string_at_invalid(char* buffer, int length);
Status test_cbenassi_concat_first_string_empty(char* buffer, int length);
Status test_cbenassi_destroy_empty_list(char* buffer, int length);



#endif
