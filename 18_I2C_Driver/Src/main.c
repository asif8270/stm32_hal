#include "stm32f4xx.h"

#define BTN_PORT 	GPIOA
#define BTN_PIN 	GPIO_PIN_0

void btn_init(void);

uint8_t btnStatus;

int main()
{
	HAL_Init();
	btn_init();

	while(1)
	{
	}
}


void btn_init(void)
{
	/*Enable clock for the port A*/
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef initGPIO = {0};

	/*Configure PA0 as the input*/
	initGPIO.Pin   = BTN_PIN;
	initGPIO.Mode  = GPIO_MODE_INPUT;
	initGPIO.Pin   = GPIO_NOPULL;
	initGPIO.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(BTN_PORT, &initGPIO);

}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
