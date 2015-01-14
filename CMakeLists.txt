cmake_minimum_required(VERSION 2.8.4)
project(ltest_example_compare)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcppunit")

set(CppUnit_CppUnit
    examples/cppunit/cppunit/hierarchy/BoardGame.cpp
    examples/cppunit/cppunit/hierarchy/BoardGame.h
    examples/cppunit/cppunit/hierarchy/BoardGameTest.h
    examples/cppunit/cppunit/hierarchy/Chess.cpp
    examples/cppunit/cppunit/hierarchy/Chess.h
    examples/cppunit/cppunit/hierarchy/ChessTest.h
    examples/cppunit/cppunit/money/Money.h
    examples/cppunit/cppunit/money/MoneyTest.cpp
    examples/cppunit/cppunit/money/MoneyTest.h
    examples/cppunit/cppunit/money/StdAfx.cpp
    examples/cppunit/cppunit/money/StdAfx.h
    examples/cppunit/cppunit/simple/ExampleTestCase.cpp
    examples/cppunit/cppunit/simple/ExampleTestCase.h
    examples/cppunit/cppunit/Main.cpp)

link_libraries(cppunit)

add_executable(CppUnit_CppUnit ${CppUnit_CppUnit})