#ifndef KEY_KEY_H_
#define KEY_KEY_H_
#endif

typedef struct KeyStruct {
	int id;
	unsigned char pressedFlag;
	void (*onPressed)(struct KeyStruct*);
	void (*listening)(struct KeyStruct*);
} Key;

Key newKey(Key *this,int id);
