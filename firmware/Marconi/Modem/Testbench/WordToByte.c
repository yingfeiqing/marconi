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


#define __WORDTOBYTE_C__


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
//	Word To Byte Initialization Block
//
//******************************************************************************
void WordToByteInit(BYTE *BlockInitStruct, BYTE *BlockObjStruct)
{

}

//******************************************************************************
//
//	Word To Byte Execution Block
//
//******************************************************************************
WORD WordToByte(WORD *inBuffer, WORD *inSize, WORD *outBuffer, WORD *outSize, BYTE *BlockObjStruct)
{
	WORD count;

	for (count = 0; count < *inSize; count++)
	{
		*outBuffer++ = *inBuffer & 0x00FF;
		*outBuffer++ = *inBuffer++ >> 8;
	}
	return 0;
}

//******************************************************************************
//
//	Word To Byte Ready Check
//
//******************************************************************************
WORD WordToByteReady(WORD *inputSize, WORD *outputSize, BYTE *BlockObjStruct)
{
	if (*inputSize >= 1 && *outputSize >= 2)
	{
		*outputSize = MIN((*inputSize * BYTES_IN_WORD), *outputSize);
		*inputSize = *outputSize / BYTES_IN_WORD;
		return TRUE;
	}
	return FALSE;
}

/***********************************  END  ************************************/
