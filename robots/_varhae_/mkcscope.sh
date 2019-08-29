#!/bin/sh
#########################################################################################################
#													#
#	FILE            : mkcscope.sh									#
#	INTRODUCE       : This is script for cscope 							#
#	AUTHOR          : leejaeseong( jslee@mobed.yonsei.ac.kr )					#
#	DATE            : 2015/01/04									#
#													#
#########################################################################################################

rm -rf cscope.out cscope.files

find . \( -name '*.c' -o -name '*.cpp' -o -name '*.cc' -o -name '*.h' -o -name '*.s' -o -name '*.S' \) -print > cscope.files

cscope -i cscope.files
