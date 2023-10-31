/**
 * Unit Test Main
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "Fib.h"


TEST_GROUP(FibGroup){

};

TEST(FibGroup, FibTest){
   Fib fib;
   CHECK_EQUAL(0, 	fib.element(0));
   CHECK_EQUAL(1, 		fib.element(1));
   CHECK_EQUAL(13, 	fib.element(6));
}

TEST_GROUP(FibLeakGroup){

};

TEST(FibLeakGroup, LeakTest){
   Fib fib;
   fib.leak();
   CHECK_EQUAL(13, 	fib.element(6));
}

TEST_GROUP(FailGroup){
};
TEST(FailGroup, FailTest){
   Fib fib;
   fib.leak();
   CHECK_EQUAL(10, 	fib.element(6));
}


int main(int ac, char** av) {

	//Initialise IO as we are using printf for debug
	stdio_init_all();

	printf("RUNNING TESTS\n");

	const char * fav[3] = {"test", "-g", "Fib"};

	int res = CommandLineTestRunner::RunAllTests(3, fav);

	printf("Runner returned %d\n", res);

	res = CommandLineTestRunner::RunAllTests(ac, av);

	for (;;){
		sleep_ms(1000);
	}
}
