#include "portable.h"

#ifndef TASKS_H_
#define TASKS_H_
#endif

typedef struct EffectNodeStruct {
	void (*effect)(void);
	struct EffectNodeStruct *nextEffect;
} EffectNode;

void onKeyPressed(Key *this);
void TasksInit();
void TasksExecute();
void effectTaskInit();
void showCurrentEffect();
void switchEffect();
