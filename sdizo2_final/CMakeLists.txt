cmake_minimum_required(VERSION 3.19)
project(sdizo_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(sdizo_test main.cpp BellmanFordAlgorithm.cpp BellmanFordAlgorithm.h DijkstraAlgorithm.cpp DijkstraAlgorithm.h Graph.cpp Graph.h KruskalAlgorithm.cpp KruskalAlgorithm.h PrimAlgorithm.cpp PrimAlgorithm.h)