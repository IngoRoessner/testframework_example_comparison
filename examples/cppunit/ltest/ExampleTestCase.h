#ifndef __ExampleTestCase_H_
#define __ExampleTestCase_H_

#include <ltest/LTest.h>

auto m_value1 = manageFixture<double>()
        .before([](double& d){
            d = 2.0;
        });

auto m_value2 = manageFixture<double>()
        .before([](double& d){
            d = 3.0;
        });

TestSuite ExampleTestCase = {
        ltest().addTest("ExampleTestCase::example", [](){
            LTAssert::EqualDelta( 1.0, 1.1, 0.05 );
            LTAssert::True( 1 == 0 );
            LTAssert::True( 1 == 1 );
        }),

        ltest().addTest("ExampleTestCase::anotherExample", [](){
            LTAssert::True( 1 == 2 );
        }),

        ltest().addTest("ExampleTestCase::testAdd", [](){
            double result = m_value1() + m_value2();
            LTAssert::True( result == 6.0 );
        }),

        ltest().addTest("ExampleTestCase::testEquals", [](){
            long* l1 = new long(12);
            long* l2 = new long(12);

            LTAssert::Equal( 12, 12 );
            LTAssert::Equal( 12L, 12L );
            LTAssert::Equal( *l1, *l2 );

            delete l1;
            delete l2;

            LTAssert::True( 12L == 12L );
            LTAssert::Equal( 12, 13 );
            LTAssert::EqualDelta( 12.0, 11.99, 0.5 );
        }),
};


#endif //__ExampleTestCase_H_
