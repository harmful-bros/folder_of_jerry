//###########################################################################
//
// FILE		: struct.h
//
// TITLE		: micromouse H2 struct header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.02 $
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
	Uint16	u16stop_flag:2;

	int16	int16qep_value;

	int32	int32accel;
	//float32	fp32next_acc;

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
			
}motor_vari_t;

__STRUCT_EXT__ motor_vari_t	g_rmotor;
__STRUCT_EXT__ motor_vari_t	g_lmotor;

typedef volatile struct sensor_variable
{
	Uint16	u16value;

	float32 fp32max_val;
	float32 fp32min_val;
	float32 fp32mid_val;

	float32 fp32high_coefficient;
	float32 fp32low_coefficient;

	float32	fp32LPF_indata;
	float32 fp32LPF_outdata;
	float32	fp32LPF_yetoutdata;

	float32	fp32LPF_diff_indata;
	float32 fp32LPF_diff_outdata;
	float32	fp32LPF_diff_yetindata;

	float32 fp32position;
	float32 fp32yet_position;
	float32 fp32pos_diff;

}sen_t;

__STRUCT_EXT__ sen_t g_sen[ 6 ];

__STRUCT_EXT__ sen_t *g_plfs; 
__STRUCT_EXT__ sen_t *g_plss;
__STRUCT_EXT__ sen_t *g_pl45s;

__STRUCT_EXT__ sen_t *g_prfs;
__STRUCT_EXT__ sen_t *g_prss;
__STRUCT_EXT__ sen_t *g_pr45s;

typedef volatile struct gyro_variable
{
	Uint16	u16value;
	Uint32	u32real_val;

	float32 fp32LPF_indata;
	float32	fp32LPF_outdata;

	float32 fp32ref_val;

	float32	fp32PID_out;

	float32	fp32proportion_val;
	float32	fp32differential_val;
	float32	fp32integral_val;

	float32	fp32err_val[ 4 ];
	float32	fp32err_val_sum;	

	
}gyro_t;

__STRUCT_EXT__ gyro_t g_gyro;

typedef volatile struct position_variable
{
	float32 fp32value;
	float32 fp32yet_value;

	float32	fp32PID_out;

	float32	fp32proportion_val;
	float32	fp32differential_val;
	float32	fp32integral_val;

	float32	fp32err_val[ 4 ];
	float32	fp32err_val_sum;	


}pos_vari_t;

__STRUCT_EXT__ pos_vari_t g_pos;

typedef volatile struct bit_field_variable
{
	Uint16 move_state:1;
	Uint16 start:1;

	Uint16 back_turn:1;
	Uint16 front_back_t:1;
	Uint16 pos_compen:1;
	Uint16 angle_compen:1;

	Uint16 diff_adj:1;
	Uint16 edge_time:1;
	Uint16 diff_adj_in:1;
	Uint16 fsen_pull:1;

	Uint16 algo:1;
	Uint16 second_rungoal:1;
	Uint16 search_end:1;	
	Uint16 fastrun:1;

	Uint16 diag_run:1;
	Uint16 diag_out:1;
	Uint16 diag_out_redge:1;
	Uint16 diag_out_ledge:1;

	Uint16 first_block_diag:1;

	Uint16 straight:1;


	Uint16 goal;

}bit_field_t;

__STRUCT_EXT__ bit_field_t g_flag;

typedef volatile struct wall_state_information
{
	Uint16 front:1;
	Uint16 right:1;
	Uint16 left:1;
	
}wall_info_t;

typedef volatile struct edge_check_variable
{
	int32 int32check_tick;

	Uint16 u16limit_cnt;
	Uint16 u16del_cnt;

	Uint16 u16wall_check_tick;

	Uint16 u16state:2;
	Uint16 u16wall_state:1;

	Uint16 u16on:1;

	Uint16 u16on_tick;
	Uint16 u16wall_fall_tick;

}edge_check_t;

__STRUCT_EXT__ edge_check_t g_rss_edge;
__STRUCT_EXT__ edge_check_t g_lss_edge;
__STRUCT_EXT__ edge_check_t g_rds_edge;
__STRUCT_EXT__ edge_check_t g_lds_edge;

typedef volatile struct bitfiled_data
{
	Uint16 u16weight;	
	
	Uint16 now_vector:4;
	Uint16 yet_vector:4;
	Uint16 block_cnt:6;
	Uint16 block_state:2;
	
}bit_data_t;

typedef volatile union maze_information
{
	Uint32 all;
	bit_data_t bit;
	
}maze_info_t;

__STRUCT_EXT__ maze_info_t g_minfo[ MAX_MAZE ];

typedef volatile struct known_vlock_path_information
{
	Uint16 u8pos:8;
	Uint16 u4m_dir:4;
	Uint16 u4t_dir:4;
	Uint16 u8cnt:8;
	Uint16 u8state:8;
	
}known_block_path_info_t;

__STRUCT_EXT__ known_block_path_info_t g_knownpath[ MAX_MAZE ];

typedef volatile struct turn_information_table
{
	edge_check_t 	*pedge;
	sen_t			*pin_sen;

	Uint16			u16in_tick;
	Uint16			u16in_err;
	Uint16			u16acc_tick;
	Uint16			u16turn_tick;
	Uint16			u16out_tick;

	int32			int32r_acc;
	int32			int32l_acc;

	float32			fp32r_accvel;
	float32			fp32l_accvel;
	float32			fp32ref_vel;

	Uint16			u16edge_tick0;
	Uint16			u16edge_tick1;
	Uint16			u16edge_tick2;
	Uint16			u16edge_tick3;	

	sen_t			*pedge_sen;
	sen_t			*pfwall_sen;

	Uint32			u32gyro;
	
}turn_info_t;

typedef volatile struct run_limit_variable_table
{
	float32 fp32str_limit_vel;
	float32 fp32diag_limit_vel;

	float32 fp32str_limit_acc;
	float32 fp32diag_limit_acc;
	
}run_limit_vari_t;

__STRUCT_EXT__ run_limit_vari_t g_run;

typedef volatile struct turn_out_distance_table
{
	float32 fp32dist90;
	float32 fp32dist45;
	float32 fp32dist135;
	float32 fp32dist180;

}turn_out_dist_t;

#endif


