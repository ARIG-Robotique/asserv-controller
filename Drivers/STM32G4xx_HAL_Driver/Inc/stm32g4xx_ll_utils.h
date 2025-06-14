/**
  ******************************************************************************
  * @file    stm32g4xx_ll_utils.h
  * @author  MCD Application Team
  * @brief   Header file of UTILS LL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The LL UTILS driver contains a set of generic APIs that can be
    used by user:
      (+) Device electronic signature
      (+) Timing functions
      (+) PLL configuration functions

  @endverbatim
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32G4xx_LL_UTILS_H
#define STM32G4xx_LL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx.h"

/** @addtogroup STM32G4xx_LL_Driver
  * @{
  */

/** @defgroup UTILS_LL UTILS
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup UTILS_LL_Private_Constants UTILS Private Constants
  * @{
  */

/* Max delay can be used in LL_mDelay */
#define LL_MAX_DELAY                  0xFFFFFFFFU

/**
 * @brief Unique device ID register base address
 */
#define UID_BASE_ADDRESS              UID_BASE

/**
 * @brief Flash size data register base address
 */
#define FLASHSIZE_BASE_ADDRESS        FLASHSIZE_BASE

/**
 * @brief Package data register base address
 */
#define PACKAGE_BASE_ADDRESS          PACKAGE_BASE

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup UTILS_LL_Private_Macros UTILS Private Macros
  * @{
  */
/**
  * @}
  */
/* Exported types ------------------------------------------------------------*/
/** @defgroup UTILS_LL_ES_INIT UTILS Exported structures
  * @{
  */
/**
  * @brief  UTILS PLL structure definition
  */
typedef struct
{
  uint32_t PLLM;   /*!< Division factor for PLL VCO input clock.
                        This parameter can be a value of @ref RCC_LL_EC_PLLM_DIV

                        This feature can be modified afterwards using unitary function
                        @ref LL_RCC_PLL_ConfigDomain_SYS(). */

  uint32_t PLLN;   /*!< Multiplication factor for PLL VCO output clock.
                        This parameter must be a number between Min_Data = 8 and Max_Data = 86

                        This feature can be modified afterwards using unitary function
                        @ref LL_RCC_PLL_ConfigDomain_SYS(). */

  uint32_t PLLR;   /*!< Division for the main system clock.
                        This parameter can be a value of @ref RCC_LL_EC_PLLR_DIV

                        This feature can be modified afterwards using unitary function
                        @ref LL_RCC_PLL_ConfigDomain_SYS(). */
} LL_UTILS_PLLInitTypeDef;

/**
  * @brief  UTILS System, AHB and APB buses clock configuration structure definition
  */
typedef struct
{
  uint32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_LL_EC_SYSCLK_DIV

                                       This feature can be modified afterwards using unitary function
                                       @ref LL_RCC_SetAHBPrescaler(). */

  uint32_t APB1CLKDivider;        /*!< The APB1 clock (PCLK1) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_LL_EC_APB1_DIV

                                       This feature can be modified afterwards using unitary function
                                       @ref LL_RCC_SetAPB1Prescaler(). */

  uint32_t APB2CLKDivider;        /*!< The APB2 clock (PCLK2) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_LL_EC_APB2_DIV

                                       This feature can be modified afterwards using unitary function
                                       @ref LL_RCC_SetAPB2Prescaler(). */

} LL_UTILS_ClkInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup UTILS_LL_Exported_Constants UTILS Exported Constants
  * @{
  */

/** @defgroup UTILS_EC_HSE_BYPASS HSE Bypass activation
  * @{
  */
#define LL_UTILS_HSEBYPASS_OFF        0x00000000U       /*!< HSE Bypass is not enabled                */
#define LL_UTILS_HSEBYPASS_ON         0x00000001U       /*!< HSE Bypass is enabled                    */
/**
  * @}
  */

/** @defgroup UTILS_EC_PACKAGETYPE PACKAGE TYPE
  * @{
  */
#define LL_UTILS_PACKAGETYPE_LQFP64             0x00000000U /*!< LQFP64 package type                      */
#define LL_UTILS_PACKAGETYPE_WLCSP64            0x00000001U /*!< WLCSP64 package type                     */
#if defined (STM32G411xB) || defined (STM32G411xC) || defined (STM32G431xx) || defined (STM32G414xx) || defined (STM32G441xx) || \
    defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G483xx) || defined (STM32G474xx) || defined (STM32G484xx)
#define LL_UTILS_PACKAGETYPE_LQFP100_LQFP80     0x00000002U /*!< LQFP100 \ LQFP80 package type             */
#define LL_UTILS_PACKAGETYPE_LQFP100 LL_UTILS_PACKAGETYPE_LQFP100_LQFP80  /*!< For backward compatibility  */
#else
#define LL_UTILS_PACKAGETYPE_LQFP100            0x00000002U /*!< LQFP100 package type                      */
#endif /* STM32G411xB || STM32G411xC || STM32G431xx || STM32G414xx || STM32G441xx || STM32G471xx || STM32G473xx || STM32G483xx || STM32G474xx || STM32G484xx */
#define LL_UTILS_PACKAGETYPE_WLCSP81            0x00000005U /*!< WLCSP81 package type                      */
#define LL_UTILS_PACKAGETYPE_LQFP128_UFBGA121   0x00000007U /*!< LQFP128 \ UFBGA121 package type           */
#define LL_UTILS_PACKAGETYPE_LQFP128 LL_UTILS_PACKAGETYPE_LQFP128_UFBGA121 /*!< For backward compatibility */
#define LL_UTILS_PACKAGETYPE_UFQFPN32           0x00000008U /*!< UFQFPN32 package type                     */
#define LL_UTILS_PACKAGETYPE_LQFP32             0x00000009U /*!< LQFP32 package type                       */
#define LL_UTILS_PACKAGETYPE_UFQFPN48           0x0000000AU /*!< UFQFPN48 package type                     */
#define LL_UTILS_PACKAGETYPE_LQFP48             0x0000000BU /*!< LQFP48 package type                       */
#define LL_UTILS_PACKAGETYPE_WLCSP49            0x0000000CU /*!< WLCSP49 package type                      */
#define LL_UTILS_PACKAGETYPE_UFBGA64            0x0000000DU /*!< UFBGA64 package type                      */
#define LL_UTILS_PACKAGETYPE_TFBGA100           0x0000000EU /*!< TFBGA100 package type                     */
#define LL_UTILS_PACKAGETYPE_UFBGA100 LL_UTILS_PACKAGETYPE_TFBGA100  /*!< For backward compatibility       */
#define LL_UTILS_PACKAGETYPE_LQFP48_EBIKE       0x00000010U /*!< LQFP48 EBIKE package type                 */
#if defined (STM32G491xx) || defined (STM32G4A1xx)
#define LL_UTILS_PACKAGETYPE_LQFP80             0x00000011U /*!< LQFP80 package type                       */
#endif /* STM32G491xx || STM32G4A1xx */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup UTILS_LL_Exported_Functions UTILS Exported Functions
  * @{
  */

/** @defgroup UTILS_EF_DEVICE_ELECTRONIC_SIGNATURE DEVICE ELECTRONIC SIGNATURE
  * @{
  */

/**
  * @brief  Get Word0 of the unique device identifier (UID based on 96 bits)
  * @retval UID[31:0]: X and Y coordinates on the wafer expressed in BCD format
  */
__STATIC_INLINE uint32_t LL_GetUID_Word0(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)UID_BASE_ADDRESS)));
}

/**
  * @brief  Get Word1 of the unique device identifier (UID based on 96 bits)
  * @retval UID[63:32]: Wafer number (UID[39:32]) & LOT_NUM[23:0] (UID[63:40])
  */
__STATIC_INLINE uint32_t LL_GetUID_Word1(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(UID_BASE_ADDRESS + 4U))));
}

/**
  * @brief  Get Word2 of the unique device identifier (UID based on 96 bits)
  * @retval UID[95:64]: Lot number (ASCII encoded) - LOT_NUM[55:24]
  */
__STATIC_INLINE uint32_t LL_GetUID_Word2(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(UID_BASE_ADDRESS + 8U))));
}

/**
  * @brief  Get Flash memory size
  * @note   This bitfield indicates the size of the device Flash memory expressed in
  *         Kbytes. As an example, 0x040 corresponds to 64 Kbytes.
  * @retval FLASH_SIZE[15:0]: Flash memory size
  */
__STATIC_INLINE uint32_t LL_GetFlashSize(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)FLASHSIZE_BASE_ADDRESS)) & 0x0000FFFFUL);
}

/**
  * @brief  Get Package type
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UTILS_PACKAGETYPE_LQFP64
  *         @arg @ref LL_UTILS_PACKAGETYPE_LQFP100
  *         @arg @ref LL_UTILS_PACKAGETYPE_WLCSP81
  *         @arg @ref LL_UTILS_PACKAGETYPE_LQFP128
  *         @arg @ref LL_UTILS_PACKAGETYPE_UFQFPN32
  *         @arg @ref LL_UTILS_PACKAGETYPE_LQFP32
  *         @arg @ref LL_UTILS_PACKAGETYPE_UFQFPN48
  *         @arg @ref LL_UTILS_PACKAGETYPE_LQFP48
  *         @arg @ref LL_UTILS_PACKAGETYPE_WLCSP49
  *         @arg @ref LL_UTILS_PACKAGETYPE_UFBGA64
  *         @arg @ref LL_UTILS_PACKAGETYPE_UFBGA100
  *         @arg @ref LL_UTILS_PACKAGETYPE_LQFP48_EBIKE
  *
*/
__STATIC_INLINE uint32_t LL_GetPackageType(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)PACKAGE_BASE_ADDRESS)) & 0x1FU);
}

/**
  * @}
  */

/** @defgroup UTILS_LL_EF_DELAY DELAY
  * @{
  */

/**
  * @brief  This function configures the Cortex-M SysTick source of the time base.
  * @param  HCLKFrequency HCLK frequency in Hz (can be calculated thanks to RCC helper macro)
  * @note   When a RTOS is used, it is recommended to avoid changing the SysTick
  *         configuration by calling this function, for a delay use rather osDelay RTOS service.
  * @param  Ticks Frequency of Ticks (Hz)
  * @retval None
  */
__STATIC_INLINE void LL_InitTick(uint32_t HCLKFrequency, uint32_t Ticks)
{
  /* Configure the SysTick to have interrupt in 1ms time base */
  SysTick->LOAD  = (uint32_t)((HCLKFrequency / Ticks) - 1UL);  /* set reload register */
  SysTick->VAL   = 0UL;                                       /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_ENABLE_Msk;                   /* Enable the Systick Timer */
}

void        LL_Init1msTick(uint32_t HCLKFrequency);
void        LL_mDelay(uint32_t Delay);

/**
  * @}
  */

/** @defgroup UTILS_EF_SYSTEM SYSTEM
  * @{
  */

void        LL_SetSystemCoreClock(uint32_t HCLKFrequency);
ErrorStatus LL_SetFlashLatency(uint32_t HCLKFrequency);
ErrorStatus LL_PLL_ConfigSystemClock_HSI(LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct,
                                         LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
ErrorStatus LL_PLL_ConfigSystemClock_HSE(uint32_t HSEFrequency, uint32_t HSEBypass,
                                         LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32G4xx_LL_UTILS_H */
