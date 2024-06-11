/**
 * flash_HAL.h
 *
 * created on: Mar 26, 2016
 * author: Max Heidbrink
 * autor-mail: max.heidbrink@octanes.de
 *
 * uses: stm32f1xx_hal, stm32f1xx_hal_cortex, stm32f1xx_hal_flash
 */

/* ================================ Includes ================================ */

#include <stdint.h>
#include "flash_HAL.h"
#include "stm32f1xx_hal.h"

/* ================================ Defines ================================= */

/**
 * 	@brief	Start address of the flash page to use for all parameters
 */

#define FLASH_PAGE 0x0801F800

/**
 * 	@brief	Start address of the flash section to use for flash parameters.
 * 			Starts at 7kB ( + (16*4)B for bootloader Parameters)
 */
//#define FLASH_ADDRESS 0x08007C00	//Page 31 in STM32F103
#define FLASH_ADDRESS 0x0801F800

#if FLASH_NUMBER_OF_PARAMETERS > 256
#error "FLASH_NUMBER_OF_PARAMETERS is too high"
#endif

/* ================================ parameters =============================== */

/**
 *  @brief Array of pointers to the linked variables in RAM
 */
static uint32_t* variableInRAM[FLASH_NUMBER_OF_PARAMETERS];

static bool init_done = false;

/* ================================ Code ==================================== */

/**
 * 	@brief	Initializes the flash module and loads the bootloader parameters into RAN
 */
void flash_init(void) {

	init_done = true;
}

/**
 *  @brief	Registers a variable for use as flash parameter and loads its value
 *  		from flash into the RAM buffer. If the content in flash is empty
 *  		(i. e. 0xFFFF), the variable in RAM is not overwritten.
 *  @param	variable: A pointer to the variable in RAM.
 *  @param	parameter: The corresponding flash parameter.
 */
void flash_registerVariable(uint32_t* variable, flashParam_t parameter) {
	if(!init_done) flash_init();

	variableInRAM[parameter] = variable;

	uint32_t value = *((__IO uint32_t*) (FLASH_ADDRESS + parameter*4));
	if(value != 0xFFFFFFFF) *variable = value;
}

/**
 *  @brief	Change a parameter in RAM, call flash_saveFlash() to write all
 *  		parameters into flash.
 *  @param	parameter: The parameter to overwrite.
 *  @param	value: The value to write.
 */
void flash_write(flashParam_t parameter, uint32_t value) {
	*variableInRAM[parameter] = value;
}

/**
 *  @brief	Read a parameter from the RAM buffer.
 *  @param	parameter: The parameter to read.
 */
uint32_t flash_read(flashParam_t parameter) {
	return *variableInRAM[parameter];
}

/**
 *	@brief	Save all parameters into flash
 *	@retval	true if erase and write successful
 */
bool flash_savetoFlash(void) {
	if(!init_done) flash_init();

	HAL_FLASH_Unlock();
	uint32_t PageError = 0;

	FLASH_EraseInitTypeDef EraseInitStruct;
	EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.PageAddress = FLASH_PAGE;
	EraseInitStruct.NbPages     = 1;
	HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);
	if(PageError != 0xFFFFFFFF) return false;

	for(uint8_t i = 0; i < FLASH_NUMBER_OF_PARAMETERS; i++) {
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,
				FLASH_ADDRESS + i*4, *variableInRAM[i])
			!= HAL_OK) return false;
	}
	HAL_FLASH_Lock();
	return true;
}
