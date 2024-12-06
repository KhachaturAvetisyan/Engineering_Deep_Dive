cmake_minimum_required(VERSION 3.28)

project(homework1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/")

add_executable(Multiple_Fork_calls Multiple_Fork_calls.cpp)
add_executable(Simple_Fork_and_Exec Simple_Fork_and_Exec.cpp)
add_executable(Multiple_Forks_and_Execs Multiple_Forks_and_Execs.cpp)
add_executable(Fork_and_Exec_with_Arguments Fork_and_Exec_with_Arguments.cpp)
add_executable(Fork_and_Exec_with_Command-Line_Arguments Fork_and_Exec_with_Command-Line_Arguments.cpp)
