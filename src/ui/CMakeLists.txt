add_library(ui
        STATIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ui.h
        STATIC ${CMAKE_CURRENT_SOURCE_DIR}/source/ui.c
        )
target_include_directories(ui PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
