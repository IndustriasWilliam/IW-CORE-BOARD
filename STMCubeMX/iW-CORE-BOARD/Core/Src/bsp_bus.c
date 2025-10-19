
/*
 * bsp_bus.c
 *
 *  Created on: Dec 23, 2024
 *      Author: Deived Azevedo
 */

#include "main.h"
#include "bsp_bus.h"
#include "i2c.h"
//#include "cmsis_os.h"


//static osSemaphoreId_t BspI2cSemaphore = NULL;

int32_t BSP_I2C3_WriteReg16(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length){

	int32_t res = BSP_ERROR_NONE;

#if defined(BSP_USE_CMSIS_OS)
	if(osSemaphoreAcquire (BspI2cSemaphore, 100) == osOK){
#endif


	if(HAL_I2C_Mem_Write(&hi2c3, DevAddr, Reg, I2C_MEMADD_SIZE_16BIT, pData, Length, 1000) != HAL_OK){
		if (HAL_I2C_GetError(&hi2c3) == HAL_I2C_ERROR_AF)
		{
			res = BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE;
		}
		else
		{
			res =  BSP_ERROR_PERIPH_FAILURE;
		}
	}

#if defined(BSP_USE_CMSIS_OS)
	osSemaphoreRelease(BspI2cSemaphore);
	}
#endif

	return res;

}
int32_t BSP_I2C3_ReadReg16(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length){

	int32_t res = BSP_ERROR_NONE;

#if defined(BSP_USE_CMSIS_OS)
	if(osSemaphoreAcquire (BspI2cSemaphore, 100) == osOK){
#endif

	if(HAL_I2C_Mem_Read(&hi2c3, DevAddr, Reg, I2C_MEMADD_SIZE_16BIT, pData, Length, 1000) != HAL_OK){
		if (HAL_I2C_GetError(&hi2c3) == HAL_I2C_ERROR_AF)
		{
			res = BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE;
		}
		else
		{
			res =  BSP_ERROR_PERIPH_FAILURE;
		}
	}
#if defined(BSP_USE_CMSIS_OS)
	osSemaphoreRelease(BspI2cSemaphore);
	}
#endif

	return res;
}
int32_t BSP_I2C3_Init(void){

	MX_I2C3_Init();

#if defined(BSP_USE_CMSIS_OS)
	BspI2cSemaphore = osSemaphoreNew(1, 1, NULL);
#endif

	return BSP_ERROR_NONE;
}

int32_t BSP_I2C3_DeInit(void){
	int32_t res = BSP_ERROR_NONE;

	if(HAL_I2C_DeInit(&hi2c3) != HAL_OK){
		res = BSP_ERROR_BUS_FAILURE;
	}
	return res;
}

int32_t BSP_GetTick(void){
	return (int32_t)HAL_GetTick();
}
