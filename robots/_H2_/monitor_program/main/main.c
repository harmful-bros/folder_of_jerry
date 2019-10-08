//###########################################################################
//
// FILE:   main.c
//
// TITLE:  MAZE 10th  28335 Monitor Main
//
// DESCRIPTION:
//	    				
// 		Jeon yu hun (dimbibara@gmail.com)
//
//  Copyright (C) 2008  Jeon yu hun
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
// 
//
//###########################################################################
// $Release Date: 12-23, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//#define ReleaseVersion	0.1 // First make
//#define ReleaseVersion	0.2 // ram down complete
//#define ReleaseVersion	0.3 // flash down complete
//#define ReleaseVersion	0.4 // auto run complete
//#define ReleaseVersion	0.5 // serial.c function modify
#define ReleaseVersion	0.6 // Xintf compatable 16bt and 32bit

#define ONEWAITSEC		0.125  //auto run wait 1 time. full wait time = ONEWAITSEC * 3

#define	ON_L	1L

#define	LED_OFF		GpioDataRegs.GPADAT.all &= ~( 0x0cc0c000 )
#define	LED_ON		GpioDataRegs.GPADAT.all |= 0x0cc0c000

#define	UP_SW		GpioDataRegs.GPADAT.bit.GPIO10
#define	RIGHT_SW	GpioDataRegs.GPADAT.bit.GPIO11
#define	DOWN_SW		GpioDataRegs.GPADAT.bit.GPIO12
#define	LEFT_SW		GpioDataRegs.GPADAT.bit.GPIO13

typedef enum
{
	LED_0 = 14 ,
	LED_1 = 15,
	LED_2 = 22,
	LED_3 = 23,
	LED_4 = 26,
	LED_5 = 27,
	LED_NUM = 6
	
}led_e;

volatile Uint16 led_table[ LED_NUM ] = 
{
	LED_0 , LED_1 , LED_2 , LED_3 , LED_4 , LED_5 
};


interrupt void cpu_timer0_isr(void);


/*   CPU_TIMER0_ISR   */
/*************************************************************************
*	@name    	cpu_timer0_isr
*	@memo	       _varhae_ monitor program interrupt
*	@author	       leejaeseong
*	@company	Hertz
*    
**************************************************************************/
interrupt void cpu_timer0_isr(void)
{
	static int32 flag = OFF;
	static int32 count = 0;

	if( !flag )
	{
		LED_ON;
		flag = ON;
	}
	else
	{
		GpioDataRegs.GPADAT.all = ( ON_L << led_table[ count ] );
		count++;
		if( count >=  LED_NUM )		count = 0;
	}

	vfd_scroll("=Hi=  ");

   // Acknowledge this interrupt to receive more interrupts from group 1
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

/*   MAIN   */
/*************************************************************************
*	@name    	main
*	@memo	       Monitor program Main
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
void main(void)
{
	char RcvData;
//	static int32 temp_reg = 0x0000400;
//	GpioDataRegs.GPASET.all = temp_reg << 1;
	
	// PLL, WatchDog, enable Peripheral Clocks
	InitSysCtrl();

	InitGpio();
	InitXintf();

	// Disable CPU interrupts
	DINT;
	
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

	// Initialize PIE control registers to their default state.
	InitPieCtrl();

	// Disable CPU interrupts and clear all CPU interrupt flags:
	IER = 0x0000;
	IFR = 0x0000;

	// Initialize the PIE vector table with pointers to the shell Interrupt
	// Service Routines (ISR).
	InitPieVectTable();



	// Interrupts that are used in this example are re-mapped to
	EALLOW;  // This is needed to write to EALLOW protected registers
	GpioCtrlRegs.GPADIR.all = 0x0cc0c00f;	/* gpio0 ~ gpio31 data output pin setting up */
	GpioCtrlRegs.GPBDIR.all = 0x000f0003;	/* gpio32 ~ gpio63 data output pin setting up */
	PieVectTable.TINT0 = &cpu_timer0_isr;
	EDIS;    // This is needed to disable write to EALLOW protected registers

	InitFlash();
	InitSci();
	InitFlashAPI();
	InitCpuTimers();

	InitEPwm1Gpio();
	InitEPwm2Gpio();

	vfd_init();
	vfdprintf("=Hi=");
	

#if (CPU_FRQ_150MHZ)
	// 150MHz CPU Freq, 1 second Period (in uSeconds)
	ConfigCpuTimer(&CpuTimer0, 150, ONEWAITSEC * 1000000);
#endif

#if (CPU_FRQ_100MHZ)
	// 100MHz CPU Freq, 1 second Period (in uSeconds)
	ConfigCpuTimer(&CpuTimer0, 100, ONEWAITSEC * 1000000);
#endif

	CpuTimer0Regs.TCR.bit.TSS = 0; // Use write-only instruction to set TSS bit = 0
	IER |= M_INT1;
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
	EINT;   // Enable Global interrupt INTM

	StartCpuTimer0();

	if( DOWN_SW == 0 )
	{
		LED_OFF;
		StopCpuTimer0();
		DINT;
		
		vfdprintf("=Hi=");
		DownFromFlash();
	}
	else
	{

		HelpMenu();
		SCIa_Printf("\nMonitor28335_ctml]#");	

		for(;;)
		{
			RcvData = SCIa_RxChar();
			SCIx_TxChar(RcvData,&SciaRegs);

			LED_OFF;
			StopCpuTimer0();
			DINT;

			vfdprintf("=Hi=");			
			
			switch(RcvData)
			{
				case 'h':
				case 'H':
					HelpMenu();
					break;

				case 'M':
				case 'm':
					PrintMenu();
					break;
					
				case 'A':
				case 'a':
					Erase_AllFlash();
					break;
					
				case 'S':
				case 's':
					Erase_SelectFlash();
					break;
					
				case 'R':
				case 'r':
					DownFromSCI();  // 씨리얼로 다운받아 바로 재배치한다. 
					break;
					
				case 'D':
				case 'd':
					SCItoFLASH();  // 씨리얼로 프로그램을 다운받아 FLASH에 저장한다.
					DownFromFlash(); // FLASH 에서 읽어와서 재배치 한다.

				case 'G':
				case 'g':
					DownFromFlash(); // FLASH 에서 읽어와서 재배치 한다.
					break;

				case CR:
					break;

				case ESC:
					break;
					
				default:
					SCIa_Printf("\n=======Wrong Command!!========\n");
					PrintMenu();
					break;
			} 
			
			SCIa_Printf("\nMonitor28335_ctml]#");
		}

	}
}


/*   PRINTMENU   */
/*************************************************************************
*	@name    	PrintMenu
*	@memo	       모니터 프로그램 메뉴 출력
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
void PrintMenu(void)
{
	SCIa_Printf("\n\n");
	SCIa_Printf(" TMS320F28335 Monitor V%.1f ctml\n",ReleaseVersion);	
	SCIa_Printf("--------------------------------------------------------\n");		
	SCIa_Printf("  H  :	Display Help.\n");
	SCIa_Printf("  M  :	Display Menu.\n");
	SCIa_Printf("  A  :	Erase All Flash.( Sector B - H )\n");
	SCIa_Printf("  S  :	Select sector and Erase Flash sector. ( ex. S-B )\n");
	SCIa_Printf("  R  :	Download to RAM ( *.Hex )\n");
	SCIa_Printf("  D  :	Download to FLASH ( *.Hex )\n");
	SCIa_Printf("  G  :	Go User Program\n");
	SCIa_Printf("--------------------------------------------------------\n");		
	SCIa_Printf("  MAZE 10th  Jeon yu hun   <dimbibara@gmail.com> \n");	
	SCIa_Printf("=======================================================================\n");		
	SCIa_Printf(" \n!!!! Hertz9th Eum Sang Hoon & leejaeseong _H2_( v.28335 ) monitor program !!!!\n\n");
	SCIa_Printf("=======================================================================\n");	
}

/*   HELPMENU   */
/*************************************************************************
*	@name    	HelpMenu
*	@memo	       모니터 프로그램 메뉴 HELP
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
void HelpMenu(void)
{
	SCIa_Printf("\n\n\n");
	SCIa_Printf(" TMS320F28335 Monitor V%.1f ctml\n\n",ReleaseVersion);	
	SCIa_Printf("MENU :	one key button executable \n");		
	SCIa_Printf(" key :	Description \n");		
	SCIa_Printf("--------------------------------------------------------\n");		
	SCIa_Printf("  H  :	Help this page..\n");
	SCIa_Printf("  M  :	Display user available inputs, and executes.\n");
	SCIa_Printf("  A  :	Erase all sector of internal FLASH. sector B~H.\n\t(without sector A, Monitor sector)\n");
	SCIa_Printf("  S  :	Erase selected sector of internal FLASH. \n\t(It can be sector B~H)\n");
	SCIa_Printf("  R  :	Download HEX file to external RAM and relocation.  \n");
	SCIa_Printf("  D  :	Download HEX file to internal FLASH and relocation.\n\t(It will be stored from H to B)\n");
	SCIa_Printf("  G  :	JUMP program Counter to user start address.\n");											
	SCIa_Printf("--------------------------------------------------------\n");		
	SCIa_Printf("  MAZE 10th  Jeon yu hun   <dimbibara@gmail.com> \n");	
	SCIa_Printf("=======================================================================\n");		
	SCIa_Printf(" \n!!!! Hertz9th Eum Sang Hoon & leejaeseong _H2_( v.28335 ) monitor program !!!!\n\n");
	SCIa_Printf("=======================================================================\n");	

}


