//###########################################################################
//
// FILE		: search.h
//
// TITLE		: micromouse H2 search header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2012.03.24 $
//###########################################################################

#ifndef __SEARCH_H__
#define __SEARCH_H__

#define BASE_VEL_LIMIT		( float32 )1600.0
#define BASE_ACC_LIMIT		( float32 )3.0

extern int32 race_start_init( int32 *turn_vel , int32 *vel_sel );
extern void known_block_run_mode( Uint16 path_cnt );
extern void search_run_mode( void );

#endif
