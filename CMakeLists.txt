cmake_minimum_required(VERSION 4.2.1)

project(15Puzzle VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC_FILES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(main ${SRC_FILES})

target_compile_options(15Puzzle PRIVATE
  -Wall -Wextra -Wpedantic -Wsign-conversion -Wconversion
)
target_include_directories(15Puzzle PUBLIC ${PROJECT_SOURCE_DIR}/include)
