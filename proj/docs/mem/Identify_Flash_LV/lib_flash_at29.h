//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : lib_flash_at29.h
//* Object              : Flash AT29LV Prototyping File
//*                         - AT29LV1024
//*                         - AT29C020
//*
//* 1.0 02/11/00 JPP    : Creation
//*----------------------------------------------------------------------------

#ifndef lib_flash_at29_h
#define lib_flash_at29_h

/*---------------------------  Constants definition -------------------------*/

/* Standards	*/
typedef unsigned int        u_int;   

/* 16-bit Flash Data type */
typedef volatile unsigned short flash_word ;

/* Include Standard c Libraries to allow stand alone compiling and operation */
#define TRUE    1
#define FALSE   0

/* Timeout loop count */
#define TIME_OUT_AT29       10000

/* Define Flash Codes */
#define FLASH_SEQ_ADD_1     (0x5555 << 1)
#define FLASH_SEQ_ADD_2     (0x2AAA << 1)

#define FLASH_WORD_COM_1    ((short)0xAAAA)
#define FLASH_WORD_COM_2    ((short)0x5555)
#define PROT_WORD_COM       ((short)0xA0A0)
#define ID_IN_WORD_COM      ((short)0x9090)
#define ID_OUT_WORD_COM     ((short)0xF0F0)

#endif  /* lib_flash_at29_h */
