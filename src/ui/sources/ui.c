// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#include <stdio.h>
#include <ui.h>

#define ENTER_NUMBER(type, spec)            \
  {                                         \
    type ret_value = 0;                     \
    while (scanf(spec, &ret_value) != 1) {  \
      scanf("%*[^\n]");                     \
      printf("Invalid input!\n%s", prompt); \
    }                                       \
    return ret_value;                       \
  }

size_t get_size() { ENTER_NUMBER(size_t, "%lu"); }

int get_number() { ENTER_NUMBER(int, "%d"); }
