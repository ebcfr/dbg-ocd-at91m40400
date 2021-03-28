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

typedef struct OrgDef
{
    unsigned int    sector_number ;
    unsigned int    sector_size ;
} OrgDef ;

//* Defines Flash device definition structure
typedef struct FlashAt29LVDef
{
    unsigned int    flash_size;
    unsigned int    flash_manuf_id;
    unsigned int    flash_id;
    unsigned int    flash_mask;
    OrgDef          *flash_org;
    unsigned int    flash_block_nb;

} FlashAt29LVDef;


/* Defines organization structure */
OrgDef OrgAT29LV1024[] =
{
    {
        512,
        256
    }
};
OrgDef OrgAT29C020[] =
{
    {
        512,
        512
    }
};

//* Define supported flash Table
FlashAt29LVDef FlashTableAT29[NB_FLASH_AT29_SUPPORTED] =
{
    {
        512*256,                  //* 128 K Bytes
        ATMEL_MANUFACTURED,
        FLASH_AT29LV1024,
        0x000FFFFF,
        OrgAT29LV1024,
        1
    },
    {
        512*512,                  //* 256 K Bytes
        ATMEL_MANUFACTURED,
        FLASH_AT29C020,
        0x000FFFFF,
        OrgAT29C020,
        1
    }
};

#define RED			2
#define GREEN		4
#define YELLOW		16	

#define R_BIT	1
#define W_BIT	2

//* test
void led_on(int state, int led){

	int *pt;
	
	if (state){
		pt=(int *)0xFFFF0030;	
		*pt = led;
	} else {
		pt=(int *)0xFFFF0034;	
		*pt = led;
	}
}

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


//* --------------------------- Export function -------------------------------

/*void Pause(){
	
	int count;
	
    for (count=0; count < 10000; count++)
    {
*/
        /* Do nothing - just wait */
 /*   }

}
*/

//*----------------------------------------------------------------------------
//* Function Name       : flash_at29_identify
//* Object              : Get the device id
//* Input Parameters    : <base_addr> Flash base address
//* Output Parameters   : device_code or 0xFFFF if bad manuf code
//*----------------------------------------------------------------------------
/*flash_word flash_at29_identify( int base_addr )
{
    flash_word manuf_code, device_code;
    Pause();
*/
    /* Enter Software Product Identification Mode  */
 /*   *((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = FLASH_WORD_COM_1;
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_2)) = FLASH_WORD_COM_2;
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = ID_IN_WORD_COM;
 */
    /* Wait 10 ms for the device to change state */
  //*  Pause();

    /* Read Manufacturer and device code from the device */
  /*  manuf_code  = (*((volatile short *) (base_addr + 0))) & 0x00FF;
    device_code = (*((volatile short *) (base_addr + 2))) & 0x00FF;
*/
    /* Exit Software Product Identification Mode  */
 /*   *((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = FLASH_WORD_COM_1;
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_2)) = FLASH_WORD_COM_2;
    *((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = ID_OUT_WORD_COM;
  */
    /* Wait 20 ms */
   //* Pause();

    /* Check the Manufacturer - Fail if not known */
  /*  if (manuf_code != ATMEL_MANUFACTURED) {
        return FLASH_AT29LV_UNKNOW;
    }

  return device_code;
}
*/


//*----------------------------------------------------------------------------
//* Function Name       : main
//* Object              : Get data and stored them in flash
//* Input Parameters    : none
//* Output Parameters   : none
//*----------------------------------------------------------------------------
int main(){

	int count, i;
	int size_sector;
	flash_word expected;
	
	//* Added
	int end = 0;
	
	u_int buffer[64]; //* 128 words of 16 bits
	
	u_int base_addr = 0x01000000; //* base address of flash
	u_int addr;
	flash_word *data, *load_addr;
	FlashAt29LVDef *flash = &FlashTableAT29[0];
	
	led_on (0, YELLOW);
	
	while (end != 1)
	{
		//* Get the load address	
		while( ((read_dbg_control() & R_BIT) != R_BIT) ); //* Wait a new data to read
		addr = read_dbg_data();
		load_addr = (flash_word *)(base_addr + addr);

		led_on(1, GREEN);
    	
		count = 0;
		
		//* Store 64 32 bits words from the Comm Channel to a buffer 
		while (count < 64){
			
			while( ((read_dbg_control() & R_BIT) != R_BIT) ); //* Wait a new data to read
    		buffer[count] = read_dbg_data();
			
			count++;
		}
		
		//* Read end value
		while( ((read_dbg_control() & R_BIT) != R_BIT) ); //* Wait a new data to read
		end = read_dbg_data();

		//********************************
		//* Start copying data into flash
		//********************************
		data = (flash_word *)buffer; //* data points towards 16 bits values

    	//* Get the sector size
    	size_sector = flash->flash_org->sector_size /2;

    	//* Enter Data protection routine code
    	*((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = FLASH_WORD_COM_1;
    	*((volatile short *)(base_addr + FLASH_SEQ_ADD_2)) = FLASH_WORD_COM_2;
    	*((volatile short *)(base_addr + FLASH_SEQ_ADD_1)) = PROT_WORD_COM;

    	/* Write the data in full int steps - regardless of FLASH Data bus width */
	  	for (count = 0; count < (size_sector) ; count++)
    	{
        	 load_addr[count] = data[count];
    	}

		for(count=0; count<160000; count++); //* Wait 20 ms   
    	
    	/* Check that the final word has been written before continuing */
    	expected = data[(size_sector)-1];
    	
    	while( (expected != load_addr[(size_sector)-1]) && (count++ < TIME_OUT_AT29));

        if (count >= TIME_OUT_AT29)
       		led_on(1, RED);
       		
    	/* Reread the sector and check it matches what we wrote */
    	for (count = 0; count < (size_sector); count++)
    	{
        	if (load_addr[count] != data[count])
           		led_on(1, YELLOW);
    	}
	
	} //* end while
	
	//* Send the data
	while( ((read_dbg_control() & W_BIT) == W_BIT) ); //* Wait a new data to write
	write_dbg_data(0xCAFECAFE);
	
	while(1){
	
		led_on(1, GREEN);
		
		for (i=0; i<150000;i++);
		
		led_on(0, GREEN);
		
		for (i=0; i<150000;i++);
	
	}

    /* Return  */
    return (TRUE);
}

//* End of file