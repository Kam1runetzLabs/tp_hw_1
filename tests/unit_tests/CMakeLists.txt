hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(array_test array_test.cpp)
add_executable(pfinder_test progression_finder_test.cpp)
target_link_libraries(array_test GTest::gtest_main int_array)
target_link_libraries(pfinder_test GTest::gtest_main progression_finder)

add_test(NAME array_unit_test COMMAND array_test)
add_test(NAME pfinder_unit_test COMMAND pfinder_test)
