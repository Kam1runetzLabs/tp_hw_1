// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#include <int_array.h>
#include <memory.h>
#include <stdlib.h>

int_array_t *init_array(size_t size) {
  if (!size) return NULL;
  int_array_t *array = (int_array_t *)malloc(sizeof(int_array_t));
  if (!array) return NULL;
  array->begin = (int *)malloc(sizeof(int) * size);
  if (!array->begin) {
    free(array);
    return NULL;
  }
  array->end = array->begin + size;
  return array;
}

void delete_array(int_array_t *array) {
  if (!array) return;
  if (array->begin) free(array->begin);
  array->begin = array->end = NULL;
  free(array);
}

int_array_t *init_array_from_mem(const_iterator begin, const_iterator end) {
  if (!begin) return NULL;
  if (begin >= end) return NULL;
  int_array_t *array = (int_array_t *)malloc(sizeof(int_array_t));
  if (!array) return NULL;
  array->begin = (int *)malloc(sizeof(int) * (end - begin));
  if (!array->begin) {
    free(array);
    return NULL;
  }
  memcpy(array->begin, begin, sizeof(int) * (end - begin));
  array->end = array->begin + (end - begin);
  return array;
}
