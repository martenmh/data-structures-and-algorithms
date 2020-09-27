cmake_minimum_required(VERSION 3.17)
project(data_structures)

set(CMAKE_CXX_STANDARD 20)
include_directories(contiguous linked abstract-data-types)

add_executable(data_structures main.cpp boilerplate.h boilerplatetester.h simpleboilerplate.h array_boilerplate.h test.cpp bench.cpp contiguous/Array.h linked/List.h abstract-data-types/Stack.h abstract-data-types/Deque.h abstract-data-types/Queue.h abstract-data-types/Dictionairy.h abstract-data-types/BTree.h)