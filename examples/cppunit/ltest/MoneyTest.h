#ifndef __MoneyTest_H_
#define __MoneyTest_H_

#include "../src/money/Money.h"
#include <ltest/LTest.h>

TestSuite MoneyTest = {
        ltest().addTest("MoneyTest::testConstructor", [](){
            // Set up
            const std::string currencyFF( "FF" );
            const double longNumber = 1234.5678;

            // Process
            Money money( longNumber, currencyFF );

            // Check
            LTAssert::Equal(longNumber, money.getAmount());
            LTAssert::Equal( currencyFF, money.getCurrency() );
        }),

        ltest().addTest("MoneyTest::testEqual", [](){
            // Set up
            const Money money123FF( 123, "FF" );
            const Money money123USD( 123, "USD" );
            const Money money12FF( 12, "FF" );
            const Money money12USD( 12, "USD" );

            // Process & Check
            LTAssert::True( money123FF == money123FF );    // ==
            LTAssert::True( money12FF != money123FF );     // != amount
            LTAssert::True( money123USD != money123FF );   // != currency
            LTAssert::True( money12USD != money123FF );    // != currency and != amount
        }),

        ltest().addTest("MoneyTest::testAdd", [](){
            // Set up
            const Money money12FF( 12, "FF" );
            const Money expectedMoney( 135, "FF" );

            // Process
            Money money( 123, "FF" );
            money += money12FF;

            // Check
            LTAssert::Equal( expectedMoney, money );           // add works
            LTAssert::True( &money == &(money += money12FF) );  // add returns ref. on 'this'.
        }),

        ltest().addTest("MoneyTest::testAddThrow", [](){
            // Set up
            const Money money123FF( 123, "FF" );

            // Process
            Money money( 123, "USD" );

            money += money123FF;        // should throw an exception
        })
};



#endif //__MoneyTest_H_
