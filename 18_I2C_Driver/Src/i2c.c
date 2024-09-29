/*
 * i2c.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Asif
 */
#include "stm32f4xx.h"
#include "i2c.h"

void gpio_init(void)
{
	/*Enable clock for the port B*/
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef initGPIO = {0};

	/*Configure PB6 and PB7 as the alternate function*/
	initGPIO.Pin       = (SCL_PIN | SDA_PIN);
	initGPIO.Mode      = GPIO_MODE_AF_OD;
	initGPIO.Pin       = GPIO_PULLUP;
	initGPIO.Speed     = GPIO_SPEED_FREQ_HIGH;
	initGPIO.Alternate = GPIO_AF4_I2C1;

	HAL_GPIO_Init(GPIO_PORT, &initGPIO);

}

/*Configure I2C module*/

void i2c1_init(void)
{
	__HAL_RCC_I2C1_CLK_ENABLE();

	I2C_HandleTypeDef hi2c;

	hi2c.Instance             = I2C1;
	hi2c.Init.ClockSpeed      = 400000;
	hi2c.Init.DutyCycle       = I2C_DUTYCYCLE_2;
	hi2c.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	hi2c.Init.OwnAddress1     = 0;
	hi2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

	HAL_I2C_Init(&hi2c);
}
