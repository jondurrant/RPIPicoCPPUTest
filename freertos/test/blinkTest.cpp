/*
 * blinkTest.cpp
 *
 *  Created on: 7 Nov 2023
 *      Author: jondurrant
 */

#include "BlinkAgent.h"

#include "CppUTest/TestHarness.h"

#include <math.h>


#define TASK_PRIORITY     ( tskIDLE_PRIORITY + 1UL )
#define LED_GPIO 					15

TEST_GROUP(BlinkGrp){
	BlinkAgent *pBlink;

	void setup() _override{
		pBlink = new  BlinkAgent(LED_GPIO);
		pBlink->start("Blink",  TASK_PRIORITY);
	}

	void teardown() _override{
		pBlink->stop();
		delete pBlink;
	}

};

TEST(BlinkGrp, BlinkDefault){
	uint count;
	count = pBlink->getBlinkCount();
	uint32_t start = to_ms_since_boot(get_absolute_time());
	CHECK_EQUAL(0, count);
	vTaskDelay(3000);
	count = pBlink->getBlinkCount();
	uint32_t now = to_ms_since_boot(get_absolute_time());
	CHECK(count > 0);

	uint expected = (now - start ) /1000;
	if (expected == count){
		CHECK_EQUAL(expected,  count);
	} else {
		CHECK_EQUAL(expected + 1,  count);
	}

}

TEST(BlinkGrp, BlinkOff){
	pBlink->blinkOff();
	uint start  = pBlink->getBlinkCount();
	vTaskDelay(3000);
	uint end = pBlink->getBlinkCount();

	CHECK_EQUAL(start,  end);
}

TEST(BlinkGrp, BlinkOn){
	pBlink->blinkOff();
	uint start  = pBlink->getBlinkCount();
	vTaskDelay(1000);
	uint end = pBlink->getBlinkCount();
	CHECK_EQUAL(start,  end);
	pBlink->blinkOn();

	vTaskDelay(2000);
	end = pBlink->getBlinkCount();
	CHECK(start< end);
}

TEST(BlinkGrp, BlinkSpeed){
	pBlink->blinkOff();
	uint start  = pBlink->getBlinkCount();

	pBlink->setSpeed(120);
	pBlink->blinkOn();
	uint32_t startTime = to_ms_since_boot(get_absolute_time());

	vTaskDelay(3000);

	uint end = pBlink->getBlinkCount();
	uint32_t now = to_ms_since_boot(get_absolute_time());
	double expected = (now - startTime) /1000.0;
	expected = expected * ( 120.0 / 60.0);
	uint exp = ceil(expected);
	CHECK_EQUAL(end - start,  exp);
}



