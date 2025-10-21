/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.24.1. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */
#include <stdio.h>
#include <STM32TouchController.hpp>

extern "C"{
	#include "bsp_bus.h"
	#include "ts.h"

}

void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */

	int32_t probeStatus;
	TS_Init_t hTS;

	probeStatus = GT911_Probe(0);
	if (probeStatus == BSP_ERROR_NONE) {
		hTS.Orientation = TS_SWAP_NONE;
	}
	hTS.Accuracy = 8;
	hTS.Width = LCD_GetXSize();
	hTS.Height = LCD_GetYSize();
	BSP_TS_Init(0, &hTS);
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /**
     * By default sampleTouch returns false,
     * return true if a touch has been detected, otherwise false.
     *
     * Coordinates are passed to the caller by reference by x and y.
     *
     * This function is called by the TouchGFX framework.
     * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
     *
     */
	TS_State_t TS_State = { 0 };
	BSP_TS_GetState(0, &TS_State);

	if (TS_State.TouchDetected) {

//		x = map_coord(TS_State.TouchX, 476, 480);
//		y = map_coord(TS_State.TouchY, 268, 272);

		x = (int32_t)TS_State.TouchX;
		y = (int32_t)TS_State.TouchY;

		printf("%i %i | %i %i\r\n", x, y, TS_State.TouchX, TS_State.TouchY);
		return true;
	}
    return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
