/**
 * Unit Test Main
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include "Fib.h"

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
