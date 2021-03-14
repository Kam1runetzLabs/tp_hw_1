// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#ifndef INCLUDE_PROGRESSION_FINDER_H_
#define INCLUDE_PROGRESSION_FINDER_H_

#include <stddef.h>

#include "int_array.h"

///@brief находит подмассив, составляющий арифметическую прогрессию максимальной
///длины
///@param src - массив, в котором будет происходить поиск
///@param dest - указатель на массив, в который будет сохранена прогрессия.
///!!!Не должен указывать на инициализированный массив, ининциализация будет
///произведена внутри функции
///@return длина наибольшей прогрессии или -1 в случае ошибки
ptrdiff_t find_longest_progression(const int_array_t *src, int_array_t **dest);

#endif  // INCLUDE_PROGRESSION_FINDER_H_
