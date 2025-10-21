/*
 * ts.h
 *
 *  Created on: Dec 23, 2024
 *      Author: Deived Azevedo
 */



#ifndef INC_TS_H_
#define INC_TS_H_

#include "main.h"
#include "config_defs.h"

#ifndef USE_TS_MULTI_TOUCH
#define USE_TS_MULTI_TOUCH          1U
#endif
#ifndef USE_TS_GESTURE
#define USE_TS_GESTURE              1U
#endif

#ifndef TS_TOUCH_NBR
#define TS_TOUCH_NBR                2U
#endif

#define TS_INSTANCES_NBR            2U

/* Maximum border values of the touchscreen pad */
#define TS_MAX_WIDTH                480U     /* Touchscreen pad max width   */
#define TS_MAX_HEIGHT               272U     /* Touchscreen pad max height  */

#define TS_SWAP_NONE                0x01U
#define TS_SWAP_X                   0x02U
#define TS_SWAP_Y                   0x04U
#define TS_SWAP_XY                  0x08U

/**
  * @brief TouchScreen Slave I2C address 1
  */
#define TS_I2C_ADDRESS              0x70U
#define TS_I2C_ADDRESS_GT           0x28U
#define TS_I2C_ADDRESS_BACK         0x28U

/**
  * @brief Touch screen interrupt signal
  */
#define TS_INT_PIN                   GPIO_PIN_5
#define TS_INT_GPIO_PORT             GPIOE
#define TS_INT_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOE_CLK_ENABLE()
#define TS_INT_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOE_CLK_DISABLE()
#define TS_INT_EXTI_IRQn             EXTI9_5_IRQn
#define TS_EXTI_LINE                 EXTI_LINE_5


typedef struct
{
  uint32_t   Width;                  /* Screen Width */
  uint32_t   Height;                 /* Screen Height */
  uint32_t   Orientation;            /* Touch Screen orientation from the upper left position  */
  uint32_t   Accuracy;               /* Expressed in pixel and means the x or y difference vs old
                                        position to consider the new values valid */
} TS_Init_t;

typedef struct
{
  uint32_t   Width;
  uint32_t   Height;
  uint32_t   Orientation;
  uint32_t   Accuracy;
  uint32_t   MaxX;
  uint32_t   MaxY;
  uint32_t   PreviousX[TS_TOUCH_NBR];
  uint32_t   PreviousY[TS_TOUCH_NBR];
} TS_Ctx_t;

typedef struct
{
  uint8_t   MultiTouch;
  uint8_t   Gesture;
  uint8_t   MaxTouch;
  uint32_t  MaxXl;
  uint32_t  MaxYl;
} TS_Capabilities_t;

typedef struct
{
  uint32_t  TouchDetected;
  uint32_t  TouchX;
  uint32_t  TouchY;
} TS_State_t;

typedef struct
{
  uint32_t  TouchDetected;
  uint32_t  TouchX[TS_TOUCH_NBR];
  uint32_t  TouchY[TS_TOUCH_NBR];
  uint32_t  TouchWeight[TS_TOUCH_NBR];
  uint32_t  TouchEvent[TS_TOUCH_NBR];
  uint32_t  TouchArea[TS_TOUCH_NBR];
} TS_MultiTouch_State_t;

#if (USE_TS_GESTURE > 0)
/**
  *  @brief TS_Gesture_Id_t
  *  Define Possible managed gesture identification values returned by touch screen
  *  driver.
  */
#define GESTURE_ID_NO_GESTURE   0x00U /*!< Gesture not defined / recognized */
#define GESTURE_ID_MOVE_UP      0x01U /*!< Gesture Move Up */
#define GESTURE_ID_MOVE_RIGHT   0x02U /*!< Gesture Move Right */
#define GESTURE_ID_MOVE_DOWN    0x03U /*!< Gesture Move Down */
#define GESTURE_ID_MOVE_LEFT    0x04U /*!< Gesture Move Left */
#define GESTURE_ID_ZOOM_IN      0x05U /*!< Gesture Zoom In */
#define GESTURE_ID_ZOOM_OUT     0x06U /*!< Gesture Zoom Out */
#define GESTURE_ID_NB_MAX       0x07U /*!< max number of gesture id */

typedef struct
{
  uint32_t  Radian;
  uint32_t  OffsetLeftRight;
  uint32_t  OffsetUpDown;
  uint32_t  DistanceLeftRight;
  uint32_t  DistanceUpDown;
  uint32_t  DistanceZoom;
} TS_Gesture_Config_t;

#endif /* (USE_TS_GESTURE > 0) */


typedef struct
{
  int32_t ( *Init                 ) (void *);
  int32_t ( *DeInit               ) (void *);
  int32_t ( *GestureConfig        ) (void *, void*);
  int32_t ( *ReadID               ) (void *, uint32_t *);
  int32_t ( *GetState             ) (void *, void*);
  int32_t ( *GetMultiTouchState   ) (void *, void*);
  int32_t ( *GetGesture           ) (void *, void*);
  int32_t ( *GetCapabilities      ) (void *, void*);
  int32_t ( *EnableIT             ) (void *);
  int32_t ( *DisableIT            ) (void *);
  int32_t ( *ClearIT              ) (void *);
  int32_t ( *ITStatus             ) (void *);
}TS_Drv_t;


extern void               *Ts_CompObj[TS_INSTANCES_NBR];
extern EXTI_HandleTypeDef hts_exti[TS_INSTANCES_NBR];
extern TS_Ctx_t           Ts_Ctx[TS_INSTANCES_NBR];

int32_t BSP_TS_Init(uint32_t Instance, TS_Init_t *TS_Init);
int32_t BSP_TS_DeInit(uint32_t Instance);
int32_t BSP_TS_EnableIT(uint32_t Instance);
int32_t BSP_TS_DisableIT(uint32_t Instance);
int32_t BSP_TS_GetState(uint32_t Instance, TS_State_t *TS_State);
#if (USE_TS_MULTI_TOUCH == 1)
int32_t BSP_TS_Get_MultiTouchState(uint32_t Instance, TS_MultiTouch_State_t *TS_State);
#endif /* USE_TS_MULTI_TOUCH == 1 */
#if (USE_TS_GESTURE == 1)
int32_t BSP_TS_GestureConfig(uint32_t Instance, TS_Gesture_Config_t *GestureConfig);
int32_t BSP_TS_GetGestureId(uint32_t Instance, uint32_t *GestureId);
#endif /* (USE_TS_GESTURE == 1) */
int32_t BSP_TS_Set_Orientation(uint32_t Instance, uint32_t Orientation);
int32_t BSP_TS_Get_Orientation(uint32_t Instance, uint32_t *Orientation);
int32_t BSP_TS_GetCapabilities(uint32_t Instance, TS_Capabilities_t *Capabilities);
void    BSP_TS_Callback(uint32_t Instance);
void    BSP_TS_IRQHandler(uint32_t Instance);
int32_t GT911_Probe(uint32_t Instance);
int32_t FT5336_Probe(uint32_t Instance);



#endif /* INC_TS_H_ */
