#include "led.h"
#include "key.h"
#include "ws2812.h"
#include "stm32f0xx_hal.h"

#ifndef PORTABLE_H_
#define PORTABLE_H_
#endif

/* method implements */
void ledIOInit(LED *this);
void setLED(LED *this , unsigned char status);
void delayMs(int ms);
void keyIOInit(Key *this);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void EXTI4_15_IRQHandler(void);
void ws2812GroupIOInit(WS2812Group *this);
void ws2812GroupWriteData(WS2812Group *this);
