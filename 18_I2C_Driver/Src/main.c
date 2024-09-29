#include "stm32f4xx.h"
#include "i2c.h"
#include "lis302dl.h"

uint8_t device_id;

int main()
{
	HAL_Init();
	gpio_init();

	while(1)
	{
	}
}

void lis302_init(void)
{
	lis302_read_address(WHO_AM_I, (uint8_t*) &device_id);
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
