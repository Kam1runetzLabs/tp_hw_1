// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#include <gtest/gtest.h>

extern "C" {
#include <malloc.h>

#include "int_array.h"
#include "progression_finder.h"
}

TEST(ERROR_HANDLING, ARRAY_IS_NULL) {
  int_array_t *array = nullptr;
  int_array_t *progression = nullptr;
  ptrdiff_t progression_size = find_longest_progression(array, &progression);
  EXPECT_LT(progression_size, 0);
  EXPECT_FALSE(progression);
}

TEST(ERROR_HANDLING, ARRAY_WITHOUT_MEM) {
  auto *array = (int_array_t *)malloc(sizeof(int_array_t));
  array->begin = array->end = nullptr;
  int_array_t *progression = nullptr;
  ptrdiff_t progression_size = find_longest_progression(array, &progression);
  EXPECT_LT(progression_size, 0);
  EXPECT_FALSE(progression);
  free(array);
}

TEST(ERROR_HANDLING, INVALID_INITIALIZED_ARRAY) {
  auto *array = (int_array_t *)malloc(sizeof(int_array_t));
  const size_t mem_size = 10;
  const size_t beg_index = 8;
  const size_t end_index = 1;
  int *mem = new int[mem_size];
  array->begin = mem + beg_index;
  array->end = mem + end_index;
  int_array_t *progression = nullptr;
  ptrdiff_t progression_size = find_longest_progression(array, &progression);
  EXPECT_LT(progression_size, 0);
  EXPECT_FALSE(progression);
  delete[] mem;
  free(array);
}

TEST(ERROR_HANDLING, NULL_DEST_TRANSMITTED) {
  const size_t array_size = 5;
  int_array_t *array = init_array(array_size);
  ptrdiff_t size = find_longest_progression(array, nullptr);
  EXPECT_LT(size, 0);
  delete_array(array);
}

TEST(ALGORITHM_TESTING, PROGRESSION_FROM_SINGLE_SIZE_ARRAY) {
  int_array_t *array = init_array(1);
  int_array_t *progression = nullptr;
  ptrdiff_t size = find_longest_progression(array, &progression);
  EXPECT_FALSE(progression);
  EXPECT_LT(size, 0);
}

TEST(ALGORITHM_TESTING, FINDING_LONGEST_PROGRESSION) {
  const size_t array_size = 9;
  int array[array_size] = {1, 2, 3, 4, 8, 10, 12, 14, 16};
  const size_t short_progression_size = 4;
  const size_t long_progression_size = array_size - short_progression_size;
  int_array_t *src_array = init_array_from_mem(array, array + array_size);
  int_array_t *progression = nullptr;
  ptrdiff_t size = find_longest_progression(src_array, &progression);
  EXPECT_EQ(size, long_progression_size);
  delete_array(progression);
  delete_array(src_array);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
