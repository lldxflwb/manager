cmake_minimum_required(VERSION 3.18)
project(manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(manager main.cpp
        interface/MapTreeInterface.cpp
        interface/PeopleInterface.cpp
        modle/User.cpp
        modle/Manager.cpp
        tree/NameTree.cpp
        tree/NumberTree.cpp
        tree/MultiNumberTree.cpp
        test/NameTreeTest.cpp
        test/TestAction.cpp
        test/NumberTreeTest.cpp
        test/MultiTreeTest.cpp)
