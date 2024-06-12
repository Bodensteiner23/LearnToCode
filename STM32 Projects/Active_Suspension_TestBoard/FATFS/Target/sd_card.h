#ifndef TARGET_SD_CARD_H_
#define TARGET_SD_CARD_H_

#include "ff.h"

int initFileSystem(void);

FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* path   /* [IN]  File name to be opened */
);

void sd_card_ErrorHandler(void);
#endif /* TARGET_SD_CARD_H_ */
