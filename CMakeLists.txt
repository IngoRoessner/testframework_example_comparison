cmake_minimum_required(VERSION 2.8.4)
project(ltest_example_compare)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(CppUnit_CppUnit
    examples/cppunit/cppunit/BoardGameTest.h
    examples/cppunit/cppunit/ChessTest.h
    examples/cppunit/cppunit/ExampleTestCase.cpp
    examples/cppunit/cppunit/ExampleTestCase.h
    examples/cppunit/cppunit/Main.cpp
    examples/cppunit/cppunit/MoneyTest.cpp
    examples/cppunit/cppunit/MoneyTest.h
    examples/cppunit/src/hierarchy/BoardGame.cpp
    examples/cppunit/src/hierarchy/BoardGame.h
    examples/cppunit/src/hierarchy/Chess.cpp
    examples/cppunit/src/hierarchy/Chess.h
    examples/cppunit/src/money/Money.h
    examples/cppunit/src/money/StdAfx.cpp
    examples/cppunit/src/money/StdAfx.h)


set(CppUnit_LTest
    examples/cppunit/ltest/Main.cpp
    examples/cppunit/ltest/MoneyTest.h
    examples/cppunit/src/hierarchy/BoardGame.cpp
    examples/cppunit/src/hierarchy/BoardGame.h
    examples/cppunit/src/hierarchy/Chess.cpp
    examples/cppunit/src/hierarchy/Chess.h
    examples/cppunit/src/money/Money.h
    examples/cppunit/src/money/StdAfx.cpp
    examples/cppunit/src/money/StdAfx.h)

link_libraries(cppunit)
link_libraries(ltest)

add_executable(CppUnit_CppUnit ${CppUnit_CppUnit})
add_executable(CppUnit_LTest ${CppUnit_LTest})