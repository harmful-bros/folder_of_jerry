//###########################################################################
//
// FILE		: sensor.c
//
// TITLE		: micromouse H2 sensor source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.08 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//#define SENSOR_DEBUG


#define LF_SEN_SEQ			0x0000
#define LS_SEN_SEQ			0x1111
#define L45_SEN_SEQ			0x2222

#define RF_SEN_SEQ			0x8888
#define RS_SEN_SEQ			0x9999
#define R45_SEN_SEQ			0xaaaa

#define BATT_VOLT			0x3333
#define GYRO_VOLT			0xbbbb

/* sensor digital IIR filter */
#define SENSOR_F_CUT				( float32 )20.0									//sensor cut frequency 20Hz
#define SENSOR_F_SAMPLE				( float32 )2000.0								//sensor sampling time is 2KHz(500us)
#define SENSOR_W_CUT				tan( M_PI * SENSOR_F_CUT / SENSOR_F_SAMPLE )	//radian 으로 계산 해야 됨.

#define SENSOR_Ka					( float32 )-0.9390625058						//(W_CUT -1) / (W_CUT + 1)
#define SENSOR_Kb					( float32 )0.0304687471							// W_CUT / (W_CUT + 1)

#define SENSOR_F_CUT_DIFF			( float32 )50.0									//(50Hz)
#define	SENSOR_F_SAMPLE_DIFF		( float32 )2000.0								//(2KHz)
#define	SENSOR_W_CUT_DIFF			tan( M_PI * SENSOR_F_CUT_DIFF / SENSOR_F_SAMPLE_DIFF )

#define	SENSOR_Ka_DIFF				( float32 )-0.8540806855						//(W_CUT -1) / (W_CUT + 1)
#define	SENSOR_Kb_DIFF				( float32 )0.0729596573							// W_CUT / (W_CUT + 1)

#define GYRO_F_CUT					( float32 )10.0									//gyro cut frequency 10Hz

#define GYRO_Ka						( float32 )-0.9968633318						//(W_CUT -1) / (W_CUT + 1)
#define GYRO_Kb						( float32 )0.0015683341							// W_CUT / (W_CUT + 1)


/* pid compute */
#define ANGLE_KP					( float32 )0.5
#define ANGLE_KI					( float32 )0.00001
#define ANGLE_KD					( float32 )2.0
#define ANGLE_ADJ_RATIO				( float32 )0.65

#define POS_KP						( float32 )0.6
#define POS_KI						( float32 )0.00005
#define POS_KD						( float32 )0.0
#define POS_KD_MAX					( float32 )45.0

#define CAL_POS_KP_MIN				( float32 )0.35
#define CAL_POS_KP_DIFF				( float32 )0.00045

#define CAL_POS_KD_MAX				( float32 )10.0
#define CAL_POS_KD_DIFF				( float32 )0.0045


#define POS_GAP_MAX					( float32 )110.0

typedef volatile enum sensor_value
{
	LF_SEN = 4 , 
	L45_SEN , 		
	LS_SEN , 	
	RF_SEN , 	
	R45_SEN ,	
	RS_SEN ,  

	SEN_TOTAL = 6,

	SEN_AD_CONVERT = 3 , 
	SEN_SEQ , 

	BATT_SET = 2500
		
}sen_val_e;

typedef volatile enum edge_state_enum
{
	EDGE_OFF , 
	EDGE_FALL , 
	EDGE_UP , 
	EDGE_ON
	
}edge_state_e;


volatile Uint16 sen_shoot_arr[ SEN_TOTAL ] = 
{
	LF_SEN , RS_SEN , L45_SEN , RF_SEN , LS_SEN , R45_SEN
};

volatile Uint16 sen_adc_seq[ SEN_TOTAL ] = 
{
	LF_SEN_SEQ , RS_SEN_SEQ , L45_SEN_SEQ , RF_SEN_SEQ , LS_SEN_SEQ , R45_SEN_SEQ
};

volatile int32 a_int32seq_cnt = 0;


static void _front_sensor_value_to_dist_table( volatile int32 count , volatile float32 value );
static void _edge_check_func( edge_check_t *p_edge , sen_t *p_sen );
static void _diag_edge_check_func( edge_check_t *p_edge , sen_t *p_sen );


//#pragma CODE_SECTION(sensor_timer_ISR, "ramfuncs");
interrupt void sensor_timer_ISR( void ) //sensor val interrupt
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	// Acknowledge this interrupt to receive more interrupts from group 1

	EALLOW;
	GpioDataRegs.GPASET.all = ( ON_L << sen_shoot_arr[ g_int32sen_cnt ] );  //sensor shoot!!
	EDIS;

 	AdcRegs.ADCCHSELSEQ1.all = sen_adc_seq[ g_int32sen_cnt ];
	AdcRegs.ADCCHSELSEQ2.all = sen_adc_seq[ g_int32sen_cnt ];
	AdcRegs.ADCCHSELSEQ3.all = sen_adc_seq[ g_int32sen_cnt ];
	AdcRegs.ADCCHSELSEQ4.all = sen_adc_seq[ g_int32sen_cnt ];	

	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1; // ADC interrupt start
}

#pragma CODE_SECTION(adc_external_ISR, "ramfuncs"); 
interrupt void adc_external_ISR( void ) //sensor ADC interrupt
{
	static Uint32 adc_value = 0;
	volatile Uint16 *pselect = NULL;
	volatile float32 sen_value = 0.0;

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // Acknowledge this interrupt to receive more interrupts from group 1

	EALLOW;	
	GpioDataRegs.GPACLEAR.all = ( ON_L << sen_shoot_arr[ g_int32sen_cnt ] );  //sensor off.
	EDIS;

	adc_value += AdcMirror.ADCRESULT0;
	adc_value += AdcMirror.ADCRESULT1;
	adc_value += AdcMirror.ADCRESULT2;
	adc_value += AdcMirror.ADCRESULT3;
	adc_value += AdcMirror.ADCRESULT4;
	adc_value += AdcMirror.ADCRESULT5;
	adc_value += AdcMirror.ADCRESULT6;
	adc_value += AdcMirror.ADCRESULT7;
	adc_value += AdcMirror.ADCRESULT8;
	adc_value += AdcMirror.ADCRESULT9;
	adc_value += AdcMirror.ADCRESULT10;
	adc_value += AdcMirror.ADCRESULT11;
	adc_value += AdcMirror.ADCRESULT12;
	adc_value += AdcMirror.ADCRESULT13;
	adc_value += AdcMirror.ADCRESULT14;

	if( a_int32seq_cnt == SEN_AD_CONVERT )
	{
		pselect = ( g_int32sen_cnt == 0 ) ? &g_u16batt_volt : &g_gyro.u16value;
		*pselect = AdcMirror.ADCRESULT15;
	}
	else	
		adc_value += AdcMirror.ADCRESULT15; 

	AdcRegs.ADCTRL2.bit.RST_SEQ1 = ON; 	// ADC 초기화	
	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1; // SEQ1 interrupt clear

	a_int32seq_cnt++;
	if( a_int32seq_cnt >= SEN_SEQ )
	{
		g_sen[ g_int32sen_cnt ].u16value = adc_value >> 7;  //sequence 16회 & adc interrupt 4회 따라서 64번 sampling( >> 6 ) 

		adc_value = 0;		
		a_int32seq_cnt = 0;

		//sensor value IIR filter
		g_sen[ g_int32sen_cnt ].fp32LPF_yetoutdata = g_sen[ g_int32sen_cnt ].fp32LPF_outdata;
		g_sen[ g_int32sen_cnt ].fp32LPF_outdata = ( SENSOR_Kb * ( g_sen[ g_int32sen_cnt ].fp32LPF_indata + ( float32 )g_sen[ g_int32sen_cnt ].u16value ) ) - ( SENSOR_Ka * g_sen[ g_int32sen_cnt ].fp32LPF_outdata );
		g_sen[ g_int32sen_cnt ].fp32LPF_indata = ( float32 )g_sen[ g_int32sen_cnt ].u16value;		

		sen_value = g_sen[ g_int32sen_cnt ].fp32LPF_outdata;

		//sensor differential value IIR filter
		g_sen[ g_int32sen_cnt ].fp32LPF_diff_indata = g_sen[ g_int32sen_cnt ].fp32LPF_outdata - g_sen[ g_int32sen_cnt ].fp32LPF_yetoutdata;
		g_sen[ g_int32sen_cnt ].fp32LPF_diff_outdata = ( SENSOR_Kb_DIFF * ( g_sen[ g_int32sen_cnt ].fp32LPF_diff_indata + g_sen[ g_int32sen_cnt ].fp32LPF_diff_yetindata ) ) - ( SENSOR_Ka_DIFF * g_sen[ g_int32sen_cnt ].fp32LPF_diff_outdata );
		g_sen[ g_int32sen_cnt ].fp32LPF_diff_yetindata = g_sen[ g_int32sen_cnt ].fp32LPF_diff_indata;

		//gyro value IIR filter
		g_gyro.fp32LPF_outdata = ( GYRO_Kb * ( g_gyro.fp32LPF_indata + ( float32 )( g_gyro.u16value ) ) ) - ( GYRO_Ka * g_gyro.fp32LPF_outdata );		
		g_gyro.fp32LPF_indata = ( float32 )g_gyro.u16value;

		//position compute.
		if( g_int32sen_cnt == LFS || g_int32sen_cnt == RFS )
			_front_sensor_value_to_dist_table( g_int32sen_cnt , sen_value );
		else
		{
			g_sen[ g_int32sen_cnt ].fp32yet_position = g_sen[ g_int32sen_cnt ].fp32position;

			g_sen[ g_int32sen_cnt ].fp32position = ( sen_value >= g_sen[ g_int32sen_cnt ].fp32mid_val ) ? 
												   ( g_sen[ g_int32sen_cnt ].fp32high_coefficient * sqrt( sen_value - g_sen[ g_int32sen_cnt ].fp32mid_val ) ) + ( float32 )256.0 :
												   ( g_sen[ g_int32sen_cnt ].fp32low_coefficient * sqrt( sen_value - g_sen[ g_int32sen_cnt ].fp32min_val ) ) + ( float32 )512.0;

			if( g_sen[ g_int32sen_cnt ].fp32position < ( float32 )0.0 )												   
				g_sen[ g_int32sen_cnt ].fp32position = ( float32 )0.0;

			g_sen[ g_int32sen_cnt ].fp32pos_diff = g_sen[ g_int32sen_cnt ].fp32position - g_sen[ g_int32sen_cnt ].fp32yet_position;
		}

		g_int32sen_cnt++;
		if( g_int32sen_cnt >= SEN_TOTAL )
		{	
			g_int32sen_cnt = 0;
			StopCpuTimer0();  //sensor interrupt stop!!
		}			
		
	}
	else
	{
		if( a_int32seq_cnt == SEN_AD_CONVERT )
			AdcRegs.ADCCHSELSEQ4.bit.CONV15 = ( g_int32sen_cnt == 0 ) ? BATT_VOLT : GYRO_VOLT;
	
		AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1; // ADC interrupt start		
	}
	
}

void sensor_vari_init( void )
{
	a_int32seq_cnt = 0;

	memset( ( void * )&g_sen[ LFS ] , 0x00 , sizeof( sen_t ) );
	memset( ( void * )&g_sen[ LSS ] , 0x00 , sizeof( sen_t ) );
	memset( ( void * )&g_sen[ LDS ] , 0x00 , sizeof( sen_t ) );
	memset( ( void * )&g_sen[ RFS ] , 0x00 , sizeof( sen_t ) );
	memset( ( void * )&g_sen[ RSS ] , 0x00 , sizeof( sen_t ) );
	memset( ( void * )&g_sen[ RDS ] , 0x00 , sizeof( sen_t ) );	

	memset( ( void * )&g_gyro , 0x00 , sizeof( gyro_t ) );
	memset( ( void * )&g_pos , 0x00 , sizeof( pos_vari_t ) );

	g_gyro.fp32ref_val = ( float32 )2000.0;

	g_plfs = &g_sen[ LFS ]; 
	g_plss = &g_sen[ LSS ];
	g_pl45s = &g_sen[ LDS ];

	g_prfs = &g_sen[ RFS ];
	g_prss = &g_sen[ RSS ];
	g_pr45s = &g_sen[ RDS ];

	g_u16batt_volt = 0;

	memset( ( void * )g_fp32rfs_section , 0x00 , sizeof( g_fp32rfs_section ) );
	memset( ( void * )g_fp32lfs_section , 0x00 , sizeof( g_fp32lfs_section ) );	
	memset( ( void * )g_fp32rfs_sec_diff , 0x00 , sizeof( g_fp32rfs_sec_diff ) );
	memset( ( void * )g_fp32lfs_sec_diff , 0x00 , sizeof( g_fp32lfs_sec_diff ) );	
	
}

void edge_vari_init( void )
{
	g_int32tick = 0;
	g_int32edge_diff_cnt = 0;

	memset( ( void * )&g_rss_edge , 0x00 , sizeof( edge_check_t ) );
	memset( ( void * )&g_lss_edge , 0x00 , sizeof( edge_check_t ) );
	memset( ( void * )&g_rds_edge , 0x00 , sizeof( edge_check_t ) );
	memset( ( void * )&g_lds_edge , 0x00 , sizeof( edge_check_t ) );
}

void batt_volt_comform_func( sw_t *psw )
{
	//저항 비율은 2 : 1로 주고 1에 해당하는 값을 ADC로 넣는다.
	//8.4v -> 2.98v
	//7.2v -> 2.58v
	//7.2v 이하 low battery 로 간주한다!!
	
	static int flag = 0;

	if( flag == 1 )
		return;

	if( g_u16batt_volt < BATT_SET )
	{
		flag = 1;
	
		vfdprintf("lobt");
		while( DOWN_SW );

		psw->int32vfd_chatt_col = -1;
		h2_delay();
	}	
	
}

void sensor_value_view( void )
{
	sw_t sw;
	sen_t *psen[ SEN_TOTAL ];
	const char *psen_str[ SEN_TOTAL ] = { "L_fr" , "L_sd" , "L_45" , "R_45" , "R_sd" , "R_fr" };
		
	memset( ( void * )&sw , 0x00 , sizeof( sw_t ) );
	vfdprintf( ( char * )psen_str[ 0 ] );

	psen[ 0 ] = g_plfs;
	psen[ 1 ] = g_plss;
	psen[ 2 ] = g_pl45s;
	psen[ 3 ] = g_pr45s;
	psen[ 4 ] = g_prss;
	psen[ 5 ] = g_prfs;	

	while( TRUE )
	{
		if( !UP_SW && sw.u16up == OFF ) 
		{
			sw.u16up = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( !RIGHT_SW && sw.u16right == OFF )
		{
			R_RED_ON;
		
			sw.u16right = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( !LEFT_SW && sw.u16left == OFF )
		{
			L_RED_ON;
		
			sw.u16left = ON;
			g_int32menu_cnt = ZERO;
		}		
		else if( sw.u16long_rkey == OFF && sw.u16right == ON && g_int32menu_cnt > LONG_KEY_CAHTTERING )
		{
			h2_delay();
			break;
		}
		else if( UP_SW && RIGHT_SW && LEFT_SW )
		{
			if( sw.u16up == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				sw.u16up = OFF;

				while( DOWN_SW )
				{
					vfdprintf("%04u" ,  ( Uint16 )psen[ sw.int32col ]->fp32LPF_outdata );					
					DELAY_US( 100000 );
				}

				vfdprintf("esc!");
				h2_delay();
			}
			else if( sw.u16right == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				SWSU_BELL;
				sw.u16right = OFF;

				sw.int32col++;
				if( sw.int32col >= SEN_TOTAL )	sw.int32col = ZERO;
			}
			else if( sw.u16left == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				SWSU_BELL;
				sw.u16left = OFF;

				sw.int32col--;
				if( sw.int32col < ZERO )	sw.int32col = SEN_TOTAL - 1;
			}			
			else
			{
				LED_OFF;
				sw.u16up = sw.u16right = sw.u16left = OFF;
			}		
			
		}
		else;

		if( sw.int32vfd_chatt_col != sw.int32col )
		{
			vfdprintf( ( char * )psen_str[ sw.int32col ] );
			sw.int32vfd_chatt_col = sw.int32col;
		}
		
	}	
	
}

void gyro_value_view( void )
{
	sw_t sw;
	memset( ( void * )&sw , 0x00 , sizeof( sw_t ) );

	while( TRUE )
	{
		if( !RIGHT_SW && sw.u16right == OFF )
		{
			GREEN_ON;
			YELLOW_ON;
		
			sw.u16right = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( sw.u16long_rkey == OFF && sw.u16right == ON && g_int32menu_cnt > LONG_KEY_CAHTTERING )
		{
			h2_delay();
			break;
		}
		else if( RIGHT_SW )
		{
			LED_OFF;
			sw.u16right = OFF;
		}
		else;
		
		vfdprintf("%4u" , ( Uint16 )g_gyro.fp32LPF_outdata );
		DELAY_US( 100000 );		
		
	}		
	
}

void real_position_value_view( void )
{
	sw_t sw;
	memset( ( void * )&sw , 0x00 , sizeof( sw_t ) );

	g_flag.pos_compen = ON;

	while( TRUE )
	{
		if( !RIGHT_SW && sw.u16right == OFF )
		{
			GREEN_ON;
			YELLOW_ON;
		
			sw.u16right = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( sw.u16long_rkey == OFF && sw.u16right == ON && g_int32menu_cnt > LONG_KEY_CAHTTERING )
		{
			h2_delay();
			g_flag.pos_compen = OFF;
			
			break;
		}
		else if( RIGHT_SW )
		{
			LED_OFF;
			sw.u16right = OFF;
		}
		else;
		
		vfdprintf("%4.0lf" , g_pos.fp32value );		
		DELAY_US( 100000 );		
		
	}		
	
}


void sensor_position_view( void )
{
	sw_t sw;
	sen_t *psen[ SEN_TOTAL ];
	const char *psen_str[ SEN_TOTAL ] = { "L_fr" , "L_sd" , "L_45" , "R_45" , "R_sd" , "R_fr" };
		
	memset( ( void * )&sw , 0x00 , sizeof( sw_t ) );
	vfdprintf( ( char * )psen_str[ 0 ] );

	psen[ 0 ] = g_plfs;
	psen[ 1 ] = g_plss;
	psen[ 2 ] = g_pl45s;
	psen[ 3 ] = g_pr45s;
	psen[ 4 ] = g_prss;
	psen[ 5 ] = g_prfs;	

	while( TRUE )
	{
		if( !UP_SW && sw.u16up == OFF ) 
		{
			sw.u16up = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( !RIGHT_SW && sw.u16right == OFF )
		{
			R_RED_ON;
		
			sw.u16right = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( !LEFT_SW && sw.u16left == OFF )
		{
			L_RED_ON;
		
			sw.u16left = ON;
			g_int32menu_cnt = ZERO;
		}		
		else if( sw.u16long_rkey == OFF && sw.u16right == ON && g_int32menu_cnt > LONG_KEY_CAHTTERING )
		{
			h2_delay();
			break;
		}
		else if( UP_SW && RIGHT_SW && LEFT_SW )
		{
			if( sw.u16up == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				sw.u16up = OFF;

				while( DOWN_SW )
				{
					vfdprintf("%04u" ,  ( Uint16 )psen[ sw.int32col ]->fp32position );					
					DELAY_US( 100000 );
				}

				vfdprintf("esc!");
				h2_delay();
			}
			else if( sw.u16right == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				SWSU_BELL;
				sw.u16right = OFF;

				sw.int32col++;
				if( sw.int32col >= SEN_TOTAL )	sw.int32col = ZERO;
			}
			else if( sw.u16left == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				SWSU_BELL;
				sw.u16left = OFF;

				sw.int32col--;
				if( sw.int32col < ZERO )	sw.int32col = SEN_TOTAL - 1;
			}			
			else
			{
				LED_OFF;
				sw.u16up = sw.u16right = sw.u16left = OFF;
			}		
			
		}
		else;

		if( sw.int32vfd_chatt_col != sw.int32col )
		{
			vfdprintf( ( char * )psen_str[ sw.int32col ] );
			sw.int32vfd_chatt_col = sw.int32col;
		}
		
	}
	
}


void front_sensor_setting( void )
{
	int32 i;

	int32 sample_val = 0;
	int32 yet_sample_val = -1;

	double dist = 0.0;

	LED_OFF;
	vfdprintf("back");
	
	motor_vari_init();

	g_flag.start = ON;
	move_end( ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , 1 );
	
	while( DOWN_SW );
	h2_delay();
	
	move_end( -( float32 )280.0 , -( float32 )80.0 , -( float32 )280.0 , -( float32 )80.0 , 3 );
	while( !( g_flag.move_state == STOP ) )
	{
		dist = fabs( ( double )( ( g_rmotor.fp32distance_sum + g_lmotor.fp32distance_sum ) * 0.5 ) );
	
		if( dist < ( double )251.0 )  //250 부터 25구간 광량 값 저장.
		{
			sample_val = ( int32 )( dist / ( double )10.0 );
			if( sample_val != yet_sample_val )
			{
				g_fp32rfs_section[ sample_val ] = g_prfs->fp32LPF_outdata; //구간마다의 전방 센서 값을 저장.
				g_fp32lfs_section[ sample_val ] = g_plfs->fp32LPF_outdata;

				yet_sample_val = sample_val;				
			}			
		}	
	}

	for( i = 0 ; i < SENSOR_SECTION - 1 ; i++ )
	{
		g_fp32rfs_sec_diff[ i ] = ( float32 )10.0 / ( g_fp32rfs_section[ i ] - g_fp32rfs_section[ i + 1 ] );
		g_fp32lfs_sec_diff[ i ] = ( float32 )10.0 / ( g_fp32lfs_section[ i ] - g_fp32lfs_section[ i + 1 ] );
	}

#ifdef SENSOR_DEBUG
	for( i = 0 ; i < SENSOR_SECTION ; i++ )
	{
		SCIa_Printf("[ %3.0lf ] %10lf %10lf " , ( float32 )i , g_fp32rfs_section[ i ] , g_fp32lfs_section[ i ] );
		
		if( i != SENSOR_SECTION - 1 )
			SCIa_Printf("%10lf %10lf\n" , g_fp32rfs_sec_diff[ i ] , g_fp32lfs_sec_diff[ i ] );
		else
			SCIa_Printf("\n\n");
	}
#endif	

	front_sensor_value_write_rom();

	vfdprintf("done");
	g_flag.start = OFF;

	while( DOWN_SW );
	h2_delay();
	
}

void side_and_45diag_sensor_setting( void )
{
	int32 i;
	sen_t *psen[ SIDE_SENSOR_NUM ];

	psen[ 0 ] = g_plss;
	psen[ 1 ] = g_pl45s;
	psen[ 2 ] = g_pr45s;
	psen[ 3 ] = g_prss;

	LED_OFF;
	motor_vari_init();

	g_flag.start = ON;
	move_end( ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , 1 );

	vfdprintf("lmax");
	while( DOWN_SW );
	h2_delay();

	psen[ 0 ]->fp32max_val = psen[ 0 ]->fp32LPF_outdata; //left max value.
	psen[ 1 ]->fp32max_val = psen[ 1 ]->fp32LPF_outdata;

	psen[ 2 ]->fp32min_val = psen[ 2 ]->fp32LPF_outdata; //right min value
	psen[ 3 ]->fp32min_val = psen[ 3 ]->fp32LPF_outdata;	
	

	vfdprintf("rmax");
	while( DOWN_SW );
	h2_delay();

	psen[ 0 ]->fp32min_val = psen[ 0 ]->fp32LPF_outdata; //left min value.
	psen[ 1 ]->fp32min_val = psen[ 1 ]->fp32LPF_outdata;

	psen[ 2 ]->fp32max_val = psen[ 2 ]->fp32LPF_outdata; //right max value
	psen[ 3 ]->fp32max_val = psen[ 3 ]->fp32LPF_outdata;		

	vfdprintf("wall");	
	while( DOWN_SW );
	h2_delay();

	move_end( ( float32 )25.0 , ( float32 )40.0 , ( float32 )25.0 , ( float32 )40.0 , 1 );
	while( !( g_flag.move_state == STOP ) );

	vfdprintf("turn");
	h2_delay();

	move_end( HALF_BTTN_DIST , ( float32 )40.0 , -HALF_BTTN_DIST , -( float32 )40.0 , 1 );
	while( !( g_flag.move_state == STOP ) );	
	
	vfdprintf("ctr!");
	while( DOWN_SW );
	h2_delay();	
	
	psen[ 0 ]->fp32mid_val = psen[ 0 ]->fp32LPF_outdata; //left middle value.
	psen[ 1 ]->fp32mid_val = psen[ 1 ]->fp32LPF_outdata;

	psen[ 2 ]->fp32mid_val = psen[ 2 ]->fp32LPF_outdata; //right middle value
	psen[ 3 ]->fp32mid_val = psen[ 3 ]->fp32LPF_outdata;

	for( i = 0 ; i < SIDE_SENSOR_NUM ; i++ )
	{
		psen[ i ]->fp32high_coefficient = -( float32 )1.0 * ( CENTER_POSITION / sqrt( psen[ i ]->fp32max_val - psen[ i ]->fp32mid_val ) );
		psen[ i ]->fp32low_coefficient = -( float32 )1.0 * ( CENTER_POSITION / sqrt( psen[ i ]->fp32mid_val - psen[ i ]->fp32min_val ) );
	
#ifdef SENSOR_DEBUG
		SCIa_Printf("max : %10lf min : %10lf mid : %10lf high : %10lf low : %10lf\n" , 
			psen[ i ]->fp32max_val , 
			psen[ i ]->fp32min_val , 
			psen[ i ]->fp32mid_val , 
			psen[ i ]->fp32high_coefficient , 
			psen[ i ]->fp32low_coefficient );
#endif
	}

	side_and_diag_sensor_value_write_rom();

	vfdprintf("done");
	g_flag.start = OFF;

	while( DOWN_SW );
	h2_delay();	

}

static void _front_sensor_value_to_dist_table( volatile int32 count , volatile float32 value ) //광량 대 거리 테이블.
{
	volatile int32 cnt = count;
	volatile float32 val = value;

	volatile float32 *psec[] = { g_fp32lfs_section , NULL , NULL , g_fp32rfs_section };
	volatile float32 *pdiff[] = { g_fp32lfs_sec_diff , NULL , NULL , g_fp32rfs_sec_diff };

	volatile int32 idx = 0;

	if( val >= psec[ cnt ][ 13 ] )
	{
		if( val >= psec[ cnt ][ 6 ] )
		{
			if( val >= psec[ cnt ][ 3 ] )
				idx = ( val >= psec[ cnt ][ 1 ] ) ? ( ( ( val ) >= psec[ cnt ][ 0 ] ) ? -1 : 0 ) : ( ( val >= psec[ cnt ][ 2 ] ) ? 1 : 2 );
			else
				idx = ( val >= psec[ cnt ][ 5 ] ) ? ( ( val >= psec[ cnt ][ 4 ] ) ? 3 : 4 ) : ( 5 );
		}
		else
		{
			if( val >= psec[ cnt ][ 10 ] )
				idx = ( val >= psec[ cnt ][ 8 ] ) ? ( ( val >= psec[ cnt ][ 7 ] ) ? 6 : 7 ) : ( ( val >= psec[ cnt ][ 9 ] ) ? 8 : 9 );
			else
				idx = ( val >= psec[ cnt ][ 12 ] ) ? ( ( val >= psec[ cnt ][ 11 ] ) ? 10 : 11 ) : ( 12 );
		}
	}
	else
	{
		if( val >= psec[ cnt ][ 19 ] )
		{
			if( val >= psec[ cnt ][ 16 ] )
				idx = ( val >= psec[ cnt ][ 15 ] ) ? ( ( val >= psec[ cnt ][ 14 ] ) ? 13 : 14 ) : ( 15 );
			else
				idx = ( val >= psec[ cnt ][ 18 ] ) ? ( ( val >= psec[ cnt ][ 17 ] ) ? 16 : 17 ) : ( 18 );
		}
		else
		{
			if( val >= psec[ cnt ][ 22 ] )
				idx = ( val >= psec[ cnt ][ 21 ] ) ? ( ( val >= psec[ cnt ][ 20 ] ) ? 19 : 20 ) : ( 21 );			
			else
				idx = ( val >= psec[ cnt ][ 24 ] ) ? ( ( val >= psec[ cnt ][ 23 ] ) ? 22 : 23 ) : ( ( val >= psec[ cnt ][ 25 ] ) ? 24 : 0xff );
		}	
	}

	if( idx == -1 )			g_sen[ cnt ].fp32position = ( float32 )0.0;
	else if( idx == 0xff )	g_sen[ cnt ].fp32position = ( float32 )250.0;
	else					g_sen[ cnt ].fp32position = ( float32 )( idx * 10 ) + ( ( psec[ cnt ][ idx ] - val ) * pdiff[ cnt ][ idx ] );	

}

int32 init_gyro_reference_value_search( gyro_t *p_gyro ) //자이로 센터값 찾기.
{
	Uint32 buf = 0;
	int32 i , ret = 0;	
	gyro_t *pgyro = p_gyro;

	sw_t sw;
	memset( ( void * )&sw , 0x00 , sizeof( sw_t ) );

	while( TRUE )
	{
		if( !UP_SW && sw.u16up == OFF )
		{
			YELLOW_ON;
		
			sw.u16up = ON;
			g_int32menu_cnt = ZERO;		
		}	
		else if( !RIGHT_SW && sw.u16right == OFF )
		{
			GREEN_ON;
			break;
		}
		else if( sw.u16long_rkey == OFF && sw.u16up == ON && g_int32menu_cnt > KEY_CHATTERING )
		{
			ret = -1;
			h2_delay();

			goto escape;
		}		
		else if( UP_SW && RIGHT_SW )
		{
			LED_OFF;
			sw.u16up = sw.u16right = OFF;
		}
		else;
		
		vfdprintf("%4.0lf" , pgyro->fp32LPF_outdata );
		DELAY_US( 100000 );		
		
	}	

	for( i = 0 ; i < 16 ; )
	{
		if( g_int32pid_ISR_cnt ) //interrupt 동기화.
		{	
			buf += ( Uint32 )( pgyro->fp32LPF_outdata );

			i++;
			g_int32pid_ISR_cnt = 0;
		}
	}

	pgyro->fp32ref_val = ( float32 )( buf >> 4 ); //현재 상태에서 16번 값을 받아 평균냄.

	LED_OFF;
	vfdprintf("GO!!");
	h2_delay();

escape :
	return ret;
	
}


void position_pid_compute_func( void )
{
	float32 cpn_ratio = 0.0;

	volatile float32 pos_gap;

	volatile float32 cal_pos_kp = 0.0;
	volatile float32 cal_pos_kd = 0.0;

	wall_info_t wall;
	memset( ( void * )&wall , 0x00 , sizeof( wall_info_t ) );

	//edge check!!
	_edge_check_func( &g_rss_edge , g_prss );
	_edge_check_func( &g_lss_edge , g_plss );	

	//diag edge check!!
	_diag_edge_check_func( &g_rds_edge , g_pr45s );
	_diag_edge_check_func( &g_lds_edge , g_pl45s );	
	
	 //오른쪽 벽 체크!!
	if( ( g_prss->fp32pos_diff < ( float32 )0.4 ) && ( g_prss->fp32position < ( float32 )400.0 ) && ( g_pr45s->fp32LPF_outdata > g_pr45s->fp32min_val ) )
	{
		wall.right = ON;
		g_int32edge_diff_cnt = 0;
	}

	if( g_prss->fp32position > ( float32 )500.0 )
		wall.right = OFF;

	if( g_pr45s->fp32position > ( float32 )500.0 )
		wall.right = OFF;

	 //왼쪽 벽 체크!!
	if( ( g_plss->fp32pos_diff < ( float32 )0.4 ) && ( g_plss->fp32position < ( float32 )400.0 ) && ( g_pl45s->fp32LPF_outdata > g_pl45s->fp32min_val ) )
	{
		wall.left = ON;
		g_int32edge_diff_cnt = 0;
	}

	if( g_plss->fp32position > ( float32 )500.0 )
		wall.left = OFF;

	if( g_pl45s->fp32position > ( float32 )500.0 )
		wall.left = OFF;

	g_fp32left_pos = CENTER_POSITION - g_plss->fp32position;
	g_fp32right_pos = g_prss->fp32position - CENTER_POSITION;

	if( g_flag.back_turn == ON ) //백턴 시 전방 보정.
	{
		g_pos.fp32value = ( g_plfs->fp32position - g_prfs->fp32position ) * ( float32 )2.4;	
	}
	else if( g_flag.diff_adj_in == ON && g_rss_edge.u16on && g_lss_edge.u16on ) //가지벽 보정.
	{
		YELLOW_ON;
	
		g_flag.diff_adj = ON;

		g_pos.fp32value = ( float32 )( g_lss_edge.int32check_tick - g_rss_edge.int32check_tick ) * ( float32 )32.0;

		if( g_pos.fp32value > ADJ_DIFF_MAX ) 		g_pos.fp32value = ADJ_DIFF_MAX;
		else if( g_pos.fp32value < -ADJ_DIFF_MAX )	g_pos.fp32value = -ADJ_DIFF_MAX;
		else;		

		g_int32edge_diff_cnt = 0;				
	}
	else if( g_flag.diag_run == ON ) //대각 보정.
	{
		if( g_plfs->fp32position < ( float32 )250.0 && g_plfs->fp32LPF_diff_outdata > ( float32 )0.0 ) //edge를 봤다가 벗어나는 시점.
		{
			g_fp32left_pos = ( float32 )250.0 - g_plfs->fp32position;

			if( g_plfs->fp32position < ( float32 )50.0 )		g_fp32left_pos *= ( float32 )1.45;
			else if( g_plfs->fp32position < (float32 )100.0 )	g_fp32left_pos *= ( float32 )1.5;
			else if( g_plfs->fp32position < (float32 )200.0 )	g_fp32left_pos *= ( float32 )1.8;
			else												g_fp32left_pos *= ( float32 )1.4;
		}
		else
			g_fp32left_pos = ( float32 )250.0;

		if( g_prfs->fp32position < ( float32 )250.0 && g_prfs->fp32LPF_diff_outdata > ( float32 )0.0 ) //edge를 봤다가 벗어나는 시점.
		{
			g_fp32right_pos = g_prfs->fp32position - ( float32 )250.0;

			if( g_prfs->fp32position < ( float32 )50.0 )		g_fp32right_pos *= ( float32 )1.45;
			else if( g_prfs->fp32position < (float32 )100.0 )	g_fp32right_pos *= ( float32 )1.5;
			else if( g_prfs->fp32position < (float32 )200.0 )	g_fp32right_pos *= ( float32 )1.8;
			else												g_fp32right_pos *= ( float32 )1.4;
		}
		else
			g_fp32right_pos = ( float32 )250.0;	

		//대각 직진 가속 보정 비와 대각 탈출 및 대각 진입 보정의 비율은 다르다.
		//대각 탈출 및 대각 진입 시에는 각 방향의 전방센서로만 보정한다.
		if( ( g_fp32left_pos != ( float32 )250.0 ) && ( g_fp32right_pos != ( float32 )250.0 ) &&
			( g_flag.diag_out_ledge == OFF ) && ( g_flag.diag_out_redge == OFF ) )
		{
			cpn_ratio = ( g_flag.diag_out == ON ) ? ( float32 )0.64 : ( float32 )0.86;
			g_pos.fp32value = ( g_fp32left_pos + g_fp32right_pos ) * cpn_ratio;
		}
		else if( ( g_fp32left_pos != ( float32 )250.0 ) && 
				 ( ( g_flag.diag_out_ledge == OFF && g_flag.diag_out_redge == OFF ) || ( g_flag.diag_out_ledge == ON && g_flag.diag_out_redge == OFF ) ) )
		{
			cpn_ratio = ( g_flag.diag_out == ON ) ? ( float32 )0.75 : ( float32 )1.26;
			g_pos.fp32value = g_fp32left_pos * cpn_ratio;			
		}
		else if( ( g_fp32right_pos != ( float32 )250.0 ) && 
				 ( ( g_flag.diag_out_ledge == OFF && g_flag.diag_out_redge == OFF ) || ( g_flag.diag_out_ledge == OFF && g_flag.diag_out_redge == ON ) ) )
		{
			cpn_ratio = ( g_flag.diag_out == ON ) ? ( float32 )0.75 : ( float32 )1.26;
			g_pos.fp32value = g_fp32right_pos * cpn_ratio;			
		}		
		else
			g_pos.fp32value = ( float32 )0.0;
	
	}
	else if( wall.right == ON && wall.left == ON )  //양벽 다 있는 경우.
	{	
		g_flag.diff_adj = OFF;
		g_pos.fp32value = ( g_fp32left_pos + g_fp32right_pos ) * ( float32 )0.5;
	}
	else if( wall.right == ON && wall.left == OFF )  //오른쪽 벽만 있는 경우.
	{
		g_flag.diff_adj = OFF;				
		g_pos.fp32value = g_fp32right_pos;		
	}
	else if( wall.right == OFF && wall.left == ON )  //왼쪽 벽만 있는 경우.
	{
		g_flag.diff_adj = OFF;	
		g_pos.fp32value = g_fp32left_pos;
	}	
	else  //옆벽이 없을 경우 -> 가지벽 or 앞벽 보정
	{
		if( g_flag.diff_adj == ON ) //가지벽 보정.
		{
			YELLOW_OFF;
		
			if( g_pos.fp32value > ( float32 )0.0 )		g_pos.fp32value -= ( float32 )0.475;
			else if( g_pos.fp32value < ( float32 )0.0 )	g_pos.fp32value += ( float32 )0.475;
			else;

			if( fabs( ( double )( g_pos.fp32value ) ) < ( double )0.2 )
			{
				g_flag.diff_adj = OFF;
				g_pos.fp32value = ( float32 )0.0;
			}
		}		
		else if( g_flag.fsen_pull == ON ) //앞벽 밀기 -> 테스트 필요...
		{		
			if( g_prfs->fp32position < ( float32 )250.0 && g_plfs->fp32position < ( float32 )250.0 )
				g_pos.fp32value = ( g_prfs->fp32position - g_plfs->fp32position ) * ( float32 )4.0;
			else if( g_plfs->fp32position < ( float32 )250.0 )
				g_pos.fp32value = ( ( float32 )250.0 - g_plfs->fp32position ) * ( float32 )4.0;
			else if( g_prfs->fp32position < ( float32 )250.0 )
				g_pos.fp32value = ( g_prfs->fp32position - ( float32 )250.0 ) * ( float32 )4.0;
			else;
		}
		else;
		
		if( g_flag.diff_adj == OFF ) //보정할 벽이 전혀 없을 시 -> 포지션을 0으로 맹글어 현재 상태를 유지한다.
		{
			if( g_pos.fp32value > ( float32 )0.0 )		g_pos.fp32value -= ( float32 )0.525;
			else if( g_pos.fp32value < ( float32 )0.0 )	g_pos.fp32value += ( float32 )0.525;
			else;

			if( fabs( ( double )( g_pos.fp32value ) ) < ( double )0.55 )
				g_pos.fp32value = ( float32 )0.0;
		}
		
	}

	if( g_pos.fp32value > CENTER_POSITION )			g_pos.fp32value = CENTER_POSITION;
	else if( g_pos.fp32value < -CENTER_POSITION )	g_pos.fp32value = -CENTER_POSITION;
	else;

	g_pos.fp32yet_value = g_pos.fp32value;


//////////////////////////////////////////////////// gyro PID compute ////////////////////////////////////////////////////

	if( g_flag.angle_compen == ON )  //angle compenstaion ON
	{
		g_gyro.fp32err_val_sum -= g_gyro.fp32err_val[ 3 ];
		g_gyro.fp32err_val[ 3 ] = g_gyro.fp32err_val[ 2 ];
		g_gyro.fp32err_val[ 2 ] = g_gyro.fp32err_val[ 1 ];
		g_gyro.fp32err_val[ 1 ] = g_gyro.fp32err_val[ 0 ];	
		g_gyro.fp32err_val[ 0 ] = g_gyro.fp32LPF_outdata - g_gyro.fp32ref_val;	
		g_gyro.fp32err_val_sum += g_gyro.fp32err_val[ 0 ];

		g_gyro.u32real_val += ( ( Uint32 )( fabs( g_gyro.fp32err_val[ 0 ] ) ) >> 4 );

		g_gyro.fp32proportion_val = ( ANGLE_KP * g_gyro.fp32err_val[ 0 ] );
		g_gyro.fp32integral_val = ( ANGLE_KI * g_gyro.fp32err_val_sum );
		g_gyro.fp32differential_val = ( ANGLE_KD * ( ( g_gyro.fp32err_val[ 0 ] - g_gyro.fp32err_val[ 3 ] ) + ( g_gyro.fp32err_val[ 1 ] - g_gyro.fp32err_val[ 2 ] ) ) );

		g_gyro.fp32PID_out = ( g_gyro.fp32proportion_val + g_gyro.fp32integral_val + g_gyro.fp32differential_val );  //값 자체를 받으면 pid_out을 누적 시켜야 하고 에러값을 받으면 적분하지 않는다!!!	
	}
	else
		g_gyro.fp32PID_out = ( float32 )0.0;

////////////////////////////////////////////////////// position PID //////////////////////////////////////////////////////

	if( g_flag.pos_compen == ON )  //position compenstation ON
	{
		g_pos.fp32err_val_sum -= g_pos.fp32err_val[ 3 ];
		g_pos.fp32err_val[ 3 ] = g_pos.fp32err_val[ 2 ];
		g_pos.fp32err_val[ 2 ] = g_pos.fp32err_val[ 1 ];
		g_pos.fp32err_val[ 1 ] = g_pos.fp32err_val[ 0 ];	
		g_pos.fp32err_val[ 0 ] = g_pos.fp32value;	
		g_pos.fp32err_val_sum += g_pos.fp32err_val[ 0 ];

		cal_pos_kp = POS_KP - ( CAL_POS_KP_DIFF * ( g_rmotor.fp32next_vel + g_lmotor.fp32next_vel ) * ( float32 )0.5 );

		if( cal_pos_kp < CAL_POS_KP_MIN )
			cal_pos_kp = CAL_POS_KP_MIN;

		cal_pos_kd = POS_KD + ( CAL_POS_KD_DIFF * ( g_rmotor.fp32next_vel + g_lmotor.fp32next_vel ) * ( float32 )0.5 );

		if( cal_pos_kd > CAL_POS_KD_MAX )
			cal_pos_kd = CAL_POS_KD_MAX;

		g_pos.fp32proportion_val = ( cal_pos_kp * g_pos.fp32err_val[ 0 ] );
		g_pos.fp32integral_val = ( POS_KI * g_pos.fp32err_val_sum );
		g_pos.fp32differential_val = ( cal_pos_kd * ( ( g_pos.fp32err_val[ 0 ] - g_pos.fp32err_val[ 3 ] ) + ( g_pos.fp32err_val[ 1 ] - g_pos.fp32err_val[ 2 ] ) ) );

		//미분값 제한.
		if( g_pos.fp32differential_val > POS_KD_MAX )		g_pos.fp32differential_val = POS_KD_MAX;
		else if( g_pos.fp32differential_val < -POS_KD_MAX )	g_pos.fp32differential_val = -POS_KD_MAX;
		else;
		
		g_pos.fp32PID_out = ( g_pos.fp32proportion_val + g_pos.fp32integral_val + g_pos.fp32differential_val );  //값 자체를 받으면 pid_out을 누적 시켜야 하고 에러값을 받으면 적분하지 않는다!!!		

		if( g_rmotor.fp32cur_vel_avr > ( float32 )1300.0 && g_lmotor.fp32cur_vel_avr > ( float32 )1300.0 ) //직진주행시 자이로 보정 추가.
			g_pos.fp32PID_out -= ( g_gyro.fp32PID_out * ANGLE_ADJ_RATIO );

		/* handle compute */
		if( g_pos.fp32PID_out > 0 )  //왼쪽 벽에 가까움 -> 좌회전
		{
			g_fp32left_handle = ( g_fp32han_accdiff * ( CENTER_POSITION + g_pos.fp32PID_out ) ) + g_fp32han_accref;
			g_fp32right_handle = ( g_fp32han_decdiff * ( CENTER_POSITION - g_pos.fp32PID_out ) ) + g_fp32han_decref;
		}
		else						 //오른쪽 벽에 가까움 -> 우회전.
		{
			g_fp32left_handle = ( g_fp32han_decdiff * ( CENTER_POSITION + g_pos.fp32PID_out ) ) + g_fp32han_decref;
			g_fp32right_handle = ( g_fp32han_accdiff * ( CENTER_POSITION - g_pos.fp32PID_out ) ) + g_fp32han_accref;	
		}
		
	}
	else
	{
#if 1
		g_pos.fp32err_val_sum = ( float32 )0.0;
		g_pos.fp32err_val[ 3 ] = ( float32 )0.0;
		g_pos.fp32err_val[ 2 ] = ( float32 )0.0;
		g_pos.fp32err_val[ 1 ] = ( float32 )0.0;
		g_pos.fp32err_val[ 0 ] = ( float32 )0.0;

		g_gyro.fp32err_val_sum = ( float32 )0.0;
		g_gyro.fp32err_val[ 3 ] = ( float32 )0.0;
		g_gyro.fp32err_val[ 2 ] = ( float32 )0.0;
		g_gyro.fp32err_val[ 1 ] = ( float32 )0.0;
		g_gyro.fp32err_val[ 0 ] = ( float32 )0.0;		
#endif		
	
		g_fp32left_handle = ( float32 )1.0;
		g_fp32right_handle = ( float32 )1.0;
	}
	
}

static void _edge_check_func( edge_check_t *p_edge , sen_t *p_sen )
{
	sen_t *psen = p_sen;
	edge_check_t *pedge = p_edge;

	volatile Uint16 edge_tick;
	volatile Uint16 wall_tick;
	volatile float32 raise_diff;
	volatile float32 fall_diff;

	if( g_rmotor.fp32next_vel > ( float32 )2300.0 || g_lmotor.fp32next_vel > ( float32 )2300.0 )
	{
		edge_tick = 40;
		wall_tick = 10;
		raise_diff = ( float32 )0.24;
		fall_diff = -( float32 )0.34;	
	}
	else if( g_rmotor.fp32next_vel > ( float32 )1500.0 || g_lmotor.fp32next_vel > ( float32 )1500.0 )
	{
		edge_tick = 60;
		wall_tick = 20;
		raise_diff = ( float32 )0.3;
		fall_diff = -( float32 )0.35;	
	}
	else if( g_rmotor.fp32next_vel > ( float32 )1000.0 || g_lmotor.fp32next_vel > ( float32 )1000.0 )
	{
		edge_tick = 100;
		wall_tick = 25;
		raise_diff = ( float32 )0.4;
		fall_diff = -( float32 )0.47;	
	}
	else
	{
		edge_tick = 200;
		wall_tick = 30;
		raise_diff = ( float32 )0.4;
		fall_diff = -( float32 )0.5;
	}

	if( pedge->u16state != ( Uint16 )EDGE_ON )
	{	
		if( ( psen->fp32position > ( float32 )100.0 ) && 
			( psen->fp32LPF_diff_outdata > raise_diff ) &&
			( pedge->u16state != ( Uint16 )EDGE_FALL ) )  //엣지 보기 시작하는 타이밍.
		{
			pedge->u16limit_cnt = 0;
			pedge->u16state = ( Uint16 )EDGE_FALL;
		}
		else if( pedge->u16state == ( Uint16 )EDGE_FALL )
		{
			if( pedge->u16limit_cnt < edge_tick ) //edge가 들어오는 충분한 시간만큼 기다려 준다.
			{
				pedge->u16limit_cnt++;
				if( psen->fp32position > ( float32 )100.0 && psen->fp32LPF_diff_outdata < fall_diff )  //-값이 벽이 있을때 만큼 떨어지지 않는 시점.
				{
					pedge->u16del_cnt = 0;
					pedge->u16state = ( Uint16 )EDGE_UP;
				}
			}
			else
				pedge->u16state = ( Uint16 )EDGE_OFF; //edge 들어올 시간 지나면 다시 상태 초기화.
		}
		else if( pedge->u16state == ( Uint16 )EDGE_UP && psen->fp32position > ( float32 )510.0 ) //엣지를 벗어나는 시점.
		{
			pedge->u16del_cnt = 0;
			pedge->u16on_tick = 0;
			pedge->u16state = ( Uint16 )EDGE_ON; //edge on!!
			pedge->int32check_tick = g_int32edge_diff_cnt; //엣지 카운터 값 넘겨줌 -> 가지벽 보정시 비교 기준.
		}
		else;		
		
	}
	else  //edge ON!!
	{
		pedge->u16on = ON;
		if( pedge->u16del_cnt++ > 10 )
			pedge->u16state = ( Uint16 )EDGE_OFF;  //interrupt 10번 걸리고 나면 엣지 다시 볼 수 있음.
	}

	if( pedge->u16on == ON )
	{
		if( pedge->u16on_tick++ > 250 )  //일정 시간 edge 신호 ON 시켜 줌 -> position pid에서 보정 루틴 참조.
		{		
			pedge->u16on = OFF;		
			pedge->u16on_tick = 0;
		}
	}	

	//wall...

	if( pedge->u16wall_state == ON && psen->fp32position >= ( float32 )512.0 )
		pedge->u16wall_fall_tick++; //스무스 턴 엣지 카운터로 사용.

	if( psen->fp32position < ( float32 )510.0 )					 //벽이 있는 시점.
	{
		if( pedge->u16wall_check_tick > wall_tick )				 //벽 상태 ON!!
			pedge->u16wall_state = ON;

		pedge->u16wall_check_tick++;
		pedge->u16wall_fall_tick = 0;
	}
	else if( pedge->u16wall_state == ON && pedge->u16wall_fall_tick > 260 ) //벽이 떨어진 이후.
	{
		pedge->u16wall_state = OFF;
		pedge->u16wall_check_tick = 0;
	}
	else
		pedge->u16wall_check_tick = 0;
	
}

static void _diag_edge_check_func( edge_check_t *p_edge , sen_t *p_sen )
{
	sen_t *psen = p_sen;
	edge_check_t *pedge = p_edge;

	volatile Uint16 edge_tick;
	volatile Uint16 wall_tick;
	volatile float32 fall_diff;

	if( g_rmotor.fp32next_vel > ( float32 )2300.0 || g_lmotor.fp32next_vel > ( float32 )2300.0 )
	{
		edge_tick = 90;
		wall_tick = 10;
		fall_diff = ( float32 )0.02;	
	}
	else if( g_rmotor.fp32next_vel > ( float32 )1500.0 || g_lmotor.fp32next_vel > ( float32 )1500.0 )
	{
		edge_tick = 180;
		wall_tick = 20;
		fall_diff = ( float32 )0.02;	
	}
	else if( g_rmotor.fp32next_vel > ( float32 )1000.0 || g_lmotor.fp32next_vel > ( float32 )1000.0 )
	{
		edge_tick = 200;
		wall_tick = 25;
		fall_diff = ( float32 )0.038;
	}
	else
	{
		edge_tick = 250;
		wall_tick = 30;
		fall_diff = ( float32 )0.044;
	}

	if( pedge->u16state != ( Uint16 )EDGE_ON )
	{
		if( ( psen->fp32position > ( float32 )50.0 ) && 
			( psen->fp32LPF_diff_outdata > fall_diff ) &&
			( pedge->u16state != ( Uint16 )EDGE_FALL ) )  //엣지 보기 시작하는 타이밍.
		{
			pedge->u16limit_cnt = 0;
			pedge->u16state = ( Uint16 )EDGE_FALL;
		}
		else if( pedge->u16state == ( Uint16 )EDGE_FALL )
		{
			if( pedge->u16limit_cnt < edge_tick ) //edge가 들어오는 충분한 시간만큼 기다려 준다.
			{
				pedge->u16limit_cnt++;
				if( psen->fp32position > ( float32 )50.0 && psen->fp32LPF_diff_outdata < -( float32 )0.1 )  //-값이 벽이 있을때 만큼 떨어지지 않는 시점.
					pedge->u16state = ( Uint16 )EDGE_UP;
			}
			else
				pedge->u16state = ( Uint16 )EDGE_OFF; //edge 들어올 시간 지나면 다시 상태 초기화.
		}
		else if( pedge->u16state == ( Uint16 )EDGE_UP && psen->fp32position > ( float32 )510.0 ) //엣지를 벗어나는 시점.
		{
			pedge->u16del_cnt = 0;
			pedge->u16on_tick = 0;
			pedge->u16state = ( Uint16 )EDGE_ON; //edge on!!
		}
		else;

	}
	else //edge on!!
	{
		pedge->u16on = ON;
		if( pedge->u16del_cnt++ > 10 )
			pedge->u16state = ( Uint16 )EDGE_OFF;
	}

	if( pedge->u16on == ON )
	{
		if( pedge->u16on_tick++ > 100 )  //일정 시간 edge 신호 ON 시켜 줌 -> position pid에서 보정 루틴 참조.
		{
			pedge->u16on = OFF;		
			pedge->u16on_tick = 0;
		}
	}	

	//wall...

	if( pedge->u16wall_state == ON && psen->fp32position >= ( float32 )512.0 )
	{
		if( g_flag.diag_run == ON )
		{
			if( psen == g_pr45s )	REDGE_LED_ON;
			else					LEDGE_LED_ON;
		}

		pedge->u16wall_fall_tick++; //스무스 턴 엣지 카운터로 사용.
	}

	if( psen->fp32position < ( float32 )510.0 )					 //벽이 있는 시점.
	{
		if( psen == g_pr45s )	REDGE_LED_OFF;
		else					LEDGE_LED_OFF;
	
		if( pedge->u16wall_check_tick > wall_tick )				 //벽 상태 ON!!
			pedge->u16wall_state = ON;

		pedge->u16wall_check_tick++;
		pedge->u16wall_fall_tick = 0;
	}
	else if( pedge->u16wall_state == ON && pedge->u16wall_fall_tick > 260 ) //벽이 떨어진 이후.
	{
		pedge->u16wall_state = OFF;
		pedge->u16wall_check_tick = 0;
	}
	else
		pedge->u16wall_check_tick = 0;	
	

}

Uint16 wall_check_func( sen_t *p_rsen , sen_t *p_lsen ) //벽 체크 함수.
{
	Uint16 wallinfo;
	wall_info_t wall;

	sen_t *prsen = p_rsen;
	sen_t *plsen = p_lsen;

	memset( ( void * )&wall , 0x00 , sizeof( wall_info_t ) );

	if( prsen->fp32LPF_outdata > prsen->fp32min_val ) //오른쪽 벽 ON
		wall.right = ON;

	if( plsen->fp32LPF_outdata > plsen->fp32min_val ) //왼쪽 벽 ON
		wall.left = ON;

	if( g_prfs->fp32position < ( float32 )190.0 && g_plfs->fp32position < ( float32 )190.0 ) //앞벽 ON
		wall.front = ON;

	switch( g_u16mouse_dir ) //마우스의 현재 절대방향을 보고 센서값과 함께 벽을 체크 한다.
	{
		case M_N :
			wallinfo = ( ( wall.left << 3 ) & DIR_W ) + ( ( wall.right << 1 ) & DIR_E ) + ( wall.front & DIR_N );
			break;

		case M_E :
			wallinfo = ( ( wall.right << 2 ) & DIR_S ) + ( ( wall.front << 1 ) & DIR_E ) + ( wall.left & DIR_N );
			break;

		case M_S : 
			wallinfo = ( ( wall.right << 3 ) & DIR_W ) + ( ( wall.front << 2 ) & DIR_S ) + ( ( wall.left << 1 ) & DIR_E );
			break;

		case M_W :
			wallinfo = ( ( wall.front << 3 ) & DIR_W ) + ( ( wall.left << 2 ) & DIR_S ) + ( wall.right & DIR_N );
			break;

		default :
			MOTOR_OFF;

			vfdprintf("Werr");
			while( 1 );
			
	}

	return ( wallinfo & 0x0f );
	
}


