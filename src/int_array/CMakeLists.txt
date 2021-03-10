add_library(int_array STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/int_array.h
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/int_array.c
        )
target_include_directories(int_array PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
