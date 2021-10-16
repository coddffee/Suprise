#include "key.h"

/* abstract method */

extern void keyIOInit(Key *this);
__attribute__((weak)) void keyIOInit(Key *this);

extern void onKeyPressed(Key *this);
__attribute__((weak)) void onKeyPressed(Key *this) {
	return;
}

/* listening for key pressed */
static void listening(Key *this) {
	if(this->pressedFlag == 1) {
		this->onPressed(this);
	}
	this->pressedFlag = 0;
}

/* called when pressed */
static void onPressed(Key *this) {
	onKeyPressed(this);
}

/* create a key object like : Key key1 = newKey(&key1,1); */
Key newKey(Key *this,int id) {

	/* initialize fields */
	this->id = id;
	this->pressedFlag = 0;

	/* initialize methods */
	this->onPressed = onPressed;
	this->listening = listening;

	/* initialize a key io */
	keyIOInit(this);

	return *this;
}
