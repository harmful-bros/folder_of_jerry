//############################################################################
//
//		     _______         ______  
//		    |           |       |          |
//		    |           |       |          |
//		    |           |       |          |
//		    |           |____|          |
//		    |                                |
//		    |                                |
//		    |             ____            |
//		    |           |       |          |
//		    |           |       |          |
//		    |           |       |          |
//		    |______|        |______|  2 !!
//
//
//###########################################################################
//
// FILE		: main.c
//
// TITLE		: micromouse H2 main source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.01 $
//###########################################################################

#define __VARIABLE__
#define __STRUCT__

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#pragma CODE_SECTION(main, "ramfuncs"); //all code is excute from external RAM

const Uint16 g_u16wall_t[ 4 ] = { DIR_N , DIR_E , DIR_S , DIR_W }; 
const int32 g_int32move_t[ 4 ] = { 0x01 , 0x10 , -0x01 , -0x10 };

static void _ram_init( void ) //grobal variable initialize
{
	EALLOW;
	GpioCtrlRegs.GPADIR.all = 0x0cc3c3ff;	/* gpio0 ~ gpio31 data output pin setting up */
	GpioCtrlRegs.GPBDIR.all = 0x000f0003;	/* gpio32 ~ gpio63 data output pin setting up */
	EDIS;

	R_RED_ON;
	L_RED_ON;	

	motor_vari_init();
	sensor_vari_init();

	init_select_fuction_pointer();

	// struct
	memset( ( void * )&g_flag , 0x00 , sizeof( bit_field_t ) );
	memset( ( void * )&g_run , 0x00 , sizeof( run_limit_vari_t ) );

	//Uint32
	g_u32time_cnt = 0;

	//int32
	g_int32menu_cnt = 0;
	g_int32sen_cnt = 0;
	g_int32pid_ISR_cnt = 0;
	g_int32turn_vel = 0;
	g_int32vel_select = 0;
	g_int32block_to_block = 0;
	g_int32tick = 0;
	g_int32turn_acc = 0;

	g_int32straight_acc = 0;
	g_int32diag_acc = 0;

	g_int32backup_turnvel = 0;
	g_int32backup_turnsel = 0;

	//float
	g_fp32left_handle = ( float32 )1.0;
	g_fp32right_handle = ( float32 )1.0;
	
	g_fp32han_accdiff = ( float32 )0.0;
	g_fp32han_decdiff = ( float32 )0.0;
	g_fp32han_accref = ( float32 )0.0;	
	g_fp32han_decref = ( float32 )0.0;

	g_fp32err_dist = ( float32 )0.0;

	g_fp32time = ( float32 )0.0;

	g_fp32left_pos = ( float32 )0.0;
	g_fp32right_pos = ( float32 )0.0;
	
}

void main(void)
{
	// Disable CPU interrupts
	DINT;

	// Disable CPU interrupts and clear all CPU interrupt flags:
	IER = 0x0000;
	IFR = 0x0000;

	// PLL, WatchDog, enable Peripheral Clocks
	//MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

	InitSysCtrl();

	// Initalize GPIO:
	InitGpio();
	InitXintf();

	// Initialize PIE control registers to their default state.
	InitPieCtrl();

	// Initialize the PIE vector table with pointers to the shell Interrupt
	// Service Routines (ISR).
	// Clear all interrupts and initialize PIE vector table:
	InitPieVectTable();
	InitCpuTimers();

	InitAdc();
	InitEQep1Gpio();
	InitEQep2Gpio();
	InitEQep( &LQepRegs );
	InitEQep( &RQepRegs );

	_ram_init();	

	Init_ISR();
	StartCpuTimer2();	 	/* motor interrupt */
//	StartCpuTimer0();		/* sensor interrupt */
	InitSpi();

	InitSci();
	vfd_init();

	InitEPwm1Gpio();
	InitEPwm2Gpio();
	InitEPwm( &RightPwmRegs );
	InitEPwm( &LeftPwmRegs );

	front_sensor_value_read_rom();
	side_and_diag_sensor_value_read_rom();

	turn_vari_read_rom();
	fastrun_vari_read_rom();

	handle_ad_make( ACC_RATIO , DEC_RATIO );

	vfdprintf("_H2_");
	DELAY_US( 100000 );
	vfdprintf("    ");	
	DELAY_US( 100000 );
	vfdprintf("_H2_");
	DELAY_US( 100000 );

	SCIa_Printf("\n\n\n");

	menu_func_init();
	menu_select_func();

}



