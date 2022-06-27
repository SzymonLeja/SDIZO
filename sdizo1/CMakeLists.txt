cmake_minimum_required(VERSION 3.19)
project(sdizo1)

set(CMAKE_CXX_STANDARD 14)

add_executable(sdizo1 main.cpp twoWayList.cpp dynamicArray.cpp dynamicArray.h twoWayList.h listElement.h heap.h fileGenerator.cpp fileReader.cpp bst.cpp bst.h)