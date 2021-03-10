// Copyright 2021 Kam1runetzLabs <notsoserious2017@gmail.com>

#ifndef INCLUDE_UI_H_
#define INCLUDE_UI_H_

#include <stddef.h>

static const char welcome_message[] = "====ARITHMETIC PROGRESSION FINDER====";
static const char help_message[] =
    "To find longest arithmetic progression in array you need to enter array "
    "size and array elements in format"
    ">> [size] <Return>\n"
    ">> [element_1] <Return>\n"
    "...\n"
    ">> [element_n] <Return>\n";

static const char prompt[] = ">> ";

size_t get_size();

int get_number();

#endif  // INCLUDE_UI_H_
