add_executable(demo main.c)
target_include_directories(demo PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/int_array/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/ui/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/progression_finder/include
        )

target_link_libraries(demo int_array ui progression_finder)