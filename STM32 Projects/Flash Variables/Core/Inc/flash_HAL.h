/**
 * flash_HAL.h
 *
 * created on: Mar 26, 2016
 * author: Max Heidbrink
 * autor-mail: max.heidbrink@octanes.de
 *
 * uses: stm32f1xx_hal, stm32f1xx_hal_cortex, stm32f1xx_hal_flash
 */

#ifndef FLASH_H
#define FLASH_H

/* ================================ How to use ============================== */
/*
 *  WARNING:
 * This Module has been designed to work with stm32f103f6 (32kbytes of flash).
 * It is VERY likely this module will NOT work with other chips, especially with
 * chips of different flash sizes.
 *
 *  MODIFY LINKER SETTINGS:
 * In CooCox project configuration, Link tab: Change Size of IROM1 to 0x00007C00
 * and make sure Start is set to 0x08000000.
 *
 *  ADD STUFF TO main.h:
 * Add:
 *
 * //Flash defines
 * #ifndef FLASH_PARAMETERS
 * #define FLASH_PARAMETERS
 *
 * #define FLASH_NUMBER_OF_PARAMETERS [no greater than 512]
 * typedef enum {
 *     some_Parameter	= 0x01;
 *     other_Parameter	= 0x02;
 *     ...
 * } flashParam_t;
 * #endif // FLASH_PARAMETERS
 *
 * to main.h
 *
 *  BOOTLOADER:
 * This module will be updated with support for the new bootloader (once that
 * is finished and tested), so make sure to update this module and check back
 * for new instructions and configurations.
 *
 *  PLONE-LINK:
 * http://hom.mfk.uni-erlangen.de:8080/homoplone/elektronik/know-how/software/hal-bibiliothek/flash_hal
 */

/* ================================ Includes ================================ */

#include "main.h"
#include <stdbool.h>

/* ================================ Function Declarations =================== */

/**
 * 	@brief	Initializes the flash module and loads the bootloader parameters into RAN
 */
void flash_init(void);

/**
 *  @brief	Registers a variable for use as flash parameter and loads its value
 *  		from flash into the RAM buffer. If the content in flash is empty
 *  		(i. e. 0xFFFF), the variable in RAM is not overwritten.
 *  @param	variable: A pointer to the variable in RAM.
 *  @param	parameter: The corresponding flash parameter.
 */
void flash_registerVariable(uint32_t* variable, flashParam_t parameter);

/**
 *  @brief	Change a parameter in RAM, call flash_saveFlash() to write all
 *  		parameters into flash.
 *  @param	parameter: The parameter to overwrite.
 *  @param	value: The value to write.
 */
void flash_write(flashParam_t parameter, uint32_t value);

/**
 *  @brief	Read a parameter from the RAM buffer.
 *  @param	parameter: The parameter to read.
 */
uint32_t flash_read(flashParam_t parameter);

/**
 *	@brief	Save all parameters into flash
 *	@retval	true if erase and write successful
 */
bool flash_savetoFlash(void);

#endif /* FLASH_H */
