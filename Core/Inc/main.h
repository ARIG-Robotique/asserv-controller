/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DIR3_Pin GPIO_PIN_13
#define DIR3_GPIO_Port GPIOC
#define DIR2_Pin GPIO_PIN_14
#define DIR2_GPIO_Port GPIOC
#define DIR1_Pin GPIO_PIN_15
#define DIR1_GPIO_Port GPIOC
#define PWM1_Pin GPIO_PIN_0
#define PWM1_GPIO_Port GPIOC
#define PWM2_Pin GPIO_PIN_1
#define PWM2_GPIO_Port GPIOC
#define PWM3_Pin GPIO_PIN_2
#define PWM3_GPIO_Port GPIOC
#define PWM4_Pin GPIO_PIN_3
#define PWM4_GPIO_Port GPIOC
#define CHA_1_Pin GPIO_PIN_0
#define CHA_1_GPIO_Port GPIOA
#define CHB_1_Pin GPIO_PIN_1
#define CHB_1_GPIO_Port GPIOA
#define CURRENT_SENSOR__1_Pin GPIO_PIN_2
#define CURRENT_SENSOR__1_GPIO_Port GPIOA
#define CURRENT_SENSOR_2_Pin GPIO_PIN_3
#define CURRENT_SENSOR_2_GPIO_Port GPIOA
#define SLEEP_4_Pin GPIO_PIN_4
#define SLEEP_4_GPIO_Port GPIOA
#define IDX_1_Pin GPIO_PIN_5
#define IDX_1_GPIO_Port GPIOA
#define CHA_2_Pin GPIO_PIN_6
#define CHA_2_GPIO_Port GPIOA
#define CHB_2_Pin GPIO_PIN_7
#define CHB_2_GPIO_Port GPIOA
#define SLEEP_1_Pin GPIO_PIN_4
#define SLEEP_1_GPIO_Port GPIOC
#define SLEEP_2_Pin GPIO_PIN_5
#define SLEEP_2_GPIO_Port GPIOC
#define SLEEP_3_Pin GPIO_PIN_0
#define SLEEP_3_GPIO_Port GPIOB
#define CURRENT_SENSOR_3_Pin GPIO_PIN_1
#define CURRENT_SENSOR_3_GPIO_Port GPIOB
#define CHA_3_Pin GPIO_PIN_2
#define CHA_3_GPIO_Port GPIOB
#define FAULT_4_Pin GPIO_PIN_10
#define FAULT_4_GPIO_Port GPIOB
#define FAULT_3_Pin GPIO_PIN_11
#define FAULT_3_GPIO_Port GPIOB
#define IDX_3_Pin GPIO_PIN_12
#define IDX_3_GPIO_Port GPIOB
#define FAULT_2_Pin GPIO_PIN_13
#define FAULT_2_GPIO_Port GPIOB
#define CURRENT_SENSOR_4_Pin GPIO_PIN_14
#define CURRENT_SENSOR_4_GPIO_Port GPIOB
#define FAULT_1_Pin GPIO_PIN_15
#define FAULT_1_GPIO_Port GPIOB
#define CHA_4_Pin GPIO_PIN_6
#define CHA_4_GPIO_Port GPIOC
#define CHB_4_Pin GPIO_PIN_7
#define CHB_4_GPIO_Port GPIOC
#define I2C_ADD2_Pin GPIO_PIN_8
#define I2C_ADD2_GPIO_Port GPIOC
#define I2C_ADD1_Pin GPIO_PIN_9
#define I2C_ADD1_GPIO_Port GPIOC
#define HEART_BEAT_Pin GPIO_PIN_10
#define HEART_BEAT_GPIO_Port GPIOA
#define CHB_3_Pin GPIO_PIN_12
#define CHB_3_GPIO_Port GPIOC
#define IDX_2_Pin GPIO_PIN_2
#define IDX_2_GPIO_Port GPIOD
#define IDX_4_Pin GPIO_PIN_6
#define IDX_4_GPIO_Port GPIOB
#define DIR4_Pin GPIO_PIN_9
#define DIR4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
