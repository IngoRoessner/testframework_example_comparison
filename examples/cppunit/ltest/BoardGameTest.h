#ifndef __BoardGameTest_H_
#define __BoardGameTest_H_

#include "../src/hierarchy/BoardGame.h"
#include <ltest/LTest.h>

auto m_game = manageFixture<BoardGame*>()
    .before([](BoardGame*& bg){ bg = new BoardGame();})
    .after([](BoardGame*& bg){ delete bg;});

TestSuite BoardGameTest = {
    ltest().addTest("BoardGameTest::testReset", [](){
        LTAssert::True(m_game()->reset());
    }),

    ltest().addTest("BoardGameTest::testResetShouldFail", [](){
        std::cout << "The following test fails, this is intended:" << std::endl;
        LTAssert::True( !(m_game()->reset()) );
    })
};

#endif //__BoardGameTest_H_
