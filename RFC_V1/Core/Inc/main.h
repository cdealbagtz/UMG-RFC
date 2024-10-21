/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define NRF_CS_Pin GPIO_PIN_13
#define NRF_CS_GPIO_Port GPIOC
#define ADC_VBat_Pin GPIO_PIN_1
#define ADC_VBat_GPIO_Port GPIOA
#define SD_SCK_Pin GPIO_PIN_5
#define SD_SCK_GPIO_Port GPIOA
#define SD_MISO_Pin GPIO_PIN_6
#define SD_MISO_GPIO_Port GPIOA
#define SD_MOSI_Pin GPIO_PIN_7
#define SD_MOSI_GPIO_Port GPIOA
#define SD_CS_Pin GPIO_PIN_0
#define SD_CS_GPIO_Port GPIOB
#define BMP_CS_Pin GPIO_PIN_2
#define BMP_CS_GPIO_Port GPIOB
#define IMU2_SCL_Pin GPIO_PIN_10
#define IMU2_SCL_GPIO_Port GPIOB
#define NRF_SCK_Pin GPIO_PIN_12
#define NRF_SCK_GPIO_Port GPIOB
#define BMP_SCK_Pin GPIO_PIN_13
#define BMP_SCK_GPIO_Port GPIOB
#define BMP_MISO_Pin GPIO_PIN_14
#define BMP_MISO_GPIO_Port GPIOB
#define BMP_MOSI_Pin GPIO_PIN_15
#define BMP_MOSI_GPIO_Port GPIOB
#define MAG_SCL_Pin GPIO_PIN_8
#define MAG_SCL_GPIO_Port GPIOA
#define GPS_TX_Pin GPIO_PIN_9
#define GPS_TX_GPIO_Port GPIOA
#define GPS_RX_Pin GPIO_PIN_10
#define GPS_RX_GPIO_Port GPIOA
#define uLed_Pin GPIO_PIN_11
#define uLed_GPIO_Port GPIOA
#define NRF_CE_Pin GPIO_PIN_15
#define NRF_CE_GPIO_Port GPIOA
#define IMU2_SDA_Pin GPIO_PIN_3
#define IMU2_SDA_GPIO_Port GPIOB
#define NRF_MISO_Pin GPIO_PIN_4
#define NRF_MISO_GPIO_Port GPIOB
#define NRF_MOSI_Pin GPIO_PIN_5
#define NRF_MOSI_GPIO_Port GPIOB
#define IMU1_SCL_Pin GPIO_PIN_6
#define IMU1_SCL_GPIO_Port GPIOB
#define IMU1_SDA_Pin GPIO_PIN_7
#define IMU1_SDA_GPIO_Port GPIOB
#define MAG_SDA_Pin GPIO_PIN_8
#define MAG_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
