hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(array_test array_test.cpp)
add_executable(pfinder_test progression_finder_test.cpp)

target_include_directories(array_test PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../int_array/include
        )

target_include_directories(pfinder_test PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../progression_finder/include
        )

target_link_libraries(array_test GTest::gtest_main int_array)
target_link_libraries(pfinder_test GTest::gtest_main progression_finder)

add_test(NAME array_test COMMAND array_unit_tests)
add_test(NAME pfinder_test COMMAND prinder_unit_tests)
