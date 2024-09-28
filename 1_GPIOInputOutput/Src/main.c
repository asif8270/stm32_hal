#include "stm32f4xx.h"

#define BTN_PORT 	GPIOA
#define BTN_PIN 	GPIO_PIN_0
#define LED_PORT	GPIOD
#define LED_PIN 	GPIO_PIN_13

void led_init(void);
void btn_init(void);

uint8_t btnStatus;

int main()
{
	HAL_Init();
	led_init();
	btn_init();

	while(1)
	{
		btnStatus = HAL_GPIO_ReadPin(BTN_PORT, BTN_PIN);
		HAL_GPIO_WritePin(LED_PORT, LED_PIN, btnStatus);
	}
}

void led_init(void)
{
	/*Enable clock for the port D*/
	__HAL_RCC_GPIOD_CLK_ENABLE();

	/*Configure PD13 as the output*/
	GPIO_InitTypeDef initGPIO = {0};

	initGPIO.Pin   = LED_PIN;
	initGPIO.Mode  = GPIO_MODE_OUTPUT_PP;
	initGPIO.Pull  = GPIO_NOPULL;
	initGPIO.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(LED_PORT, &initGPIO);
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
