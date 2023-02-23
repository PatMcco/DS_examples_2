cmake_minimum_required(VERSION 3.24)
project(DS_examples_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(queues queues/main.cpp)
add_executable(smart_pointers smart_pointers/main.cpp)
add_executable(stacks stacks/stacks.cpp)
add_executable(palindrome palindrome/palindrome.cpp)
add_executable(factorial factorial/factorial.cpp)
add_executable(list_folders list_folders/list_folders.cpp)