//******************************************************************************
//
//              Copyright (C) 2005.  The Marconi Project
//      All rights reserved.  No part of this program may be reproduced.
//
//     http://www.sgsolutions.ca/marconi
//
//==============================================================================
//
// USAGE:		Enter Description here
//
//
//
//******************************************************************************


#define __SERIALOUTPUT_C__


//******************************************************************************
//  I N C L U D E    F I L E S
//******************************************************************************
#include "All.h"

//******************************************************************************
//  L O C A L    D E F I N I T I O N S
//******************************************************************************

//******************************************************************************
//  E X T E R N A L     F U N C T I O N    P R O T O T Y P E S
//******************************************************************************


//******************************************************************************
//  S T A T I C    F U N C T I O N    P R O T O T Y P E S
//******************************************************************************


//******************************************************************************
//  G L O B A L    V A R I A B L E S
//******************************************************************************


//******************************************************************************
//  L O C A L    V A R I A B L E S
//******************************************************************************


//******************************************************************************
//  C O D E
//******************************************************************************

//******************************************************************************
//
//	Serial Output Initialization Block
//
//******************************************************************************
void SerialOutputInit(BYTE *BlockInitStruct, BYTE *BlockObjStruct)
{
	SERIAL_OUTPUT_OBJ_STRUCT *SerialOutputObjStruct =
		(SERIAL_OUTPUT_OBJ_STRUCT *)BlockObjStruct;

	SerialOutputObjStruct->outputType = 0;
}

//******************************************************************************
//
//	Serial Output Execution Block
//
//******************************************************************************
WORD SerialOutput(WORD *inBuffer, WORD *inSize, WORD *outBuffer, WORD *outSize, BYTE *BlockObjStruct)
{
    HwUartWr(APP_UART_ID, (char *)inBuffer, *inSize);
    /*
    char buffer[2];

	//PrintMsgW("0x%04X ", *inBuffer++);
    buffer[0] = *inBuffer & 0xFF;
    buffer[1] = 0;
    PrintMsg(buffer);
	
    */
	return 0;
}

//******************************************************************************
//
//	Serial Output Ready Check
//
//******************************************************************************
WORD SerialOutputReady(WORD *inputSize, WORD *outputSize, BYTE *BlockObjStruct)
{
    *inputSize = MIN(*inputSize, HwUartWrAvail(APP_UART_ID));

    return *inputSize > 0;
    /*
	if (*inputSize >= 1)
	{
		*inputSize = 1;
		return TRUE;
	}
	return FALSE;
    */
}

/***********************************  END  ************************************/
