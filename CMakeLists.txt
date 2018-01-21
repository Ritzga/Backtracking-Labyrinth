cmake_minimum_required(VERSION 3.9)
project(AOPPruefung)

set(CMAKE_CXX_STANDARD 14)

add_executable(AOPPruefung main.cpp Labyrinth.cpp Labyrinth.h Coordinate.cpp Coordinate.h Solver.cpp Solver.h Reader.cpp Reader.h)