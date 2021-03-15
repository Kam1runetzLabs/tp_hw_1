add_library(ui STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ui.h
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/ui.c
        )
target_include_directories(ui PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
