#include "led.h"

/* abstract methods */

// initialize a led io
extern void ledIOInit(LED *this);
__attribute__((weak)) void ledIOInit(LED *this) {
	return;
}

// set a LED , status=0 , selected LED off ; selected status=1 , LED on
extern void setLED(LED *this,unsigned char status);
__attribute__((weak)) void setLED(LED *this,unsigned char status) {
	return;
}
// milliseconds delay
extern void delayMs(int ms);
__attribute__((weak)) void delayMs(int ms) {
	return;
}

/* methods of LED objects */

// turn on led like : led1.on(&led1);
static void on(LED *this) {
	setLED(this,1);
	this->status = 1;
}
// turn off led like : led1.off(&led1);
static void off(LED *this) {
	setLED(this,0);
	this->status = 0;
}
// switch status of led like : led1.switchStatus(&led1);
static void switchStatus(LED *this) {
	setLED(this,!this->status);
	this->status = !this->status;
}
// twinkling led specified times by specified delay like : led1.twinkle(&led1,500,10)
static void twinkle(LED *this,int periodMs,int times) {
	for(;times>0;times--) {
		this->switchStatus(this);
		delayMs(periodMs);
		this->switchStatus(this);
		delayMs(periodMs);
	}
}

/* create a led object like : LED led1 = newLED(&led1,1); */
LED newLED(LED *this,int id) {

	/* initialize fields */
	this->id = id;
	this->status = 0;

	/* initialize methods */
	this->on = on;
	this->off = off;
	this->switchStatus = switchStatus;
	this->twinkle = twinkle;

	/* initialize led io */
	ledIOInit(this);

	return *this;
}

