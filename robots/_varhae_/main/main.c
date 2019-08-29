//###############################################################################################################
//														#
//	 _______        ______________________       _______      _____________     _______________		#
//	|       |      /                      \     |       |    |             \   |               |		#
//	|       |     /      __        ____    \    |       |    |       __     \  |        _______|		#
//	|       |    /      /  |      |    \    \   |       |    |      |  \     \ |       |			#
//	|       |   /      /___|      |____/    /   |       |____|      |___\     \|       |_______		#
//	|       |  /                           /    |                              \               |		#
//	|       | /       _____        ___     \    |        ____        _____      \       _______|		#
//	|       |/       /     |      |   \     \   |       |    |      |     \      \     |			#
//	|               /      |      |    \     \  |       |    |      |      \      \    |_______		#
//	|              /       |      |     \     \ |       |    |      |       \      \           |		#
//	|_____________/        |______|      \_____\|_______|    |______|        \______\__________|		#
//														#
//														#
//###############################################################################################################
//
// FILE		: main.c
//
// TITLE	: _varhae_ Tracer main source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.07.11 $
//###########################################################################


#define __VARIABLE__
#define __STRUCT__

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File


#pragma CODE_SECTION(main, "ramfuncs"); //all code is excute from external RAM


static void ram_init( void ) //grobal variable initialize
{
	EALLOW;
	GpioCtrlRegs.GPADIR.all = 0x0cc3ffc3;	/* gpio0 ~ gpio31 data output pin setting up */
	GpioCtrlRegs.GPBDIR.all = 0x00030003;	/* gpio32 ~ gpio63 data output pin setting up */
	EDIS;

	BLUE_ON;

	// int32
	g_int32menu_count = 0;
	g_int32turn_vel = 0;
	g_int32turn_acc = 0;
	g_int32sen_cnt = 0;
	g_int32adc_cnt	 = 0;
	g_int32pid_ISR_cnt = 0;
	g_int32time_cnt = 0;
	g_int32error_cnt = 0;
	g_int32mark_cnt = 0;	
	g_int32speed_up_cnt = 0;
	g_int32max_speed = 0;
	g_int32large_vel = 0;	
	g_int32max_acc = 0;
	g_int32end_acc = 0;
	g_int32mid_acc = 0;
	g_int32short_acc	 = 0;
	g_int32large_acc = 0;
	g_int32start_dist = 0;
	g_int32lineout_cnt = 0;
	g_int32decel_dist_scope = 0;
	g_int3245A_vel = 0;
	g_int32s44s_vel = 0;	
	g_int3245A_acc = 0;
	g_int32pos_cnt = S_SIX;
	g_int32escape45_vel = 0;
	g_int32force_mark = 0;
	g_int32limit_vel = 0;
	g_int32s4s_vel = 0;
	g_int32inverse_run = OFF;
	g_int32large_turn_flag = OFF;
	g_int32mark_gyro_toggle = OFF;
	g_int32end_dist = END_DIST_LIMIT;

	// float32
	g_fp32right_handle = 0.0;
	g_fp32left_handle = 0.0;
	g_fp32han_accstep = 0.0;
	g_fp32han_decstep = 0.0;
	g_fp32han_accmax = 0.0;
	g_fp32han_decmax = 0.0;
	g_fp32cross_dist = 0.0;
	g_fp32time = 0.0;
	g_fp32max_val = 0.0;
	g_fp32shift_pos_val = 0.0;  //실제 포지션에 가감해질 변화량
	g_fp32shift_dist = 0.0;
	g_fp32xrun_dist = 0.0;

	// flag.Uint16
	memset( ( void * )&g_Flag , 0x00 , sizeof( bitflag ) );	

	// struct initialize
	memset( ( void * )g_ptr , 0x00 , sizeof( str_point_t * ) );
	memset( ( void * )&g_ptemp , 0x00 , sizeof( str_point_t ) );
	memset( ( void * )&g_lineinfo , 0x00 , sizeof( line_info_t ) );
	memset( ( void * )&g_secflag , 0x00 , sizeof( sec_flag_t ) );
	memset( ( void * )&g_err , 0x00 , sizeof( err_dps_t ) );
	memset( ( void * )g_secinfo , 0x00 , sizeof( sec_info_t ) * BUFF_MAX_SIZE );

	init_motor_variable( &R_motor );
	init_motor_variable( &L_motor );

	init_sen_vari();

	 //pointer
	g_ptr = &g_ptemp;
	g_ptr->psen = g_sen;
	g_ptr->pgyro = &g_gyro;
	g_ptr->ppos = &g_pos;	
	g_ptr->prmark = &g_rmark;
	g_ptr->plmark = &g_lmark;
	g_ptr->psecinfo = g_secinfo;
	g_ptr->perr = &g_err;

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

	ram_init();	

	Init_ISR();
	StartCpuTimer2();	 /* motor interrupt */
//	StartCpuTimer0();		/* sensor interrupt */
	InitSpi();

	InitSci();
	InitVFDBright(VfdBright53);

	InitEPwm1Gpio();
	InitEPwm( &RightPwmRegs );
	InitEPwm( &LeftPwmRegs );

	sensor_load_rom();
	velocity_load_rom();
	accel_load_rom();
//	line_load_rom();

	LED_OFF;

	VFDPrintf("_varhae_");
	DELAY_US( 100000 );
	VFDPrintf("        ");	
	DELAY_US( 100000 );
	VFDPrintf("#welcome");
	DELAY_US( 100000 );

#ifdef MOTOR_TEST	
	VFDPrintf("        ");
	g_Flag.start_flag = ON;
	g_fp32right_handle = g_fp32left_handle = ( float32 )1.0;
	//move_end( ( float32 )1000.0 , ( float32 )300.0 , 17 );
	move_to_move( ( float32 )2000.0 , ( float32 )500.0 , ( float32 )1000.0 , ( float32 )0.0 , ( int32 )17 );

	while( 1 )
	{
		if( g_int32pid_ISR_cnt )
		{
			SCIa_Printf("%10lf %5lf %5lf\n" , ( R_motor.fp32cur_vel_avr + L_motor.fp32cur_vel_avr ) * 0.5 , L_motor.fp32next_acc , R_motor.fp32next_acc );
			g_int32pid_ISR_cnt = 0;
		}
	}
#else
	menu_func_init();
	menu_select();	
#endif

}



