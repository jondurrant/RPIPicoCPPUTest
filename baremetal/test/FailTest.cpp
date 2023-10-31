/***
 * Functional failure test
 */

#include "CppUTest/TestHarness.h"
#include "Fib.h"


TEST_GROUP(FailGroup){
};
TEST(FailGroup, FailTest){
   Fib fib;
   fib.leak();
   CHECK_EQUAL(10, 	fib.element(6));
}
