#include "tasks.h"

static EffectNode *current;
static EffectNode effectNode0;
static EffectNode effectNode1;
static EffectNode effectNode2;
static EffectNode effectNode3;
static EffectNode effectNode4;
static EffectNode effectNode5;
static EffectNode effectNode6;

static unsigned char getR(uint32_t rgb) {return (rgb&0xff0000)>>16;}
static unsigned char getG(uint32_t rgb) {return (rgb&0x00ff00)>>8;}
static unsigned char getB(uint32_t rgb) {return (rgb&0x0000ff);}

static void effect0() {
	extern WS2812Group ws2812Group1;
	uint32_t single = 0xffffff;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,getR(single),getG(single),getB(single));
	}
	ws2812Group1.refresh(&ws2812Group1);
}

static void effect1() {
	extern WS2812Group ws2812Group1;
	static unsigned char r = 0xff;
	static unsigned char g = 0xff;
	static unsigned char b = 0xff;
	static unsigned char flag = 0;
	if(!flag) {
		r++;
		g++;
		b++;
	}
	else {
		r--;
		g--;
		b--;
	}
	if(r==0xff) flag=1;
	else if(r==0) flag=0;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,r,g,b);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(2);
}

static void effect2() {
	extern WS2812Group ws2812Group1;
	static unsigned char r = 0xff;
	static float g = 51.0;
	static unsigned char flag = 0;
	if(!flag) {
		r++;
		g+=0.2;
	}
	else {
		r--;
		g-=0.2;
	}
	if(r==0xff) flag=1;
	else if(r==0) flag=0;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,r,(unsigned char)g,0);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(2);
}

static void effect3() {
	extern WS2812Group ws2812Group1;
	static unsigned char r = 0xff;
	static unsigned char b = 0xff;
	static unsigned char flag = 0;
	if(!flag){
		r++;
		b++;
	}
	else {
		r--;
		b--;
	}
	if(r==0xff) flag=1;
	else if(r==0) flag=0;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,r,0,b);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(2);
}

static void effect4() {
	extern WS2812Group ws2812Group1;
	static unsigned char g = 0xff;
	static unsigned char b = 0xff;
	static unsigned char flag = 0;
	if(!flag){
		g++;
		b++;
	}
	else {
		g--;
		b--;
	}
	if(g==0xff) flag=1;
	else if(g==0) flag=0;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,0,g,b);
	}
	ws2812Group1.refresh(&ws2812Group1);
	HAL_Delay(2);
}

static void effect5() {
	extern WS2812Group ws2812Group1;
	uint32_t base = 0xffffff;
	uint32_t rgb1 = 0xff0000;
	uint32_t rgb2 = 0xffa500;
	uint32_t rgb3 = 0xffff00;
	uint32_t rgb4 = 0x00ff00;
	uint32_t rgb5 = 0x0000ff;
	uint32_t rgb6 = 0x00ffff;
	uint32_t rgb7 = 0xff00ff;
	static int index = 0;
	int l = ws2812Group1.length;
	for(int i=0;i<ws2812Group1.length;i++) {
		ws2812Group1.setRGB(&ws2812Group1,i+1,getR(base),getG(base),getB(base));
	}
	ws2812Group1.setRGB(&ws2812Group1,(index+0)%l+1,getR(rgb1),getG(rgb1),getB(rgb1));
	ws2812Group1.setRGB(&ws2812Group1,(index+1)%l+1,getR(rgb2),getG(rgb2),getB(rgb2));
	ws2812Group1.setRGB(&ws2812Group1,(index+2)%l+1,getR(rgb3),getG(rgb3),getB(rgb3));
	ws2812Group1.setRGB(&ws2812Group1,(index+3)%l+1,getR(rgb4),getG(rgb4),getB(rgb4));
	ws2812Group1.setRGB(&ws2812Group1,(index+4)%l+1,getR(rgb5),getG(rgb5),getB(rgb5));
	ws2812Group1.setRGB(&ws2812Group1,(index+5)%l+1,getR(rgb6),getG(rgb6),getB(rgb6));
	ws2812Group1.setRGB(&ws2812Group1,(index+6)%l+1,getR(rgb7),getG(rgb7),getB(rgb7));
	ws2812Group1.refresh(&ws2812Group1);
	index++;
	if(index>ws2812Group1.length-1) index=0;
	HAL_Delay(50);
}

static void effect6() {
	extern WS2812Group ws2812Group1;
	uint32_t rgb1 = 0xff0000;
	uint32_t rgb2 = 0xff5000;
	uint32_t rgb3 = 0x00ff00;
	uint32_t rgb4 = 0x0000ff;
	uint32_t rgb5 = 0xff00ff;
	uint32_t rgb6 = 0x00ffff;
	static int index = 0;
	int l = ws2812Group1.length;
	for(int i=0;i<4;i++) {
		ws2812Group1.setRGB(&ws2812Group1,(index+i)%l+1,getR(rgb1),getG(rgb1),getB(rgb1));
	}
	for(int i=4;i<8;i++) {
		ws2812Group1.setRGB(&ws2812Group1,(index+i)%l+1,getR(rgb2),getG(rgb2),getB(rgb2));
	}
	for(int i=8;i<12;i++) {
		ws2812Group1.setRGB(&ws2812Group1,(index+i)%l+1,getR(rgb3),getG(rgb3),getB(rgb3));
	}
	for(int i=12;i<16;i++) {
		ws2812Group1.setRGB(&ws2812Group1,(index+i)%l+1,getR(rgb4),getG(rgb4),getB(rgb4));
	}
	for(int i=16;i<20;i++) {
		ws2812Group1.setRGB(&ws2812Group1,(index+i)%l+1,getR(rgb5),getG(rgb5),getB(rgb5));
	}
	for(int i=20;i<24;i++) {
		ws2812Group1.setRGB(&ws2812Group1,(index+i)%l+1,getR(rgb6),getG(rgb6),getB(rgb6));
	}
	ws2812Group1.refresh(&ws2812Group1);
	index++;
	if(index>ws2812Group1.length-1) index=0;
	HAL_Delay(50);
}

void effectTaskInit() {
	effectNode0.effect = effect0;
	effectNode0.nextEffect = &effectNode1;
	effectNode1.effect = effect1;
	effectNode1.nextEffect = &effectNode2;
	effectNode2.effect = effect2;
	effectNode2.nextEffect = &effectNode3;
	effectNode3.effect = effect3;
	effectNode3.nextEffect = &effectNode4;
	effectNode4.effect = effect4;
	effectNode4.nextEffect = &effectNode5;
	effectNode5.effect = effect5;
	effectNode5.nextEffect = &effectNode6;
	effectNode6.effect = effect6;
	effectNode6.nextEffect = &effectNode0;
	current = &effectNode0;
}

void showCurrentEffect() {
	current->effect();
}

void switchEffect() {
	current = current->nextEffect;
}
