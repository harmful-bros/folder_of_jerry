//###########################################################################
//
// FILE		: struct.h
//
// TITLE		: _varhae33_ Tracer struct header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.10.05 $
//###########################################################################


#ifndef __STRUCT_H__
#define __STRUCT_H__

#ifdef __STRUCT__

#undef __STRUCT__
#define __STRUCT_EXT__

#else

#define __STRUCT_EXT__	extern

#endif

typedef volatile struct motor_variable
{
	Uint16	u16qep_sample;
	Uint16	u16decel_flag;

	int16	int16qep_value;

	int32	int32accel;
	float32	fp32next_acc;

	float32	fp32distance_sum;
	float32	fp32err_distance;
	float32 fp32user_distacne;
			
	float32	fp32user_vel;
	float32	fp32next_vel;
			
	float32	fp32current_vel[ 4 ];
	float32	fp32cur_vel_avr;
			
	float32	fp32err_vel[ 4 ];
	float32	fp32err_vel_sum;

	float32	fp32PID_output;
	float32	fp32kp;
	float32	fp32ki;
	float32	fp32kd;
	float32	fp32proportion_val;
	float32	fp32differential_val;
	float32	fp32integral_val;
				
	float32	fp32decel_distance;
	float32	fp32decel_vel;
				
	float32	fp32gone_distance;
	float32	fp32tick_distance;
			
}motor_vari;

__STRUCT_EXT__ motor_vari	R_motor;
__STRUCT_EXT__ motor_vari	L_motor;

typedef volatile struct sensor_variable
{
	Uint16	u16value;
	Uint16	u16result;

	Uint16	u16min_value;
	Uint16	u16max_value;

	Uint16	u16data;
	Uint16	u16div_data;
	
	Uint16	u16active_arr;
	Uint16	u16passive_arr;
	
	int32	int32weight;
	
}sen_t;

__STRUCT_EXT__ sen_t		g_sen[16];	

typedef volatile struct bitflag
{
	Uint16 move_state:1;		//주행 중인가??
	Uint16 start_flag:1;		//출발 플래그	
	Uint16 line_out:1;			//라인 아웃
	Uint16 cross_flag:1;		//크로스 체킹
	Uint16 race_start:1;		//턴마크 체크 출발 플래그
	Uint16 goal_dest:1;			//탐색? or 2차?	
	Uint16 stop_check:1;		//END 후 처리
	Uint16 speed_up_start:1;	//가속 시작 플래그
	Uint16 speed_up:1;			//가속 플래그
	Uint16 straight:1;			//모든 가속 구간 표시
	Uint16 err:1;				//마크 에러 10개 이상일 때...
	Uint16 xrun:1;				// 3차 주행 플래그
	Uint16 line_info:1;			//line debug information 수정 플래그
	Uint16 cross_shift:1;		//크로스때 포지션 쉬프트 떨림.
	
}bitflag;

__STRUCT_EXT__ bitflag	g_Flag;

typedef volatile struct gyro
{
	float32 fp32LPF_indata;
	float32 fp32LPF_outdata;
	float32 fp32ag_intergral;
	float32 fp32center;	
	
	float32 fp32past_angle[4];
	float32 fp32proportion_val;
	float32 fp32differential_val;
	float32 fp32integral_val;

	float32 fp32real_angle;
	float32 fp32err_sum;
	float32 fp32pid_out;
	float32 fp32angle;

	float32	fp32kp;
	float32	fp32ki;	
	float32	fp32kd;	
	
}gyro_t;

__STRUCT_EXT__	gyro_t	g_gyro;

typedef volatile struct position
{
	Uint16	u16sum;
	Uint16	u16enable;
	Uint16	u16state;

	float32	fp32sum_of_sec;

	float32	fp32proportion_val;
	float32	fp32differential_val;
	float32	fp32integral_val;

	float32	fp32kp;
	float32	fp32ki;	
	float32	fp32kd;	

	float32	fp32pid_out;
	float32	fp32current_pos;
	float32	fp32temp_pos;	
	float32	fp32pre_pos;	

	float32 fp32past_pos[ 4 ];

	float32 fp32pos_IIR_puted;
	float32 fp32pos_IIR_puting;
	float32 fp32pos_IIR_output;	

}position_t;

__STRUCT_EXT__	position_t		g_pos;

typedef volatile struct turnmark
{
	float32	fp32check_dis;
	float32	fp32turn_dis;
	float32	fp32dist_limit;

	Uint16	u16turn_flag;
	Uint16	u16single_flag;	
	Uint16	u16cross_flag;
	Uint16	u16mark_enable;
	Uint16	u16mark_dir;

}turnmark_t;

__STRUCT_EXT__	turnmark_t	g_rmark;
__STRUCT_EXT__	turnmark_t	g_lmark;


typedef volatile struct line_info
{
	int32 int32gone_cnt;
	int32 int32history_step;
	int32 int32step_divider;
	
	int32 int32gyro_angle;

}line_info_t;

__STRUCT_EXT__ line_info_t		g_lineinfo;

typedef volatile struct second_run_info
{
	char*	pchdir;
	char*	pchmk_dir;	

	int32	int32mark;
	int32	int32mk_dir;	
	int32	int32r_dist;
	int32	int32l_dist;
	int32	int32abs;

	int32 	int32dist;
	int32 	int32angle;
	int32 	int32dir;
	int32 	int32acc;

	int32 	int32cnt;
	int32	int32down_flag;
	int32	int32s44s_flag;
	int32	int32escape_flag;

	float32 fp32vel;
	float32 fp32in_vel;
	float32 fp32out_vel;
	float32 fp32decel_dist;
	float32 fp32m_dist;

	float32	fp32dist_limit;
	float32	fp32shift_before;
	float32	fp32shift_after;
	float32	fp32kp_down;

}sec_info_t;

__STRUCT_EXT__ sec_info_t		g_secinfo[ BUFF_MAX_SIZE ];

typedef volatile struct second_run_flag
{
	Uint16	u16sen_enable;
	Uint16	u16sen_state;
	
}sec_flag_t;

__STRUCT_EXT__	sec_flag_t	g_secflag;

typedef volatile struct error_disposal_t
{
	float32 fp32over_dist;
	
	float32 fp32under_dist[ BUFF_MAX_SIZE ];
	float32 fp32err_dist[ BUFF_MAX_SIZE ];

	int32	int32mark_val[ MARK_LIMIT ];
	
}err_dps_t;

__STRUCT_EXT__ err_dps_t g_err;


typedef volatile struct str_point
{
	sen_t		*psen;
	gyro_t		*pgyro;
	position_t	*ppos;
	turnmark_t	*prmark;
	turnmark_t	*plmark;
	sec_info_t	*psecinfo;
	err_dps_t	*perr;
	
}str_point_t;

__STRUCT_EXT__	str_point_t	g_ptemp;
__STRUCT_EXT__	str_point_t	*g_ptr;



#endif


