#include "tasks.h"

LED led1;
Key key1;
WS2812Group ws2812Group1;

void onKeyPressed(Key *this) {
	/* implement OOP by id */
	switch(this->id) {
	case 1 :
		led1.twinkle(&led1,50,3);
		switchEffect();
		break;
	}
}

void TasksInit() {

	led1 = newLED(&led1,1);
	key1 = newKey(&key1,1);
	ws2812Group1 = newWS2812Group(&ws2812Group1,1,24);
	effectTaskInit();

	/* test led after initialization */
	led1.on(&led1);
	led1.twinkle(&led1,50,5);
}

void TasksExecute() {
	key1.listening(&key1);
	showCurrentEffect();
}
