//###########################################################################
//
// FILE		: algo.h
//
// TITLE		: micromouse H2 algorithm header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2012.03.19 $
//###########################################################################

#ifndef __ALGO_H__
#define __ALGO_H__

#define DIR_N		0x01
#define DIR_E		0x02
#define DIR_S		0x04
#define DIR_W		0x08

#define M_N			0
#define M_E			1
#define M_S			2
#define M_W			3

#define F			0
#define R			1
#define B			2
#define L			3

#define GO_GOAL		0
#define GO_START	1

typedef volatile enum turn_class
{
	STRAIGHT ,		// FF		0
	R90 ,			// FRF		1
	BACKTURN ,		// B			2
	L90 ,			// FLF		3
	R180 ,			// FRRF		4
	L180 ,			// FLLF		5
	R135IN ,		// FRR		6
	L135IN ,		// FLL		7
	R45IN ,			// FR		8
	L45IN ,			// FL		9
	R135OUT ,		// RRF		a
	L135OUT ,		// LLF		b
	R45OUT ,		// RF		c
	L45OUT ,		// LF		d
	RD90 ,			// RR		e
	LD90 ,			// LL		f
	RCBR45OUT ,		// R			10
	LCBR45OUT ,		// L			11
	RCBR135OUT ,	// RR		12
	LCBR135OUT ,	// LL		13
	RDRUN ,			// RL		14
	LDRUN ,			// LR		15
	NOT_MATCH
	
}turn_class_e;

typedef volatile enum mouse_run_type
{
	SEARCH , 
	KNOWN_GOAL , 
	KNOWN_START , 
	FASTRUN

}mouse_run_type_e;

typedef volatile enum mouse_state
{
	TURN = 1 , 
	F_STRAIGHT , 
	DIAGONAL , 

	TURN_WEIGHT = 28 , 
	LAST_PATH = 77
	
}mouse_state_e;

extern void algorithm_vari_init( void );
extern void algorithm( Uint16 wallinfo );
extern void fastrun_path_make_func( void );

extern void known_path_printf( void );

#endif

