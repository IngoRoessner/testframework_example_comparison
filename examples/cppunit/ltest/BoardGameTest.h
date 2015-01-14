#ifndef __BoardGameTest_H_
#define __BoardGameTest_H_

#include "../src/hierarchy/BoardGame.h"
#include <ltest/LTest.h>

auto m_game = manageFixture<BoardGame*>()
    .before([](BoardGame*& bg){ bg = new BoardGame();})
    .after([](BoardGame*& bg){ delete bg;});

TestSuite BoardGameTest = {
    ltest().addTest("testReset", [](){
        LTAssert::True(m_game()->reset());
    }),

    ltest().ignoreNext(),
    ltest().addTest("testResetShouldFail", [](){
        LTAssert::True( !(m_game()->reset()) );
    })
};

#endif //__BoardGameTest_H_
