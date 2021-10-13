#include "portable.h"
#include "malloc.h"

/******************** portable methods in led.c ********************/

void ledIOInit(LED *this) {
	/* implemented by STM32CubeIDE */
}

void setLED(LED *this, unsigned char status) {
	/* implement OOP by id */
	switch(this->id) {
	case 1 :
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,!status?GPIO_PIN_SET:GPIO_PIN_RESET);
		break;
	}
}

void delayMs(int ms) {
	HAL_Delay(ms);
}

/******************** portable methods in key.c ********************/

void keyIOInit(Key *this) {
	/* implemented by STM32CubeIDE */
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	extern Key key1;
	switch(GPIO_Pin) {
	case GPIO_PIN_9 :
		key1.pressedFlag = 1;
		break;
	}
}

/******************** portable methods in ws2812.c ********************/

void ws2812GroupIOInit(WS2812Group *this) {
	/* implemented by STM32CubeIDE */
}

void ws2812GroupWriteData(WS2812Group *this) {
#define _0L1H_ 40
#define _1L0H_ 19

	extern TIM_HandleTypeDef htim1;
	static uint16_t *buffer = 0;

	/* Reset time of WS2812 is implemented by long and complex code below , don't need extra delay*/

	if(buffer == 0) buffer = (uint16_t*)malloc(24*sizeof(uint16_t)*this->length);
	while(buffer == 0);
	int index = 0;
	while(buffer == 0);
	for(int i=0;i<this->length;i++) {
		for(int j=0;j<8;j++) {
			buffer[index] = (this->RBuffer[i]&(0x80>>j))>0?_0L1H_:_1L0H_;
			index++;
		}
		for(int j=0;j<8;j++) {
			buffer[index] = (this->GBuffer[i]&(0x80>>j))>0?_0L1H_:_1L0H_;
			index++;
		}
		for(int j=0;j<8;j++) {
			buffer[index] = (this->BBuffer[i]&(0x80>>j))>0?_0L1H_:_1L0H_;
			index++;
		}
	}
	/* implement OOP by id */
	switch(this->id) {
	case 1 :
		HAL_TIM_PWM_Start_DMA(&htim1,TIM_CHANNEL_3,(uint32_t*)buffer,24*this->length);
		break;
	}
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	extern TIM_HandleTypeDef htim1;
	HAL_TIM_PWM_Stop_DMA(&htim1,TIM_CHANNEL_3);
}
