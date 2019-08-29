# makefile for TMS320F28x
# By RealSYS 2003/9/18
#
#########################################################################################################
#                                                                                                       #
#       FILE            : makefile( main )								#
#       INTRODUCE       : makefile for ti DSP tms320f2833x compile					#
#       AUTHOR          : Hertz9th leejaeseong                                                          #
#       DATE            : 2011/09/19                                                                    #
#       BRIEF           : compiled using a recursive make.                                              #
#                         depends on the makefile in each folder.					#
#                                                                                                       #
#########################################################################################################

# :: source directory ::
SRC_DIR = $(ROOT_DIR)/DSP2833x $(ROOT_DIR)/asm 					\
	$(ROOT_DIR)/extremerun $(ROOT_DIR)/fastrun $(ROOT_DIR)/search 		\
	$(ROOT_DIR)/motor $(ROOT_DIR)/sensor $(ROOT_DIR)/rom			\
	$(ROOT_DIR)/menu $(ROOT_DIR)/vfd $(ROOT_DIR)/serial $(ROOT_DIR)/main   

# :: include directory ::
INCLUDE = $(ROOT_DIR)/include

# :: user library path ::
USE_LIB = $(ROOT_DIR)/lib

# :: link command file ::
CMDFILE = $(MAKE_DIR)/user28335_ctml.cmd

# :: object directory ::
export OBJ_DIR = $(ROOT_DIR)/object

# :: compiler path set. :: 
export CC 	= $(COM_DIR)/cl2000
export ASM	= $(COM_DIR)/asm2000
export LNK	= $(COM_DIR)/lnk2000

# :: C compiler option set. ::
export CFLAGS = -g -pdsw225 -pm -op0 -o3 -fr$(OBJ_DIR) -d"_DEBUG" -d"LARGE_MODEL" -mf -ml -v28 -i$(INCLUDE) --float_support=fpu32

# :: assembler option set. ::
export ASM_OPT = -v28


# :: compile call & linking ::
all : compile
	$(LNK) -c -farheap0x1 -heap1 -o $(TARGET).out -m $(TARGET).map $(wildcard $(OBJ_DIR)/*.obj) $(CMDFILE) -stack0x700 -w -x \
	-l$(USE_LIB)/rts2800.lib -l$(USE_LIB)/rts2800_ml.lib -l$(USE_LIB)/rts2800_fpu32.lib -l$(USE_LIB)/IQmath_fpu32.lib

compile : 
	@for dir in $(SRC_DIR) ; do \
	make -C $$dir || exit $? ; \
	done

clean :
	rm -rf $(OBJ_DIR)/*.obj *.hex *.map *.obj

