/**
 *	module: can.c
 *			This module stores all relevant data gathered from the CAN bus and
 *			sensors and makes it available for use in other modules.
 *
 *	creator: Max Heidbrink
 *	modifier_1: Alex Berwald
 *	modifier-mail: alexander.berwald@octanes.de
 *
 *	modifier_2: Matthias Bodensteiner
 *	modifier-mail: matthias.bodensteiner@octanes.de
 */

/* ================================ Includes ================================ */
#include "main.h"
#include "can.h"
#include "boot_HAL_G4_pfusch.h"
#include <string.h>



/* ================================ Defines ================================ */
#define ACTIVESUSPENSION_FR
#define ACTIVESUSPENSION_FL
#define ACTIVESUSPENSION_RR
#define ACTIVESUSPENSION_RL

/* ================================ Variables =============================== */
FDCAN_HandleTypeDef *hfdcan;

static bool heartbeatActive = false;

can_motor_vars_t motorFR = { 0 };
can_motor_vars_t motorFL = { 0 };
can_motor_vars_t motorRR = { 0 };
can_motor_vars_t motorRL = { 0 };
can_imu_vars_t imuData = { 0 };

int16_t accelData_0 = 0;
int16_t accelData_1 = 1;
int16_t accelData_2 = 2;

/* ================================ Function Definitions ==================== */

// For boot hal
void sendMsg(uint16_t id, uint8_t dlc, uint8_t *data){
    FDCAN_TxHeaderTypeDef TxHeader = { 0 };
    TxHeader.Identifier = id;
    TxHeader.IdType = FDCAN_STANDARD_ID;
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader.DataLength = dlc << 16;
    HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, &TxHeader, data);
}

/**
 * 	@brief	Initialize this module and load parameters from flash
 */
void can_init(FDCAN_HandleTypeDef *hfdcan_p){
	hfdcan = hfdcan_p;

	//CAN Filter configuration
	FDCAN_FilterTypeDef canFilter1;

	canFilter1.FilterIndex    = 0;
	canFilter1.FilterType     = FDCAN_FILTER_DUAL;
	canFilter1.FilterConfig   = FDCAN_FILTER_TO_RXFIFO0;
	canFilter1.FilterID1      = CAN_ID_HEARTBEAT;				//these are example CAN IDs
#ifdef I_AM_NODE_ACTIVE_SUSPENSION_FRONT  						//Todo: Austauschen: I_AM_NODE_ACTIVE_SUSPENSION_FR
	canFilter1.FilterID2         = 1;							//Beispielhafter CAN-Node Filter für FRONT_R
#elif I_AM_NODE_ACTIVE_SUSPENSION_FL
	canFilter1.FilterID2         = 1;
#elif I_AM_NODE_ACTIVE_SUSPENSION_RR
	canFilter1.FilterID2         = 1;
#elif I_AM_NODE_ACTIVE_SUSPENSION_RR
	canFilter1.FilterID2         = 1;
#endif
	HAL_FDCAN_ConfigFilter(hfdcan, &canFilter1);

    canFilter1.FilterIndex = 1;
    canFilter1.FilterID1 = BOOT_RX_ID;
    canFilter1.FilterID2 = 0x7ff;
    HAL_FDCAN_ConfigFilter(hfdcan, &canFilter1);

	//Starting the CAN-Module
	if (HAL_FDCAN_Start(hfdcan) != HAL_OK) {
	      Error_Handler();
	}
	//Activate Interrupts for CAN
	if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {   //last parameter (here 0) is ignored
	 Error_Handler();
	  }

}

/* ================================ Receive Data Functions ================ */
/**
 * 	@brief	CAN callback function called by the HAL CAN module.
 * 	@param	hcan pointer to a CAN_HandleTypeDef structure that contains
 *         the configuration information for the specified CAN.
 */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *rx, uint32_t _) {
    FDCAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8];

    if (HAL_FDCAN_GetRxMessage(rx, FDCAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK) {
        Error_Handler();
    }

    switch (RxHeader.Identifier) {

    case CAN_ID_HEARTBEAT:
    		HAL_GPIO_WritePin(CPU_LED_GREEN_GPIO_Port, CPU_LED_GREEN_Pin, RxData[0]);
    		heartbeatActive = true;
    		break;

#ifdef I_AM_NODE_ACTIVE_SUSPENSION_FRONT					//ToDO: Active_Suspension_FR austauschen

		case CAN_ID_ACTIVE_SUSPENSION_FRONT_SET:{			//ToDo: CAN_ID_ACTIVE_SUSPENSION_FR_SET
/*
			motorLeft.T0_state = RxData[0] & 1;
			motorLeft.T1_state = (RxData[0] >> 1) & 1;
			motorLeft.T2_state = ((RxData[0]&0b00000100)>>2);
			motorLeft.T3_state = ((RxData[0]&0b00001000)>>3);
			motorLeft.T4_state = ((RxData[0]&0b00010000)>>4);

			motorRight.T0_state = RxData[1]&0b00000001;
			motorRight.T1_state = ((RxData[1]&0b00000010)>>1);
			motorRight.T2_state = ((RxData[1]&0b00000100)>>2);
			motorRight.T3_state = ((RxData[1]&0b00001000)>>3);
			motorRight.T4_state = ((RxData[1]&0b00010000)>>4);
*/
			break;
		}
#elif I_AM_NODE_ACTIVE_SUSPENSION_FL
		case CAN_ID_ACTIVE_SUSPENSION_FL_SET:{

			/*
			 * Mosfet Value
			 */

			break;
		}
#elif I_AM_NODE_ACTIVE_SUSPENSION_RR
		CAN_ID_ACTIVE_SUSPENSION_RR_SET:{

			/*
			 * Mosfet Value
			 */

					break;
				}
#elif I_AM_NODE_ACTIVE_SUSPENSION_RL
		CAN_ID_ACTIVE_SUSPENSION_RL_SET:{

			/*
			 * Mosfet Value
			 */

					break;
				}
#endif

        default:
        {
            CanRxMsg msg = {0};
            msg.StdId = RxHeader.Identifier;
            msg.DLC = RxHeader.DataLength >> 16;
            memcpy(msg.Data, RxData, msg.DLC);
            boot_CANHandler(msg);
            break;
        }
        }
}

/* ================================ Send Data Functions ================ */

/**
 *  @brief  Wrapper function to enable CAN message transmission with timeout.
 *  @param  hfdcan: pointer to a CAN_HandleTypeDef structure that contains
 *          the configuration information for the specified CAN.
 *  @param  pHeader: pointer to a CAN_TxHeaderTypeDef structure.
 *  @param  aData: array containing the payload of the Tx frame.
 *  @param  Timeout: Timeout duration in ms. If equal to 0, the
 *          HAL_CAN_AddTxMessage function will be called exactly once.
 *  @retval HAL status
 */
HAL_StatusTypeDef HAL_FDCAN_AddTxMessageTimeout(FDCAN_HandleTypeDef *hfdcan, FDCAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t Timeout) {
    uint32_t tick = HAL_GetTick();
    do {
        if(HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, pHeader, aData) == HAL_OK)
            return HAL_OK;
    } while(HAL_GetTick() < tick + Timeout);
    return HAL_TIMEOUT;
}

/*
 * @brief: Debug Fct. for testing the PCB
 */
void can_sendDebug(void) {

	/*
	 * usefull data for debbugging!
	 */
}

/*
 * @brief: Send Active Suspension Data
 */

void can_sendState(void) {

	uint16_t spring_travel = adc_getValue(Spring_Travel);	//Reading Spring Travel Data

	FDCAN_TxHeaderTypeDef TxHeader = {0};
	TxHeader.IdType = FDCAN_STANDARD_ID;
	TxHeader.TxFrameType = FDCAN_DATA_FRAME;

#ifdef I_AM_NODE_ACTIVE_SUSPENSION_FRONT_RIGHT
	TxHeader.Identifier = CAN_ID_ACTIVE_SUSPENSION_FRONT_RIGHT;
#elif defined(I_AM_NODE_ACTIVE_SUSPENSION_FRONT_LEFT)
	TxHeader.Identifier = CAN_ID_ACTIVE_SUSPENSION_FRONT_LEFT;
#elif defined(I_AM_NODE_ACTIVE_SUSPENSION_REAR_RIGHT)
	TxHeader.Identifier = CAN_ID_ACTIVE_SUSPENSION_REAR_RIGHT;
#elif defined(I_AM_NODE_ACTIVE_SUSPENSION_REAR_LEFT)
	TxHeader.Identifier = CAN_ID_ACTIVE_SUSPENSION_REAR_LEFT;
#endif
	TxHeader.DataLength = FDCAN_DLC_BYTES_8;

	uint8_t TxData[8];

	TxData[0] = spring_travel & 0xFF;
	TxData[1] = spring_travel >> 8;
	TxData[2] = accelData_0 & 0xFF;
	TxData[3] = accelData_0 >> 8;
	TxData[4] = accelData_1 & 0xFF;
	TxData[5] = accelData_1 >> 8;
	TxData[6] = accelData_2 & 0xFF;
	TxData[7] = accelData_2 >> 8;


	HAL_FDCAN_AddTxMessageTimeout(hfdcan, &TxHeader, TxData, 5);
}

void can_getAccelData_0(int16_t _accelData_0) {

	accelData_0 = _accelData_0;
}

void can_getAccelData_1(int16_t _accelData_1) {

	accelData_1 = _accelData_1;
}

void can_getAccelData_2(int16_t _accelData_2) {

	accelData_2 = _accelData_2;
}

/* ================================ Functions ========================== */


void taskLED(void) {
	if (heartbeatActive)
		heartbeatActive = false;
	else
		HAL_GPIO_TogglePin(CPU_LED_GREEN_GPIO_Port, CPU_LED_GREEN_Pin);
}


