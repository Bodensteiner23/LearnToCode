
#include "ff.h"
#include "stdio.h"
#include "integer.h"
#include "main.h"
#include "sd_card.h"

FRESULT fr;
FATFS *fs;		//ToDo: Check if second *fs/fs is needed for free storage
FIL fil;

DWORD fre_clust, fre_sect, tot_sect;

float accel_x_Data;
float accel_y_Data;
float accel_z_Data;

//float append_data_array[] = {accel_x_Data, accel_y_Data, accel_z_Data};



int initFileSystem(void) {

    /* Open or create a log file and ready to append */
    f_mount(fs, "", 0);											//ToDo: Check if *fs is needed
    fr = open_append(&fil, "logfile.sdlogs");
    if (fr != FR_OK) {
    	sd_card_ErrorHandler();
    }

    //Print File Storage
    fr = f_getfree("1:", &fre_clust, &fs);
    if (fr != FR_OK) {
    	sd_card_ErrorHandler();
    }
    /* Get total sectors and free sectors */
    tot_sect = (fs->n_fatent - 2) * fs->csize;
    fre_sect = fre_clust * fs->csize;

    /* Print the free space (assuming 512 bytes/sector) */
    myprintf("%10lu KiB total drive space.\n%10lu KiB available.\n", tot_sect / 2, fre_sect / 2);


    //Print Col Header
    /* Append a line */
    f_printf(&fil, "accel_x_Data, accel_y_Data, accel_z_Data \n");


    BYTE readBuf[4096];

    TCHAR* rres = f_gets((TCHAR*)readBuf, 4096, &fil);
    fr = f_open(&fil, "logfile.sdlogs", FA_READ);

    if(rres != 0) {
   		myprintf("Read string from 'test.csv' contents: %s\r\n", readBuf);
   	  } else {
   		myprintf("f_gets error (%i)\r\n", fr);
   	  }

    /* Close the file */
    f_close(&fil);

    return 0;
}



//FRESULT open_append (
//    FIL* fp,            /* [OUT] File object to create */
//    const char* path   /* [IN]  File name to be opened */
//)
//{
//    FRESULT _fr;
//
//    /* Opens an existing file. If not exist, creates a new file. */
//    _fr = f_open(fp, path, FA_WRITE | FA_OPEN_ALWAYS);
//    if (_fr == FR_OK) {
//        /* Seek to end of the file to append data */
//        _fr = f_lseek(fp, f_size(fp));
//        if (_fr != FR_OK)
//            f_close(fp);
//    }
//    return _fr;
//}




//void writeData(float append_data[]) {
//	//Jump to end of file
//	fr = open_append(&fil, "logfile.csv");
//
//    BYTE buffer[4096] = append_data;   /* File copy buffer */
//
//    fr = f_write(fp, buff, btw, bw)
//
//}


void sd_card_ErrorHandler(void) {
	while(1) {
		// Error Handler
	}
}









