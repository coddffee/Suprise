#ifndef LED_LED_H_
#define LED_LED_H_
#endif

typedef struct LEDStruct {
	/* fields */
	int id;
	unsigned char status;
	/* methods */
	void(*on)(struct LEDStruct*);
	void(*off)(struct LEDStruct*);
	void(*switchStatus)(struct LEDStruct*);
	void(*twinkle)(struct LEDStruct*,int,int);
} LED;

LED newLED(LED *this , int id);


