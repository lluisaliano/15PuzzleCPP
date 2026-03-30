cmake_minimum_required(VERSION 4.2.1)

project(LearnCpp_Practises VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(fmt REQUIRED)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE fmt::fmt)

target_compile_options(main PRIVATE
  -Wall -Wextra -Wpedantic -Wsign-conversion -Wconversion
)
target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)
