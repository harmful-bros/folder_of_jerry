#########################################################################################################
#													#
#	FILE            : run.sh									#
#	INTRODUCE       : ti DSP tms320f2833x compile script.						#
#	AUTHOR          : Hertz9th leejaeseong								#
#	DATE            : 2011/09/19									#
#	BRIEF		: remove all bad messages.							#
#			  If an error occurs, delete the *.hex file					#
#													#
#########################################################################################################

echo;

export TARGET=a_varhae
export ROOT_DIR=/Users/leejaeseong/ti_dsp/_varhae_for_linux

export MAKE_DIR=$ROOT_DIR/make
export COM_DIR=$ROOT_DIR/cgtools/bin

printf '\n@@ *.obj & target file delete. @@\n\n'

make clean -C $MAKE_DIR

printf '\n@@ compile start. @@\n\n'

make -C $MAKE_DIR

if [ -e $MAKE_DIR/$TARGET.out ]; then

	echo;

	$COM_DIR/hex2000 $MAKE_DIR/$TARGET.out -o $MAKE_DIR/$TARGET.hex -map $MAKE_DIR/$TARGET.map -i -datawidth 16 -memwidth 16 -romwidth 16

	if [ -e $MAKE_DIR/$TARGET.hex ]; then
		rm $MAKE_DIR/$TARGET.out
	fi

	printf '\n@@ compile success!! @@\n\n'

	printf '\n@@ 09 ~ 11 DCtracer _varhae_ source compile complete. @@\n\n'
	printf '\nthanks to MAZE14th Ahn Hee-Jin & Hertz9th leejaeseong.\n\n'
else
	if [ -e $MAKE_DIR/$TARGET.hex ]; then
		rm $MAKE_DIR/$TARGET.hex
	fi

	printf '\n@@ !!!! compile failed !!!! @@\n\n'
fi

