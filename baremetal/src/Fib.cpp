/*
 * Fib.cpp
 *
 *  Created on: 29 Oct 2023
 *      Author: jondurrant
 */

#include "Fib.h"

Fib::Fib() {
	pBuf = (char *)malloc(100);

}

Fib::~Fib() {
	free(pBuf);
}

int Fib::element(uint index){
	int prev = 0;
	int elem = 1;

	if (index == 0){
		return 0;
	}

	for (uint i=0; i < index; i++){
		int n = prev + elem;
		prev = elem;
		elem = n;
	}
	return elem;
}

void Fib::leak(){
	pBuf = (char *)malloc(100);
}

