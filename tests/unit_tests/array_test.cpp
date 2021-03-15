// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#include <gtest/gtest.h>
extern "C" {
#include "int_array.h"
}

const size_t test_array_size = 123;
const size_t invalid_test_array_size = -1;

TEST(InitArray, DefaultInitArray) {
  int_array_t *array = init_array(test_array_size);
  EXPECT_TRUE(array);
  EXPECT_TRUE(array->begin);
  delete_array(array);
}

TEST(InitArray, InitWithInvalidSize) {
  int_array_t *array = init_array(invalid_test_array_size);
  EXPECT_FALSE(array);
}

TEST(InitArray, DefaultInitFromMem) {
  int *array = new int[test_array_size];
  const size_t beg_index = 1;
  const size_t end_index = 5;
  int_array_t *int_array =
      init_array_from_mem(array + beg_index, array + end_index);
  EXPECT_TRUE(int_array);
  EXPECT_FALSE(int_array->begin == array + 1);
  EXPECT_EQ(int_array->end - int_array->begin, end_index - beg_index);
  delete_array(int_array);
  EXPECT_TRUE(array + beg_index);
  delete[] array;
}

TEST(InitArray, InitFromMemWithNullMem) {
  int *beg_mem = nullptr;
  int *end_mem = nullptr;
  int_array_t *int_array = init_array_from_mem(beg_mem, end_mem);
  EXPECT_FALSE(int_array);
}

TEST(InitArray, InitFromMemWithInvalidMem) {
  int *array = new int[test_array_size];
  const size_t beg_index = 5;
  const size_t end_index = 1;
  int_array_t *int_array =
      init_array_from_mem(array + beg_index, array + end_index);
  EXPECT_FALSE(int_array);
  delete[] array;
}

TEST(InitArray, InitArrayWithNullSize) {
  int_array_t *array = init_array(0);
  EXPECT_FALSE(array);
}

TEST(DeleteArray, DefaultDeleteArray) {
  int_array_t *array = init_array(test_array_size);
  if (!array) FAIL() << "internal error";
  if (!array->begin) FAIL() << "internal error";
  delete_array(array);
}

TEST(DeleteArray, DeleteNullArray) {
  int_array_t *array = NULL;
  delete_array(array);
}

TEST(DeleteArray, DeleteInvalidArray) {
  auto array = (int_array_t *)malloc(sizeof(int_array_t));
  array->begin = NULL;
  delete_array(array);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
