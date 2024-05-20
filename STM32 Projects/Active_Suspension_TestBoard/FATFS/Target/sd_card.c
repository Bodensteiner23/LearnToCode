
#include "ff.h"
#include "stdio.h"
#include "integer.h"

FRESULT fr;
FATFS *fs;		//ToDo: Check if second *fs/fs is needed for free storage
FIL fil;

DWORD fre_clust, fre_sect, tot_sect;

float accel_x_Data;
float accel_y_Data;
float accel_z_Data;



void sd_card_ErrorHandler(void) {
	while(1) {
		// Error Handler
	}
}

FRESULT open_append (
    FIL* fp,            /* [OUT] File object to create */
    const char* path   /* [IN]  File name to be opened */
)
{
    FRESULT fr;



    /* Opens an existing file. If not exist, creates a new file. */
    fr = f_open(fp, path, FA_WRITE | FA_OPEN_ALWAYS);
    if (fr == FR_OK) {
        /* Seek to end of the file to append data */
        fr = f_lseek(fp, f_size(fp));
        if (fr != FR_OK)
            f_close(fp);
    }
    return fr;
}


int initFileSystem(void) {

    /* Open or create a log file and ready to append */
    f_mount(fs, "", 0);											//ToDo: Check if *fs is needed
    fr = open_append(&fil, "logfile.csv");
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
    printf("%10lu KiB total drive space.\n%10lu KiB available.\n", tot_sect / 2, fre_sect / 2);


    //Col header
    /* Append a line */
    f_printf(&fil, "%f, %f, %f \n", accel_x_Data, accel_y_Data, accel_z_Data);

    /* Close the file */
    f_close(&fil);

    return 0;
}


//void writeData(float append_data[]) {
//	//Jump to end of file
//	fr = open_append(&fil, "logfile.csv");
//
//    BYTE buffer[4096] = append_data;   /* File copy buffer */
//
//}











