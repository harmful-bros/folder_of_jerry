// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:46:44 $
//###########################################################################
//
// FILE:   DSP2833x_Spi.c
//
// TITLE:  DSP2833x SPI Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x Header Files V1.20 $
// $Release Date: August 1, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define	SPI_CS_HIGH		{GpioDataRegs.GPBSET.bit.GPIO57 = 1;}
#define	SPI_CS_LOW		{GpioDataRegs.GPBCLEAR.bit.GPIO57 = 1;}

#define SPI_CS_DELAY	DELAY_US(10000);

#define PAGE_PROGRAM_DIRECT 	0x82
#define PAGE_READ				0xd2
#define STATUS_REG_READ			0xd7

void InitSpi(void)
{
	InitSpiGpio();

	SpiaRegs.SPICCR.all = 0x0007;		 //전송 char 길이 8bit 			00x0 0111
	SpiaRegs.SPICTL.all = 0x001f;		 //모든 인터럽트 및 핀 활성화.		xxx1 1111
	SpiaRegs.SPISTS.all = 0x00;			 //111x xxxx
	SpiaRegs.SPIBRR = 0x00;				 //전송 속도					x000 0000
	SpiaRegs.SPIFFTX.all = 0x8000;		 //FIFO 전송 셋팅				1000 0000 0000 0000
	SpiaRegs.SPIFFRX.all = 0x0000;		 //FIFO 수신 셋팅				0000 0000 0000 0000
	SpiaRegs.SPIFFCT.all = 0x00;		 //FIFO 컨트롤 셋팅				xxxx xxxx 0000 0000
	SpiaRegs.SPIPRI.all = 0x0010; 		 //우선순위 셋팅					xx01 xxxx
}   

void InitSpiGpio()
{
	EALLOW;

	/* Configure SPI-A pins using GPIO regs*/
	// This specifies which of the possible GPIO pins will be SPI functional pins.
	// Comment out other unwanted lines.
	GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 1; // Configure GPIO54 as SPISIMOA
	GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 1; // Configure GPIO55 as SPISOMIA
	GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 1; // Configure GPIO56 as SPICLKA
	GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0; // Configure GPIO57 as SPISTEA(GPIO I/O)

	GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1;

	/* Set qualification for selected pins to asynch only */
	// This will select asynch (no qualification) for the selected pins.
	// Comment out other unwanted lines.
	GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 0; // Asynch input GPIO54 (SPISIMOA)
	GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 0; // Asynch input GPIO55 (SPISOMIA)
	GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 0; // Asynch input GPIO56 (SPICLKA)
	GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 0; // Asynch input GPIO57 (SPISTEA)

	/* Enable internal pull-up for the selected pins */
	// Pull-ups can be enabled or disabled by the user.  
	// This will enable the pullups for the specified pins.
	// Comment out other unwanted lines.
	GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0;   // Enable pull-up on GPIO54 (SPISIMOA)
	GpioCtrlRegs.GPBPUD.bit.GPIO55 = 0;   // Enable pull-up on GPIO55 (SPISOMIA)
	GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;   // Enable pull-up on GPIO56 (SPICLKA)
	GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0;   // Enable pull-up on GPIO57 (SPISTEA)

	EDIS;
}

void SpiBusyOK(void)
{	
	Uint16 StatusReg = 0;

	while((StatusReg & 0x08) != 0x08)
	{
		SPI_CS_HIGH;
		SPI_CS_DELAY;
		SPI_CS_LOW;
		SPI_CS_DELAY;

		SpiaRegs.SPICCR.bit.SPISWRESET = 1;

		SpiTx(STATUS_REG_READ);
		StatusReg = SpiTx(0);

		SPI_CS_HIGH;
		SPI_CS_DELAY;
	}
	
}


void SpiLoadRom(Uint16 PageAdd, Uint16 BufAdd, Uint16 Number, Uint16 *pBuf)
{
	Uint16 SpiCMD = 0;
	Uint16 Add1 = 0;
	Uint16 Add2 = 0;
	Uint16 Add3 = 0;
	Uint16 i = 0;

	SpiBusyOK();

	//rom address ..
	//xxxx xxPP // PPPP PPPB // BBBB BBBB //

	Add1 = (PageAdd & 0x1ff) >> 7;
	Add2 = ((PageAdd & 0x7f) << 1)	| ((BufAdd & 0x1ff) >> 8);	
	Add3 = (BufAdd & 0xff);
	SpiCMD = PAGE_READ;

	SPI_CS_HIGH;
	SPI_CS_DELAY;
	SPI_CS_LOW;
	SPI_CS_DELAY;

	//send 0xd2
	SpiaRegs.SPICCR.bit.SPISWRESET = 1;

	SpiTx(SpiCMD);
	SpiTx(Add1);
	SpiTx(Add2);
		SpiTx(Add3);
	//dont care byte
	SpiTx(0);
	SpiTx(0);
	SpiTx(0);
	SpiTx(0);

	for(i = 0; i < Number; i++)
	{
		pBuf[i] = SpiTx(0);
	}

	SPI_CS_HIGH;
	SPI_CS_DELAY;


}


void SpiSaveRom(Uint16 PageAdd, Uint16 BufAdd, Uint16 Number, Uint16 *pBuf)
{
	Uint16 SpiCMD = 0;
	Uint16 Add1 = 0;
	Uint16 Add2 = 0;
	Uint16 Add3 = 0;
	Uint16 i = 0;

	SpiBusyOK();

	//rom address ..
	//xxxx xxPP // PPPP PPPB // BBBB BBBB //

	Add1 = (PageAdd & 0x1ff) >> 7;
	Add2 = ((PageAdd & 0x7f) << 1)	| ((BufAdd & 0x1ff) >> 8);	
	Add3 = (BufAdd & 0xff);
	SpiCMD = PAGE_PROGRAM_DIRECT;

	SPI_CS_HIGH;
	SPI_CS_DELAY;
	SPI_CS_LOW;
	SPI_CS_DELAY;

	//send 0x82
	SpiaRegs.SPICCR.bit.SPISWRESET = 1;

	SpiTx(SpiCMD);
	SpiTx(Add1);
	SpiTx(Add2);
	SpiTx(Add3);

	for(i = 0; i < Number; i++)
	{
		SpiTx(pBuf[i] & 0xff);
	}

	SPI_CS_HIGH;
	SPI_CS_DELAY;


}


Uint16 SpiTx(Uint16 Buf)
{	
	SpiaRegs.SPITXBUF = (Uint16)((Buf & 0xff) << 8);
	SpiaRegs.SPISTS.bit.BUFFULL_FLAG = ON;
	while(SpiaRegs.SPISTS.bit.INT_FLAG == OFF);

	return ((SpiaRegs.SPIRXBUF) & 0xff);
}

//===========================================================================
// End of file.
//===========================================================================

