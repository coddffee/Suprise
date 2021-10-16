#include "ws2812.h"
#include "malloc.h"

/* abstract methods */

extern void ws2812GroupIOInit(WS2812Group *this);
__attribute__((weak)) void ws2812GroupIOInit(WS2812Group *this);

extern void ws2812GroupWriteData(WS2812Group *this);
__attribute__((weak)) void ws2812GroupWriteData(WS2812Group *this);

static void setRGB(WS2812Group *this,int itemId,unsigned char r,unsigned char g,unsigned char b) {
	if(itemId > this->length) return;
	this->RBuffer[itemId-1] = r;
	this->GBuffer[itemId-1] = g;
	this->BBuffer[itemId-1] = b;
}

static void refresh(WS2812Group *this) {
	ws2812GroupWriteData(this);
}

static void delete(WS2812Group *this) {
	free(this->RBuffer);
	this->RBuffer = 0;
	free(this->GBuffer);
	this->GBuffer = 0;
	free(this->BBuffer);
	this->BBuffer = 0;
}

WS2812Group newWS2812Group(WS2812Group *this,int id,int length) {

	this->id = id;
	this->length = length;

	this->setRGB = setRGB;
	this->refresh = refresh;
	this->delete = delete;

	this->RBuffer = (unsigned char*)malloc(length*sizeof(unsigned char));
	this->GBuffer = (unsigned char*)malloc(length*sizeof(unsigned char));
	this->BBuffer = (unsigned char*)malloc(length*sizeof(unsigned char));

	while(this->RBuffer == 0 || this->GBuffer == 0 || this->BBuffer == 0);

	ws2812GroupIOInit(this);

	for(int i=0;i<this->length;i++) this->setRGB(this,i+1,0x00,0x00,0x00);
	this->refresh(this);

	return *this;
}
