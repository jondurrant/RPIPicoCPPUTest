/*
 * Fib.h
 *
 * Fibonacci sequence
 *
 *  Created on: 29 Oct 2023
 *      Author: jondurrant
 */

#ifndef BAREMETAL_SRC_FIB_H_
#define BAREMETAL_SRC_FIB_H_

#include "pico/stdlib.h"
#include <cstdlib>

class Fib {
public:
	Fib();
	virtual ~Fib();

	/***
	 * Return the index element within Fib sequence
	 * First element is index 0
	 * @param index - index from 0
	 * @return element of sequence
	 */
	int element(uint index);

	/***
	 * Cause a memory leak
	 */
	void leak();
private:
	char *pBuf = NULL;

};

#endif /* BAREMETAL_SRC_FIB_H_ */
