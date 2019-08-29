//###########################################################################
//
// FILE:   serial.c
//
// TITLE:  MAZE 10th  28335 Serial module
//
// DESCRIPTION:
//	    				
//         Jeon yu hun  serial test
//
//###########################################################################
// $Release Date: 12-18, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File


/*   SCIA_RXCHAR   */
/*************************************************************************
*	@name    	SCIa_RxChar
*	@memo	       Uart_a char 입력 리턴
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
char SCIa_RxChar(void)
{
    while( !(SciaRegs.SCIRXST.bit.RXRDY) );
    return (char)SciaRegs.SCIRXBUF.all;
}






/*   SCIB_RXCHAR   */
/*************************************************************************
*	@name    	SCIb_RxChar
*	@memo	       Uart_b char 입력 리턴
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
char SCIb_RxChar(void)
{
    while( !(ScibRegs.SCIRXST.bit.RXRDY) );
    return (char)ScibRegs.SCIRXBUF.all;
}






/*   SCIC_RXCHAR   */
/*************************************************************************
*	@name    	SCIc_RxChar
*	@memo	       Uart_c char 입력 리턴
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
char SCIc_RxChar(void)
{
    while( !(ScicRegs.SCIRXST.bit.RXRDY) );
    return (char)ScicRegs.SCIRXBUF.all;
}





/*   SCIX_TXCHAR   */
/*************************************************************************
*	@name    	SCIx_TxChar
*	@memo	       지정된 SCI 에 한문자 출력
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
void SCIx_TxChar(char Data, volatile struct SCI_REGS *sciadd)
{	
	while(!(sciadd->SCICTL2.bit.TXRDY));
	sciadd->SCITXBUF = Data;
}





/*   SCIX_TXSTRING   */
/*************************************************************************
*	@name    	SCIx_TxString
*	@memo	       지정된 SCI에 문자열 출력
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
void SCIx_TxString(char *Str, volatile struct SCI_REGS *sciadd)
{
    while(*Str) 
    {
        if(*Str == '\n'){
            SCIx_TxChar('\r', sciadd);
        }		
        SCIx_TxChar(*Str++,sciadd );
    }
}      








/*   SCIA_PRINTF   */
/*************************************************************************
*	@name    	SCIa_Printf
*	@memo	       SCIA Printf 형식 함수
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
void SCIa_Printf(char *Form, ... )
{
    static char Buff[100];
    va_list ArgPtr;
    va_start(ArgPtr,Form);	 
    vsprintf(Buff, Form, ArgPtr);
    va_end(ArgPtr);
//    SCIa_TxString(Buff);
    SCIx_TxString(Buff,&SciaRegs);
}










/*   SCIB_PRINTF   */
/*************************************************************************
*	@name    	SCIb_Printf
*	@memo	       SCIB Printf 형식 함수
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
void SCIb_Printf(char *Form, ... )
{
    static char Buff[100];
    va_list ArgPtr;
    va_start(ArgPtr,Form);	 
    vsprintf(Buff, Form, ArgPtr);
    va_end(ArgPtr);
//    SCIa_TxString(Buff);
    SCIx_TxString(Buff,&ScibRegs);
}







/*   SCIC_PRINTF   */
/*************************************************************************
*	@name    	SCIc_Printf
*	@memo	       SCIC Printf 형식 함수
*	@author	       Joen yu hun
*	@company	MAZE
*    
**************************************************************************/
void SCIc_Printf(char *Form, ... )
{
    static char Buff[100];
    va_list ArgPtr;
    va_start(ArgPtr,Form);	 
    vsprintf(Buff, Form, ArgPtr);
    va_end(ArgPtr);
//    SCIa_TxString(Buff);
    SCIx_TxString(Buff,&ScicRegs);
}

