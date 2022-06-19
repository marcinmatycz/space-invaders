add_subdirectory(googletest)

include(GoogleTest)

add_executable(unit_tests test.cpp)
target_link_libraries(unit_tests PRIVATE gtest_main)

target_compile_options(
  unit_tests
  PRIVATE
  -Wold-style-cast
  -Wall
  -Wpedantic
  -Wextra
  -Werror
  -Wshadow
  $<$<CONFIG:Debug>:-Og>
  -Wcast-align
  -Wunused
  -Woverloaded-virtual
  -Wconversion
  -Wsign-conversion
  -Wnull-dereference
  -Wdouble-promotion
  -Wformat=2
  -Wmisleading-indentation
  -Wduplicated-cond
  -Wduplicated-branches
  -Wlogical-op
  -Wuseless-cast
)
target_link_options(unit_tests PRIVATE -pthread)

gtest_discover_tests(unit_tests)
