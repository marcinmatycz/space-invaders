cmake_minimum_required(VERSION 3.20.5)

project(space-invaders)
        
enable_language(C CXX ASM)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

enable_testing()
add_subdirectory(test)

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} raylib)

target_compile_options(
  ${PROJECT_NAME}
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
