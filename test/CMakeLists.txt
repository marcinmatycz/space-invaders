find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(unit_tests test.cpp)
target_link_libraries(unit_tests PRIVATE gtest_main)

gtest_discover_tests(unit_tests)
