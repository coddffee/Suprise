#include "tasks.h"

static EffectNode *current;
static EffectNode effectNode1;
static EffectNode effectNode2;
static EffectNode effectNode3;
static EffectNode effectNode4;
static EffectNode effectNode5;

static void effect1() {
	extern WS2812Group ws2812Group1;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0xff,0xff,0xff);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0x00,0x00,0x00);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
}

static void effect2() {
	extern WS2812Group ws2812Group1;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0xff,0x00,0x00);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0x00,0x00,0xff);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
}

static void effect3() {
	extern WS2812Group ws2812Group1;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0xff,0xff,0x00);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0x00,0xff,0x00);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
}

static void effect4() {
	extern WS2812Group ws2812Group1;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0xff,0x00,0xff);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0x00,0xff,0xff);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
}

static void effect5() {
	extern WS2812Group ws2812Group1;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0xff,0xcc,0xbb);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0xaa,0x11,0x10);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(200);
}

void effectTaskInit() {
	effectNode1.effect = effect1;
	effectNode1.nextEffect = &effectNode2;

	effectNode2.effect = effect2;
	effectNode2.nextEffect = &effectNode3;

	effectNode3.effect = effect3;
	effectNode3.nextEffect = &effectNode4;

	effectNode4.effect = effect4;
	effectNode4.nextEffect = &effectNode5;

	effectNode5.effect = effect5;
	effectNode5.nextEffect = &effectNode1;

	current = &effectNode1;
}

void showCurrentEffect() {
	current->effect();
}

void switchEffect() {
	current = current->nextEffect;
}





