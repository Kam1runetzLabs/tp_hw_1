// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#ifndef INCLUDE_PROGRESSION_FINDER_H_
#define INCLUDE_PROGRESSION_FINDER_H_

#include <int_array.h>
#include <stddef.h>

///\brief this function find longest arithmetic progression in array
///\param src - array in which the search will occur
///\param dest - result progression
///\return length of longest progression
ptrdiff_t find_longest_progression(const int_array_t *src, int_array_t **dest);

#endif  // INCLUDE_PROGRESSION_FINDER_H_
