//###########################################################################
//
// FILE		: sensor.c
//
// TITLE		: _varhae_ Tracer sensor source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.09.19 $
//###########################################################################


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

static void sen_val_to_div( sen_t *psen , int32 div_cnt );

/* ADC timming */
#define ADC_0	0x0000
#define ADC_1	0x0000
#define ADC_2	0x1111
#define ADC_3	0x2222

#define ADC_4	0x3333
#define ADC_5	0x4444
#define ADC_6	0x5555
#define ADC_7	0x6666

#define ADC_8	0x7777
#define ADC_9	0x8888
#define ADC_10	0x9999
#define ADC_11	0xaaaa

#define ADC_12	0xbbbb
#define ADC_13	0xcccc
#define ADC_14	0xdddd
#define ADC_15	0xdddd

/* sensor digital IIR filter */
#define SENSOR_F_CUT				20.0		 //sensor cut frequency 20Hz
#define SENSOR_F_SAMPLE				4000.0	 //sensor sampling time is 4KHz(250us)
#define SENSOR_W_CUT				tan( M_PI * SENSOR_F_CUT / SENSOR_F_SAMPLE )  //radian 으로 계산 해야 됨.

#define SENSOR_Ka					-0.969067417193	//(W_CUT -1) / (W_CUT + 1)
#define SENSOR_Kb					0.0154662914031	// W_CUT / (W_CUT + 1)


#define SEARCH_GYRO_F_CUT			10.0		 //gyro cut frequency 10Hz

#define SEARCH_GYRO_Ka				-0.984414127416	//(W_CUT -1) / (W_CUT + 1)
#define SEARCH_GYRO_Kb				0.0077929362919	// W_CUT / (W_CUT + 1)


#define FASTRUN_GYRO_F_CUT			1.0		 //gyro cut frequency 1Hz

#define FASTRUN_GYRO_Ka				( float32 )-0.99843043608309411		//(W_CUT -1) / (W_CUT + 1)
#define FASTRUN_GYRO_Kb				( float32 )0.000784781958452940		// W_CUT / (W_CUT + 1)


/* position PID */
#define	F_dt						0.00025
#define	F_cut						80.0
#define	W_cut						(4.0 * 3.14 * F_cut)

#define	PID_Kb						0.1116352117046		//(W_cut *  F_dt) / (2.0 + W_cut * F_dt)
#define	PID_Ka						-0.776729576590		//(W_cut *  F_dt - 2.0) / (2.0 + W_cut * F_dt)


/* mark  checking */
#define	TURN_MARK_STEP					3.0
#define	TURN_MARK_CHECK_STEP			65.0

/* state center */
#define STATE_CENTER					9


typedef volatile enum
{
	SEN_0 = 6,
	SEN_1 ,
	SEN_2 ,
	SEN_3 ,
	SEN_4 ,
	SEN_5 ,
	SEN_6 ,
	SEN_7 ,
	SEN_NUM = 8,
	ADC_NUM = 16

}sensor_number;

volatile Uint16 sen_shoot_arr[ SEN_NUM ] = 
{
	SEN_7 , SEN_6 , SEN_5 , SEN_4 , SEN_3 , SEN_2 , SEN_1 , SEN_0
};

volatile Uint16 sen_adc_seq[ ADC_NUM ] = 
{
	ADC_15 , ADC_14 , ADC_13 , ADC_12 , ADC_11 , ADC_10 , ADC_9 , ADC_8,
	ADC_7 , ADC_6 , ADC_5 , ADC_4 , ADC_3 , ADC_2 , ADC_1 , ADC_0
};

volatile Uint16 state_table[] = 
{
	0xf000 , 0xf000 , 0xf000 , 
		
	0xf000 ,  // 1111 0000 0000 0000
	0x7800 ,  // 0111 1000 0000 0000
	0x3c00 ,  // 0011 1100 0000 0000
	0x1e00 ,  // 0001 1110 0000 0000	
	0x0f00 ,  // 0000 1111 0000 0000
	0x0780 ,  // 0000 0111 1000 0000
	0x03c0 ,  // 0000 0011 1100 0000
	0x01e0 ,  // 0000 0001 1110 0000	
	0x00f0 ,  // 0000 0000 1111 0000
	0x0078 ,  // 0000 0000 0111 1000
	0x003c ,  // 0000 0000 0011 1100
	0x001e ,  // 0000 0000 0001 1110
	0x000f ,  // 0000 0000 0000 1111
	
	0x000f , 0x000f , 0x000f
};


void init_sen_vari( void )
{
	memset( ( void * )g_sen , 0x00 , sizeof( sen_t ) * ADC_NUM );

	memset( ( void * )&g_gyro , 0x00 , sizeof( gyro_t ) );
	memset( ( void * )&g_pos , 0x00 , sizeof( position_t ) );
	memset( ( void * )&g_rmark , 0x00 , sizeof( turnmark_t ) );
	memset( ( void * )&g_lmark , 0x00 , sizeof( turnmark_t ) );	

	g_pos.u16enable = 0xffff; // 1111 1111 1111 1111

	g_sen[ L0 ].int32weight = -16000;		g_sen[ L0 ].u16active_arr = 0x8000;		g_sen[ L0 ].u16passive_arr = 0x7fff;	 // 1000 0000 0000 0000
	g_sen[ L1 ].int32weight = -14000;		g_sen[ L1 ].u16active_arr = 0x4000;		g_sen[ L1 ].u16passive_arr = 0xbfff;	 // 0100 0000 0000 0000
	g_sen[ L2 ].int32weight = -12000;		g_sen[ L2 ].u16active_arr = 0x2000;		g_sen[ L2 ].u16passive_arr = 0xdfff;	 // 0010 0000 0000 0000
	g_sen[ L3 ].int32weight = -10000;		g_sen[ L3 ].u16active_arr = 0x1000;		g_sen[ L3 ].u16passive_arr = 0xefff;	 // 0001 0000 0000 0000

	g_sen[ L4 ].int32weight = -8000;		g_sen[ L4 ].u16active_arr = 0x0800;		g_sen[ L4 ].u16passive_arr = 0xf7ff;	 // 0000 1000 0000 0000
	g_sen[ L5 ].int32weight = -6500;		g_sen[ L5 ].u16active_arr = 0x0400;		g_sen[ L5 ].u16passive_arr = 0xfbff;	 // 0000 0100 0000 0000
	g_sen[ L6 ].int32weight = -3000;		g_sen[ L6 ].u16active_arr = 0x0200;		g_sen[ L6 ].u16passive_arr = 0xfdff;	 // 0000 0010 0000 0000
	g_sen[ L7 ].int32weight = -1000;		g_sen[ L7 ].u16active_arr = 0x0100;		g_sen[ L7 ].u16passive_arr = 0xfeff;	 // 0000 0001 0000 0000

	g_sen[ R7 ].int32weight = 1000;			g_sen[ R7 ].u16active_arr = 0x0080;		g_sen[ R7 ].u16passive_arr = 0xff7f;	 // 0000 0000 1000 0000
	g_sen[ R6 ].int32weight = 3000;			g_sen[ R6 ].u16active_arr = 0x0040;		g_sen[ R6 ].u16passive_arr = 0xffbf;	 // 0000 0000 0100 0000
	g_sen[ R5 ].int32weight = 6500;			g_sen[ R5 ].u16active_arr = 0x0020;		g_sen[ R5 ].u16passive_arr = 0xffdf;	 // 0000 0000 0010 0000
	g_sen[ R4 ].int32weight = 8000;			g_sen[ R4 ].u16active_arr = 0x0010;		g_sen[ R4 ].u16passive_arr = 0xffef;	 // 0000 0000 0001 0000

	g_sen[ R3 ].int32weight = 10000;		g_sen[ R3 ].u16active_arr = 0x0008;		g_sen[ R3 ].u16passive_arr = 0xfff7;	 // 0000 0000 0000 1000
	g_sen[ R2 ].int32weight = 12000;		g_sen[ R2 ].u16active_arr = 0x0004;		g_sen[ R2 ].u16passive_arr = 0xfffb;	 // 0000 0000 0000 0100
	g_sen[ R1 ].int32weight = 14000;		g_sen[ R1 ].u16active_arr = 0x0002;		g_sen[ R1 ].u16passive_arr = 0xfffd;	 // 0000 0000 0000 0010
	g_sen[ R0 ].int32weight = 16000;		g_sen[ R0 ].u16active_arr = 0x0001;		g_sen[ R0 ].u16passive_arr = 0xfffe;	 // 0000 0000 0000 0001

	g_rmark.u16mark_enable = RIGHT_MARK_CHEK; 	// 0000 0000 0000 0111
	g_lmark.u16mark_enable = LEFT_MARK_CHEK; 	// 1110 0000 0000 0000

	g_rmark.u16mark_dir = RIGHT_TURN; //마크 방향 초기화
	g_lmark.u16mark_dir = LEFT_TURN;

	//조절 필요
	g_pos.fp32kp = POS_KP_UP;
	g_pos.fp32ki = 0.3;
	g_pos.fp32kd = POS_KD_UP;

	 //조절 필요
	g_gyro.fp32kp = 2.0;
	g_gyro.fp32ki = 0.00001;
	g_gyro.fp32kd = 5.0;

}

interrupt void sensor_timer_ISR( void ) //sensor val interrupt
{
//	GpioDataRegs.GPBSET.bit.GPIO32 = 1;

	// Acknowledge this interrupt to receive more interrupts from group 1
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

	GpioDataRegs.GPASET.all = ( ON << sen_shoot_arr[ g_int32sen_cnt ] );	 //sensor shoot code

	AdcRegs.ADCCHSELSEQ1.all = sen_adc_seq[ g_int32sen_cnt ];
	AdcRegs.ADCCHSELSEQ2.all = sen_adc_seq[ g_int32sen_cnt + SEN_NUM ];	
	AdcRegs.ADCCHSELSEQ3.all = sen_adc_seq[ g_int32sen_cnt ];
	AdcRegs.ADCCHSELSEQ4.all = sen_adc_seq[ g_int32sen_cnt + SEN_NUM ]; //ADC 순서 지정

	if( g_int32sen_cnt == 7 ) //adc to gyro value
	{
		AdcRegs.ADCCHSELSEQ4.bit.CONV15 = 15;
	}

	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1; /* ADC interrupt start */

}

interrupt void adc_timer_ISR( void ) //sensor ADC interrupt
{
	Uint16 adc_v1 = 0;
	Uint16 adc_v2 = 0;
	Uint16 gyro_v1 = 0;

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

	GpioDataRegs.GPACLEAR.all = ( ON << sen_shoot_arr[ g_int32sen_cnt ] ); //sensor shoot stop

	adc_v1 += AdcMirror.ADCRESULT0;
	adc_v1 += AdcMirror.ADCRESULT1;
	adc_v1 += AdcMirror.ADCRESULT2;
	adc_v1 += AdcMirror.ADCRESULT3;

	adc_v2 += AdcMirror.ADCRESULT4;
	adc_v2 += AdcMirror.ADCRESULT5;
	adc_v2 += AdcMirror.ADCRESULT6;
	adc_v2 += AdcMirror.ADCRESULT7;		

	adc_v1 += AdcMirror.ADCRESULT8;
	adc_v1 += AdcMirror.ADCRESULT9;
	adc_v1 += AdcMirror.ADCRESULT10;          
	adc_v1 += AdcMirror.ADCRESULT11;		

	adc_v2 += AdcMirror.ADCRESULT12;
	adc_v2 += AdcMirror.ADCRESULT13;
	adc_v2 += AdcMirror.ADCRESULT14; //ADC value sum
	
	if( g_int32sen_cnt == 7 ) // gyro value adc
		gyro_v1 = AdcMirror.ADCRESULT15;
	else
		adc_v2 += AdcMirror.ADCRESULT15;

	AdcRegs.ADCTRL2.bit.RST_SEQ1 = ON; //ADC 초기화	
	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1; /* SEQ1 interrupt clear */

	g_sen[ g_int32sen_cnt ].u16result = adc_v1 >> 3;
	g_sen[ g_int32sen_cnt + SEN_NUM ].u16result = adc_v2 >> 3;	 //ADC average value compute

	if( g_sen[ g_int32adc_cnt ].u16result > g_sen[ g_int32adc_cnt ].u16max_value )			g_sen[ g_int32adc_cnt ].u16data = 127;
	else if( g_sen[ g_int32adc_cnt ].u16result < g_sen[ g_int32adc_cnt ].u16min_value )		g_sen[ g_int32adc_cnt ].u16data = 0;
	else //sensor data value compute
	{
		g_sen[ g_int32adc_cnt ].u16data = ( Uint16 )( ( ( float32 )( g_sen[ g_int32adc_cnt ].u16result - g_sen[ g_int32adc_cnt ].u16min_value ) * ( float32 )127 ) 
										/ ( float32 )( g_sen[ g_int32adc_cnt ].u16max_value - g_sen[ g_int32adc_cnt ].u16min_value ) );
	}

	if( g_sen[ g_int32adc_cnt ].u16data > 60 )	g_pos.u16state |= g_sen[ g_int32adc_cnt ].u16active_arr; // current sensor state compute
	else										g_pos.u16state &= g_sen[ g_int32adc_cnt ].u16passive_arr;

	g_int32adc_cnt++;
	if( g_int32adc_cnt > 15 )		g_int32adc_cnt = 0;	
	
	g_int32sen_cnt++;
	if( g_int32sen_cnt >= 8 )
	{
		g_int32sen_cnt = 0;

		if( g_Flag.goal_dest )
			g_gyro.fp32LPF_outdata = ( FASTRUN_GYRO_Kb * ( g_gyro.fp32LPF_indata + ( float32 )gyro_v1 ) ) - ( FASTRUN_GYRO_Ka * g_gyro.fp32LPF_outdata ); // gyro value IIR filtering
		else
			g_gyro.fp32LPF_outdata = ( SEARCH_GYRO_Kb * ( g_gyro.fp32LPF_indata + ( float32 )gyro_v1 ) ) - ( SEARCH_GYRO_Ka * g_gyro.fp32LPF_outdata ); // gyro value IIR filtering
			
		g_gyro.fp32LPF_indata = ( float32 )gyro_v1;

		g_gyro.fp32real_angle = g_gyro.fp32LPF_outdata;

		StopCpuTimer0(); //sensor interrupt stop
		
	}

//	GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;	

}


static void debug_menu( str_point_t *pstr , e_debug_menu mode ) //debug menu func
{
	int32 cnt = 0;
	int32 div_cnt = 0 , div_flag = OFF;

	gyro_t *pgyro = pstr->pgyro;
	pgyro->fp32ag_intergral = 0.0;
	
	LED_OFF;

	while( 1 )
	{
		position_compute();		

		if( mode == SEN_DIV )
		{			
			sen_val_to_div( pstr->psen , div_cnt );		

			if( !div_flag )
			{
				VFDPrintf("%1x%1x%1x%1x%1x%1x%1x%1x" , ( pstr->psen + L4 )->u16div_data , 
													   ( pstr->psen + L5 )->u16div_data , 
													   ( pstr->psen + L6 )->u16div_data , 
													   ( pstr->psen + L7 )->u16div_data , 
													   ( pstr->psen + R7 )->u16div_data , 
													   ( pstr->psen + R6 )->u16div_data , 
													   ( pstr->psen + R5 )->u16div_data , 
													   ( pstr->psen + R4 )->u16div_data );
			}
			else
			{
				VFDPrintf("%1x%1x%1x%1x%1x%1x%1x%1x" , ( pstr->psen + L0 )->u16div_data , 
													   ( pstr->psen + L1 )->u16div_data , 
													   ( pstr->psen + L2 )->u16div_data , 
													   ( pstr->psen + L3 )->u16div_data , 
													   ( pstr->psen + R3 )->u16div_data , 
													   ( pstr->psen + R2 )->u16div_data , 
													   ( pstr->psen + R1 )->u16div_data , 
													   ( pstr->psen + R0 )->u16div_data );			
			}
			
			div_cnt++;
			if( div_cnt > ADC_NUM - 1 )	div_cnt = 0;						
			
		}
		else if( mode == GYRO_ANGLE )
		{
			g_Flag.goal_dest = ON;
			
			if( !div_flag )
				VFDPrintf("%4ld%4ld" , ( int32 )( pgyro->fp32angle ) , ( int32 )( pgyro->fp32ag_intergral ) );	
			else
				VFDPrintf("P:%6ld" , ( int32 )( pstr->ppos->fp32current_pos - CENTER_POSITION) );					
		}
		else
		{
			switch( mode )
			{
				case SEN_VAL :		VFDPrintf("AD%2ld%4d" , cnt , ( pstr->psen + cnt )->u16result);						break;
				case SEN_DATA :		VFDPrintf("AD%2ld%4d" , cnt , ( pstr->psen + cnt )->u16data);						break;
				case SEN_POS :		VFDPrintf("P:%6ld" , ( int32 )( pstr->ppos->fp32current_pos - CENTER_POSITION) );	break;
				case SEN_STATE :	VFDPrintf("-0x%04x-" , pstr->ppos->u16state );										break;
				case GYRO_VAL :		VFDPrintf("GY  %4ld" , ( int32 )( pstr->pgyro->fp32angle ) );						break;

				default :			VFDPrintf(" -NONE- ");																break;
			}
		}

		DELAY_US( 10000 );				

		if( !RIGHT_SW )
		{
			div_flag = ON;
			cnt++;		
			if( cnt > ADC_NUM - 1 )	cnt = 0;
			SWR_BELL;
			SWSU_BELL;
		}
		else if( !LEFT_SW )
		{
			div_flag = OFF;		
			cnt--;
			if( cnt < 0 )	cnt = ADC_NUM - 1;
			SWR_BELL;
			SWSU_BELL;
		}
		else if( !DOWN_SW )
		{	
			pgyro->fp32ag_intergral = 0.0;
			g_Flag.goal_dest = OFF;
			break;
		}
		else;
		
	}

}

static void sen_val_to_div( sen_t *psen , int32 div_cnt ) // sensor value expression from 0~F
{
	if( ( psen + div_cnt )->u16result > ( psen + div_cnt )->u16max_value )		( psen + div_cnt )->u16div_data = 15;
	else if( (psen + div_cnt)->u16result< ( psen + div_cnt )->u16min_value )	( psen + div_cnt )->u16div_data = 0;
	else
	{
		( psen + div_cnt )->u16div_data = ( Uint16 )( ( ( float32 )( ( psen + div_cnt )->u16result - ( psen + div_cnt )->u16min_value ) * ( float32 )15.0 ) 
												/ ( float32 )( ( psen + div_cnt )->u16max_value - ( psen + div_cnt )->u16min_value ) );
	}	
}


int32 gyro_center_value_search( gyro_t *pgyro )
{
	int32 gyro_cnt = 0;
	float32 gyro_que = 0.0;

	// gyro center value setting
	gyro_cnt = 0;

	while( 1 )
	{
		if( !UP_SW )
		{
			vh_delay();
			return -1;
		}
		else if( !DOWN_SW )
		{
			vh_delay();
			return 0;		
		}
		else;
	
		gyro_que = 0.0;		
	
		while( gyro_cnt < 10 )
		{
			gyro_cnt++;		
			gyro_que += ( pgyro->fp32angle / ( float32 )( 10.0 ) );
		}

		gyro_cnt = 0;
		pgyro->fp32center = gyro_que;

		VFDPrintf("G:  %4ld" , ( int32 )pgyro->fp32center);
		DELAY_US( 10000 );
		
	}
	
}

static void sen_maxmin_search( sen_t *psen ) //sensor max / min value setting
{
	int32 sen_cnt;

	LED_OFF;

	( psen + 0 )->u16max_value = 0;
	( psen + 1 )->u16max_value = 0;
	( psen + 2 )->u16max_value = 0;
	( psen + 3 )->u16max_value = 0;
	( psen + 4 )->u16max_value = 0;
	( psen + 5 )->u16max_value = 0;
	( psen + 6 )->u16max_value = 0;
	( psen + 7 )->u16max_value = 0;
	( psen + 8 )->u16max_value = 0;
	( psen + 9 )->u16max_value = 0;
	( psen + 10 )->u16max_value = 0;
	( psen + 11 )->u16max_value = 0;
	( psen + 12 )->u16max_value = 0;
	( psen + 13 )->u16max_value = 0;
	( psen + 14 )->u16max_value = 0;
	( psen + 15 )->u16max_value = 0;	

	( psen + 0 )->u16min_value = 0;
	( psen + 1 )->u16min_value = 0;
	( psen + 2 )->u16min_value = 0;
	( psen + 3 )->u16min_value = 0;	
	( psen + 4 )->u16min_value = 0;
	( psen + 5 )->u16min_value = 0;
	( psen + 6 )->u16min_value = 0;
	( psen + 7 )->u16min_value = 0;	
	( psen + 8 )->u16min_value = 0;
	( psen + 9 )->u16min_value = 0;
	( psen + 10 )->u16min_value = 0;
	( psen + 11 )->u16min_value = 0;	
	( psen + 12 )->u16min_value = 0;
	( psen + 13 )->u16min_value = 0;
	( psen + 14 )->u16min_value = 0;
	( psen + 15 )->u16min_value = 0;		

	// I.R. sensor max value setting
	sen_cnt = 0;
	VFDPrintf("max   >>");	

	while( DOWN_SW );
	vh_delay();
	while( DOWN_SW )
	{
		if( ( psen + sen_cnt )->u16max_value < ( psen + sen_cnt )->u16result )
			( psen + sen_cnt )->u16max_value = ( psen + sen_cnt )->u16result;

		sen_cnt++;
		if( sen_cnt >= ADC_NUM )	sen_cnt = 0;	
	}

	// I.R. sensor min value setting
	sen_cnt = 0;
	VFDPrintf("min   >>");	
	
	while( DOWN_SW );	
	vh_delay();
	while( DOWN_SW )
	{
		if( ( psen + sen_cnt )->u16min_value < ( psen + sen_cnt )->u16result )
			( psen + sen_cnt )->u16min_value = ( psen + sen_cnt )->u16result;

		sen_cnt++;
		if( sen_cnt >= ADC_NUM )	sen_cnt = 0;	
	}

	//sensor setting value filtering	
	VFDPrintf(" =wait= ");				
	vh_delay();
	
	for( sen_cnt = 0 ; sen_cnt < ADC_NUM ; sen_cnt++ ) 
	{
		if( sen_cnt < 3 || sen_cnt > 12 )
		{
			( psen + sen_cnt )->u16max_value -= ( ( psen + sen_cnt )->u16max_value >> 2 );
			( psen + sen_cnt )->u16min_value += ( ( psen + sen_cnt )->u16min_value >> 2 );			
		}
		else
		{
			( psen + sen_cnt )->u16max_value -= ( ( psen + sen_cnt )->u16max_value >> 2 );
			( psen + sen_cnt )->u16min_value += ( Uint16 )( ( float32 )( ( psen + sen_cnt )->u16min_value ) * 0.35 );
		}
	}
	
	sensor_write_rom(); //sensor setting value save
	VFDPrintf("=finish=");
	
	while( DOWN_SW );
	vh_delay();

#ifdef DEBUG_MODE
	 sensor_printf_func( psen );
#endif

}

void debug_sen_val( str_point_t *pstr ) //sensor reseult value debug
{
	debug_menu( pstr , SEN_VAL );
}

void debug_sen_div( str_point_t *pstr )
{
	debug_menu( pstr , SEN_DIV );
}

void debug_sen_data( str_point_t *pstr ) //sensor data value debug
{
	debug_menu( pstr , SEN_DATA );
}

void debug_gyro_val( str_point_t *pstr ) //gyro value debug
{
	debug_menu( pstr , GYRO_VAL );
}

void debug_gyro_angle( str_point_t *pstr )
{
	debug_menu( pstr , GYRO_ANGLE );
}

void debug_sen_pos( str_point_t *pstr ) //position value debug
{
	debug_menu( pstr , SEN_POS );
}

void debug_sen_state( str_point_t *pstr ) //sensor state value debug
{
	debug_menu( pstr , SEN_STATE );
}

void debug_cps_val( str_point_t *pstr )
{
	debug_menu( pstr , CPS_VAL );
}

void sensor_setting_classic( void ) //setting call function
{
	sen_maxmin_search( g_sen );
}

void sensor_printf_func( sen_t *psen ) //setting value comfirm func
{
	int32 cnt;

	SCIa_Printf("\n\n\n");

	for( cnt = 0 ; cnt < ADC_NUM ; cnt++ )
	{
		SCIa_Printf("[ AD%2ld ]\tMAX : %4d\t\tMIN : %4d\n" , cnt , ( psen + cnt )->u16max_value , ( psen + cnt )->u16min_value );
	}
}

static int32 cross_checking_func( void ) //턴 탈출 후 제자리를 못잡은 상태에서 크로스를 만났을때 튀는 문제 있음
{
	volatile Uint16 state = 0x00;

	if( g_secflag.u16sen_enable & RIGHT_ENABLE )  //오른쪽 턴일때 -> 마크를 오른쪽으로 당김
		state = STATE_CENTER + g_secflag.u16sen_state;
	else if( g_secflag.u16sen_enable & LEFT_ENABLE )  //왼쪽 턴일 때 -> 마크를 왼쪽으로 당김
		state = STATE_CENTER - g_secflag.u16sen_state;
	else
		state = STATE_CENTER;

	if( ( ( g_pos.u16state & state_table[ state - 1 ] ) == state_table[ state - 1 ] ||
	      ( g_pos.u16state & state_table[ state + 1 ] ) == state_table[ state + 1 ] ||
	      ( g_pos.u16state & state_table[ state ] ) == state_table[ state ] ) )
	{
		if( g_Flag.cross_flag == OFF )
		{
			g_Flag.cross_flag = ON;
			g_Flag.cross_shift = ON;
			
			if( !g_Flag.goal_dest )		YELLOW_ON;			
		}
		else if( g_fp32cross_dist > CROSS_DIST_LIMIT )
			g_Flag.line_out = ON;  //트레이서 대리석으로 나갔을 때
		else;
	}
	else if( g_Flag.cross_flag )
	{
		g_int32lineout_cnt = 0;		
		g_Flag.cross_shift = OFF;		

		if( g_fp32cross_dist > ( float32 )( 140.0 ) ) //cross checking distance
		{
			if( !g_Flag.goal_dest )		YELLOW_OFF;
			
			g_rmark.u16turn_flag = OFF;
			g_lmark.u16turn_flag = OFF;

			g_rmark.fp32turn_dis = 0.0;
			g_lmark.fp32turn_dis = 0.0;

			g_fp32cross_dist = 0.0;
			g_Flag.cross_flag = OFF;
		}
	}
	else
	{
		g_int32lineout_cnt = 0;
		g_fp32cross_dist = 0.0;

		g_Flag.cross_shift = OFF;		
	}

	return 1;

}

static void position_enable_setfunc( position_t *ppos , sen_t *psen )
{
	sen_t *p_sen = psen;
	position_t *p_pos = ppos;

	if( p_pos->fp32temp_pos < ( float32 )( ( p_sen + L0 )->int32weight ) )
 	{
 		g_int32pos_cnt = NONE;
		g_secflag.u16sen_enable = ( Uint16 )( LEFT_EIGHT_SHIFT ) + LEFT_ENABLE;	 	//1100 0000 0000 0000
 	}
	else if( p_pos->fp32temp_pos > ( float32 )( ( p_sen + R0 )->int32weight ) )
	{
		g_int32pos_cnt = S_TWELVE;
		g_secflag.u16sen_enable = ( Uint16 )( RIGHT_EIGHT_SHIFT ) + RIGHT_ENABLE;	//0000 0000 0000 0011
	}
	else if( p_pos->fp32temp_pos < ( float32 )( ( p_sen + L1 )->int32weight ) )
	{
 		g_int32pos_cnt = NONE;	
		g_secflag.u16sen_enable = ( Uint16 )( LEFT_SEVEN_SHIFT ) + LEFT_ENABLE;		//1110 0000 0000 0000
	}
	else if( p_pos->fp32temp_pos > ( float32 )( ( p_sen + R1 )->int32weight ) )
	{
 		g_int32pos_cnt = S_TWELVE;	
		g_secflag.u16sen_enable = ( Uint16 )( RIGHT_SEVEN_SHIFT ) + RIGHT_ENABLE;	//0000 0000 0000 0111
	}
	else if( p_pos->fp32temp_pos < ( float32 )( ( p_sen + L2 )->int32weight ) )
	{
 		g_int32pos_cnt = NONE;	
		g_secflag.u16sen_enable = ( Uint16 )( LEFT_SIX_SHIFT ) + LEFT_ENABLE;		//1111 0000 0000 0000
	}
	else if( p_pos->fp32temp_pos > ( float32 )( ( p_sen + R2 )->int32weight ) )
	{
 		g_int32pos_cnt = S_TWELVE;	
		g_secflag.u16sen_enable = ( Uint16 )( RIGHT_SIX_SHIFT ) + RIGHT_ENABLE;		//0000 0000 0000 1111
	}
	else if( p_pos->fp32temp_pos < ( float32 )( ( p_sen + L3 )->int32weight ) )
	{
 		g_int32pos_cnt = ONE;	
		g_secflag.u16sen_enable = ( Uint16 )( LEFT_FIVE_SHIFT ) + LEFT_ENABLE;		//0111 1000 0000 0000
	}
	else if( p_pos->fp32temp_pos > ( float32 )( ( p_sen + R3 )->int32weight ) )
	{
 		g_int32pos_cnt = S_ELEVEN;	
		g_secflag.u16sen_enable = ( Uint16 )( RIGHT_FIVE_SHIFT ) + RIGHT_ENABLE;	//0000 0000 0001 1110
	}
	else if( p_pos->fp32temp_pos < ( float32 )( ( p_sen + L4 )->int32weight ) )
	{
 		g_int32pos_cnt = S_TWO;	
		g_secflag.u16sen_enable = ( Uint16 )( LEFT_FOUR_SHIFT ) + LEFT_ENABLE;		//0011 1100 0000 0000
	}
	else if( p_pos->fp32temp_pos > ( float32 )( ( p_sen + R4 )->int32weight ) )
	{
 		g_int32pos_cnt = S_TEN;	
		g_secflag.u16sen_enable = ( Uint16 )( RIGHT_FOUR_SHIFT ) + RIGHT_ENABLE;	//0000 0000 0011 1100
	}
	else if( p_pos->fp32temp_pos < ( float32 )( ( p_sen + L5 )->int32weight ) )
	{
 		g_int32pos_cnt = S_THREE;	
		g_secflag.u16sen_enable = ( Uint16 )( LEFT_THREE_SHIFT ) + LEFT_ENABLE;		//0001 1110 0000 0000
	}
	else if( p_pos->fp32temp_pos > ( float32 )( ( p_sen + R5 )->int32weight ) )
	{
 		g_int32pos_cnt = S_NINE;	
		g_secflag.u16sen_enable = ( Uint16 )( RIGHT_THREE_SHIFT ) + RIGHT_ENABLE;	//0000 0000 0111 1000
	}
	else if( p_pos->fp32temp_pos < ( float32 )( ( p_sen + L6 )->int32weight ) )
	{
 		g_int32pos_cnt = S_FOUR;	
		g_secflag.u16sen_enable = ( Uint16 )( LEFT_TWO_SHIFT ) + LEFT_ENABLE;		//0000 1111 0000 0000
	}
	else if( p_pos->fp32temp_pos > ( float32 )( ( p_sen + R6 )->int32weight ) )
	{
 		g_int32pos_cnt = S_EIGHT;	
		g_secflag.u16sen_enable = ( Uint16 )( RIGHT_TWO_SHIFT ) + RIGHT_ENABLE;		//0000 0000 1111 0000
	}
	else if( p_pos->fp32temp_pos < ( float32 )( ( p_sen + L7 )->int32weight ) )
	{
 		g_int32pos_cnt = S_FIVE;	
		g_secflag.u16sen_enable = ( Uint16 )( LEFT_ONE_SHIFT ) + LEFT_ENABLE;		//0000 0111 1000 0000
	}
	else if( p_pos->fp32temp_pos > ( float32 )( ( p_sen + R7 )->int32weight ) )
	{
 		g_int32pos_cnt = S_SEVEN;	
		g_secflag.u16sen_enable = ( Uint16 )( RIGHT_ONE_SHIFT ) + RIGHT_ENABLE;		//0000 0001 1110 0000
	}
	else if( ( p_pos->fp32temp_pos >= ( float32 )( ( p_sen + L7 )->int32weight ) ) && 
		     ( p_pos->fp32temp_pos <= ( float32 )( ( p_sen + R7 )->int32weight ) ) )		
	{
 		g_int32pos_cnt = S_SIX;	
		g_secflag.u16sen_enable = ( Uint16 )( NON_SHIFT );							//0000 0011 1100 0000
	}

	g_secflag.u16sen_state = g_secflag.u16sen_enable & ( ~RIGHT_ENABLE ) & ( ~LEFT_ENABLE );  //현재 들어오는 마크 위치 변경 -> enable에 따라서 한칸씩 밀림
	
}

void position_compute( void )
{
	g_pos.u16sum = 0;
	g_pos.fp32sum_of_sec = 0.0;

	g_pos.u16sum += g_sen[ g_int32pos_cnt + 0 ].u16data;
	g_pos.u16sum += g_sen[ g_int32pos_cnt + 1 ].u16data;
	g_pos.u16sum += g_sen[ g_int32pos_cnt + 2 ].u16data;
	g_pos.u16sum += g_sen[ g_int32pos_cnt + 3 ].u16data;

	if( g_pos.u16sum ) //센서에 라인이 걸릴 경우
	{
		cross_checking_func();

		g_pos.fp32sum_of_sec += ( float32 )( g_sen[ g_int32pos_cnt + 0 ].int32weight ) * ( float32 )( g_sen[ g_int32pos_cnt + 0 ].u16data );
		g_pos.fp32sum_of_sec += ( float32 )( g_sen[ g_int32pos_cnt + 1 ].int32weight ) * ( float32 )( g_sen[ g_int32pos_cnt + 1 ].u16data );
		g_pos.fp32sum_of_sec += ( float32 )( g_sen[ g_int32pos_cnt + 2 ].int32weight ) * ( float32 )( g_sen[ g_int32pos_cnt + 2 ].u16data );
		g_pos.fp32sum_of_sec += ( float32 )( g_sen[ g_int32pos_cnt + 3 ].int32weight ) * ( float32 )( g_sen[ g_int32pos_cnt + 3 ].u16data );

		g_pos.fp32temp_pos = g_pos.fp32sum_of_sec / ( float32 )( g_pos.u16sum ); //실제 포지션 계산

		if( g_pos.fp32temp_pos > CENTER_POSITION )			g_pos.fp32temp_pos = CENTER_POSITION;
		else if( g_pos.fp32temp_pos < -CENTER_POSITION )	g_pos.fp32temp_pos = -CENTER_POSITION;
		else;

		g_pos.fp32current_pos = g_pos.fp32temp_pos + g_fp32shift_pos_val + CENTER_POSITION;

		position_enable_setfunc( g_ptr->ppos , g_ptr->psen );		
		
	}		
	else
		g_Flag.line_out = ON;

}


void position_PID_handle( void )
{
//////////////////////////////////////////////////// gyro PID compute ////////////////////////////////////////////////////

	g_gyro.fp32err_sum -= g_gyro.fp32past_angle[ 3 ];
	g_gyro.fp32past_angle[ 3 ] = g_gyro.fp32past_angle[ 2 ];
	g_gyro.fp32past_angle[ 2 ] = g_gyro.fp32past_angle[ 1 ];
	g_gyro.fp32past_angle[ 1 ] = g_gyro.fp32past_angle[ 0 ];	
	g_gyro.fp32past_angle[ 0 ] = g_gyro.fp32real_angle;
	g_gyro.fp32err_sum += g_gyro.fp32past_angle[ 0 ];

	g_gyro.fp32proportion_val = g_gyro.fp32past_angle[ 0 ] * g_gyro.fp32kp;
	g_gyro.fp32integral_val = g_gyro.fp32err_sum * g_gyro.fp32ki;
	g_gyro.fp32differential_val = ( ( g_gyro.fp32past_angle[ 0 ] - g_gyro.fp32past_angle[ 3 ] ) + 3.0 * ( g_gyro.fp32past_angle[ 1 ] - g_gyro.fp32past_angle[ 2 ] ) ) * g_gyro.fp32kd;

	g_gyro.fp32pid_out = g_gyro.fp32proportion_val + g_gyro.fp32integral_val + g_gyro.fp32differential_val; //자이로 PID 연산 
	g_gyro.fp32angle = g_gyro.fp32pid_out;	

//////////////////////////////////////////////////// position PID + IIR compute ////////////////////////////////////////////////////

	g_pos.fp32pos_IIR_puted = g_pos.fp32pos_IIR_puting;

	g_pos.fp32pos_IIR_puting = CENTER_POSITION - g_pos.fp32current_pos;

	g_pos.fp32pos_IIR_output = ( PID_Kb * ( g_pos.fp32pos_IIR_puted + g_pos.fp32pos_IIR_puting ) ) - ( PID_Ka * g_pos.fp32past_pos[ 0 ] );

	g_pos.fp32past_pos[ 3 ] = g_pos.fp32past_pos[ 2 ];
	g_pos.fp32past_pos[ 2 ] = g_pos.fp32past_pos[ 1 ];
	g_pos.fp32past_pos[ 1 ] = g_pos.fp32past_pos[ 0 ];
	g_pos.fp32past_pos[ 0 ] = g_pos.fp32pos_IIR_output;	

	g_pos.fp32proportion_val = g_pos.fp32past_pos[ 0 ] * g_pos.fp32kp;
	g_pos.fp32differential_val = ( ( g_pos.fp32past_pos[ 0 ] - g_pos.fp32past_pos[ 3 ] ) + 3.0 * ( g_pos.fp32past_pos[ 1 ] - g_pos.fp32past_pos[ 2 ] ) ) * g_pos.fp32kd;

	if( g_Flag.straight == ON && ( g_secinfo[ g_int32mark_cnt ].int32dir & STRAIGHT ) )
		g_pos.fp32pid_out = g_pos.fp32proportion_val + g_pos.fp32differential_val - ( ( g_gyro.fp32pid_out - g_gyro.fp32center ) * 0.15 );	//직진 가속시 -> 자이로 보정
	else	
		g_pos.fp32pid_out = g_pos.fp32proportion_val + g_pos.fp32differential_val; //position에 PD제어 적용

	if( g_pos.fp32pid_out > CENTER_POSITION )			g_pos.fp32pid_out = CENTER_POSITION;
	else if( g_pos.fp32pid_out < -CENTER_POSITION )		g_pos.fp32pid_out = -CENTER_POSITION;
	else;

	if( g_pos.fp32pid_out > 0.0 )  //좌회전  //자이로값 4000보다 작음
	{
		g_fp32left_handle = ( g_fp32han_decstep * ( HANDLE_CENTER - g_pos.fp32pid_out ) ) + g_fp32han_decmax;
		g_fp32right_handle = ( g_fp32han_accstep * ( HANDLE_CENTER + g_pos.fp32pid_out ) ) + g_fp32han_accmax;

		if( g_fp32left_handle < ( float32 )0.0 )
		{
			g_fp32left_handle = ( float32 )0.0;
		}
		else if( g_Flag.straight && ( g_secinfo[ g_int32mark_cnt ].int32dir & STRAIGHT ) )  //직진 가속시 -> 핸들 값 막음( 흔들림 방지 )
		{
			if( g_fp32right_handle > MAX_SPEED_HANDLE )		g_fp32right_handle = MAX_SPEED_HANDLE;
			if( g_fp32left_handle < -MAX_SPEED_HANDLE )		g_fp32left_handle = -MAX_SPEED_HANDLE;
		}
		else;
	}
	else	  //우회전  //자이로값 4000보다 큼
	{
		g_fp32left_handle = ( g_fp32han_accstep * ( HANDLE_CENTER - g_pos.fp32pid_out ) ) + g_fp32han_accmax;
		g_fp32right_handle = ( g_fp32han_decstep * ( HANDLE_CENTER + g_pos.fp32pid_out ) ) + g_fp32han_decmax;

		if( g_fp32right_handle < ( float32 )0.0 )
		{
			g_fp32right_handle = ( float32 )0.0;
		}
		else if( g_Flag.straight && ( g_secinfo[ g_int32mark_cnt ].int32dir & STRAIGHT ) ) //직진 가속시 -> 핸들 값 막음( 흔들림 방지 )
		{
			if( g_fp32left_handle > MAX_SPEED_HANDLE )		g_fp32left_handle = MAX_SPEED_HANDLE;
			if( g_fp32right_handle < -MAX_SPEED_HANDLE )	g_fp32right_handle = -MAX_SPEED_HANDLE;
		}
		else;
	}		

}

static void start_end_checking( void )
{
	int32 acc = g_int32end_acc;

	if( !g_Flag.race_start ) //처음 양 쪽 마크 다 들어왔을 경우 -> start
	{
		if( !g_Flag.goal_dest )
		{
			g_secinfo[ 0 ].int32mk_dir = STRAIGHT;  //출발은 무조건 직진.

			g_int32start_dist = ( int32 )( ( R_motor.fp32gone_distance + L_motor.fp32gone_distance ) * 0.5 );  //마크와 마크 사이 거리
			if( g_int32mark_cnt > 0 )	g_int32start_dist = 150;
		}
	
		g_Flag.race_start = ON;
		g_int32time_cnt = 0; //시간 초기화
	}
	else
	{
		if( g_int32mark_cnt < g_int32force_mark )
			return;
	
		g_Flag.move_state = OFF; //주행 중 아님...
		VFDPrintf("=finish=");

		if( g_Flag.goal_dest )	 // 2차주행
		{
			if( g_secinfo[ g_int32total_mark - 1 ].int32acc < 5  )	acc = 6;

			move_end( ( float32 )( g_int32start_dist + g_int32end_dist ) , ( R_motor.fp32cur_vel_avr + L_motor.fp32cur_vel_avr ) * 0.5 , acc ); //일정 거리 진입 후 정지			
			
			R_motor.fp32gone_distance = 0.0; //간 거리 초기화 ( 2차주행시만!!!! )
			L_motor.fp32gone_distance = 0.0;
		} 
		else
			move_end( ( float32 )100.0 , ( R_motor.fp32cur_vel_avr + L_motor.fp32cur_vel_avr ) * 0.5 , acc ); //일정 거리 진입 후 정지

		R_motor.fp32distance_sum = 0.0;
		L_motor.fp32distance_sum = 0.0;

		g_Flag.stop_check = ON; //정지 후 처리 function call 
	}
	
}

static void mark_enable_shift( turnmark_t *pleft , turnmark_t *pright )
{
	if( g_secflag.u16sen_enable & RIGHT_ENABLE )  //오른쪽 턴일때 -> 마크를 오른쪽으로 당김
	{
		pleft->u16mark_enable = LEFT_MARK_CHEK >>  g_secflag.u16sen_state;
		pright->u16mark_enable = RIGHT_MARK_CHEK >>  g_secflag.u16sen_state;	
	}
	else if( g_secflag.u16sen_enable & LEFT_ENABLE )  //왼쪽 턴일 때 -> 마크를 왼쪽으로 당김
	{
		pleft->u16mark_enable = LEFT_MARK_CHEK <<  g_secflag.u16sen_state;
		pright->u16mark_enable = RIGHT_MARK_CHEK <<  g_secflag.u16sen_state;
	}
	else
	{
		pleft->u16mark_enable = LEFT_MARK_CHEK;
		pright->u16mark_enable = RIGHT_MARK_CHEK;	
	}	
}

void mark_checking_func( turnmark_t *p_mark , turnmark_t *p_remark )
{
	turnmark_t *pmark = p_mark;
	turnmark_t *premark = p_remark;

	if( pmark->u16single_flag )  //반대편 마크가 들어오지 않았을 때
	{
		if( pmark->fp32turn_dis > pmark->fp32dist_limit )	  //일정 거리 지난 후...
		{
			if( pmark == g_ptr->plmark)
			{
				LMARK_LED_OFF;
				if( premark->u16single_flag )	return;				
			}
			else if( pmark == g_ptr->prmark  )	RMARK_LED_OFF;			
			else;

			pmark->u16single_flag = OFF;
			pmark->u16turn_flag = OFF;
			pmark->fp32turn_dis = 0.0; //마크 변수 초기화

			if( pmark->u16cross_flag )  //반대편 마크가 값이 들어왔을 경우
			{
				pmark->u16cross_flag = OFF;

				if( pmark == g_ptr->prmark )
				{
					if( g_Flag.cross_flag ) //크로스 인가???
						return;

					if( g_Flag.goal_dest && g_Flag.race_start )
					{
						if( g_int32mark_cnt < ( g_int32total_mark - 10 ) )
							return; //저장된 총 마크값보다 작음에도 end가 들어왔을 경우 return
					}

					start_end_checking(); //크로스가 아닐 경우 -> start or END
				}
			}
			else //반대편 마크가 들어오지 않았을 경우
			{
				if( !g_Flag.move_state ) //END마크를 찍은 후 들어오는 턴마크는 모조리 무시
					return;

				if( !g_Flag.goal_dest )		line_information( pmark ); //턴마크로 간주하고 라인 정보를 저장
				else						runmode_lineinfo( g_ptr->psecinfo , g_ptr->perr );
			}
			
		}
		else if( premark->u16single_flag )	pmark->u16cross_flag = ON; //반대편 마크가 들어왔을 때
		else;

		return;	
		
	}

	mark_enable_shift( g_ptr->plmark , g_ptr->prmark );

	if( pmark->u16mark_enable & g_pos.u16state ) //마크 센서에 값이 들어왔을 때
	{
		if( !pmark->u16turn_flag ) //더 이상 마크를 체크하지 않음
		{
			pmark->fp32dist_limit = pmark->fp32turn_dis + TURN_MARK_STEP;
			pmark->u16turn_flag = ON;
		}
		else //반대편 마크 값이 들어오는지 일정 구간 기다림
		{
			pmark->fp32dist_limit = pmark->fp32turn_dis + TURN_MARK_CHECK_STEP;
			pmark->u16single_flag = ON;

			if( !g_Flag.cross_flag )				
			{
				if( pmark == g_ptr->plmark )		LMARK_LED_ON;
				else if( pmark == g_ptr->prmark )	RMARK_LED_ON;
				else;
			}
		}	
	}
	else //마크 센서에 값이 들어오지 않을 경우
	{
		pmark->fp32turn_dis = 0.0;
		pmark->u16turn_flag = OFF;	
	}

}



