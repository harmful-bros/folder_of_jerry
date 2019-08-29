//###########################################################################
//
// FILE:   serial.h
//
// TITLE:  MAZE 10th  28335 Serial module
//
// DESCRIPTION:
//	    				
//         Jeon yu hun  serial test
//
//###########################################################################
// $Release Date: 12-13, 2008 $
//###########################################################################

#ifndef SERIAL_H
#define SERIAL_H


#ifdef __cplusplus
extern "C" {
#endif

extern char SCIa_RxChar(void);
extern char SCIb_RxChar(void);
extern char SCIc_RxChar(void);

extern void SCIx_TxChar(char Data, volatile struct SCI_REGS *sciadd);
extern void SCIx_TxString(char *Str, volatile struct SCI_REGS *sciadd);
extern void SCIa_Printf(char *Form, ... );
extern void SCIb_Printf(char *Form, ... );
extern void SCIc_Printf(char *Form, ... );



#ifdef __cplusplus
}
#endif /* extern "C" */


#endif

