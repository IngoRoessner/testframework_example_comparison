#ifndef __ChessTest_H_
#define __ChessTest_H_

#include "../src/hierarchy/Chess.h"
#include <ltest/LTest.h>

auto chess_game = manageFixture<Chess*>()
        .before([](Chess*& bg){ bg = new Chess();})
        .after([](Chess*& bg){ delete bg;});

TestSuite ChessTest = {
        ltest().addTest("ChessTest::testNumberOfPieces", [](){
            LTAssert::True( chess_game()->getNumberOfPieces () == 32 );
        }),

        ltest().addTest("ChessTest::testReset", [](){
            LTAssert::True(m_game()->reset());
        }),

        ltest().addTest("ChessTest::testResetShouldFail", [](){
            std::cout << "The following test fails, this is intended:" << std::endl;
            LTAssert::True( !(m_game()->reset()) );
        })
};

#endif //__ChessTest_H_
