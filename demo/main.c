// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#include <int_array.h>
#include <progression_finder.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ui.h>

#define HANDLE_ERROR(msg)         \
  {                               \
    fprintf(stderr, "%s\n", msg); \
    exit(EXIT_FAILURE);           \
  }

const char help_flag[] = "--help";
const char help_flag_alias[] = "-h";
const char invalid_args_msg[] =
    "invalid flags, use <program> --help or <program> -h";

int main(int argc, char *argv[]) {
  if (argc > 1) {
    if (!strcmp(help_flag, argv[1]) || !strcmp(help_flag_alias, argv[1])) {
      printf("%s\n", help_message);
    } else {
      HANDLE_ERROR(invalid_args_msg);
    }
  }

  printf("%s\n", welcome_message);
  printf("%s", prompt);
  size_t size = get_size();
  int_array_t *array = init_array(size);
  if (!array) HANDLE_ERROR("internal allocation error");

  for (iterator it = array->begin; it != array->end; ++it) {
    printf("%s", prompt);
    *it = get_number();
  }

  int_array_t *progression = NULL;
  ptrdiff_t progression_size;
  progression_size = find_longest_progression(array, &progression);
  if (progression_size < 0) {
    delete_array(array);
    HANDLE_ERROR("internal error");
  }

  printf("progression size: %lu\n", progression_size);
  for (const_iterator it = progression->begin; it != progression->end; ++it)
    printf("%d ", *it);
  printf("\n");
  return 0;
}
