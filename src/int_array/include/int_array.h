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

///@brief - создает целочисленный массив заданного размера
///@param size - размер создаваемого массива
///@return указатель на инициализированный массив или NULL в случае ошибки
int_array_t *init_array(size_t size);

///@brief инициализирует массив как копию уже выделенной памяти
///@param begin - начало копируемого участка памяти
///@param end - конец копируемого участка памяти
///@return указатель на инициализированный массив или NULL в случае ошибки
int_array_t *init_array_from_mem(const_iterator begin, const_iterator end);

///@brief освобождает память, выделенную под массив
///@param array - указатель на удаляемый массив, может быть не валидным
void delete_array(int_array_t *array);

#endif  // INCLUDE_INT_ARRAY_H_
