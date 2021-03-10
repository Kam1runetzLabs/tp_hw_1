include("../../tools/gate/cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.278.tar.gz"
        SHA1 "35fa55bc1dfcf9f4d7264f8bb26cd1759ce1ae07"
    )
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(tests tests.cpp)
target_link_libraries(tests GTest::main)

add_test(NAME unit_tests COMMAND unit_tests)
