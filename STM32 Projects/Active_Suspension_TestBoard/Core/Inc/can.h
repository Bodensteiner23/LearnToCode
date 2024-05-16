/**
 *	module: can.c
 *			This module fetches and stores all relevant data gathered from the CAN bus and
 *			sensors and makes it available for use in other modules.
 *
 *	creator: Max Heidbrink
 *	modifier: Alex Berwald
 *	modifier-mail: alexander.berwald@octanes.de
 *	modifier 2: Matthias Bodensteiner
 *	modifier-mail: matthias.bodensteiner@octanes.de
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CAN_H_
#define CAN_H_


/* Define which Active Suspension you are using */

//#define I_AM_NODE_ACTIVE_SUSPENSION_FRONT_RIGHT
#define I_AM_NODE_ACTIVE_SUSPENSION_FRONT_LEFT
//#define I_AM_NODE_ACTIVE_SUSPENSION_REAR_RIGHT
//#define I_AM_NODE_ACTIVE_SUSPENSION_REAR_LEFT

/* ================================ Includes ================================ */
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_fdcan.h"
#include "CAN_IDs.h"
#include "stdbool.h"



/* ================================ Typedefs ================================ */

/*
 * 	@brief:	Struct containing all motor data
 *
 */
typedef struct {

	uint16_t motorVoltage;
	uint16_t motorCurrent;
	uint16_t springTravel;
	uint16_t rotationSpeed;		//Measured by the Encoder placed on the PCB
	uint16_t Mosfet_state;
} can_motor_vars_t;

/*
 * @brief: struct containing all IMU data
 */
typedef struct {
	double Acc_X;
	double Acc_Y;
	double Acc_Z;
} can_imu_vars_t;


/* ================================ Function Declarations =================== */

/**
 * 	@brief	Initialize this module and load parameters from flash
 */
void can_init(FDCAN_HandleTypeDef *hfdcan_p);

void can_sendDebug(void);
void can_sendState(void);

//void can_calculateADCValues(void);

void taskLED(void);

void can_getAccelData_0(int16_t _accelData_0);
void can_getAccelData_1(int16_t _accelData_1);
void can_getAccelData_2(int16_t _accelData_2);

/**
 * 	@brief	Get copy of the motor struct
 */
/*can_motor_vars_t can_getMotorLeftVars(void);
can_motor_vars_t can_getMotorRightVars(void);
can_imu_vars_t can_getImuVars(void);*/
#endif /* CAN_H_ */












