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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TMC_STATUS_Pin GPIO_PIN_13
#define TMC_STATUS_GPIO_Port GPIOC
#define TMC_ENABLE_Pin GPIO_PIN_14
#define TMC_ENABLE_GPIO_Port GPIOC
#define ENC1_A_Pin GPIO_PIN_0
#define ENC1_A_GPIO_Port GPIOA
#define ENC1_B_Pin GPIO_PIN_1
#define ENC1_B_GPIO_Port GPIOA
#define CPU_GS0_Pin GPIO_PIN_2
#define CPU_GS0_GPIO_Port GPIOA
#define CPU_GS1_Pin GPIO_PIN_3
#define CPU_GS1_GPIO_Port GPIOA
#define SPI1_CS_SD_Pin GPIO_PIN_4
#define SPI1_CS_SD_GPIO_Port GPIOA
#define SPI1_SCK_SD_Pin GPIO_PIN_5
#define SPI1_SCK_SD_GPIO_Port GPIOA
#define SPI1_MISO_SD_Pin GPIO_PIN_6
#define SPI1_MISO_SD_GPIO_Port GPIOA
#define SPI1_MOSI_SD_Pin GPIO_PIN_7
#define SPI1_MOSI_SD_GPIO_Port GPIOA
#define ADC2_I_TOTAL_Pin GPIO_PIN_2
#define ADC2_I_TOTAL_GPIO_Port GPIOB
#define CPU_LED_GREEN_Pin GPIO_PIN_13
#define CPU_LED_GREEN_GPIO_Port GPIOB
#define ACC_SENSOR_INT2_Pin GPIO_PIN_14
#define ACC_SENSOR_INT2_GPIO_Port GPIOB
#define ACC_SENSOR_INT1_Pin GPIO_PIN_15
#define ACC_SENSOR_INT1_GPIO_Port GPIOB
#define CPU_R_ARRAY_2_Pin GPIO_PIN_8
#define CPU_R_ARRAY_2_GPIO_Port GPIOA
#define CPU_R_ARRAY_4_Pin GPIO_PIN_9
#define CPU_R_ARRAY_4_GPIO_Port GPIOA
#define CPU_R_ARRAY_8_Pin GPIO_PIN_10
#define CPU_R_ARRAY_8_GPIO_Port GPIOA
#define SPI3_CS_TMC_Pin GPIO_PIN_15
#define SPI3_CS_TMC_GPIO_Port GPIOA
#define SPI3_SCK_TMC_Pin GPIO_PIN_3
#define SPI3_SCK_TMC_GPIO_Port GPIOB
#define SPI4_MISO_TMC_Pin GPIO_PIN_4
#define SPI4_MISO_TMC_GPIO_Port GPIOB
#define SPI4_MOSI_TMC_Pin GPIO_PIN_5
#define SPI4_MOSI_TMC_GPIO_Port GPIOB
#define CPU_PWM_LVL2_Pin GPIO_PIN_6
#define CPU_PWM_LVL2_GPIO_Port GPIOB
#define CPU_R_ARRAY_1_Pin GPIO_PIN_7
#define CPU_R_ARRAY_1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

#define	ADC_NUMBER_OF_CHANNELS	3

#define Spring_Travel 1
#define CPU_TEMP_BOARD 2

/****
 *	@brief Calls a function to initialize the system
 ****/
void system_init(void);

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
