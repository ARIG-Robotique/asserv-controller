/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "itm_log.h"
#include "fdcan.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for heartBeatTimer */
osTimerId_t heartBeatTimerHandle;
const osTimerAttr_t heartBeatTimer_attributes = {
  .name = "heartBeatTimer"
};
/* Definitions for adcTimer */
osTimerId_t adcTimerHandle;
const osTimerAttr_t adcTimer_attributes = {
  .name = "adcTimer"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void notifyVersion(FDCAN_TxHeaderTypeDef txHeader);
void notifyMotor(FDCAN_TxHeaderTypeDef txHeader, Motor motor);
void notifyEncoder(FDCAN_TxHeaderTypeDef txHeader, Encoder encoder);

void setMotorSpeed(Motor motor);

Encoder getEncoder(uint8_t encoderIndex);
Motor getMotor(uint8_t motorIndex);

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void heartBeatCallback(void *argument);
void adcCallback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  LOG_INFO("freertos: Init FreeRTOS");
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of heartBeatTimer */
  heartBeatTimerHandle = osTimerNew(heartBeatCallback, osTimerPeriodic, NULL, &heartBeatTimer_attributes);

  /* creation of adcTimer */
  adcTimerHandle = osTimerNew(adcCallback, osTimerPeriodic, NULL, &adcTimer_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  LOG_INFO("mainTask: Start");


  LOG_INFO("mainTask: Init variables");
  encoderConfiguration.encoder1Enabled = false;
  encoderConfiguration.encoder1Inverted = false;
  encoderConfiguration.encoder2Enabled = false;
  encoderConfiguration.encoder2Inverted = false;
  encoderConfiguration.encoder3Enabled = false;
  encoderConfiguration.encoder3Inverted = false;
  encoderConfiguration.encoder4Enabled = false;
  encoderConfiguration.encoder4Inverted = false;

  motorConfiguration.motor1Enabled = false;
  motorConfiguration.motor1Inverted = false;
  motorConfiguration.motor2Enabled = false;
  motorConfiguration.motor2Inverted = false;
  motorConfiguration.motor3Enabled = false;
  motorConfiguration.motor3Inverted = false;
  motorConfiguration.motor4Enabled = false;
  motorConfiguration.motor4Inverted = false;

  encoder1.value = 0.0;
  encoder2.value = 0.0;
  encoder3.value = 0.0;
  encoder4.value = 0.0;

  motor1.speed = 0.0;
  motor1.current = 0.0;
  motor1.fault = false;
  motor2.speed = 0.0;
  motor2.current = 0.0;
  motor2.fault = false;
  motor3.speed = 0.0;
  motor3.current = 0.0;
  motor3.fault = false;
  motor4.speed = 0.0;
  motor4.current = 0.0;
  motor4.fault = false;

  LOG_INFO("mainTask: Start FDCan listener");
  HAL_FDCAN_Start(&hfdcan1);

  // Start timers after boot init
  osTimerStart(heartBeatTimerHandle, 1000);
  osTimerStart(adcTimerHandle, 2000);

  /* Prepare FDCAN Tx */
  FDCAN_TxHeaderTypeDef TxHeader;

  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  TxHeader.MessageMarker = 0;
  TxHeader.Identifier = 0;
  TxHeader.DataLength = 0;

  /* Infinite loop */
  // ReSharper disable once CppDFAEndlessLoop
  while(true)
  {
    /* Check if a message is come */
    FDCAN_RxHeaderTypeDef RxHeader;
    uint8_t               RxData[1];
    HAL_StatusTypeDef canRequest = HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader, RxData);
    if (canRequest == HAL_OK) {
      TxHeader.Identifier = RxHeader.Identifier;
      if (RxHeader.Identifier == GET_ENCODER_ID) {
        notifyEncoder(TxHeader, getEncoder(RxData[0]));

      } else if (RxHeader.Identifier == SET_MOTOR_SPEED_ID) {
        setMotorSpeed(getMotor(RxData[0]));

      } else if (RxHeader.Identifier == SET_MOTOR_CONFIGURATION_ID) {


      } else if (RxHeader.Identifier == SET_ENCODER_CONFIGURATION_ID) {


      } else if (RxHeader.Identifier == GET_VERSION) {
        notifyVersion(TxHeader);

      } else {
        LOG_WARN("mainTask: Unknown message");
      }
    }
    osDelay(50);

  }
  /* USER CODE END StartDefaultTask */
}

/* heartBeatCallback function */
void heartBeatCallback(void *argument)
{
  /* USER CODE BEGIN heartBeatCallback */
  HAL_GPIO_TogglePin(HEART_BEAT_GPIO_Port, HEART_BEAT_Pin);
  /* USER CODE END heartBeatCallback */
}

/* adcCallback function */
void adcCallback(void *argument)
{
  /* USER CODE BEGIN adcCallback */

  /* USER CODE END adcCallback */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void notifyVersion(FDCAN_TxHeaderTypeDef txHeader) {
  LOG_INFO("notifyVersion");

  // Notify
  txHeader.Identifier = GET_VERSION;
  txHeader.DataLength = sizeof(VERSION_SHORT);

  uint8_t txBuffer[sizeof(VERSION_SHORT)];
  for (int i = 0 ; i < sizeof(VERSION_SHORT) ; i++) {
    txBuffer[i] = VERSION_SHORT[i];
  }

  if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &txHeader, txBuffer) != HAL_OK) {
    /* Transmission request Error */
    Error_Handler();
  }
}

void notifyMotor(FDCAN_TxHeaderTypeDef txHeader, Motor motor) {

}
void notifyEncoder(FDCAN_TxHeaderTypeDef txHeader, Encoder encoder) {

}

void setMotorSpeed(Motor motor) {

}

Encoder getEncoder(uint8_t encoderIndex) {
  switch (encoderIndex) {
    case 4:
      return encoder4;
    case 3:
      return encoder3;
    case 2:
      return encoder2;
    default:
      return encoder1;
  }
}

Motor getMotor(uint8_t motorIndex) {
  switch (motorIndex) {
    case 4:
      return motor4;
    case 3:
      return motor3;
    case 2:
      return motor2;
    default:
      return motor1;
  }
}
/* USER CODE END Application */
