/*
 * lis302dl.h
 *
 *  Created on: Sep 29, 2024
 *      Author: Asif
 */

#include "stm32f4xx.h"
#include "i2c.h"

#ifndef __LIS302DL_H_
#define __LIS302DL_H_

#define DEVICE_ADDR		0x1D //SD0 pin either connected to Vdd_IO or floating

#define WHO_AM_I		0x0F
#define CTRL_REG1 		0x20
#define STATUS_REG 		0x27
#define OUTX 			0x29
#define OUTY			0x2B
#define OUTZ			0x2D

extern I2C_HandleTypeDef hi2c;

void lis302_write(uint8_t reg, uint8_t value);
void lis302_read_values(uint8_t reg, uint8_t *pData);
void lis302_read_address(uint8_t reg, uint8_t *pData);

#endif /* __LIS302DL_H_ */
