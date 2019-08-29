//###########################################################################
//
// FILE:   flash.c
//
// TITLE:  SSM_ DSPMATE  28335 Monitor Flash
//
// DESCRIPTION:
//	    				
//         Jeon yu hun  
//
//###########################################################################
// $Release Date: 11-25, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define FROMSCI		0
#define FROMFLASH	1

/*
   FLASHH      : origin = 0x300000, length = 0x008000    <- User program
   FLASHG      : origin = 0x308000, length = 0x008000    
   FLASHF      : origin = 0x310000, length = 0x008000     
   FLASHE      : origin = 0x318000, length = 0x008000     
   FLASHD      : origin = 0x320000, length = 0x008000     
   FLASHC      : origin = 0x328000, length = 0x008000     
   FLASHB      : origin = 0x330000, length = 0x008000     <- user program stored data
   FLASHA      : origin = 0x338000, length = 0x007F80     <- Monitor
*/
#define USER_FLASH	(Uint32)0x300000

//External RAM zone6
#define USER_RAM	(Uint32)0x100000

#define FLASH_DEBUG		0

const Uint16 FlashSector[7] = {0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE};
//							H,      H~G, H~ F, H~E,  H~D,  H~C,  H~B

Uint16 *pFlashAdd;
Uint16 *pRamAdd;

#define USER_PRG_ADD	(Uint32)0x008300  // user program code_start

//#pragma CODE_SECTION(Convert_HEX_AtoI, "ramfuncs");
//#pragma CODE_SECTION(DownHEXFrom, "ramfuncs");
//#pragma CODE_SECTION(DownUserProgfrom, "ramfuncs");
//#pragma CODE_SECTION(SCItoFLASH, "ramfuncs");


/*--- Global variables used to interface to the flash routines */
FLASH_ST FlashStatus;
volatile struct HEX_FIELD DownLoadingHex;


/*   INITFLASHAPI   */
/*************************************************************************
*	@name    	InitFlashAPI
*	@memo	       FLASH API를 사용하기 위한 초기화
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void InitFlashAPI(void)
{

/*
      5. If required, copy the flash API functions into on-chip zero waitstate
         RAM.  
      6. Initalize the Flash_CPUScaleFactor variable to SCALE_FACTOR
      7. Initalize the callback function pointer or set it to NULL
      8. Optional: Run the Toggle test to confirm proper frequency configuration
         of the API. 
      9. Optional: Unlock the CSM.
     10. Make sure the PLL is not running in limp mode  
*/
	float32 Version;        // Version of the API in floating point
	Uint16 VersionHex;     // Version of the API in decimal encoded hex
	Uint16 flash_Status;

	MemCopy(&Flash28_API_LoadStart, &Flash28_API_LoadEnd, &Flash28_API_RunStart);


	Flash_CPUScaleFactor = SCALE_FACTOR;
	Flash_CallbackPtr = NULL; 

/*------------------------------------------------------------------
 Unlock the CSM.
    If the API functions are going to run in unsecured RAM
    then the CSM must be unlocked in order for the flash 
    API functions to access the flash.
   
    If the flash API functions are executed from secure memory 
    (L0-L3) then this step is not required.
------------------------------------------------------------------*/

	flash_Status = CsmUnlock();
	if(flash_Status != STATUS_SUCCESS) 
	{
		SCIa_Printf("\n  Flash Csmunlock Error!!\n");
		asm("    ESTOP0");
	}


	//Version check
	VersionHex = Flash_APIVersionHex();
	if(VersionHex != 0x0210)
	{
		// Unexpected API version
		// Make a decision based on this info. 
		SCIa_Printf("\n  Flash API version Error!!\n");
		asm("    ESTOP0");
	}   


	Version = Flash_APIVersion();
	if(Version != (float32)2.10)
	{
		// Unexpected API version
		// Make a decision based on this info. 
		SCIa_Printf("\n  Flash API version Error!!\n");
		asm("    ESTOP0");
	}
   
	
}

/*   INITSTRUCT_HEXDOWN   */
/*************************************************************************
*	@name    	InitStruct_HexDown
*	@memo	       HEX 의상태와 현제 어드레스등 HEX 다운로드관련 구조체 ZERO 초기화
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void InitStruct_HexDown(void)
{
	memset((void *)&DownLoadingHex, 0x00, sizeof(DownLoadingHex));
}

/*   ERASE_SELECTFLASH   */
/*************************************************************************
*	@name    	Erase_SelectFlash
*	@memo	       선택된 FLASH 영역을 지운다.
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void Erase_SelectFlash(void)
{
	Uint16 Status;
	char RcvData;
	Uint16 EraseSector;

	SCIa_Printf("\nErase sector... Select Sector(B~H) :");

	RcvData = SCIa_RxChar();
	SCIx_TxChar(RcvData, &SciaRegs);
	switch(RcvData)
	{
		case 'b':
		case 'B':
			EraseSector = SECTORB;
			SCIa_Printf("\n  Erase Sector B.\n");
			break;
			
		case 'c':
		case 'C':
			EraseSector = SECTORC;
			SCIa_Printf("\n  Erase Sector C.\n");
			break;
			
		case 'd':
		case 'D':
			EraseSector = SECTORD;
			SCIa_Printf("\n  Erase Sector D.\n");
			break;

		case 'e':
		case 'E':
			EraseSector = SECTORE;
			SCIa_Printf("\n  Erase Sector E.\n");
			break;

		case 'f':
		case 'F':
			EraseSector = SECTORF;
			SCIa_Printf("\n  Erase Sector F.\n");
			break;

		case 'g':
		case 'G':
			EraseSector = SECTORG;
			SCIa_Printf("\n  Erase Sector G.\n");
			break;

		case 'h':
		case 'H':
			EraseSector = SECTORH;
			SCIa_Printf("\n  Erase Sector H.\n");
			break;
			
		default:
			SCIa_Printf("\nWrong Sector Selected. You can select B to H\n");
			return;
	}

	Status = Flash_Erase(EraseSector, &FlashStatus);

	if(Status != STATUS_SUCCESS)
	{
		SCIa_Printf("\n  Erase Sector %c Error!!\n",RcvData);
		return;
	}

	SCIa_Printf("\n  Erase Sector %c OK!!\n",RcvData);

	
}

/*   ERASE_ALLFLASH   */
/*************************************************************************
*	@name    	Erase_AllFlash
*	@memo	       모든 FLASH영역을 지운다. SectorA 는 모니터프로그램이라 제외
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void Erase_AllFlash(void)
{
	Uint16 Status;

	SCIa_Printf("\n  Erase All Flash Sector.\n");
				
	Status = Flash_Erase(SECTORB|SECTORC|SECTORD|SECTORE|SECTORF|SECTORG|SECTORH, &FlashStatus);
	
	if(Status != STATUS_SUCCESS)
	{
		SCIa_Printf("\n  Flash_Erase Error!!\n");
		return;
	}
	
	SCIa_Printf("\n  Erase All Flash Sector OK!!(SECTOR B ~ SECTOR H)\n");
	
}

/*   DOWNFROMSCI   */
/*************************************************************************
*	@name    	DownFromSCI
*	@memo	       씨리얼을 통한 유저프로그램 다운로드
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void DownFromSCI(void)
{
	InitStruct_HexDown();
	SCIa_Printf("\n  Send User Program *.Hex\n");

	SCIx_TxChar(BEL,&SciaRegs);

	if(DownUserProgfrom(FROMSCI)) 
		SCIa_Printf("\n  DownLoading Success !!");
	else 
	{
		SCIa_Printf("\n  DownLoading Failure !!"); 
		return;
	}
	SCIa_Printf("\n  Go To User Program !!\n");

	Go_UserProgram();
	
}

/*   DOWNFROMFLASH   */
/*************************************************************************
*	@name    	DownFromFlash
*	@memo	       FLASH 영역에서 유저프로그램 다운로드
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void DownFromFlash(void)
{
	SetUserHEXFlashadd();
	InitStruct_HexDown();
	
	if(DownUserProgfrom(FROMFLASH)) 
		SCIa_Printf("\n  DownLoading Success !!");
	else 
	{
		SCIa_Printf("\n  DownLoading Failure !!"); 
		//return;//
	}

	SCIa_Printf("\n  Go To User Program !!\n");

	Go_UserProgram();
		
}

/*   SCITOFLASH   */
/*************************************************************************
*	@name    	SCItoFLASH
*	@memo	       씨리얼로 받은 HEX를 FLASH영역에 저장한다
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void SCItoFLASH(void)
{
	char RcvData[2];
	Uint16 Header_ignore;
	Uint16 WriteData;
	Uint16 HEXBuf[80];		
	Uint16 ByteCount;

	Uint16 Loop, WriteLoop;
	Uint16 Status;

	Uint32 SizeofData; //offset_address


// 씨리얼 다운로드
	SCIa_Printf("\n  Send User Program *.Hex\n");
	
	SCIx_TxChar(BEL,&SciaRegs);
	
	pFlashAdd = (Uint16 *)USER_FLASH;
	pRamAdd = (Uint16 *)USER_RAM;
	SizeofData = 0;

	while((RcvData[0] = SCIa_RxChar())!=':');
	Header_ignore=0;
	ByteCount=0;
	
	for(;;)
	{	
		if (Header_ignore)
			RcvData[0] = SCIa_RxChar();

		else
		{
			RcvData[0] = ':';
			Header_ignore=1;
		}


		RcvData[1] = SCIa_RxChar();

		WriteData = ((RcvData[0] << 8) + RcvData[1]);
		*(pRamAdd + SizeofData++) = WriteData;

		//end of file check
		
		if(RcvData[0] == ':')
		{
			SCIx_TxChar('.',&SciaRegs);
			ByteCount = 0;
			HEXBuf[ByteCount++] = RcvData[0];
			HEXBuf[ByteCount++] = RcvData[1];
		}
 //2008/12/18    마지막줄엔 오로지 CR만 있었슴 LF 없음
		else
		{
			HEXBuf[ByteCount++] = RcvData[0];
			HEXBuf[ByteCount++] = RcvData[1];
			#ifdef DEBUG_FLASHDOWN
			if(RcvData[1] == CR) SCIa_Printf(",");
			#endif
		}

		if(ByteCount == 12)
		{
			ByteCount = 0;
			//end of file
			// :00000001FF
			if(HEXBuf[0] == ':')
			 if(HEXBuf[1] == '0')
			  if(HEXBuf[2] == '0')
			   if(HEXBuf[3] == '0')
			    if(HEXBuf[4] == '0')
			     if(HEXBuf[5] == '0')
			      if(HEXBuf[6] == '0')
			       if(HEXBuf[7] == '0')			
			        if(HEXBuf[8] == '1')
			         if(HEXBuf[9] == 'F')
			          if(HEXBuf[10] == 'F')
				    break;
		}

	
	}

	SCIa_Printf("\n  %ld Word Download Complete!!\n", SizeofData);



 // flash erase

	for(Loop = 0; Loop < 7; Loop++)
	{
		if(SizeofData < ((Uint32)0x8000*(Loop+1)))
		{
			break;
		}
		else;
	}

	if (Loop ==0) //H 경우 
	{
		SCIa_Printf("\n  Erase Flash Sector H");
		
		Status = Flash_Erase(FlashSector[Loop], &FlashStatus);
		
		if(Status != STATUS_SUCCESS)
		{
			SCIa_Printf("\n  Flash Error!!\n");
			return;
		}
		else
		{
			SCIa_Printf("\n  Flash Erase complete!! ");
		}


	}
	else if (Loop >6)  //2008/12/18    용량초과
	{
		SCIa_Printf("\n  User Program Size too Big !!\n");
		SCIa_Printf("\n  Error!! \n");		
		return;
	}
	else //H~B 사이인 경우 
	{
		SCIa_Printf("\n  Erase Flash Sector  %c~%c \n",('H'-Loop), 'H');
		
		Status = Flash_Erase(FlashSector[Loop], &FlashStatus);
		
		if(Status != STATUS_SUCCESS)
		{
			SCIa_Printf("\n  Flash Error!!\n");
			return;
		}
		else
		{
			SCIa_Printf("\n  Flash Erase complete!! ");
		}
	}
		

//Flash Write

//pFlashAdd = (Uint16 *)USER_FLASH;
//pRamAdd = (Uint16 *)USER_RAM;



	for(WriteLoop = 0; WriteLoop < Loop; WriteLoop++)
	{			
		Status = Flash_Program(pFlashAdd+(0x8000*WriteLoop),pRamAdd+(0x8000*WriteLoop),0x8000*(WriteLoop+1),&FlashStatus);
		if(Status != STATUS_SUCCESS)
		{
			SCIa_Printf("\n  Flash Write Error!!\n");
			return;
		}	

	}
	Status = Flash_Program(pFlashAdd+(0x8000*WriteLoop),pRamAdd+(0x8000*WriteLoop),SizeofData-(0x8000*WriteLoop),&FlashStatus);
	if(Status != STATUS_SUCCESS)
	{
		SCIa_Printf("\n  Flash Write Error!!\n");
		return;
	}	

	SCIa_Printf("\n  Burn User Program End!!\n");
	
	SCIx_TxChar(BEL,&SciaRegs);

}


/*   GO_USERPROGRAM   */
/*************************************************************************
*	@name    	Go_UserProgram
*	@memo	       사용자 프로그램의 시작주소로 점프한다.
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void Go_UserProgram(void)
{
	Uint32 Add = USER_PRG_ADD;   

	void (*UserPrg)(void) = (void (*)(void))Add;
//	void (*UserPrg)(void) = (*(void)Add);

	DINT;

	UserPrg();
	 // 유저 프로그램으로 이동 후 스택 메모리 프로그램 전체 초기화됨
}



/*   SETUSERHEXFLASHADD   */
/*************************************************************************
*	@name    	SetUserHEXFlashadd
*	@memo	       user 프로그램 hex가 저장되어있는 flash 주소 선택
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
void SetUserHEXFlashadd(void)
{
	pFlashAdd = (Uint16 *)USER_FLASH;
}


/*   LOADFLASHDATA   */
/*************************************************************************
*	@name    	LoadFlashData
*	@memo	       플래시에 저장된 유저 hex 데이타를 가져온다
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
Uint16 LoadFlashData(void)
{
	static Uint16 Flag = OFF;
	Uint16 Data;

	if(Flag == OFF)
	{
		Data = (*pFlashAdd >> 8) & 0xff;
		Flag = ON;
	}
	else
	{
		Data = *pFlashAdd & 0xff;
		Flag = OFF;
		pFlashAdd++;
	}

	return Data;
}


/*   DOWNUSERPROGFROM   */
/*************************************************************************
*	@name    	DownUserProgfrom
*	@memo	       유저프로그램을 받아서 재배치 시킨다
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
Uint16 DownUserProgfrom(Uint16 Source)
{
	int i;
	Uint16 CheckSum;
	Uint16 DataBuffer;
	while(DownLoadingHex.Status.bit.end_of_file==FALSE)
	{  
		if(Source == FROMSCI)
		{
			while( SCIa_RxChar() != ':' );
		}
		else//FLASH
		{
			while((i = LoadFlashData()) != ':')
			{
				if(i == 'F')
				{
					SCIa_Printf("\n  Flash Invalid!! \n");
					return FALSE;
				}
			}
		}
		
		DownLoadingHex.Checksum = CheckSum = 0;
		
		 // hex 포맷의 datalength
		DownLoadingHex.DataLength = DownHEXFrom(2, Source);
		 // 32비트 어드레스 상위 16비트 지정
		DownLoadingHex.Address.Word.low16 = DownHEXFrom(4, Source);
		// Data Type
		DownLoadingHex.RecordType = DownHEXFrom(2, Source);

		switch (DownLoadingHex.RecordType) 
		{

	/*
	'00'       Data Record
	'0l'        End of File Record
	'02'       Extended Segment Address Record
	'03'       Start Segment Address Record
	'04'       Extended Linear Address Record
	'05'       Start Linear Address Record
	*/

			// '00'       Data Record
			case 0x00:
				// data lenth *2 = datalenth in byte
				for( i = 0; i < DownLoadingHex.DataLength; i += 2)
				{
					if( ( DownLoadingHex.DataLength - i ) == 1 )  //이런경우가 없길..
					{
						DataBuffer = DownHEXFrom(2, Source);
						SCIa_Printf("\nHEX converting Error. it is NOT a 16bit data hex\n");
					}
					else 
						DataBuffer = DownHEXFrom(4, Source); // 16 bit hex

						
					 //2008/12/17    지정 메모리에 데이타 재배치
					*(Uint16 *)DownLoadingHex.Address.all = DataBuffer;
					DownLoadingHex.Address.all ++;
				}
				break;

			
			// '01'        End of File Record
			case 0x01:
				DownLoadingHex.Status.bit.end_of_file = TRUE;
				break;

				
			// '02'       Extended Segment Address Record	
			case 0x02: //not use
				break;
			//'03'       Start Segment Address Record	
			case 0x03: //not use
				break;

			//      Extended Linear Address 
			case 0x04: //use in 32bit addressing
				 //상위 16비트 재지정
				DownLoadingHex.Address.Word.high16 = DownHEXFrom(4, Source);
				break;

			// '05'       Start Linear Address Record
			case 0x05: //not use
				break;

		}
		CheckSum = ((~(DownLoadingHex.Checksum)) + 1) & 0xff; // 2' complement

		if( CheckSum != DownHEXFrom(2, Source) )
		{
			SCIa_Printf("\nCheckSumError");
			return FALSE;
		}

		 SCIx_TxChar('.',&SciaRegs); //Dot per one HEX line
	}

	return TRUE;
}


/*   DOWNHEXFROM   */
/*************************************************************************
*	@name    	DownHEXFrom
*	@memo	       Source에 서 Intel hex 해석후 리턴
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
Uint16 DownHEXFrom( Uint16 NumByte, Uint16 Source)
{
	Uint16 Value, i, Shift_Count;
	char Rcvdata;

	Value = 0;

	Shift_Count = NumByte;	//2008/12/17    16bit 데이타 헥사에선 항상 2나 4

	for ( i = 0; i < NumByte; i++ ) 
	{
		if(Source == FROMSCI)
	        	Rcvdata = SCIa_RxChar();
		else
			Rcvdata = LoadFlashData();
		
		Value |= (Uint16)(Convert_HEX_AtoI( Rcvdata ) << ((--Shift_Count) * 4));
//		Value |= Convert_HEX_AtoI( Rcvdata ) << ( ( (NumByte -1)-i ) * 4 );
	}

	 //check sum 부분
	if( NumByte == 4 )
	{
	    DownLoadingHex.Checksum += (( Value >> 8 ) & 0xff); 
	    DownLoadingHex.Checksum += (Value & 0xff);
	}
	else  // 2바이트일 경우
	{
	    DownLoadingHex.Checksum += (Value & 0xff);
	}

	return Value;
}


/*   CONVERT_HEX_ATOI   */
/*************************************************************************
*	@name    	Convert_HEX_AtoI
*	@memo	       문자 HEX를 정수형으로 변환한다.
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
char Convert_HEX_AtoI(char Ascii)
{
	if(Ascii >= '0' && Ascii <= '9')return(Ascii-'0');
	else if(Ascii >= 'a' && Ascii<= 'f')return(Ascii-'a'+10);
	else if(Ascii >= 'A' && Ascii <= 'F')return(Ascii-'A'+10);
	else return(0xFF);
}


/*   CSMUNLOCK   */
/*************************************************************************
*	@name    	CsmUnlock
*	@memo	       Flash API가 L0~L2 사이의 램에서 동작될경우 CSM 을 풀어야 한다.
*	@author	       Joen yu hun
*	@company	SSM
*    
**************************************************************************/
Uint16 CsmUnlock(void)
{
    volatile Uint16 temp;
    
    // Load the key registers with the current password
    // These are defined in Example_Flash2833x_CsmKeys.asm
    
    EALLOW;
    CsmRegs.KEY0 = PRG_key0;
    CsmRegs.KEY1 = PRG_key1;
    CsmRegs.KEY2 = PRG_key2;
    CsmRegs.KEY3 = PRG_key3;
    CsmRegs.KEY4 = PRG_key4;
    CsmRegs.KEY5 = PRG_key5;
    CsmRegs.KEY6 = PRG_key6;
    CsmRegs.KEY7 = PRG_key7;   
    EDIS;

    // Perform a dummy read of the password locations
    // if they match the key values, the CSM will unlock 
        
    temp = CsmPwl.PSWD0;
    temp = CsmPwl.PSWD1;
    temp = CsmPwl.PSWD2;
    temp = CsmPwl.PSWD3;
    temp = CsmPwl.PSWD4;
    temp = CsmPwl.PSWD5;
    temp = CsmPwl.PSWD6;
    temp = CsmPwl.PSWD7;

    // If the CSM unlocked, return succes, otherwise return
    // failure.
    if ( (CsmRegs.CSMSCR.all & 0x0001) == 0) return STATUS_SUCCESS;
    else return STATUS_FAIL_CSM_LOCKED;
    
}


