// TI File $Revision: /main/3 $
// Checkin $Date: July 27, 2007   11:55:20 $
//###########################################################################
//
// FILE:   DSP2833x_EQep.c
//
// TITLE:  DSP2833x eQEP Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x Header Files V1.20 $
// $Release Date: August 1, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitEQep:
//---------------------------------------------------------------------------
// This function initializes the eQEP(s) to a known state.
//
void InitEQep(volatile struct EQEP_REGS *pQepRegs)
{
#if 1
	pQepRegs->QDECCTL.all = 0x0000;

	pQepRegs->QEPCTL.bit.FREE_SOFT = 3;
	pQepRegs->QEPCTL.bit.PCRM = 3;
	pQepRegs->QEPCTL.bit.SEI = 0;
	pQepRegs->QEPCTL.bit.IEI = 0;
	pQepRegs->QEPCTL.bit.SWI = 1;
	pQepRegs->QEPCTL.bit.SEL = 0;
	pQepRegs->QEPCTL.bit.IEL = 0;
	pQepRegs->QEPCTL.bit.QPEN = 1;
	pQepRegs->QEPCTL.bit.QCLM = 0;
	pQepRegs->QEPCTL.bit.UTE = 0;
	pQepRegs->QEPCTL.bit.WDE = 0;

	pQepRegs->QPOSCTL.all = 0x0000;

	pQepRegs->QPOSCNT = 0;
	pQepRegs->QPOSINIT = 0;
	pQepRegs->QPOSMAX = 4096;
	pQepRegs->QPOSCMP = 0;

#else
	/*
	pQEP->QDECCTL.bit.QSRC = 0;//Quadrature count mode
	pQEP->QDECCTL.bit.SOEN = 0;//Disable position-compare sync output
	pQEP->QDECCTL.bit.SPSEL = 0;//index pin is used for sync output
	pQEP->QDECCTL.bit.XCR = 0;// 2x resolution
	pQEP->QDECCTL.bit.SWAP = 0;//Quadrature-clk inputs are not swapped
	pQEP->QDECCTL.bit.IGATE = 0;//Disable gating of index pulse
	pQEP->QDECCTL.bit.QAP = 0;//NO effect
	pQEP->QDECCTL.bit.QBP = 0;//NO effect
	pQEP->QDECCTL.bit.QIP = 0;//NO effect
	pQEP->QDECCTL.bit.QSP = 0;//NO effect
	*/
	pQepRegs->QDECCTL.all = 0;

	/*
	pQEP->QEPCTL.bit.FREE_SOFT = 2;//unaffected by emulation suspend
	pQEP->QEPCTL.bit.PCRM = 1;//Position counter reset on the maximum position
	pQEP->QEPCTL.bit.SEI = 0;//disable Strobe event
	pQEP->QEPCTL.bit.IEI = 0;//disable Index event
	pQEP->QEPCTL.bit.SWI = 0;// do noting   software init position counter
	pQEP->QEPCTL.bit.SEL = 0;//.
	pQEP->QEPCTL.bit.IEL = 0;//.
	pQEP->QEPCTL.bit.QPEN = 1;//position counter is enabled
	pQEP->QEPCTL.bit.QCLM = 0;//.
	pQEP->QEPCTL.bit.UTE = 0;//Enable unit timer
	pQEP->QEPCTL.bit.WDE = 0;//Disable the QEP watch dog
	*/
	// 1001 0000 0000 1010
	pQepRegs->QEPCTL.all =0x9008; 
	
	pQepRegs->QPOSCTL.all = 0;//Disable position compare unit

	//T term
	pQepRegs->QUPRD = 0;// unit timer off. value * 10ns

	pQepRegs->QCAPCTL.bit.CEN = 0;//Diasble QEP capture


	// 4 - 6.26MHz - 160ns
	pQepRegs->QCAPCTL.bit.CCPS = 0;//CAPCLK = sysclk /1
	
	pQepRegs->QCAPCTL.bit.UPPS = 0;//UPEVNT = QCLK/1

	pQepRegs->QEPSTS.bit.UPEVNT = 1;// Unit position event detected clear
	pQepRegs->QCAPCTL.bit.CEN = 1;//Enable QEP capture

	pQepRegs->QEINT.all = 0;
	pQepRegs->QPOSINIT = 0;
	pQepRegs->QPOSMAX = 4096;
	pQepRegs->QEPCTL.bit.SWI = 1;
#endif
}

//---------------------------------------------------------------------------
// Example: InitEQepGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as eQEP pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
//
// Caution:
// For each eQEP peripheral
// Only one GPIO pin should be enabled for EQEPxA operation.
// Only one GPIO pin should be enabled for EQEPxB operation.
// Only one GPIO pin should be enabled for EQEPxS operation.
// Only one GPIO pin should be enabled for EQEPxI operation.
// Comment out other unwanted lines.

void InitEQepGpio()
{
#if DSP28_EQEP1
   InitEQep1Gpio();
#endif  // endif DSP28_EQEP1
#if DSP28_EQEP2
   InitEQep2Gpio();
#endif // endif DSP28_EQEP2
}

#if DSP28_EQEP1
void InitEQep1Gpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pull-up on GPIO20 (EQEP1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;   // Enable pull-up on GPIO21 (EQEP1B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;   // Enable pull-up on GPIO22 (EQEP1S)
//    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;   // Enable pull-up on GPIO23 (EQEP1I)

//    GpioCtrlRegs.GPBPUD.bit.GPIO50 = 0;   // Enable pull-up on GPIO50 (EQEP1A)
//    GpioCtrlRegs.GPBPUD.bit.GPIO51 = 0;   // Enable pull-up on GPIO51 (EQEP1B)
//    GpioCtrlRegs.GPBPUD.bit.GPIO52 = 0;   // Enable pull-up on GPIO52 (EQEP1S)
//    GpioCtrlRegs.GPBPUD.bit.GPIO53 = 0;   // Enable pull-up on GPIO53 (EQEP1I)


// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;   // Sync to SYSCLKOUT GPIO20 (EQEP1A)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 0;   // Sync to SYSCLKOUT GPIO21 (EQEP1B)
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO22 = 0;   // Sync to SYSCLKOUT GPIO22 (EQEP1S)
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 0;   // Sync to SYSCLKOUT GPIO23 (EQEP1I)

//    GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 0;   // Sync to SYSCLKOUT GPIO50 (EQEP1A)
//    GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 0;   // Sync to SYSCLKOUT GPIO51 (EQEP1B)
//    GpioCtrlRegs.GPBQSEL2.bit.GPIO52 = 0;   // Sync to SYSCLKOUT GPIO52 (EQEP1S)
//    GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 0;   // Sync to SYSCLKOUT GPIO53 (EQEP1I)

/* Configure eQEP-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be eQEP1 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;   // Configure GPIO20 as EQEP1A
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1;   // Configure GPIO21 as EQEP1B
//    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 1;   // Configure GPIO22 as EQEP1S
//    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 1;   // Configure GPIO23 as EQEP1I

//    GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 1;   // Configure GPIO50 as EQEP1A
//    GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 1;   // Configure GPIO51 as EQEP1B
//    GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 1;   // Configure GPIO52 as EQEP1S
//    GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 1;   // Configure GPIO53 as EQEP1I


    EDIS;
}
#endif // if DSP28_EQEP1



#if DSP28_EQEP2
void InitEQep2Gpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;    // Enable pull-up on GPIO24 (EQEP2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;    // Enable pull-up on GPIO25 (EQEP2B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;    // Enable pull-up on GPIO26 (EQEP2I)
//    GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0;    // Enable pull-up on GPIO27 (EQEP2S)

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0;  // Sync to SYSCLKOUT GPIO24 (EQEP2A)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 0;  // Sync to SYSCLKOUT GPIO25 (EQEP2B)
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0;  // Sync to SYSCLKOUT GPIO26 (EQEP2I)
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 0;  // Sync to SYSCLKOUT GPIO27 (EQEP2S)

/* Configure eQEP-2 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be eQEP2 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 2;   // Configure GPIO24 as EQEP2A
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 2;   // Configure GPIO25 as EQEP2B
//    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 2;   // Configure GPIO26 as EQEP2I
//    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 2;   // Configure GPIO27 as EQEP2S


    EDIS;
}
#endif // endif DSP28_EQEP2




//===========================================================================
// End of file.
//===========================================================================
