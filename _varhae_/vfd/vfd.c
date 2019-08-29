//###########################################################################
//
// FILE		: vfd.c
//
// TITLE		: _varhae_ Tracer VFD source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.04.14 $
//###########################################################################

#if 0  //example
	while( 1 )
	{
		// VFD_scroll( "Hertz9th leejaeseong  " , 0.5 );
		// VFD_loiter( "  =Hi=  " , 4 , 0.5 );
	}
#endif


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define VFD_CNT_CS		(*(volatile Uint16 *)0x0200010)
#define VFD_DATA		(Uint32)0x0200018

#define VFDCLEAR		0x80

#define VFD_SECTION 	7
#define BUFF_SIZE		128

Uint16 VFDAddr;
Uint16 VFDBright;

void InitVFDBright(Uint16 i)
{
	VFD_CNT_CS = i; // 주소에 값을 넣음
	DSP28x_usDelay(500);
	VFDAddr = 0;
	VFDBright = i;
}

void VFDPutChar(char Data)
{
	if(VFDAddr < 0x08)
	{
		(*(volatile Uint16 *)(VFD_DATA + VFDAddr)) = Data; // 주소에 데이터를 넣음
		DSP28x_usDelay(50);
	}
	else;
	
	VFDAddr+=1; // 주소증가
}

void VFDString(char *Str)
{	
	VFD_CNT_CS = VFDCLEAR | VFDBright; // 데이터 0,1,2,3에 밝기 추가한후 주소에 값을 넣음
	DSP28x_usDelay(1000);
	VFDAddr = 0;

	while(*Str)
	{
		VFDPutChar(*Str++); // 데이터 한바이트씩 넣음
	}
}

void VFDPrintf(char *form, ... )
{
    static char buff[50];

	va_list argptr;
    va_start(argptr,form);
    vsprintf(buff, form, argptr);
	va_end(argptr);
	VFDString(buff); // 문자열 출력
}


void VFD_scroll( char *str , float32 sec )
{
	int i , j , length;

	int val_table[ BUFF_SIZE ] = { 0 , };
	char real_str[ BUFF_SIZE ] = { 0 , };

	length = strlen( ( const char * )str );

	if( str == NULL || length > 127 )  //error disposal
	{
		VFDPrintf(" =NULL= ");
		return;
	}
	
	sprintf( real_str , "%s" , str );

	for( i = 0 , j = 0 ; i < length + VFD_SECTION ; i++ , j++ )	 //초기화
	{
		if( j >= length )	j = 0;
		val_table[ i ] = j;
	}

	for( i = 0 ; i < length ; i++ )
	{
		DELAY_US( sec * 100000 );

		VFD_CNT_CS = VFDCLEAR | VFDBright; // 데이터 0,1,2,3에 밝기 추가한후 주소에 값을 넣음
		DSP28x_usDelay( 1000 ); 
		
		VFDAddr = 0;
	
		for( j = 0 ; j <= VFD_SECTION ; j++ )
		{
			VFDPutChar( real_str[ val_table[ i + j ] ] );
		}
	}
	
}

void VFD_loiter( char *str , int gap , float32 sec )
{
	int32 i , j , k , length;
	int val_table[ 16 ] = { 0 , };
	char real_str[ 16 ] = { 0 , };

	if( str == NULL || ( gap & 0x01 ) || !gap || ( length = strlen( str ) ) > 8 || !length )
	{
		VFDPrintf(" =NULL= ");
		return;
	}

	for( i = 0 , j = 8 - ( gap >> 1 ) ; i < gap + 8 ; i++ , j++ )
	{
		if( j > 7 )	j = 0;
		val_table[ i ] = j;
	}

	sprintf( real_str , "%s" , str );

	for( i = 0 ; i < gap << 1 ; i++ )
	{
		DELAY_US( sec * 100000 );

		VFD_CNT_CS = VFDCLEAR | VFDBright; // 데이터 0,1,2,3에 밝기 추가한후 주소에 값을 넣음
		DSP28x_usDelay( 1000 ); 
		
		VFDAddr = 0;
	
		k = i > gap ? k - 1 : i;
		for( j = k ; j <= k + 7 ; j++ )
		{
			VFDPutChar( real_str[ val_table[ j ] ] );
		}
	}

}

