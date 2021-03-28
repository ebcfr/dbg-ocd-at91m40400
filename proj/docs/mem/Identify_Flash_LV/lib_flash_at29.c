//*-----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*-----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*-----------------------------------------------------------------------------
//* File Name               : lib_flash_at29.c
//* Object                  : FLASH programmer for :
//*                             - AT29LV1024
//*                             - AT29C020
//*
//* 1.0 22/11/00 JPP        : Creation
//*-----------------------------------------------------------------------------


//* --------------------------- include file ----------------------------------
#include    "lib_flash_at29.h"

//* ------------------------------  Local variable ----------------------------
/* #define RED			2
#define GREEN		4
#define YELLOW		16	
*/
#define R_BIT	1
#define W_BIT	2


//* test
/* void led_on(int state, int led){

	int *pt;
	
	if (state){
		pt=(int *)0xFFFF0030;	
		*pt = led;
	} else {
		pt=(int *)0xFFFF0034;	
		*pt = led;
	}
}
*/

//* --------------------------- Static function -------------------------------

//*----------------------------------------------------------------------------
//* Function Name       : read_dbg_data
//* Object              : read debug communication data register
//* Input Parameters    : 
//* Output Parameters   : R0
//*----------------------------------------------------------------------------
extern u_int read_dbg_data(void);

//*----------------------------------------------------------------------------
//* Function Name       : read_dbg_control
//* Object              : read debug communication data register
//* Input Parameters    : 
//* Output Parameters   : R0
//*----------------------------------------------------------------------------
extern u_int read_dbg_control(void);

//*----------------------------------------------------------------------------
//* Function Name       : write_dbg_data
//* Object              : read debug communication data register
//* Input Parameters    : Val = R0
//* Output Parameters   : 
//*----------------------------------------------------------------------------
extern void write_dbg_data(u_int val);


//*----------------------------------------------------------------------------
//* Function Name       : Pause
//* Object              : read debug communication data register
//* Input Parameters    : Val = R0
//* Output Parameters   : 
//*----------------------------------------------------------------------------
void Pause(){
	
	int count;
	
    for (count=0; count < TIME_OUT_AT29; count++)
    {
        /* Do nothing - just wait */
    }

}

//*----------------------------------------------------------------------------
//* Function Name       : main
//* Object              : Get data and stored them in flash
//* Input Parameters    : none
//* Output Parameters   : none
//*----------------------------------------------------------------------------
int main(){

    u_int i;
    u_int base_addr;
    flash_word manuf_code, device_code;

//*	led_on(0, YELLOW);

	//* Get base address
	while( ((read_dbg_control() & R_BIT) != R_BIT) ); //* Wait a new data to read
	base_addr = read_dbg_data();
    
    Pause();

    /* Enter Software Product Identification Mode  */
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = FLASH_WORD_COM_1;
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_2)) = FLASH_WORD_COM_2;
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = ID_IN_WORD_COM;
 
    /* Wait 10 ms for the device to change state */
    Pause();

    /* Read Manufacturer and device code from the device */
    manuf_code  = (*((volatile short *) (base_addr + 0))) & 0x00FF;
    device_code = (*((volatile short *) (base_addr + 2))) & 0x00FF;

    /* Exit Software Product Identification Mode  */
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = FLASH_WORD_COM_1;
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_2)) = FLASH_WORD_COM_2;
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = ID_OUT_WORD_COM;
  
    /* Wait 20 ms */
    Pause();

	//* Send the data
	while( ((read_dbg_control() & W_BIT) == W_BIT) ); //* Wait a new data to write
	write_dbg_data((u_int)manuf_code);
	
	while( ((read_dbg_control() & W_BIT) == W_BIT) ); //* Wait a new data to write
	write_dbg_data((u_int)device_code);

	while(1){
	
	/*	led_on(1, GREEN);
		
		for (i=0; i<150000;i++);
		
		led_on(0, GREEN);
		
		for (i=0; i<150000;i++);
	*/
	
	}
	
    return TRUE;
}

//* End of file