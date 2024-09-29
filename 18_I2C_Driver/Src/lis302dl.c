/*
 * lis302dl.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Asif
 */


#include "stm32f4xx.h"
#include "lis302dl.h"
#include "i2c.h"

void lis302_write(uint8_t reg, uint8_t value)
{
	uint8_t data[2];
	data[0] = reg;
	data[1] = value;

	HAL_I2C_Master_Transmit(&hi2c, DEVICE_ADDR, data, 2, 100);
}

void lis302_read_values(uint8_t reg, uint8_t *pData)
{
	uint8_t data_buffer = *pData;
	HAL_I2C_Mem_Read(&hi2c, DEVICE_ADDR, reg, 1, &data_buffer, sizeof(data_buffer), 100);
}

void lis302_read_address(uint8_t reg, uint8_t *pData)
{
	uint8_t addr_buffer = *pData;
	HAL_I2C_Mem_Read(&hi2c, DEVICE_ADDR, reg, 1, &addr_buffer, sizeof(addr_buffer), 100);
}
