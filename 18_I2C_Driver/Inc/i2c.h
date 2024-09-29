/*
 * i2c.h
 *
 *  Created on: Sep 29, 2024
 *      Author: Asif
 */

#include "stm32f4xx.h"

#ifndef __I2C_H_
#define __I2C_H_

#define GPIO_PORT 	GPIOB

#define SCL_PIN 	GPIO_PIN_6
#define SDA_PIN 	GPIO_PIN_7

extern I2C_HandleTypeDef hi2c;

void gpio_init(void);
void i2c1_init(void);

#endif /* __I2C_H_ */
