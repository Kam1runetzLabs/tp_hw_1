// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#include "progression_finder.h"

static const_iterator find_progression(const_iterator begin,
                                       const_iterator end) {
  int delta = *(begin + 1) - *begin;
  const_iterator end_of_progression = begin;
  for (const_iterator it = begin; it != end - 1; ++it) {
    if (*(it + 1) - *(it) == delta)
      end_of_progression = it + 2;
    else
      return end_of_progression;
  }
  return end_of_progression;
}

ptrdiff_t find_longest_progression(const int_array_t *array,
                                   int_array_t **dest) {
  if (!dest) {
    return -1;
  }

  if (!array) {
    dest = NULL;
    return -1;
  }

  if (!array->begin) {
    dest = NULL;
    return -1;
  }

  if (array->begin >= array->end) {
    dest = NULL;
    return -1;
  }

  if (array->end - array->begin == 1) {
    dest = NULL;
    return -1;
  }

  const_iterator begin_progression = array->begin;
  const_iterator end_progression = array->begin + 2;
  ptrdiff_t progression_size = end_progression - begin_progression;

  for (const_iterator it = array->begin; it != array->end; ++it) {
    const_iterator end_cur_progression = find_progression(it, array->end);
    ptrdiff_t cur_progression_size = end_cur_progression - it;
    if (cur_progression_size > progression_size) {
      progression_size = cur_progression_size;
      begin_progression = it;
      end_progression = end_cur_progression;
    }
  }

  *dest = init_array_from_mem(begin_progression, end_progression);
  if (!*dest) return -1;
  return progression_size;
}
