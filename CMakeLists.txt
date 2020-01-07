cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__ LeyDeCramer.cpp Kramer.h Kramer.cpp)
add_executable(LeyDeCramer.cpp LeyDeCramer.cpp Kramer.h)
add_executable(LeyDeCramer3.cpp LeyDeCramer3.cpp)
