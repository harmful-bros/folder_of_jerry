# makefile for DSP28x
# By RealSYS	2003/9/18

#:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#:  modified. 2008-9-26    by  Jeon you hoon (Edited by Hertz9th leejaeseong 11/04/16)
#:   ;Fix damn all..  
#:   ;Compile only NEW *.c and *.h files.
#:   ;depend on build_Bat.bat
#:
#:   ;File name : Makefile                ;tms320f28335
#:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#.SILENT:

# :: Target name ::  It must match in build_bat
TARGET = a_varhae_monitor

# :: Source Directory ::
SRC_DIR = D:\work\_varhae_\monitor_base

# :: Object Directory ::
OBJ_DIR = $(SRC_DIR)\main


# :: Compiler Directory ::
COM_DIR = $(SRC_DIR)\cgtools\bin

# :: Include Directory ::
INCLUDE = $(SRC_DIR)\include

# :: User path ::
USR_LIB = $(SRC_DIR)\lib

# :: Sources ::
CSRC = 	DSP2833x_Adc.c DSP2833x_EPwm.c DSP2833x_EQep.c DSP2833x_CpuTimers.c DSP2833x_DefaultIsr.c	\
		DSP2833x_GlobalVariableDefs.c DSP2833x_Gpio.c DSP2833x_MemCopy.c DSP2833x_PieCtrl.c			\
		DSP2833x_PieVect.c DSP2833x_Sci.c DSP2833x_Spi.c DSP2833x_SysCtrl.c DSP2833x_Xintf.c			\
		Main.c VFD.c Serial.c Flash.c
		

# :: ASM source files ::
ASRC = DSP2833x_CodeStartBranch.asm Example_Flash2833x_CsmKeys.asm DSP2833x_usDelay.asm DSP2833x_ADC_cal.asm \

# :: Link Command ::
CMDFILE	= monitor28335_ctml.cmd

CC      = $(COM_DIR)\cl2000.exe
ASM     = $(COM_DIR)\asm2000.exe
LNK     = $(COM_DIR)\lnk2000.exe

#----- C compiler option -----
CFLAGS = -pdr -pdsw225 -fr"$(OBJ_DIR)" -i$(INCLUDE) -d"_DEBUG" -d"LARGE_MODEL" -ml -v28 --float_support=fpu32

#----- Assembler option -----
ASM_OPT = -v28 

# compile option
%.obj : %.c
	$(CC) $(CFLAGS) $<
	
# 2010.02.12 	 
# 어셈블러 규칙이 따로 정해 지 않음...
# 따라서 C 컴파일러 규칙을 따르므로 ASM 옵션을 주면 안됨( 335 스펙 )
%.obj : %.asm
	$(CC) $(CFLAGS) $<
#	$(ASM) $(ASM_OPT) $<  //주석 풀면 컴파일 에러...

OBJS = $(CSRC:.c=.obj) $(ASRC:.asm=.obj)

$(TARGET).out: $(OBJS) 
	$(LNK) -c -farheap0x1 -heap1 -o $(TARGET).out -m $(TARGET).map $(OBJS) $(CMDFILE) -stack0x300 -w -x -l$(USR_LIB)\rts2800_fpu32.lib -l$(USR_LIB)\Flash28335_API_V210.lib


# Default target.
all: $(TARGET).out

# Target: clean project.
clean: 
	del *.out
	del *.map
	del *.obj

