/***
 * Test for a memory leak
 */

#include "CppUTest/TestHarness.h"
#include "Fib.h"

TEST_GROUP(FibLeakGroup){

};

TEST(FibLeakGroup, LeakTest){
   Fib fib;
   fib.leak();
   CHECK_EQUAL(13, 	fib.element(6));
}
