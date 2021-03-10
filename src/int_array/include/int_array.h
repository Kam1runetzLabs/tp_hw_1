// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#ifndef INCLUDE_INT_ARRAY_H_
#define INCLUDE_INT_ARRAY_H_

#include <stddef.h>

typedef struct {
  int *begin;
  int *end;
} int_array_t;

typedef int *iterator;
typedef const int *const_iterator;

///\brief initialize array with transmitted size
///\param size - size of the array to create
///\return pointer to the created array or NULL if allocation error happened
int_array_t *init_array(size_t size);

///\brief initialize array by copy of existing array
///\param begin - start of copying memory
///\param end - end of copying memory
///\return pointer to the created array or NULL if error
int_array_t *init_array_from_mem(const_iterator begin, const_iterator end);

///\brief frees the memory from the array
///\param array - pointer to array to delete, may be NULL
void delete_array(int_array_t *array);

#endif  // INCLUDE_INT_ARRAY_H_
