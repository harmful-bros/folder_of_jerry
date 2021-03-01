#!/bin/bash

ARCH="arm"
CROSS_COMPILE="arm-linux-gnueabihf-"
CPU_NUM=$(grep -c processor /proc/cpuinfo)

OUT_DIR="${PWD}/out"

MAKE_ARGS=(
	"ARCH=${ARCH}"
	"CROSS_COMPILE=${CROSS_COMPILE}"
	"O=${OUT_DIR}"
	"-j ${CPU_NUM}"
)

BUILD_ARGS=(
	"uImage"
	"dtbs"
	"LOADADDR=0x80008000"
)

set -e
mkdir -p ${OUT_DIR}

if [[ $# -ne 1 ]]
then
	echo "Need to input the parameter"
	echo "You can input the parameters as below."
	echo "distclean, build, module"
	echo "ex) ./docker.sh module"
	exit
fi

case "$1" in
	"distclean")
		make ARCH=${ARCH} distclean
		;;

	"build")
		make ${MAKE_ARGS[@]} bb.org_defconfig
		make ${MAKE_ARGS[@]} ${BUILD_ARGS[@]}
		;;

	"module")
		make ${MAKE_ARGS[@]} INSTALL_MOD_PATH=${OUT_DIR} modules
		make ${MAKE_ARGS[@]} INSTALL_MOD_PATH=${OUT_DIR} modules_install
		;;

	*)
		echo "Invalid Parameter!"
		exit 1
		;;
esac

echo "Done!"
