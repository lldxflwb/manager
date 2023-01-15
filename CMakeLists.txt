cmake_minimum_required(VERSION 3.18)
project(manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(manager main.cpp interface/MapTreeInterface.cpp interface/PeopleInterface.cpp modle/User.cpp tree/NameTree.cpp)
