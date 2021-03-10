add_library(progression_finder
        STATIC ${CMAKE_CURRENT_SOURCE_DIR}/include/progression_finder.h
        STATIC ${CMAKE_CURRENT_SOURCE_DIR}/source/progression_finder.c
        )
target_include_directories(progression_finder PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../int_array/include
        )