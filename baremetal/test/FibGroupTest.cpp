/***
 * Tests for Fib Sequence
 */

#include "CppUTest/TestHarness.h"
#include "Fib.h"

TEST_GROUP(FibGroup){

};

TEST(FibGroup, FibTest){
   Fib fib;
   CHECK_EQUAL(0, 	fib.element(0));
   CHECK_EQUAL(1, 		fib.element(1));
   CHECK_EQUAL(13, 	fib.element(6));
}
