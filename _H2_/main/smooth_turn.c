//###########################################################################
//
// FILE		: smooth_turn.c
//
// TITLE		: micromouse H2 smooth turn source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2012.03.10 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

//#define BACK_TURN_TEST
//#define SMOOTH_TURN_TEST
#define SMT_EDGE_TEST

//#define POS_TO_DIST			( float32 )0.17578125  //( ONE_BLOCK / 2 ) / ( CENTER_POSITON * 2 )
#define POS_TO_DIST			( float32 )0.2  //( ONE_BLOCK / 2 ) / ( CENTER_POSITON * 2 )
#define H2_TREAD			( float32 )90.0

#define TEST_TURN			( float32 )650.0
#define KNOWN_BLOCK_SPEED	( float32 )800.0

#define DIAG_IN_DIST		( float32 )60.0

static void _block_straight( void );
static void _back_turn( void );
static void _smooth_turn( void );

static void _diag_180turn( void );
static void _diag_45_135_in_turn( void );
static void _diag_45_135_out_turn( void );
static void _diag_90_continuous_turn( void );
static void _cobra_45_135_out_turn( void );
static void _diag_block_run( void );

#pragma DATA_SECTION(a_turn_table,"TURN_TABLE");
const turn_info_t a_turn_table[ 5 ][ 20 ] = 
{
//turn velocity 650
 	{
//straight
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , NULL , NULL } ,  	
//R90		edge | sensor | in time | in error | acc time | turn time | out time | right acc | left acc | right acc vel | left acc vel | reference vel | edge 0 | edge 1 | edge2
		{ &g_rss_edge , &g_sen[ RSS ] , 30 , 145 , 94 , 244 , 26 , 7 , 7 , 321.0 , 979.0 , 650.0 , 222 , 172 , 175 , 0 , &g_sen[ LSS ] , &g_sen[ LDS ] } , 
//back turn!!
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , NULL , NULL } , 
//L90
		{ &g_lss_edge , &g_sen[ LSS ] , 30 , 131 , 94 , 240 , 26 , 7 , 7 , 979.0 , 321.0 , 650.0 , 226 , 176 , 178 , 0 , &g_sen[ RSS ] , &g_sen[ RDS ] } , 
		
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,  	
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,  	
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,  	
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		
//R cobra 45 out
		{ &g_rds_edge , &g_sen[ RDS ] , 20 , 0 , 85 , 0 , 0 , 8 , 8 , 990.0 , 310.0 , 650.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,  	
//L cobra 45 out
		{ &g_lds_edge , &g_sen[ LDS ] , 40 , 0 , 85 , 0 , 0 , 8 , 8 , 310.0 , 990.0 , 650.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
//R cobra 135 out
		{ &g_rds_edge , &g_sen[ RDS ] , 62 , 0 , 80 , 0 , 0 , 8 , 8 , 970.0 , 330.0 , 650.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
//L cobra 135 out
		{ &g_lds_edge , &g_sen[ LDS ] , 62 , 0 , 80 , 0 , 0 , 8 , 8 , 330.0 , 970.0 , 650.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 		
 	} , 
//turn velocity 800
 	{
//straight
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , NULL , NULL } ,  	
//R90		edge | sensor | in time | in error | acc time | turn time | out time | right acc | left acc | right acc vel | left acc vel | reference vel | edge 0 | edge 1 | edge2
		{ &g_rss_edge , &g_sen[ RSS ] , 93 , 0 , 100 , 213 , 0 , 7 , 7 , 450.0 , 1150.0 , 800.0 , 160 , 161 , 162 , 0 , &g_sen[ LDS ] , &g_sen[ LDS ] } , 
//back turn!!		
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
//L90		
		{ &g_lss_edge , &g_sen[ LSS ] , 95 , 0 , 100 , 213 , 0 , 7 , 7 , 1150.0 , 450.0 , 800.0 , 159 , 170 , 179 , 0 , &g_sen[ RDS ] , &g_sen[ RDS ] } , 
//R180
		{ &g_rss_edge , &g_sen[ RSS ] , 10 , 0 , 89 , 610 , 0 , 7 , 7 , 488.5 , 1111.5 , 800.0 , 443 , 443 , 521 , 542 , &g_sen[ LFS ] , &g_sen[ LDS ] } ,  	
//L180
		{ &g_lss_edge , &g_sen[ LSS ] , 10 , 0 , 89 , 620 , 0 , 7 , 7 , 1111.5 , 488.5 , 800.0 , 444 , 444 , 529 , 560 , &g_sen[ RFS ] , &g_sen[ RDS ] } , 
//R135IN
		{ &g_rss_edge , &g_sen[ RSS ] , 36 , 0 , 100 , 372 , 0 , 7 , 7 , 450.0 , 1150.0 , 800.0 , 173 , 176 , 238 , 263 , &g_sen[ LFS ] , &g_sen[ RFS ] } , 
//L135IN
		{ &g_lss_edge , &g_sen[ LSS ] , 30 , 0 , 100 , 372 , 0 , 7 , 7 , 1150.0 , 450.0 , 800.0 , 150 , 156 , 229 , 260 , &g_sen[ RFS ] , &g_sen[ LFS ] } , 
//R45IN
		{ &g_rds_edge , &g_sen[ RDS ] , 90 , 0 , 66 , 84 , 200 , 11 , 11 , 437.0 , 1163.0 , 800.0 , 0 , 32 , 0 , 0 , NULL , &g_sen[ RFS ] } ,  	
//L45IN
		{ &g_lds_edge , &g_sen[ LDS ] , 100 , 0 , 66 , 84 , 200 , 11 , 11 , 1163.0 , 437.0 , 800.0 , 0 , 29 , 0 , 0 , NULL , &g_sen[ LFS ] } , 
//R135OUT
		{ &g_rss_edge , &g_sen[ RSS ] , 52 , 0 , 99 , 372 , 0 , 7 , 7 , 453.5 , 1146.5 , 800.0 , 332 , 332 , 159 , 292 , &g_sen[ LSS ] , &g_sen[ RFS ] } , 
//L135OUT
		{ &g_lss_edge , &g_sen[ LSS ] , 76 , 0 , 99 , 382 , 0 , 7 , 7 , 1146.5 , 453.5 , 800.0 , 350 , 350 , 180 , 298 , &g_sen[ RSS ] , &g_sen[ LFS ] } , 
//R45OUT
		{ &g_rss_edge , &g_sen[ RSS ] , 140 , 0 , 85 , 95 , 0 , 7 , 7 , 502.5 , 1097.5 , 800.0 , 33 , 69 , 0 , 0 , &g_sen[ LSS ] , &g_sen[ LFS ] } ,  	
//L45OUT
		{ &g_lss_edge , &g_sen[ LSS ] , 128 , 0 , 85 , 98 , 0 , 7 , 7 , 1097.5 , 502.5 , 800.0 , 53 , 68 , 0 , 0 , &g_sen[ RSS ] , &g_sen[ RFS ] } , 
//RD90
		{ &g_rss_edge , &g_sen[ RSS ] , 37 , 0 , 104 , 198 , 0 , 7 , 7 , 436.0 , 1164.0 , 800.0 , 45 , 132 , 142 , 0 , &g_sen[ LSS ] , &g_sen[ RFS ] } , 
//LD90
		{ &g_lss_edge , &g_sen[ LSS ] , 41 , 0 , 104 , 198 , 0 , 7 , 7 , 1164.0 , 436.0 , 800.0 , 56 , 137 , 148 , 0 , &g_sen[ RSS ] , &g_sen[ LFS ] } , 
		
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,  	
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
 	} , 

//turn velocity 1000
 	{
//straight
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , NULL , NULL } ,  	
//R90		edge | sensor | in time | in error | acc time | turn time | out time | right acc | left acc | right acc vel | left acc vel | reference vel | edge 0 | edge 1 | edge2		
		{ &g_rss_edge , &g_sen[ RSS ] , 30 , 0 , 83 , 205 , 0 , 9 , 9 , 626.5 , 1373.5 , 1000.0 , 152 , 166 , 172 , 0 , &g_sen[ LDS ] , &g_sen[ LDS ] } , 
//back turn!!		
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
//L90		
		{ &g_lss_edge , &g_sen[ LSS ] , 34 , 0 , 83 , 207 , 0 , 9 , 9 , 1373.5 , 626.5 , 1000.0 , 161 , 164 , 174 , 0 , &g_sen[ RDS ] , &g_sen[ RDS ] } , 
//R180		
		{ &g_rds_edge , &g_sen[ RDS ] , 40 , 0 , 87 , 470 , 0 , 9 , 9 , 608.5 , 1391.5 , 1000.0 , 346 , 352 , 409 , 438 , &g_sen[ LFS ] , &g_sen[ LDS ] } ,  	
//L180		
		{ &g_lds_edge , &g_sen[ LDS ] , 40 , 0 , 85 , 490 , 0 , 9 , 9 , 1382.5 , 617.5 , 1000.0 , 354 , 359 , 417 , 454 , &g_sen[ RFS ] , &g_sen[ RDS ] } , 
//R135IN
		{ &g_rds_edge , &g_sen[ RDS ] , 80 , 0 , 103 , 246 , 0 , 9 , 9 , 536.5 , 1463.5 , 1000.0 , 106 , 117 , 162 , 188 , &g_sen[ LFS ] , &g_sen[ RFS ] } , 
//L135IN
		{ &g_lds_edge , &g_sen[ LDS ] , 84 , 0 , 103 , 246 , 0 , 9 , 9 , 1463.5 , 536.5 , 1000.0 , 103 , 116 , 164 , 188 , &g_sen[ RFS ] , &g_sen[ LFS ] } , 
//R45IN
		{ &g_rds_edge , &g_sen[ RDS ] , 32 , 0 , 62 , 78 , 200 , 12 , 12 , 628.0 , 1372.0 , 1000.0 , 0 , 16 , 0 , 0 , NULL , &g_sen[ RFS ] } ,
//L45IN
		{ &g_lds_edge , &g_sen[ LDS ] , 40 , 0 , 62 , 78 , 200 , 12 , 12 , 1372.0 , 628.0 , 1000.0 , 0 , 36 , 0 , 0 , NULL , &g_sen[ LFS ] } ,
//R135OUT
		{ &g_rds_edge , &g_sen[ RDS ] , 118 , 0 , 110 , 210 , 0 , 9 , 9 , 505.0 , 1495.0 , 1000.0 , 196 , 192 , 115 , 186 , &g_sen[ LDS ] , &g_sen[ RFS ] } , 
//L135OUT
		{ &g_lds_edge , &g_sen[ LDS ] , 130 , 0 , 110 , 224 , 0 , 9 , 9 , 1495.0 , 505.0 , 1000.0 , 220 , 218 , 142 , 218 , &g_sen[ RDS ] , &g_sen[ LFS ] } , 
//R45OUT
		{ &g_rss_edge , &g_sen[ RSS ] , 72 , 0 , 70 , 94 , 0 , 9 , 9 , 685.0 , 1315.0 , 1000.0 , 31 , 70 , 0 , 0 , &g_sen[ LDS ] , &g_sen[ LFS ] } ,  	
//L45OUT
		{ &g_lss_edge , &g_sen[ LSS ] , 50 , 0 , 70 , 110 , 0 , 9 , 9 , 1315.0 , 685.0 , 1000.0 , 25 , 62 , 0 , 0 , &g_sen[ RDS ] , &g_sen[ RFS ] } , 
//RD90
		{ &g_rds_edge , &g_sen[ RDS ] , 66 , 0 , 103 , 122 , 0 , 9 , 9 , 536.5 , 1463.5 , 1000.0 , 32 , 98 , 104 , 0 , &g_sen[ LSS ] , &g_sen[ RFS ] } , 
//LD90
		{ &g_lds_edge , &g_sen[ LDS ] , 76 , 0 , 103 , 130 , 0 , 9 , 9 , 1463.5 , 536.5 , 1000.0 , 42 , 95 , 123 , 0 , &g_sen[ RSS ] , &g_sen[ LFS ] } , 
		
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,  	
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
 	} , 
//turn velocity 1200
 	{
//straight
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
//R90		edge | sensor | in time | in error | acc time | turn time | out time | right acc | left acc | right acc vel | left acc vel | reference vel | edge 0 | edge 1 | edge2		
		{ &g_rds_edge , &g_sen[ RDS ] , 60 , 0 , 75 , 180 , 0 , 11 , 11 , 787.5 , 1612.5 , 1200.0 , 148 , 153 , 156 , 0 , &g_sen[ LDS ] , &g_sen[ LDS ] } ,
//back turn!!		
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
//L90		
		{ &g_lds_edge , &g_sen[ LDS ] , 40 , 0 , 75 , 186 , 0 , 11 , 11 , 1612.5 , 787.5 , 1200.0 , 157 , 174 , 168 , 0 , &g_sen[ RDS ] , &g_sen[ RDS ] } ,
//R180		
		{ &g_rds_edge , &g_sen[ RDS ] , 10 , 0 , 81 , 382 , 0 , 11 , 11 , 754.5 , 1645.5 , 1200.0 , 299 , 304 , 355 , 376 , &g_sen[ LFS ] , &g_sen[ LDS ] } ,
//L180		
		{ &g_lds_edge , &g_sen[ LDS ] , 10 , 0 , 83 , 386 , 0 , 11 , 11 , 1656.5 , 743.5 , 1200.0 , 296 , 298 , 347 , 382 , &g_sen[ RFS ] , &g_sen[ RDS ] } ,
//R135IN
		{ &g_rds_edge , &g_sen[ RDS ] , 7 , 0 , 87 , 220 , 0 , 11 , 11 , 721.5 , 1678.5 , 1200.0 , 98 , 106 , 156 , 177 , &g_sen[ LFS ] , &g_sen[ RFS ] } ,
//L135IN
		{ &g_lds_edge , &g_sen[ LDS ] , 28 , 0 , 89 , 235 , 0 , 11 , 11 , 1689.5 , 710.5 , 1200.0 , 89 , 105 , 152 , 180 , &g_sen[ RFS ] , &g_sen[ LFS ] } ,
//R45IN
		{ &g_rds_edge , &g_sen[ RDS ] , 16 , 0 , 56 , 90 , 200 , 13 , 13 , 836.0 , 1564.0 , 1200.0 , 0 , 22 , 0 , 0 , NULL , &g_sen[ RFS ] } ,
//L45IN
		{ &g_lds_edge , &g_sen[ LDS ] , 16 , 0 , 56 , 90 , 200 , 13 , 13 , 1564.0 , 836.0 , 1200.0 , 0 , 40 , 0 , 0 , NULL , &g_sen[ LFS ] } ,
//R135OUT
		{ &g_rds_edge , &g_sen[ RDS ] , 46 , 0 , 88 , 242 , 0 , 11 , 11 , 716.0 , 1684.0 , 1200.0 , 216 , 215 , 124 , 194 , &g_sen[ LDS ] , &g_sen[ RFS ] } ,
//L135OUT
		{ &g_lds_edge , &g_sen[ LDS ] , 30 , 0 , 88 , 242 , 0 , 11 , 11 , 1684.0 , 716.0 , 1200.0 , 216 , 215 , 114 , 209 , &g_sen[ RDS ] , &g_sen[ LFS ] } ,
//R45OUT
		{ &g_rss_edge , &g_sen[ RSS ] , 20 , 0 , 62 , 91 , 0 , 11 , 11 , 859.0 , 1541.0 , 1200.0 , 41 , 68 , 0 , 0 , &g_sen[ LDS ] , &g_sen[ LFS ] } ,
//L45OUT
		{ &g_lss_edge , &g_sen[ LSS ] , 16 , 0 , 62 , 93 , 0 , 11 , 11 , 1541.0 , 859.0 , 1200.0 , 44 , 51 , 0 , 0 , &g_sen[ RDS ] , &g_sen[ RFS ] } ,
//RD90
		{ &g_rds_edge , &g_sen[ RDS ] , 15 , 0 , 86 , 120 , 0 , 11 , 11 , 727.0 , 1673.0 , 1200.0 , 53 , 105 , 105 , 0 , &g_sen[ LSS ] , &g_sen[ RFS ] } ,
//LD90
		{ &g_lds_edge , &g_sen[ LDS ] , 28 , 0 , 86 , 136 , 0 , 11 , 11 , 1673.0 , 727.0 , 1200.0 , 61 , 98 , 115 , 0 , &g_sen[ RSS ] , &g_sen[ LFS ] } ,
		
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,  	
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
 	} , 
//first block diagnal
 	{
//straight
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
//R90		edge | sensor | in time | in error | acc time | turn time | out time | right acc | left acc | right acc vel | left acc vel | reference vel | edge 0 | edge 1 | edge2		
		{ &g_rss_edge , &g_sen[ RSS ] , 80 , 0 , 91 , 180 , 0 , 9 , 9 , 590.5 , 1409.5 , 1000.0 , 144 , 146 , 152 , 0 , &g_sen[ LDS ] , &g_sen[ LDS ] } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
//R135IN
		{ &g_rss_edge , &g_sen[ RSS ] , 94 , 0 , 102 , 216 , 0 , 10 , 10 , 490.0 , 1510.0 , 1000.0 , 175 , 181 , 182 , 172 , &g_sen[ LFS ] , &g_sen[ RFS ] } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
//R45IN
		{ &g_rds_edge , &g_sen[ RDS ] , 120 , 0 , 76 , 104 , 200 , 10 , 10 , 620.0 , 1380.0 , 1000.0 , 0 , 55 , 0 , 0 , NULL , &g_sen[ RFS ] } ,

		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,		
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } ,  	
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
		{ NULL , NULL , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0.0 , 0.0 , 0.0 , 0 , 0 , 0 , 0 , NULL , NULL } , 
 	} ,  	
};

#pragma DATA_SECTION(a_cbrturn_table,"TURN_TABLE");
const turn_info_t a_cbrturn_table[ 4 ] = 
{
//		edge | sensor | in time | in error | acc time | turn time | out time | right acc | left acc | right acc vel | left acc vel | refence vel | edge 0 | edge 1 | fall edge
//RCBR45OUT
		{ NULL , NULL , 0 , 0 , 102 , 100 , 0 , 8 , 8 , 242.0 , 1058.0 , 650.0 , 0 , 0 , 0 , NULL , NULL } , 
//LCBR45OUT
		{ NULL , NULL , 0 , 0 , 102 , 116 , 0 , 8 , 8 , 1058.0 , 242.0 , 650.0 , 0 , 0 , 0 , NULL , NULL } , 
//RCBR135OUT
		{ NULL , NULL , 0 , 0 , 84 , 570 , 23 , 7 , 7 , 356.0 , 944.0 , 650.0 , 0 , 0 , 0 , NULL , NULL } , 
//LCBR135OUT	
		{ NULL , NULL , 0 , 0 , 84 , 570 , 23 , 7 , 7 , 944.0 , 356.0 , 650.0 , 0 , 0 , 0 , NULL , NULL }
};


//턴 탈출 후 턴별 탈출 거리..
turn_out_dist_t a_outturn_err[ 5 ] = 
{
//	90		45		135		180
	{ 0.0 	, 0.0 	, 0.0 	, 0.0 	} ,  	// 650
	{ 20.0 	, 60.0 	, 34.0 	, 35.0 	} , 	// 800
	{ 35.0 	, 90.0	, 25.0 	, 44.0 	} ,		// 1000
	{ 40.0 	, 100.0	, 50.0 	, 17.0 	} , 	// 1200
	{ 0.0 	, 0.0 	, 0.0 	, 0.0 	} , 	//first block diagnal
};

//턴 진입 시 여유거리.   			
turn_out_dist_t a_inturn_err[ 5 ] = 
{
//	90		45		135 		180
	{ 70.0	, 0.0	, 0.0	, 0.0	} , 	// 650
	{ 70.0	, 70.0	, 70.0	, 70.0	} , 	// 800
	{ 70.0	, 70.0	, 70.0	, 70.0	} , 	// 1000
	{ 80.0	, 70.0	, 70.0	, 70.0	} , 	// 1200
	{ 80.0	, 75.0	, 75.0	, 70.0	} , 	//first block diagnal
};


#ifdef SMOOTH_TURN_TEST
typedef volatile struct smooth_turn_data
{
	float32	fp32front_pos[ 1024 ];
	float32 fp32front_diff[ 1024 ];

	float32 fp32side_pos[ 1024 ];
	float32 fp32side_diff[ 1024 ];

	float32 fp32diag_pos[ 1024 ];
	float32 fp32diag_diff[ 1024 ];

}smt_data_t;

smt_data_t a_rsen;
smt_data_t a_lsen;
#endif

const Uint16 a_u16wall_array[ 4 ][ 3 ] = 
{
	{ DIR_N , DIR_E , DIR_W } , 
	{ DIR_E , DIR_S , DIR_N } , 
	{ DIR_S , DIR_W , DIR_E } , 
	{ DIR_W , DIR_N , DIR_S }
};

float32 a_fp32speed;


void init_select_fuction_pointer( void )
{
	pselect_func[ STRAIGHT ] 		= _block_straight;
	pselect_func[ R90 ] 			= _smooth_turn;
	pselect_func[ BACKTURN ] 		= _back_turn;
	pselect_func[ L90 ] 			= _smooth_turn;
	pselect_func[ R180 ] 			= _diag_180turn;
	pselect_func[ L180 ] 			= _diag_180turn;
	pselect_func[ R135IN ] 			= _diag_45_135_in_turn;
	pselect_func[ L135IN ] 			= _diag_45_135_in_turn;
	pselect_func[ R45IN ] 			= _diag_45_135_in_turn;
	pselect_func[ L45IN ] 			= _diag_45_135_in_turn;
	pselect_func[ R135OUT ] 		= _diag_45_135_out_turn;
	pselect_func[ L135OUT ] 		= _diag_45_135_out_turn;
	pselect_func[ R45OUT ] 			= _diag_45_135_out_turn;
	pselect_func[ L45OUT ] 			= _diag_45_135_out_turn;
	pselect_func[ RD90 ] 			= _diag_90_continuous_turn;
	pselect_func[ LD90 ] 			= _diag_90_continuous_turn;
	pselect_func[ RCBR45OUT ] 		= _cobra_45_135_out_turn;
	pselect_func[ LCBR45OUT ] 		= _cobra_45_135_out_turn;
	pselect_func[ RCBR135OUT ] 		= _cobra_45_135_out_turn;
	pselect_func[ LCBR135OUT ] 		= _cobra_45_135_out_turn;
	pselect_func[ RDRUN ] 			= _diag_block_run;
	pselect_func[ LDRUN ] 			= _diag_block_run;
	pselect_func[ NOT_MATCH ] 		= NULL;
	pselect_func[ NOT_MATCH + 1 ] 	= NULL;
	
}

void straight_run_test_func( void )
{
	//테스트 할때 살려야됨 -> #define BACK_TURN_TEST

	LED_OFF;
	
	POS_CPN_ON;
	ANGLE_CPN_ON;		 //보정 ON!!
	motor_vari_init();	 //모터 변수 초기화.
	edge_vari_init();	 //엣지 변수 초기화.

	g_flag.start = ON;
	move_end( ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , 1 );	 //0상 제어 시작.

	vfdprintf("GO!!");

	while( RIGHT_SW );
	h2_delay();

	vfdprintf("    ");	

	g_int32turn_vel = SEARCH_S;
	a_fp32speed = ( float32 )g_int32turn_vel;

	while( 1 )
	{
#if 1
		g_int32turn_acc = g_rmotor.int32accel = g_lmotor.int32accel = 5;
		move_to_move( ( ONE_BLOCK * ( float32 )15.0 ) - 20.0 , a_fp32speed , TEST_TURN , g_int32turn_acc );
		_back_turn();
#endif		

#if 1
		a_fp32speed += ( float32 )100.0;
		if( a_fp32speed > ( float32 )2800.0 )
			a_fp32speed = ( float32 )2800.0;		
#endif
	}
	
}

void smoothturn_test_func( void )
{
#ifdef SMOOTH_STRA_DIST_TEST
	float32 sub_dist = 0.0;
#endif

#ifdef SMOOTH_TURN_TEST
	int32 i;
#endif

	LED_OFF;
	
	POS_CPN_ON;
	ANGLE_CPN_ON;		 //보정 ON!!
	motor_vari_init();	 //모터 변수 초기화.
	edge_vari_init();	 //엣지 변수 초기화.

	g_flag.start = ON;
	move_end( ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , 1 );	 //0상 제어 시작.

	vfdprintf("GO!!");

	while( RIGHT_SW );
	h2_delay();

	vfdprintf("    ");


	g_int32turn_vel = 800;	
	g_int32vel_select = V_800;
	g_u16path_cnt = 0;

	g_knownpath[ 0 ].u8state = L135IN;

#if 0 //대각 맞출때 보정 꺼야 됨.
	POS_CPN_OFF;
	ANGLE_CPN_OFF;
#endif

#ifdef SMOOTH_TURN_TEST
	memset( ( void * )&a_rsen , 0x00 , sizeof( smt_data_t ) );
	memset( ( void * )&a_lsen , 0x00 , sizeof( smt_data_t ) );
#endif
	
#ifdef SMOOTH_STRA_DIST_TEST
	sub_dist = 68.0;
	move_end( ( ONE_BLOCK * 3.0 ) - sub_dist , ( float32 )g_int32turn_vel , ( ONE_BLOCK * 3.0 ) - sub_dist , ( float32 )g_int32turn_vel , g_int32turn_acc );	
	while( !( g_flag.move_state == STOP ) );

	vfdprintf("%4.0f" , g_fp32err_dist * 0.5 );
#else
	move_to_move( ONE_BLOCK * 3.0 , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , 4 );

#if 0
	GREEN_ON;

	while( g_rmotor.fp32distance_sum < ( ONE_BLOCK * ( float32 )3.0 ) - ( float32 )150.0 || 
		   g_lmotor.fp32distance_sum < ( ONE_BLOCK * ( float32 )3.0 ) - ( float32 )150.0 );

	GREEN_OFF;
#endif	

	pselect_func[ g_knownpath[ 0 ].u8state ]();

#if 0
	POS_CPN_ON;
	ANGLE_CPN_ON;
#endif	

//	move_end( ONE_BLOCK * 1.0 - 90.0 , ( float32 )g_int32turn_vel , ONE_BLOCK * 1.0 - 90.0 , ( float32 )g_int32turn_vel , g_int32turn_acc );
//	move_end( ONE_BLOCK * 2.0 , ( float32 )g_int32turn_vel , ONE_BLOCK * 2.0 , ( float32 )g_int32turn_vel , g_int32turn_acc );
	move_end( 0.0 , 0.0 , 0.0 , 0.0 , g_int32turn_acc );

#ifdef SMOOTH_TURN_TEST
	while( DOWN_SW );

	SCIa_Printf("\n\n");
	
	for( i = 0 ; i < ( int32 )a_turn_table[ g_int32vel_select ][ g_knownpath[ 0 ].u8state ].u16turn_tick ; i++ )
		SCIa_Printf("LF : %10lf   %10lf LS : %10lf   %10lf L45 : %10lf   %10lf RF : %10lf   %10lf RS : %10lf   %10lf R45 : %10lf   %10lf \n" , 
		a_lsen.fp32front_pos[ i ] , 
		a_lsen.fp32front_diff[ i ] , 
		a_lsen.fp32side_pos[ i ] , 
		a_lsen.fp32side_diff[ i ] , 
		a_lsen.fp32diag_pos[ i ] , 
		a_lsen.fp32diag_diff[ i ] ,		
		a_rsen.fp32front_pos[ i ] , 
		a_rsen.fp32front_diff[ i ] , 
		a_rsen.fp32side_pos[ i ] , 
		a_rsen.fp32side_diff[ i ] , 
		a_rsen.fp32diag_pos[ i ] , 
		a_rsen.fp32diag_diff[ i ] );

	SCIa_Printf("\n\n");
#endif

#endif	
	
	while( 1 );	

}

static void _block_straight( void )
{
	Uint16 cnt;
	Uint16 block_cnt;
	
	Uint16 yet_dir;
	Uint16 next_dir;
	Uint16 next_next_dir;

	Uint16 edge_reset = OFF;

	float32 dist;
	float32 in_dist;

	float32 start_edgechk_dist;
	float32 diagout_dist;

	volatile float32 acc_vel = 0.0;
	volatile float32 run_dist = 0.0;	

	g_flag.diag_run = OFF;						 //대각 보정 OFF
	g_flag.back_turn = OFF;						 //백턴 전방 수평 보정 OFF
	g_int32block_to_block = TURN_TO_STRAIGHT;

	POS_CPN_ON;
	ANGLE_CPN_ON;

	edge_vari_init();

	g_flag.fsen_pull = ON; //앞벽 밀기 ON

	block_cnt = g_knownpath[ g_u16path_cnt ].u8cnt;

	yet_dir = ( g_u16path_cnt == 0 ) ? NOT_MATCH : g_knownpath[ g_u16path_cnt - 1 ].u8state;

	if( g_flag.algo == ON )		next_dir = NOT_MATCH;
	else
	{
		next_dir = g_knownpath[ g_u16path_cnt + 1 ].u8state;
		next_next_dir = g_knownpath[ g_u16path_cnt + 2 ].u8state;

		//FLx / FRx / FRR / FLL

		if( ( g_int32vel_select == V_650 ) || ( g_int32vel_select == V_800 ) )
		{
			if( ( next_dir == ( Uint16 )R90 || next_dir == ( Uint16 )L90 ) && 
				( next_next_dir == ( Uint16 )R90 || next_next_dir == ( Uint16 )L90 || next_next_dir == ( Uint16 )LAST_PATH ) )
			{
				g_int32turn_vel = SEARCH_S;	
				g_int32vel_select = V_650;
				if( block_cnt == 1 )
				{
					g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )SEARCH_S;
					g_rmotor.fp32decel_vel = g_lmotor.fp32decel_vel = ( float32 )SEARCH_S;
				}
			}
			else
			{
				g_int32turn_vel = S800;	
				g_int32vel_select = V_800;

				g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )S800;
				g_rmotor.fp32decel_vel = g_lmotor.fp32decel_vel = ( float32 )S800;
			}		
			
		}
		else if( g_int32vel_select == V_1000 )
		{
			g_int32turn_vel = S1000;	

			if( block_cnt == 1 )
			{
				g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )S1000;
				g_rmotor.fp32decel_vel = g_lmotor.fp32decel_vel = ( float32 )S1000;	
			}
		}
		else
		{
			g_int32turn_vel = S1200;	
			
			if( block_cnt == 1 )
			{
				g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )S1200;
				g_rmotor.fp32decel_vel = g_lmotor.fp32decel_vel = ( float32 )S1200;
			}		
		}
		
	}

	if( block_cnt > 1 ) //아는 길 직진.
	{
		acc_vel = g_run.fp32str_limit_vel;
		run_dist = ( float32 )( block_cnt ) * ONE_BLOCK;

		if( next_dir == ( Uint16 )BACKTURN )					start_edgechk_dist = ( float32 )0.0;		//시작 점으로 돌아오는 백턴.
		else if( g_knownpath[ g_u16path_cnt ].u8pos == 0x00 )	start_edgechk_dist = ( float32 )68.0;		//스타트 직진일때.
		else if( g_flag.front_back_t == ON )					start_edgechk_dist = ( float32 )80.0;		//백턴 후 시작점.
		else													start_edgechk_dist = ( float32 )0.0;

		run_dist -= start_edgechk_dist;

		//턴 탈출시 거리 재조정.
		if( yet_dir == ( Uint16 )R45OUT || yet_dir == ( Uint16 )L45OUT )			diagout_dist = a_outturn_err[ g_int32vel_select ].fp32dist45;
		else if( yet_dir == ( Uint16 )R90 || yet_dir == ( Uint16 )L90 )				diagout_dist = a_outturn_err[ g_int32vel_select ].fp32dist90;
		else if( yet_dir == ( Uint16 )R135OUT || yet_dir == ( Uint16 )L135OUT )		diagout_dist = a_outturn_err[ g_int32vel_select ].fp32dist135;
		else if( yet_dir == ( Uint16 )R180 || yet_dir == ( Uint16 )L180 )			diagout_dist = a_outturn_err[ g_int32vel_select ].fp32dist180;
		else																		diagout_dist = ( float32 )0.0;

		run_dist -= diagout_dist;

		//아는 길 진입 거리 재조정.
		if( next_dir == ( Uint16 )R45IN || next_dir == ( Uint16 )L45IN )			in_dist = a_inturn_err[ g_int32vel_select ].fp32dist45;
		else if( next_dir == ( Uint16 )R90 || next_dir == ( Uint16 )L90 )			in_dist = a_inturn_err[ g_int32vel_select ].fp32dist90;		
		else if( next_dir == ( Uint16 )R135IN || next_dir == ( Uint16 )L135IN )		in_dist = a_inturn_err[ g_int32vel_select ].fp32dist135;		
		else if( next_dir == ( Uint16 )R180 || next_dir == ( Uint16 )L180 )			in_dist = a_inturn_err[ g_int32vel_select ].fp32dist180;		
		else if( next_dir == ( Uint16 )BACKTURN )									in_dist = ONE_BLOCK;						//시적점 돌아오는 백턴.
		else if( next_dir == ( Uint16 )NOT_MATCH )																				//벽체크 하고 알고리즘 돌릴 경우.
		{
			g_int32turn_vel = SEARCH_S;
			g_int32vel_select = V_650;
			in_dist = ( float32 )165.0;
		}
		else;

		run_dist -= ONE_BLOCK - in_dist;		

		if( g_flag.second_rungoal == ON ) //골로 직진 가속해서 들어올 경우 -> 탐색 속도로 전환.
			g_int32turn_vel = SEARCH_S;		

		move_to_move( run_dist , acc_vel , ( float32 )g_int32turn_vel , ( int32 )g_run.fp32str_limit_acc );

		cnt = 0;
		while( ( g_rmotor.fp32distance_sum < run_dist ) && ( g_lmotor.fp32distance_sum < run_dist ) ) //주행 거리 도달 전.
		{
			dist = ( g_rmotor.fp32distance_sum + g_lmotor.fp32distance_sum ) * ( float32 )0.5;

			if( ( dist > ( ONE_BLOCK * cnt ) - start_edgechk_dist - diagout_dist + ( float32 )10.0 ) && ( edge_reset == OFF ) ) //한 블럭 시작.
			{
				edge_reset = ON;
				g_flag.diff_adj_in = ON; //가지벽 보정 플래그 ON				
				edge_vari_init();			 //edge reset!!
			}

			if( ( dist > ( ONE_BLOCK * cnt ) - start_edgechk_dist - diagout_dist + ( float32 )160.0 ) && ( edge_reset == ON ) ) //한 블럭 끝.
			{
				cnt++;				
				edge_reset = OFF;
				g_flag.diff_adj_in = OFF;
			}

			if( dist > run_dist - ( float32 )120.0 ) //총거리 120 남았을 때 앞벽 밀기 OFF
			{
				GREEN_ON;
				g_flag.fsen_pull = OFF;			
			}
			
		}

		if( next_dir != ( Uint16 )NOT_MATCH )
			edge_vari_init();

		g_flag.diff_adj_in = OFF;	 //가지벽 보정 OFF
		g_rmotor.fp32distance_sum = g_lmotor.fp32distance_sum = in_dist;	//진입 거리 맞춰줌.
	
	}
	else
	{
		if( g_flag.second_rungoal == ON ) //골 도착시 탐색 속도로 전환.
		{
			g_int32turn_vel = SEARCH_S;

			g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )SEARCH_S;
			g_rmotor.fp32decel_vel = g_lmotor.fp32decel_vel = ( float32 )SEARCH_S;
		}

		//턴 탈출시 거리 재조정.
		if( yet_dir == ( Uint16 )R45OUT || yet_dir == ( Uint16 )L45OUT )
		{
			g_rmotor.fp32distance_sum += a_outturn_err[ g_int32vel_select ].fp32dist45;
			g_lmotor.fp32distance_sum += a_outturn_err[ g_int32vel_select ].fp32dist45;
		}
		else if( yet_dir == ( Uint16 )R90 || yet_dir == ( Uint16 )L90 )
		{
			g_rmotor.fp32distance_sum += a_outturn_err[ g_int32vel_select ].fp32dist90;
			g_lmotor.fp32distance_sum += a_outturn_err[ g_int32vel_select ].fp32dist90;
		}
		else if( yet_dir == ( Uint16 )R135OUT || yet_dir == ( Uint16 )L135OUT )
		{
			g_rmotor.fp32distance_sum += a_outturn_err[ g_int32vel_select ].fp32dist135;
			g_lmotor.fp32distance_sum += a_outturn_err[ g_int32vel_select ].fp32dist135;
		}
		else if( yet_dir == ( Uint16 )R180 || yet_dir == ( Uint16 )L180 )
		{
			g_rmotor.fp32distance_sum += a_outturn_err[ g_int32vel_select ].fp32dist180;
			g_lmotor.fp32distance_sum += a_outturn_err[ g_int32vel_select ].fp32dist180;
		}
		else;

		//아는 길 진입 거리 재조정.
		if( next_dir == ( Uint16 )R45IN || next_dir == ( Uint16 )L45IN )			in_dist = a_inturn_err[ g_int32vel_select ].fp32dist45;
		else if( next_dir == ( Uint16 )R90 || next_dir == ( Uint16 )L90 )			in_dist = a_inturn_err[ g_int32vel_select ].fp32dist90;		
		else if( next_dir == ( Uint16 )R135IN || next_dir == ( Uint16 )L135IN )		in_dist = a_inturn_err[ g_int32vel_select ].fp32dist135;		
		else if( next_dir == ( Uint16 )R180 || next_dir == ( Uint16 )L180 )			in_dist = a_inturn_err[ g_int32vel_select ].fp32dist180;		
		else if( next_dir == ( Uint16 )BACKTURN )									in_dist = ONE_BLOCK;					 //시적점 돌아오는 백턴.
		else if( next_dir == ( Uint16 )NOT_MATCH ) 
		{
			//g_flag.algo == ON이면 next_dir은 STRAIGHT.
			//알고리즘 돌릴 경우 -> 탐색 속도로 변경!!
		
			g_int32turn_vel = SEARCH_S;	
			g_int32vel_select = V_650;

			g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )SEARCH_S;
			g_rmotor.fp32decel_vel = g_lmotor.fp32decel_vel = ( float32 )SEARCH_S;

			in_dist = ( float32 )165.0;
		}
		else;
		
	}

	while( ( g_rmotor.fp32distance_sum < in_dist ) || ( g_lmotor.fp32distance_sum < in_dist ) )  //진입 거리 만큼 기다림.
	{
		if( g_rmotor.fp32distance_sum > ( float32 )60.0 || g_lmotor.fp32distance_sum > ( float32 )60.0 )
			g_flag.fsen_pull = OFF;
	}

	GREEN_OFF;
	g_flag.fsen_pull = OFF; //앞벽 밀기 OFF

	if( g_flag.algo == ON )
	{
		if( g_flag.second_rungoal == ON ) //골 도착시 속도 전환 및 시간 계산.
		{
			g_flag.goal = GO_START;
			g_flag.second_rungoal = OFF;

			g_int32turn_vel = SEARCH_S;
			g_int32vel_select = V_650;

			g_fp32time = ( float32 )g_u32time_cnt * SAMPLE_FRQ; //시간 계산.
		}	

		algorithm( wall_check_func( &g_sen[ RDS ] , &g_sen[ LDS ] ) );
		next_dir = g_knownpath[ 0 ].u8state;		
	}
	else
		next_dir = g_knownpath[ g_u16path_cnt + 1 ].u8state;

	if( next_dir == STRAIGHT || next_dir == BACKTURN )
	{
		while( g_rmotor.fp32distance_sum < ONE_BLOCK && g_lmotor.fp32distance_sum < ONE_BLOCK ); //한블럭 갈 때까지 기다림.

		if( next_dir == STRAIGHT ) //탐색에서만 유효... 2차에선 직진 다음 직진은 없음!!
			move_to_move( ONE_BLOCK , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , g_int32turn_acc );
	}

	g_flag.front_back_t	= OFF;	//백턴시 앞벽 존재 flag OFF

}

static void _back_turn( void )
{
	float32 wheel_diff;

	float32 move_across_dist;	
	float32 left_across_dist;
	float32 right_across_dist;
	float32 left_across_vel;
	float32 right_across_vel;	

	float32 left_pos = ( float32 )0.0;
	float32 right_pos = ( float32 )0.0;	

	float32 cp_dist = ( float32 )0.0;

	Uint16 wallinfo;
	Uint16 goal_flag = OFF;

	wall_info_t wall;
	memset( ( void * )&wall , 0x00 , sizeof( wall_info_t ) );

	g_flag.back_turn = OFF; 		//앞벽 보정 끄기.
	g_flag.diff_adj_in = OFF;		//가지벽 보정 끄기.

	//벽체크.
	wallinfo = g_u16map[ g_knownpath[ g_u16path_cnt ].u8pos ] & 0x0f;

	wall.front = ( wallinfo & a_u16wall_array[ g_knownpath[ g_u16path_cnt ].u4m_dir ][ 0 ] ) ? ON : OFF;
	wall.right = ( wallinfo & a_u16wall_array[ g_knownpath[ g_u16path_cnt ].u4m_dir ][ 1 ] ) ? ON : OFF;
	wall.left = ( wallinfo & a_u16wall_array[ g_knownpath[ g_u16path_cnt ].u4m_dir ][ 2 ] ) ? ON : OFF;	

#ifdef BACK_TURN_TEST
	wall.front = ON;
	wall.left = ON;
	wall.right = ON;
	g_flag.search_end = OFF;
#endif

	if( wall.front == ON ) //앞벽이 있는 경우.
	{
#ifndef BACK_TURN_TEST
		move_to_move( ONE_BLOCK , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , g_int32turn_acc );
#endif

		while( 1 )
		{
			if( g_prfs->fp32position < ( float32 )18.0 || g_plfs->fp32position < ( float32 )18.0 ) //정지.
			{
				move_end( ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , ( float32 )0.0 , g_int32turn_acc );
				break;
			}
			else if( g_prfs->fp32position < ( float32 )30.0 || g_plfs->fp32position < ( float32 )30.0 ) //센서 보정 끄고 포지션 값 저장.
			{
				POS_CPN_OFF;
				g_flag.back_turn = OFF;

				left_pos = g_plss->fp32position;
				right_pos = g_prss->fp32position;				
			}
			else if( g_prfs->fp32position < ( float32 )85.0 || g_plfs->fp32position < ( float32 )85.0 ) //앵글 보정 끄고 속도 낮춤 & 전방 수평 보정.
			{
				ANGLE_CPN_OFF;
				g_flag.back_turn = ON;
				g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )100.0;
			}
			else;
			
#ifndef BACK_TURN_TEST
			if( g_rmotor.fp32distance_sum + g_lmotor.fp32distance_sum > ( float32 )260.0 ) //예외적으로 앞벽을 못보는 경우.
			{
				POS_CPN_OFF;
				ANGLE_CPN_OFF;

				g_flag.back_turn = OFF;
				left_pos = right_pos = CENTER_POSITION;

				move_end( 0.0 , 0.0 , 0.0 , 0.0 , g_int32turn_acc );
				while( !( g_flag.move_state == STOP ) );

				break;			
			}
#endif			
		}
		
	}
	else
		move_end( ONE_BLOCK + BACKTURN_COMPEN_DIST , ( float32 )g_int32turn_vel , ONE_BLOCK + BACKTURN_COMPEN_DIST , ( float32 )g_int32turn_vel , g_int32turn_acc ); //앞벽이 없는 경우 -> 한블럭 완전 가기 

	while( !( g_flag.move_state == STOP ) );	
	POS_CPN_OFF;		

	//벗어난 포지션을 거리값으로 환산.
	if( wall.right == OFF && wall.left == OFF )	wheel_diff = ( float32 )0.0;
	else if( wall.right == OFF )				wheel_diff = ( left_pos - CENTER_POSITION ) * POS_TO_DIST;
	else if( wall.left == OFF )					wheel_diff =  ( CENTER_POSITION - right_pos ) * POS_TO_DIST;
	else										wheel_diff = ( ( left_pos - CENTER_POSITION ) + ( CENTER_POSITION - right_pos ) ) * POS_TO_DIST * ( float32 )0.5;
	
	if( wall.front == ON && fabs( wheel_diff ) > ( float32 )8.0 )	 //최소 보정으로 센터 맞춤!!
	{
		move_across_dist = H2_TREAD * ( float32 )acos( ( double )( ( H2_TREAD - ( fabs( wheel_diff ) * ( float32 )0.25 ) ) / H2_TREAD ) ); //http://minihp.cyworld.com/40232387/227767784 참조
		
		if( wheel_diff > ( float32 )0.0 )	
		{
			left_across_vel = ( float32 )0.0;
			left_across_dist = ( float32 )0.0;
		
			right_across_vel = KNOWN_BLOCK_SPEED;
			right_across_dist = move_across_dist;
		}
		else
		{
			left_across_vel = KNOWN_BLOCK_SPEED;
			left_across_dist = move_across_dist;
		
			right_across_vel = ( float32 )0.0;
			right_across_dist = ( float32 )0.0; 		
		}

		move_end( right_across_dist * -( float32 )1.0 , right_across_vel * -( float32 )1.0 , left_across_dist * -( float32 )1.0 , left_across_vel * -( float32 )1.0 , 8 );
		while( !( g_flag.move_state == STOP ) );
		
		move_end( left_across_dist * -( float32 )1.0 , left_across_vel * -( float32 )1.0 , right_across_dist * -( float32 )1.0 , right_across_vel * -( float32 )1.0 , 8 );
		while( !( g_flag.move_state == STOP ) );
		
		move_end( right_across_dist , right_across_vel , left_across_dist , left_across_vel , 8 );
		while( !( g_flag.move_state == STOP ) );
		
		move_end( left_across_dist , left_across_vel , right_across_dist , right_across_vel , 8 );
		while( !( g_flag.move_state == STOP ) );		
		
	}

	move_end( -BACKTURN_DIST , -KNOWN_BLOCK_SPEED , BACKTURN_DIST , KNOWN_BLOCK_SPEED , 4 );  //back turn!!

#ifndef BACK_TURN_TEST	
	maze_map_write_rom(); //미로 저장.	
#endif

	while( !( g_flag.move_state == STOP ) );

	if( g_flag.search_end == OFF )
	{
		g_u16mouse_pos = g_knownpath[ g_u16path_cnt ].u8pos;	

		if( g_u16mouse_pos == 0x77 ||
			g_u16mouse_pos == 0x78 ||
			g_u16mouse_pos == 0x87 ||
			g_u16mouse_pos == 0x88 )
			goal_flag = ON;

#ifndef BACK_TURN_TEST	
		algorithm( g_u16map[ g_u16mouse_pos ] );
#endif

		g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;
		if( ( g_knownpath[ 0 ].u8state == STRAIGHT ) && 
			( g_knownpath[ 0 ].u8cnt == 1 ) && 
			( g_knownpath[ 1 ].u8state == R45IN || g_knownpath[ 1 ].u8state == L45IN ) && ( wall.front == ON ) &&
			( goal_flag == OFF ) ) //첫블럭 대각시 거리 짧으므로 가속도 올린다!!
		{
			move_end( -20.0 , -40.0 , -20.0 , -40.0 , 1 ); //뒤로 당겨 자세 보정 한다.	
			while( !( g_flag.move_state == STOP ) );
		
			g_rmotor.int32accel = g_lmotor.int32accel = 11;
		}

		POS_CPN_ON;
		ANGLE_CPN_ON;		

		move_to_move( ONE_BLOCK , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , g_int32turn_acc );

		g_flag.front_back_t = wall.front; //앞벽 유무...
		
		cp_dist = ( wall.front == ON ) ? BLOCK_COMPEN_DIST : BACKTURN_COMPEN_DIST; //거리 보상.
		if( goal_flag == ON )
			cp_dist += BACKTURN_COMPEN_DIST + ( float32 )2.0;
		
		g_lmotor.fp32distance_sum = g_rmotor.fp32distance_sum = cp_dist;

		g_flag.algo = ON;		
		
	}
	else //탐색이 끝난 후 시작점으로  돌아 왔을 경우.
	{
		R_RED_ON;
		L_RED_ON;

		g_u16yet_mpos = 0;

		if( g_fp32time )
			vfdprintf("%1.2lf" , g_fp32time ); //시간 뿌리기.

		move_end( -20.0 , -40.0 , -20.0 , -40.0 , 1 ); //뒤로 당겨 자세 보정 한다.	
		while( !( g_flag.move_state == STOP ) );

		DELAY_US( 500000 );				

		g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;

		LED_OFF;	

		POS_CPN_ON;
		ANGLE_CPN_ON;		 //보정 ON!!
		
	}

	GREEN_OFF;
	g_flag.fsen_pull = OFF; //앞벽 밀기 flag OFF

}


static void _smooth_turn( void )
{
	int32 idx;

	Uint16 state;
	Uint16 m_dir;
	Uint16 pos;
	int32 next_pos;
	
#ifndef SMOOTH_TURN_TEST
	Uint16 next_dir;
	block_to_block_e block_state[ 4 ] = { TURN_TO_STRAIGHT , TURN_TO_TURN , TURN_TO_BACKTURN , TURN_TO_TURN };
#else
	Uint16 temp = 0;

	smt_data_t *prs = &a_rsen;
	smt_data_t *pls = &a_lsen;
#endif

	Uint16 goal_pole;

	Uint16 wallinfo;
	Uint16 front_wall;
	Uint16 side_wall;	
	Uint16 turn_wall;

	Uint16 turn_edge = OFF;

	Uint16 turn_in_time;
	turn_info_t *pturn_table;
	volatile Uint16 *pedge_cnt = NULL;

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = OFF;

	state = g_knownpath[ g_u16path_cnt ].u8state;
	m_dir = g_knownpath[ g_u16path_cnt ].u4m_dir;
	pos = g_knownpath[ g_u16path_cnt ].u8pos;

#if 0
	if( g_flag.goal == GO_START )
	{
		vfdprintf("%u%u%02x" , g_u16path_cnt , state , g_u16mouse_pos );

		move_end( 0.0 , 0.0 , 0.0 , 0.0 , g_int32turn_acc );
		while( 1 );						
	}
#endif				

	pturn_table = ( turn_info_t * )&a_turn_table[ g_int32vel_select ][ state ];

	goal_pole = ( pos == 0x77 || pos == 0x78 || pos == 0x87 || pos  == 0x88 ) ? ON : OFF;

	//앞벽 유무...
	wallinfo = g_u16map[ pos ] & 0x0f;
	front_wall = wallinfo & a_u16wall_array[ m_dir ][ 0 ];

	//앞벽 + 옆벽의 유무...
	next_pos = 	( int32 )pos + g_int32move_t[ ( state + m_dir ) & 0x03 ];
	wallinfo = next_pos < 0 ? OFF : g_u16map[ next_pos ] & 0x0f;
	side_wall = wallinfo & a_u16wall_array[ m_dir ][ 0 ];

	//yet_pos와 pos를 가지고 현재 벽의 방향 정보 생성.
	//턴 진입 시점 체크를 위해 전 블럭의 좌우 벽정보가 필요하다.
	//벽이 있으면 벽이 사라질 때를 체크 or 벽이 없으면 edge를 체크한다.
	next_pos = ( int32 )pos + g_int32move_t[ ( m_dir + 2 ) & 0x03 ];	
	wallinfo = next_pos < 0 ? OFF : g_u16map[ next_pos ] & 0x0f;
	
	idx = ( state == R90 ) ? 1 : 2;
	turn_wall = wallinfo & a_u16wall_array[ m_dir ][ idx ];	  

#ifdef SMOOTH_TURN_TEST
	front_wall = ON;
	side_wall = ON;
	turn_wall = ON;
	pos = 0x01;	
	g_flag.algo = OFF;
#endif

	if( g_int32block_to_block != TURN_TO_TURN )
	{
		turn_in_time = pturn_table->u16in_tick + pturn_table->u16in_err; //side sensor 떨어지는 시점부터 폴 중앙까지 틱 -> in_err

		if( turn_wall == OFF ) //양 벽이 없을 경우.
		{
			pedge_cnt = &( pturn_table->pedge->u16on_tick ); 	//에찌 보는 틱
			while( pturn_table->pedge->u16on == OFF ) 			//에찌 떨어지는 순간!!
			{
				if( goal_pole == ON )
					break;
			}
		}
		else
		{
			pedge_cnt = &( pturn_table->pedge->u16wall_fall_tick );		 	//벽 떨어지는 틱.
			while( pturn_table->pin_sen->fp32position < ( float32 )512.0 );	//벽이 떨어질 때까지 기다림.
		}
	}
	else
	{
		g_lmotor.fp32distance_sum = ( float32 )0.0;
		g_rmotor.fp32distance_sum = ( float32 )0.0;

		turn_in_time = pturn_table->u16in_tick; //턴 to 턴 일 경우 -> 진입 직진만 생각 한다.
		pedge_cnt = ( Uint16 * )&g_int32tick;
		pedge_cnt = 0;
	}

	POS_CPN_OFF;

	//straight section.
	for( ; *pedge_cnt < turn_in_time ;  )
	{
		if( goal_pole == ON && g_rmotor.fp32distance_sum + g_lmotor.fp32distance_sum > ( float32 )390.0 ) //goal에 pole이 없을 경우.
			break;
	}

	g_rmotor.int32accel = pturn_table->int32r_acc;
	g_lmotor.int32accel = pturn_table->int32l_acc;
	g_rmotor.fp32user_vel = pturn_table->fp32r_accvel;
	g_lmotor.fp32user_vel = pturn_table->fp32l_accvel;

	//turn accel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	//turn uniform section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16turn_tick ) ; )
	{
#ifdef SMOOTH_TURN_TEST	
		prs->fp32front_pos[ g_int32tick ] = g_sen[ RFS ].fp32position;
		prs->fp32front_diff[ g_int32tick ] = g_sen[ RFS ].fp32LPF_diff_outdata;

		prs->fp32diag_pos[ g_int32tick ] = g_sen[ RDS ].fp32position;
		prs->fp32diag_diff[ g_int32tick ] = g_sen[ RDS ].fp32LPF_diff_outdata;

		prs->fp32side_pos[ g_int32tick ] = g_sen[ RSS ].fp32position;
		prs->fp32side_diff[ g_int32tick ] = g_sen[ RSS ].fp32LPF_diff_outdata;

		pls->fp32front_pos[ g_int32tick ] = g_sen[ LFS ].fp32position;
		pls->fp32front_diff[ g_int32tick ] = g_sen[ LFS ].fp32LPF_diff_outdata;

		pls->fp32diag_pos[ g_int32tick ] = g_sen[ LDS ].fp32position;
		pls->fp32diag_diff[ g_int32tick ] = g_sen[ LDS ].fp32LPF_diff_outdata;

		pls->fp32side_pos[ g_int32tick ] = g_sen[ LSS ].fp32position;
		pls->fp32side_diff[ g_int32tick ] = g_sen[ LSS ].fp32LPF_diff_outdata;
#endif
#ifdef SMT_EDGE_TEST
		if( front_wall == OFF ) //앞벽이 없을 경우 -> edge생성 or 벽이 생기는 시점을 본다.
		{
#if 1
			if( ( turn_edge == OFF ) &&
				( g_int32tick > ( int32 )( pturn_table->u16edge_tick0 ) - 50 ) &&
				( pturn_table->pedge_sen->fp32position < ( float32 )510.0 )  )
			{
				turn_edge = ON;
				//temp = ( Uint16 )g_int32tick;
				g_int32tick = ( int32 )( pturn_table->u16edge_tick0 );
			}
#endif			
		}
		else //앞벽이 있을 경우 -> 센서의 최대값을 본다.
		{
#if 1
			if( ( turn_edge == OFF ) &&
				( g_int32tick > ( int32 )( pturn_table->u16edge_tick1 ) - 50 ) &&
				( pturn_table->pfwall_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) && 
				( pturn_table->pfwall_sen->fp32position < ( float32 )150.0 ) )
			{
				turn_edge = ON;
				//temp = ( Uint16 )g_int32tick;
				g_int32tick = ( int32 )( ( side_wall == OFF ) ? pturn_table->u16edge_tick1 : pturn_table->u16edge_tick2 );
			}		
#endif			
		}
#endif		
		
	}

	g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = pturn_table->fp32ref_vel;

	//turn decel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;
	g_int32tick = 0;

#ifdef SMOOTH_TURN_TEST
	//straight section.
	for( ; g_int32tick < ( int32 )( pturn_table->u16out_tick ) ; );

	vfdprintf("%4u" , temp);
#else

	//첫블럭 대각 처리.
	if( g_flag.first_block_diag == ON )
	{
		g_int32turn_vel = g_int32backup_turnvel;
		g_int32vel_select = g_int32backup_turnsel;
	
		g_flag.first_block_diag = OFF;
	}	

	if( g_flag.algo == ON ) //다음 알고리즘 돌리기.
	{
		algorithm( wall_check_func( &g_sen[ RSS ] , &g_sen[ LSS ] ) );
		next_dir = g_knownpath[ 0 ].u8state;
	}
	else
		next_dir = g_knownpath[ g_u16path_cnt + 1 ].u8state;

	//straight section.
	for( ; g_int32tick < ( int32 )( pturn_table->u16out_tick ) ; );

	POS_CPN_ON;		 //보정 켬.
	ANGLE_CPN_ON;	

	if( next_dir <= 0x03 ) //직진 | R90 | 백턴 | L90
	{
		g_int32block_to_block = ( int32 )block_state[ next_dir ]; //다음 블럭 상황 재 조정.
		
		if( next_dir == STRAIGHT )
			move_to_move( ONE_BLOCK , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , g_int32turn_acc ); //직진일 경우 한블럭 완전 가기.		
	}

	GREEN_OFF;

#endif	

}

static void _diag_180turn( void )
{
	Uint16 idx;

	Uint16 state;
	Uint16 m_dir;
	Uint16 pos;
	int32 next_pos;
	
	Uint16 wallinfo;
	Uint16 front_wall;
	Uint16 side_wall;

#ifdef SMOOTH_TURN_TEST
	Uint16 temp = 0;

	smt_data_t *prs = &a_rsen;
	smt_data_t *pls = &a_lsen;		
#endif	

	Uint16 turn_edge = OFF;
	turn_info_t *pturn_table;

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = OFF;

	state = g_knownpath[ g_u16path_cnt ].u8state;
	m_dir = g_knownpath[ g_u16path_cnt ].u4m_dir;
	pos = g_knownpath[ g_u16path_cnt ].u8pos;

	pturn_table = ( turn_info_t * )&a_turn_table[ g_int32vel_select ][ state ];

	//앞벽의 유무...
	wallinfo = g_u16map[ pos ] & 0x0f;
	front_wall = wallinfo & a_u16wall_array[ m_dir ][ 0 ];

	//앞벽 + 옆벽의 유무...
	idx = ( state == R180 ) ? 1 : 3;
	next_pos = ( int32 )pos + g_int32move_t[ ( idx + m_dir ) & 0x03 ];
	wallinfo = next_pos < 0 ? OFF : g_u16map[ next_pos ] & 0x0f;

	side_wall = wallinfo & a_u16wall_array[ m_dir ][ 0 ];

#ifdef SMOOTH_TURN_TEST
	front_wall = ON;
	side_wall = ON;
#endif

	while( pturn_table->pin_sen->fp32position < ( float32 )512.0 ); //벽 떨어지는 시점까지 기다림.

	POS_CPN_OFF;

	for( ; pturn_table->pedge->u16wall_fall_tick < pturn_table->u16in_tick ; );

	g_rmotor.int32accel = pturn_table->int32r_acc;
	g_lmotor.int32accel = pturn_table->int32l_acc;
	g_rmotor.fp32user_vel = pturn_table->fp32r_accvel;
	g_lmotor.fp32user_vel = pturn_table->fp32l_accvel;

	//turn accel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	//turn uniform section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16turn_tick ) ; )
	{
#ifdef SMOOTH_TURN_TEST	
		prs->fp32front_pos[ g_int32tick ] = g_sen[ RFS ].fp32position;
		prs->fp32front_diff[ g_int32tick ] = g_sen[ RFS ].fp32LPF_diff_outdata;

		prs->fp32diag_pos[ g_int32tick ] = g_sen[ RDS ].fp32position;
		prs->fp32diag_diff[ g_int32tick ] = g_sen[ RDS ].fp32LPF_diff_outdata;

		prs->fp32side_pos[ g_int32tick ] = g_sen[ RSS ].fp32position;
		prs->fp32side_diff[ g_int32tick ] = g_sen[ RSS ].fp32LPF_diff_outdata;

		pls->fp32front_pos[ g_int32tick ] = g_sen[ LFS ].fp32position;
		pls->fp32front_diff[ g_int32tick ] = g_sen[ LFS ].fp32LPF_diff_outdata;

		pls->fp32diag_pos[ g_int32tick ] = g_sen[ LDS ].fp32position;
		pls->fp32diag_diff[ g_int32tick ] = g_sen[ LDS ].fp32LPF_diff_outdata;

		pls->fp32side_pos[ g_int32tick ] = g_sen[ LSS ].fp32position;
		pls->fp32side_diff[ g_int32tick ] = g_sen[ LSS ].fp32LPF_diff_outdata;

#endif	
#ifdef SMT_EDGE_TEST
		if( front_wall == OFF )
		{
#if 1
			if( ( turn_edge == OFF ) &&
				( g_int32tick > ( int32 )( pturn_table->u16edge_tick0 ) - 30 ) &&
				( pturn_table->pedge_sen->fp32position < ( float32 )250.0 ) )
			{
				turn_edge = ON;
				//temp = ( Uint16 )g_int32tick;
				g_int32tick = ( side_wall == OFF ) ? ( int32 )( pturn_table->u16edge_tick0 ) : ( int32 )( pturn_table->u16edge_tick1 );				
			}
#endif			
		}		
		else
		{
#if 1
			if( ( turn_edge == OFF ) &&
				( g_int32tick > ( int32 )( pturn_table->u16edge_tick2 ) - 50 ) &&
				( pturn_table->pfwall_sen->fp32position < ( float32 )250.0 ) &&
				( pturn_table->pfwall_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) )
			{
				turn_edge = ON;
				//temp = ( Uint16 )g_int32tick;
				g_int32tick = ( side_wall == OFF ) ? ( int32 )( pturn_table->u16edge_tick2 ) : ( int32 )( pturn_table->u16edge_tick3 );
			}		
#endif			
		}
#endif		
	}
	
	g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = pturn_table->fp32ref_vel;

	//turn decel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;

#ifdef SMOOTH_TURN_TEST
	//straight section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16out_tick ) ; );

	vfdprintf("%4u" , temp );	
#else
	POS_CPN_ON;
	ANGLE_CPN_ON;

	move_to_move( ONE_BLOCK , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , g_int32turn_acc ); //180도 턴 탈출은 무조건 직진!!
#endif	

}

static void _diag_45_135_in_turn( void )
{
	int32 idx;
	int32 edge_tick;

	Uint16 state;
	Uint16 m_dir;
	Uint16 pos;
	int32 next_pos;

	Uint16 next_dir;
	
	Uint16 wallinfo;
	Uint16 front_wall;
	Uint16 side_wall;
	Uint16 turn_wall;
	
#ifdef SMOOTH_TURN_TEST
	Uint16 temp = 0;

	smt_data_t *prs = &a_rsen;
	smt_data_t *pls = &a_lsen;	
#endif

	Uint16 turn_edge = OFF;
	turn_info_t *pturn_table;
	volatile Uint16 *pedge_cnt = NULL;

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = OFF;

	state = g_knownpath[ g_u16path_cnt ].u8state;
	m_dir = g_knownpath[ g_u16path_cnt ].u4m_dir;
	pos = g_knownpath[ g_u16path_cnt ].u8pos;
	next_dir = g_knownpath[ g_u16path_cnt + 1 ].u8state;	

	pturn_table = ( turn_info_t * )&a_turn_table[ g_int32vel_select ][ state ];

	//앞벽의 유무 -> 턴엣지 판별.
	wallinfo = g_u16map[ pos ] & 0x0f;
	front_wall = wallinfo & a_u16wall_array[ m_dir ][ 0 ];

	if( state == R135IN || state == L135IN )	idx = ( state == R135IN ) ? 2 : 1;
	else										idx = ( state == R45IN ) ? 1 : 2;

	//135도 진입 옆벽의 유무 -> 앞벽 없을 시...
	side_wall = wallinfo & a_u16wall_array[ m_dir ][ idx ];			

	//45도 진입 벽의 유무... -> 벽인지 엣지인지 // 135도 side side wall -> side wall 없을시 edge 떨어지는 타이밍 위해...
	next_pos = ( int32 )pos + g_int32move_t[ ( m_dir + 2 ) &  0x03 ];		
	wallinfo = next_pos < 0 ? OFF : g_u16map[ next_pos ] & 0x0f;
	turn_wall = wallinfo & a_u16wall_array[ m_dir ][ idx ];	

#ifdef SMOOTH_TURN_TEST
	front_wall = ON;
	side_wall = ON;
	turn_wall = ON;
	next_dir = RDRUN;
#endif

	//135도 턴은 엣지 진입이 없음!!
	if( ( turn_wall == OFF ) && ( state == R45IN || state == L45IN ) )
	{
		pedge_cnt = &( pturn_table->pedge->u16on_tick );	//에찌 보는 틱
		while( pturn_table->pedge->u16on == OFF ); 			//에찌 떨어지는 순간!!
	}
	else
	{
		pedge_cnt = &( pturn_table->pedge->u16wall_fall_tick );		 	//벽 떨어지는 틱.
		while( pturn_table->pin_sen->fp32position < ( float32 )512.0 );	//벽이 떨어질 때까지 기다림.	
	}

	POS_CPN_OFF;
	for( ; ( *pedge_cnt ) < pturn_table->u16in_tick ; ); //진입 거리 만큼 기다림.

	g_rmotor.int32accel = pturn_table->int32r_acc;
	g_lmotor.int32accel = pturn_table->int32l_acc;
	g_rmotor.fp32user_vel = pturn_table->fp32r_accvel;
	g_lmotor.fp32user_vel = pturn_table->fp32l_accvel;

	//turn accel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	//turn uniform section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16turn_tick ) ; )
	{
#ifdef SMOOTH_TURN_TEST	
		prs->fp32front_pos[ g_int32tick ] = g_sen[ RFS ].fp32position;
		prs->fp32front_diff[ g_int32tick ] = g_sen[ RFS ].fp32LPF_diff_outdata;

		prs->fp32diag_pos[ g_int32tick ] = g_sen[ RDS ].fp32position;
		prs->fp32diag_diff[ g_int32tick ] = g_sen[ RDS ].fp32LPF_diff_outdata;

		prs->fp32side_pos[ g_int32tick ] = g_sen[ RSS ].fp32position;
		prs->fp32side_diff[ g_int32tick ] = g_sen[ RSS ].fp32LPF_diff_outdata;

		pls->fp32front_pos[ g_int32tick ] = g_sen[ LFS ].fp32position;
		pls->fp32front_diff[ g_int32tick ] = g_sen[ LFS ].fp32LPF_diff_outdata;

		pls->fp32diag_pos[ g_int32tick ] = g_sen[ LDS ].fp32position;
		pls->fp32diag_diff[ g_int32tick ] = g_sen[ LDS ].fp32LPF_diff_outdata;

		pls->fp32side_pos[ g_int32tick ] = g_sen[ LSS ].fp32position;
		pls->fp32side_diff[ g_int32tick ] = g_sen[ LSS ].fp32LPF_diff_outdata;
#endif	
#ifdef SMT_EDGE_TEST
		if( state == R135IN || state == L135IN )
		{		
			if( front_wall == OFF ) //앞벽이 없을 경우...
			{			
#if 1
				//																		edge 							 side side wall 						side wall
				edge_tick = ( int32 )( ( side_wall == OFF ) ? ( ( turn_wall == OFF ) ? ( pturn_table->u16edge_tick0 ) : ( pturn_table->u16edge_tick1 ) ) : ( pturn_table->u16edge_tick2 ) );

				if( ( turn_edge == OFF ) &&
					( g_int32tick > edge_tick - 15 ) &&
					( pturn_table->pedge_sen->fp32position > ( float32 )248.0 ) &&
					( pturn_table->pedge_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) )
				{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = edge_tick;
				}
#endif	
			}
			else
			{
#if 1
				if( ( turn_edge == OFF ) &&
					( g_int32tick > ( int32 )( pturn_table->u16edge_tick3 ) - 30 ) &&
					( pturn_table->pfwall_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) )
				{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = ( int32 )( pturn_table->u16edge_tick3 );
				}
#endif				
			}
			
		}
		else //45도 진입 
		{
			if( front_wall == ON )
			{
#if 1
				if( ( turn_edge == OFF ) &&
					( g_int32tick > ( int32 )( pturn_table->u16edge_tick1 ) - 10 ) &&
					( pturn_table->pfwall_sen->fp32position > ( float32 )248.0 ) && 
					( pturn_table->pfwall_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) )
				{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = ( int32 )( pturn_table->u16edge_tick1 );
				}
#endif				
			}

		}
#endif
	}

	g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = pturn_table->fp32ref_vel;

	//turn decel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;

#ifdef SMOOTH_TURN_TEST
	//straight section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16out_tick ) ; );

	vfdprintf("%4u" , temp );	
#else

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = ON;
	g_flag.diag_out = ON;
	g_flag.diag_out_ledge = OFF;
	g_flag.diag_out_redge = OFF;

	POS_CPN_ON;
	ANGLE_CPN_OFF; //자이로 보정 끔 -> 대각 직진 일 경우.

	if( next_dir >= RCBR45OUT && next_dir <= LCBR135OUT ) //다음이 코브라 인 경우 -> 속도 낮춤!!
	{
		g_rmotor.int32accel = g_lmotor.int32accel = 8;
	
		g_int32turn_vel = SEARCH_S;
		g_int32vel_select = V_650;
		g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )SEARCH_S;
		g_rmotor.fp32decel_vel = g_lmotor.fp32decel_vel = ( float32 )SEARCH_S; 
	}

	if( g_flag.first_block_diag == ON )	//첫 블럭 대각 -> 속도 원 위치.
	{
		g_int32turn_vel = g_int32backup_turnvel;
		g_int32vel_select = g_int32backup_turnsel;

		g_flag.first_block_diag = OFF;

		for( g_int32tick = 0 ; g_int32tick < 15 ; );
	}

	GREEN_OFF;
	
#endif	

}

static void _diag_45_135_out_turn( void )
{
	int32 idx;	
	int32 edge_tick;

	Uint16 state;
	Uint16 m_dir;
	Uint16 pos;
	int32 next_pos;

	Uint16 next_dir;

#ifdef SMOOTH_TURN_TEST
	Uint16 temp = 0;

	smt_data_t *prs = &a_rsen;
	smt_data_t *pls = &a_lsen;	
#endif	
	
	Uint16 wallinfo;
	Uint16 diag_front_wall;
	Uint16 diag_side_wall;

	Uint16 in_edge = OFF;
	Uint16 turn_edge = OFF;

	turn_info_t *pturn_table;

#ifndef SMOOTH_TURN_TEST
	POS_CPN_ON;
	ANGLE_CPN_OFF;

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = ON;
	g_flag.diag_out = ON;
#endif		

	state = g_knownpath[ g_u16path_cnt ].u8state;
	m_dir = g_knownpath[ g_u16path_cnt ].u4m_dir;
	pos = g_knownpath[ g_u16path_cnt ].u8pos;

	pturn_table = ( turn_info_t * )&a_turn_table[ g_int32vel_select ][ state ];

	if( state == R45OUT || state == R135OUT ) //엣지 선택.
	{
		g_flag.diag_out_redge = ON;
		g_flag.diag_out_ledge = OFF;
	}
	else
	{
		g_flag.diag_out_redge = OFF;
		g_flag.diag_out_ledge = ON;		
	}

	wallinfo = g_u16map[ pos ] & 0x0f;
	if( state == R45OUT )			diag_front_wall = wallinfo & a_u16wall_array[ m_dir ][ 2 ];
	else if( state == L45OUT )		diag_front_wall = wallinfo & a_u16wall_array[ m_dir ][ 1 ];
	else
	{
		//R135OUT || L135OUT
		diag_front_wall = wallinfo & a_u16wall_array[ m_dir ][ 0 ]; 					//앞벽의 유무...
		
		idx = ( state == R135OUT ) ? 1 : 3;
		next_pos = ( int32 )pos + g_int32move_t[ ( m_dir + idx ) & 0x03 ];
		wallinfo = next_pos < 0 ? OFF : g_u16map[ next_pos ] & 0x0f;
		diag_side_wall = wallinfo & a_u16wall_array[ m_dir ][ 0 ];						//앞벽 + 옆벽의 유무...
	}

#ifdef SMOOTH_TURN_TEST
	diag_front_wall = ON;
	diag_side_wall = ON;
	next_dir = NOT_MATCH;
	POS_CPN_OFF;
#else
	next_dir = g_knownpath[ g_u16path_cnt + 1 ].u8state;
#endif

	while( 1 ) //턴 진입 시점 기다림...
	{
		if( ( in_edge == OFF ) &&
			( ( pturn_table->pin_sen->fp32position < ( float32 )230.0 ) || 
			( ( pturn_table->pin_sen->fp32position < ( float32 )480.0 ) && ( pturn_table->pin_sen->fp32LPF_diff_outdata > ( float32 )0.6 ) ) ) )
			in_edge = ON;
		else if( ( in_edge == ON && pturn_table->pin_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) )
			break;
		else;
	}

	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16in_tick ) ; )
	{
		if( ( int32 )( pturn_table->u16in_tick ) < ( g_int32tick + 20 ) ) //진입 타이밍 어느정도 기다렸다가 보정 끔.
			POS_CPN_OFF;
	}

	g_rmotor.int32accel = pturn_table->int32r_acc;
	g_lmotor.int32accel = pturn_table->int32l_acc;
	g_rmotor.fp32user_vel = pturn_table->fp32r_accvel;
	g_lmotor.fp32user_vel = pturn_table->fp32l_accvel;

	//turn accel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	//turn uniform section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16turn_tick ) ; )
	{
#ifdef SMOOTH_TURN_TEST	
		prs->fp32front_pos[ g_int32tick ] = g_sen[ RFS ].fp32position;
		prs->fp32front_diff[ g_int32tick ] = g_sen[ RFS ].fp32LPF_diff_outdata;

		prs->fp32diag_pos[ g_int32tick ] = g_sen[ RDS ].fp32position;
		prs->fp32diag_diff[ g_int32tick ] = g_sen[ RDS ].fp32LPF_diff_outdata;

		prs->fp32side_pos[ g_int32tick ] = g_sen[ RSS ].fp32position;
		prs->fp32side_diff[ g_int32tick ] = g_sen[ RSS ].fp32LPF_diff_outdata;

		pls->fp32front_pos[ g_int32tick ] = g_sen[ LFS ].fp32position;
		pls->fp32front_diff[ g_int32tick ] = g_sen[ LFS ].fp32LPF_diff_outdata;

		pls->fp32diag_pos[ g_int32tick ] = g_sen[ LDS ].fp32position;
		pls->fp32diag_diff[ g_int32tick ] = g_sen[ LDS ].fp32LPF_diff_outdata;

		pls->fp32side_pos[ g_int32tick ] = g_sen[ LSS ].fp32position;
		pls->fp32side_diff[ g_int32tick ] = g_sen[ LSS ].fp32LPF_diff_outdata;
#endif	
#ifdef SMT_EDGE_TEST
		if( state == R45OUT || state == L45OUT )
		{
			if( diag_front_wall == OFF )
			{
			
#if 1
				if( ( turn_edge == OFF ) &&
					( g_int32tick > ( int32 )( pturn_table->u16edge_tick0 ) - 20 ) &&
					( pturn_table->pedge_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) &&
					( pturn_table->pedge_sen->fp32position > ( float32 )510.0 ) )
				{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = ( int32 )( pturn_table->u16edge_tick0 );
				}
#endif				
			}
			else
			{
			
#if 1
				if( ( turn_edge == OFF ) &&
					( g_int32tick > ( int32 )( pturn_table->u16edge_tick1 ) - 20 ) &&
					( pturn_table->pfwall_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) &&
					( pturn_table->pfwall_sen->fp32position > ( float32 )130.0 ) )
				{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = ( int32 )( pturn_table->u16edge_tick1 );
				}
#endif				
			}
			
		}
		else
		{
			if( diag_front_wall == OFF )
			{
#if 1
				edge_tick = ( diag_side_wall == OFF ) ? ( int32 )( pturn_table->u16edge_tick0 ) : ( int32 )( pturn_table->u16edge_tick1 );

				if( ( turn_edge == OFF ) &&
					( g_int32tick > edge_tick - 20 ) &&
					( pturn_table->pedge_sen->fp32position < ( float32 )512.0 ) )
				{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = edge_tick;
				}
#endif				
			}
			else
			{
#if 1
				edge_tick = ( diag_side_wall == OFF ) ? ( int32 )( pturn_table->u16edge_tick2 ) : ( int32 )( pturn_table->u16edge_tick3 );

				if( ( turn_edge == OFF ) &&
					( g_int32tick > edge_tick - 20 ) &&
					( pturn_table->pfwall_sen->fp32position > ( float32 )248.0 ) && 
					( pturn_table->pfwall_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) )
				{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = edge_tick;
				}
#endif				
			}	

		}
#endif
	}

	g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = pturn_table->fp32ref_vel;

	//turn decel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;

#ifdef SMOOTH_TURN_TEST
	//straight section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16out_tick ) ; );

	vfdprintf("%4u" , temp );	
#else
	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = OFF;

	POS_CPN_ON;
	ANGLE_CPN_ON;
  
	if( next_dir == STRAIGHT || next_dir == BACKTURN )	
		move_to_move( ONE_BLOCK , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , g_int32turn_acc );
	else
	{
		MOTOR_OFF;
		vfdprintf("%uER" , next_dir );		
		while( 1 );
	}
	
#endif	

}

static void _diag_90_continuous_turn( void )
{
	Uint16 state;
	Uint16 m_dir;
	Uint16 pos;
	Uint16 next_dir;

#ifdef SMOOTH_TURN_TEST
	Uint16 temp = 0;

	smt_data_t *prs = &a_rsen;
	smt_data_t *pls = &a_lsen;	
#endif	
	
	Uint16 wallinfo;
	Uint16 front_wall;
	Uint16 side_wall;

	Uint16 in_edge = OFF;
	Uint16 turn_edge = OFF;

	int32 idx;
	int32 edge_tick;

	turn_info_t *pturn_table;

#ifndef SMOOTH_TURN_TEST
	POS_CPN_ON;
	ANGLE_CPN_OFF;

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = ON;
	g_flag.diag_out = ON;
#endif		

	state = g_knownpath[ g_u16path_cnt ].u8state;
	m_dir = g_knownpath[ g_u16path_cnt ].u4m_dir;
	pos = g_knownpath[ g_u16path_cnt ].u8pos;

	pturn_table = ( turn_info_t * )&a_turn_table[ g_int32vel_select ][ state ];

	if( state == RD90 ) //엣지 선택.
	{
		g_flag.diag_out_redge = ON;
		g_flag.diag_out_ledge = OFF;
	}
	else
	{
		g_flag.diag_out_redge = OFF;
		g_flag.diag_out_ledge = ON; 	
	}

	wallinfo = g_u16map[ pos ] & 0x0f;
	front_wall = wallinfo & a_u16wall_array[ m_dir ][ 0 ];  //앞벽의 유무...

	idx = ( state == LD90 ) ? 1 : 2;
	side_wall = wallinfo & a_u16wall_array[ m_dir ][ idx ]; //옆벽의 유무...

#ifdef SMOOTH_TURN_TEST
	front_wall = ON;
	side_wall = ON;
	POS_CPN_OFF;
#else
	next_dir = g_knownpath[ g_u16path_cnt + 1 ].u8state;
#endif

	while( 1 ) //턴 진입 시점 기다림...
	{
		if( ( in_edge == OFF ) &&
			( ( pturn_table->pin_sen->fp32position < ( float32 )230.0 ) || 
			( ( pturn_table->pin_sen->fp32position < ( float32 )480.0 ) && ( pturn_table->pin_sen->fp32LPF_diff_outdata > ( float32 )0.6 ) ) ) )
			in_edge = ON;			
		else if( in_edge == ON && pturn_table->pin_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) //진입 센서가 떨어졌다  올라가는 시점!!
			break;
		else;
	}

	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16in_tick ) ; )
	{
		if( ( int32 )( pturn_table->u16in_tick ) < ( g_int32tick + 10 ) ) //진입 타이밍 어느정도 기다렸다가 보정 끔.
			POS_CPN_OFF;
	}

	g_rmotor.int32accel = pturn_table->int32r_acc;
	g_lmotor.int32accel = pturn_table->int32l_acc;
	g_rmotor.fp32user_vel = pturn_table->fp32r_accvel;
	g_lmotor.fp32user_vel = pturn_table->fp32l_accvel;

	//turn accel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );	

	ANGLE_CPN_ON;
	g_gyro.u32real_val = 0;

	//turn uniform section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16turn_tick ) ; )
	{
#ifdef SMOOTH_TURN_TEST	
		prs->fp32front_pos[ g_int32tick ] = g_sen[ RFS ].fp32position;
		prs->fp32front_diff[ g_int32tick ] = g_sen[ RFS ].fp32LPF_diff_outdata;

		prs->fp32diag_pos[ g_int32tick ] = g_sen[ RDS ].fp32position;
		prs->fp32diag_diff[ g_int32tick ] = g_sen[ RDS ].fp32LPF_diff_outdata;

		prs->fp32side_pos[ g_int32tick ] = g_sen[ RSS ].fp32position;
		prs->fp32side_diff[ g_int32tick ] = g_sen[ RSS ].fp32LPF_diff_outdata;

		pls->fp32front_pos[ g_int32tick ] = g_sen[ LFS ].fp32position;
		pls->fp32front_diff[ g_int32tick ] = g_sen[ LFS ].fp32LPF_diff_outdata;

		pls->fp32diag_pos[ g_int32tick ] = g_sen[ LDS ].fp32position;
		pls->fp32diag_diff[ g_int32tick ] = g_sen[ LDS ].fp32LPF_diff_outdata;

		pls->fp32side_pos[ g_int32tick ] = g_sen[ LSS ].fp32position;
		pls->fp32side_diff[ g_int32tick ] = g_sen[ LSS ].fp32LPF_diff_outdata;
#endif	
#ifdef SMT_EDGE_TEST
		if( front_wall == OFF )
		{
#if 1
			edge_tick = ( side_wall == OFF ) ? ( int32 )( pturn_table->u16edge_tick0 ) : ( int32 )( pturn_table->u16edge_tick1 );

			if( ( turn_edge == OFF ) &&
				( g_int32tick > edge_tick - 10 ) &&
				( pturn_table->pedge_sen->fp32position > ( float32 )510.0 ) &&
				( pturn_table->pedge_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) )
			{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = edge_tick;
			}
#endif			
		}
		else
		{
#if 1
			if( ( turn_edge == OFF ) &&
				( g_int32tick > ( int32 )( pturn_table->u16edge_tick2 ) - 20 ) &&
				( pturn_table->pfwall_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) &&
				( pturn_table->pfwall_sen->fp32position > ( float32 )248.0 ) )
			{
					turn_edge = ON;
					//temp = ( Uint16 )g_int32tick;
					g_int32tick = ( int32 )( pturn_table->u16edge_tick2 );			
			}	
#endif			
		}
#endif
	}

	g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = pturn_table->fp32ref_vel;

	//turn decel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;

#ifdef SMOOTH_TURN_TEST
	//straight section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16out_tick ) ; );

	vfdprintf("%4u" , temp );	
#else
	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = ON;
	g_flag.diag_out = ON;
	g_flag.diag_out_ledge = OFF;
	g_flag.diag_out_redge = OFF;

	POS_CPN_ON;
	ANGLE_CPN_OFF; //자이로 보정 끔 -> 대각 직진 일 경우.

	if( next_dir >= RCBR45OUT && next_dir <= LCBR135OUT ) //다음이 코브라 인 경우 -> 속도 낮춤!!
	{
		g_rmotor.int32accel = g_lmotor.int32accel = 8;

		g_int32turn_vel = SEARCH_S;
		g_int32vel_select = V_650;
		g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = ( float32 )SEARCH_S;
		g_rmotor.fp32decel_vel = g_lmotor.fp32decel_vel = ( float32 )SEARCH_S; 
	}
#endif

}

static void _cobra_45_135_out_turn( void )
{
	Uint16 state;

	Uint16 in_edge = OFF;
	turn_info_t *pcbr_t = NULL;

	turn_info_t *pturn_table;

#ifndef SMOOTH_TURN_TEST
	Uint16 next_dir;
	block_to_block_e block_state[ 4 ] = { TURN_TO_STRAIGHT , TURN_TO_TURN , TURN_TO_BACKTURN , TURN_TO_TURN };

	POS_CPN_ON;
	ANGLE_CPN_OFF;

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = ON;
	g_flag.diag_out = ON;
	g_flag.diag_out_redge = OFF;
	g_flag.diag_out_ledge = OFF;
#endif		

	state = g_knownpath[ g_u16path_cnt ].u8state;
	pturn_table = ( turn_info_t * )&a_turn_table[ 0 ][ state ]; //코브라는 탐색때 밖에 없다!!

	g_int32vel_select = V_650;

	GREEN_ON;

#ifdef SMOOTH_TURN_TEST
	POS_CPN_OFF;
#endif

	while( 1 ) //턴 진입 시점 기다림...
	{
		if( ( in_edge == OFF ) &&
			( ( pturn_table->pin_sen->fp32position < ( float32 )230.0 ) || 
			( ( pturn_table->pin_sen->fp32position < ( float32 )480.0 ) && ( pturn_table->pin_sen->fp32LPF_diff_outdata > ( float32 )0.2 ) ) ) )
			in_edge = ON;			
		else if( in_edge == ON && pturn_table->pin_sen->fp32LPF_diff_outdata < ( float32 )0.0 ) //진입 센서가 떨어졌다  올라가는 시점!!
			break;
		else;
	}
	
	POS_CPN_OFF;

	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16in_tick ) ; );  //진입 구간 기다림.

	g_rmotor.int32accel = pturn_table->int32r_acc;
	g_lmotor.int32accel = pturn_table->int32l_acc;
	g_rmotor.fp32user_vel = pturn_table->fp32r_accvel;
	g_lmotor.fp32user_vel = pturn_table->fp32l_accvel;

	//turn accel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );	

	//turn uniform section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16turn_tick ) ; );

	g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = pturn_table->fp32ref_vel;

	//turn decel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16acc_tick ) ; );

	g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;

	//straight section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pturn_table->u16out_tick ) ; );

	//대각 구간 끝 -> 턴 구간 진입!!
	pcbr_t = ( turn_info_t * )&a_cbrturn_table[ state - 16 ];

	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pcbr_t->u16in_tick ) ; );  //진입 구간 기다림.

	g_rmotor.int32accel = pcbr_t->int32r_acc;
	g_lmotor.int32accel = pcbr_t->int32l_acc;
	g_rmotor.fp32user_vel = pcbr_t->fp32r_accvel;
	g_lmotor.fp32user_vel = pcbr_t->fp32l_accvel;

	//turn accel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pcbr_t->u16acc_tick ) ; );	

	//turn uniform section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pcbr_t->u16turn_tick ) ; );

	g_rmotor.fp32user_vel = g_lmotor.fp32user_vel = pcbr_t->fp32ref_vel;

	//turn decel section.
	for( g_int32tick = 0 ; g_int32tick < ( int32 )( pcbr_t->u16acc_tick ) ; );

	g_rmotor.int32accel = g_lmotor.int32accel = g_int32turn_acc;
	g_int32tick = 0;	

#ifndef SMOOTH_TURN_TEST
	algorithm( wall_check_func( &g_sen[ RSS ] , &g_sen[ LSS ] ) );
	next_dir = g_knownpath[ 0 ].u8state;

	if( next_dir <= 0x03 ) //직진 | R90 | 백턴 | L90
	{
		g_int32block_to_block = ( int32 )block_state[ next_dir ]; //다음 블럭 상황 재 조정.
		
		if( next_dir == STRAIGHT )
			move_to_move( ONE_BLOCK , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , g_int32turn_acc ); //직진일 경우 한블럭 완전 가기.		
	}

	POS_CPN_ON;		 //보정 켬.
	ANGLE_CPN_ON;

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = OFF;	
#endif	

	GREEN_OFF;

	//straight section.
//	for( ; g_int32tick < ( int32 )( pcbr_t->u16out_tick ) ; );

}

static void _diag_block_run( void )
{
	Uint16 block_cnt;
	Uint16 next_dir;

	volatile float32 run_dist;
	volatile mouse_speed_e vel[] = { SEARCH_S , S800 , S1000 , S1200 };

	POS_CPN_ON;
	ANGLE_CPN_ON;

	g_flag.back_turn = OFF;
	g_flag.diff_adj_in = OFF;
	g_flag.diag_run = ON;
	g_flag.diag_out = OFF;
	g_flag.diag_out_ledge = OFF;
	g_flag.diag_out_redge = OFF;

	block_cnt = g_knownpath[ g_u16path_cnt ].u8cnt;
	next_dir = g_knownpath[ g_u16path_cnt + 1 ].u8state;

	if( next_dir >= RCBR45OUT && next_dir <= LCBR135OUT ) //다음이 코브라 턴일 경우 속도 낮춤.
	{
		g_int32turn_vel = SEARCH_S;
		g_int32vel_select = V_650;
	}
	else
		g_int32turn_vel = ( int32 )vel[ g_int32vel_select ];

	if( block_cnt > 1 )
	{
		run_dist = ( DIAG_ONE_BLOCK * ( float32 )block_cnt ) - DIAG_IN_DIST;
		move_to_move( run_dist , g_run.fp32diag_limit_vel , ( float32 )g_int32turn_vel , ( int32 )g_run.fp32diag_limit_acc );

		while( ( g_rmotor.fp32distance_sum < run_dist - ( float32 )15.0 ) &&
			   ( g_lmotor.fp32distance_sum < run_dist - ( float32 )15.0 ) );	 //대각 거리동안 기다림.
	}
	else //한 블럭 대각.
	{
		move_to_move( DIAG_IN_DIST , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , ( int32 )g_run.fp32diag_limit_acc );

		while( g_rmotor.fp32distance_sum < DIAG_IN_DIST && g_lmotor.fp32distance_sum < DIAG_IN_DIST );
	}

	g_flag.diag_run = OFF;
	g_flag.diag_out = ON;

}


