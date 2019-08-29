// TI File $Revision: /main/2 $
// Checkin $Date: March 1, 2007   16:06:07 $
//###########################################################################
//
// FILE:	DSP2833x_Sci.c
//
// TITLE:	DSP2833x SCI Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x Header Files V1.20 $
// $Release Date: August 1, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitSci: 
//---------------------------------------------------------------------------
// This function initializes the SCI(s) to a known state.
//
void InitSci(void)
{
	InitSciGpio();
	
	// Initialize SCI-A:
	//SCI FIFO init
/*
	SciaRegs.SCIFFTX.bit.TXFFIL = 0; 		// 4:0	Interrupt level
	SciaRegs.SCIFFTX.bit.TXFFIENA = 0; 		// 5		Interrupt enable
	SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1;	// 6		Clear INT flag
	SciaRegs.SCIFFTX.bit.TXFFINT = 0; 		// 7		INT flag;
	SciaRegs.SCIFFTX.bit.TXFFST = 0; 		// 12:8	FIFO status
	SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;	// 13 	FIFO resetET
	SciaRegs.SCIFFTX.bit.SCIFFENA = 0; 		// 14 	Enhancement enable
	SciaRegs.SCIFFTX.bit.SCIRST = 1; 		// 15 	SCI reset rx/tx channels 
*/
//	SciaRegs.SCIFFTX.all = 0xA000;		// FIFO reset  //1010000000000000
	SciaRegs.SCIFFTX.all=0xA040;					//1010000001000000


/*
	SciaRegs.SCIFFRX.bit.RXFFIL = 1;		 // 4:0	Interrupt level
	SciaRegs.SCIFFRX.bit.RXFFIENA = 0;		 // 5	   Interrupt enable
	SciaRegs.SCIFFRX.bit.RXFFINTCLR = 0; 	 // 6	   Clear INT flag
	SciaRegs.SCIFFRX.bit.RXFFINT = 0;		 // 7	   INT flag
	SciaRegs.SCIFFRX.bit.RXFFST = 0; 		 // 12:8   FIFO status
	SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;	 // 13	   FIFO reset
	SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 0; 	 // 14	   Clear overflow
	SciaRegs.SCIFFRX.bit.RXFFOVF = 0;		 // 15	   FIFO overflow
*/
//	SciaRegs.SCIFFRX.all = 0x2000; 	//10000000000000
	SciaRegs.SCIFFRX.all=0x2041;		//10000001001111



	SciaRegs.SCIFFCT.bit.FFTXDLY = 0;         // 7:0    FIFO transmit delay
	SciaRegs.SCIFFCT.bit.rsvd = 0;            // 12:8   reserved
	SciaRegs.SCIFFCT.bit.CDC = 0;             // 13     Auto baud mode enable
	SciaRegs.SCIFFCT.bit.ABDCLR = 0;          // 14     Auto baud clear
	SciaRegs.SCIFFCT.bit.ABD = 0;             // 15     Auto baud detect

	SciaRegs.SCIFFCT.all = 0;//0x4000;		// Clear ABD(Auto baud bit) 										

	// SCI Control init
/*
	SciaRegs.SCICCR.bit.STOPBITS = 0;//One stop bit
	SciaRegs.SCICCR.bit.PARITY = 0;// not care
	SciaRegs.SCICCR.bit.PARITYENA = 0;//parity disable
	SciaRegs.SCICCR.bit.LOOPBKENA = 0;//loop back test mode disable
	SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0;//idle-line protocol selected
	SciaRegs.SCICCR.bit.SCICHAR = 7;//length = 8
*/
	SciaRegs.SCICCR.all = 0x0007;
/*
	SciaRegs.SCICTL1.bit.RXERRINTENA = 0;//error int disable
	SciaRegs.SCICTL1.bit.SWRESET = 0;//not rst
	SciaRegs.SCICTL1.bit.TXWAKE = 0;//transmit feature is not selected
	SciaRegs.SCICTL1.bit.SLEEP = 0;//sleep mode disable
	SciaRegs.SCICTL1.bit.TXENA = 1;//Transmitter enabled
	SciaRegs.SCICTL1.bit.RXENA = 1;//Received enabled
*/
	SciaRegs.SCICTL1.all = 0x0003;

	SciaRegs.SCICTL2.bit.RXBKINTENA = 0;//Disable RxRDY int
	SciaRegs.SCICTL2.bit.TXINTENA = 0;//Disable TxRDY int

	#if (CPU_FRQ_150MHZ)
		SciaRegs.SCIHBAUD = BAUD150_115200 >> 8; // 115200 baud @LSPCLK = 37.5MHz.
		SciaRegs.SCILBAUD = BAUD150_115200 & 0xff;
	#endif
	#if (CPU_FRQ_100MHZ)
		SciaRegs.SCIHBAUD    =BAUD100_115200>>8;  // 115200 baud @LSPCLK = 20MHz.
      		SciaRegs.SCILBAUD    =BAUD100_115200&0xff;;
	#endif

	
	SciaRegs.SCICTL1.all =0x0023;  // Relinquish SCI from Reset
	// Initialize SCI-B:

	//tbd...
  
      // Initialize SCI-C:

      //tbd...
}	

//---------------------------------------------------------------------------
// Example: InitSciGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as SCI pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 
// Caution: 
// Only one GPIO pin should be enabled for SCITXDA/B operation.
// Only one GPIO pin shoudl be enabled for SCIRXDA/B operation. 
// Comment out other unwanted lines.

void InitSciGpio()
{
   InitSciaGpio();
#if DSP28_SCIB   
   InitScibGpio();
#endif // if DSP28_SCIB  
#if DSP28_SCIC
   InitScicGpio();
#endif // if DSP28_SCIC
}

void InitSciaGpio()
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.  
// This will enable the pullups for the specified pins.

//	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up for GPIO28 (SCIRXDA)
//	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;	   // Enable pull-up for GPIO29 (SCITXDA)
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 0;    // Enable pull-up for GPIO36 (SCIRXDA)
	GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 0;	   // Enable pull-up for GPIO35 (SCITXDA)

/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.  
// This will select asynch (no qualification) for the selected pins.

//	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 3;  // Asynch input GPIO36 (SCIRXDA)

/* Configure SCI-A pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be SCI functional pins.

//	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // Configure GPIO28 for SCIRXDA operation
//	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // Configure GPIO29 for SCITXDA operation
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 1;   // Configure GPIO36 for SCIRXDA operation
	GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 1;   // Configure GPIO35 for SCITXDA operation
	
    EDIS;
}

#if DSP28_SCIB 
void InitScibGpio()
{
   EALLOW;
	
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.  
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

//  GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;     // Enable pull-up for GPIO9  (SCITXDB)
//  GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;    // Enable pull-up for GPIO14 (SCITXDB)
	GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;	   // Enable pull-up for GPIO18 (SCITXDB)
//  GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;    // Enable pull-up for GPIO22 (SCITXDB)

	
//  GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;    // Enable pull-up for GPIO11 (SCIRXDB)
//  GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // Enable pull-up for GPIO15 (SCIRXDB)
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;	   // Enable pull-up for GPIO19 (SCIRXDB)
//  GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;    // Enable pull-up for GPIO23 (SCIRXDB)

/* Set qualification for selected pins to asynch only */
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.

//  GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 3;  // Asynch input GPIO11 (SCIRXDB)
//  GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;  // Asynch input GPIO15 (SCIRXDB)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3;  // Asynch input GPIO19 (SCIRXDB)
//  GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 3;  // Asynch input GPIO23 (SCIRXDB)

/* Configure SCI-B pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be SCI functional pins.
// Comment out other unwanted lines.

//  GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 2;    // Configure GPIO9 for SCITXDB operation
//  GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 2;   // Configure GPIO14 for SCITXDB operation
	GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 2;   // Configure GPIO18 for SCITXDB operation
//  GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 3;   // Configure GPIO22 for SCITXDB operation
	
//  GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 2;   // Configure GPIO11 for SCIRXDB operation
//  GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 2;   // Configure GPIO15 for SCIRXDB operation
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 2;   // Configure GPIO19 for SCIRXDB operation
//  GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 3;   // Configure GPIO23 for SCIRXDB operation
	
    EDIS;
}
#endif // if DSP28_SCIB 

#if DSP28_SCIC
void InitScicGpio()
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.  
// This will enable the pullups for the specified pins.

	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0;    // Enable pull-up for GPIO62 (SCIRXDC)
	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 0;	   // Enable pull-up for GPIO63 (SCITXDC)

/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.  
// This will select asynch (no qualification) for the selected pins.

	GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 3;  // Asynch input GPIO62 (SCIRXDC)

/* Configure SCI-C pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be SCI functional pins.

	GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 1;   // Configure GPIO62 for SCIRXDC operation
	GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 1;   // Configure GPIO63 for SCITXDC operation
	
    EDIS;
}

#endif // if DSP28_SCIC 

	
//===========================================================================
// End of file.
//===========================================================================
