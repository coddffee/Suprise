#ifndef WS2812_H_
#define WS2812_H_
#endif

typedef struct WS2812GroupStruct {
	int id;
	int length;
	unsigned char *RBuffer;
	unsigned char *GBuffer;
	unsigned char *BBuffer;
	void (*setRGB)(struct WS2812GroupStruct*,int,unsigned char,unsigned char,unsigned char);
	void (*refresh)(struct WS2812GroupStruct*);
	void (*delete)(struct WS2812GroupStruct*);
} WS2812Group;

/* create a new WS2812Group object like : WS2812Group group1 = newWS2812Group(&group1,1,25); */
WS2812Group newWS2812Group(WS2812Group *this,int id,int length);
