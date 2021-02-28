#!/bin/bash

ARCH="arm"
CROSS_COMPILE="arm-linux-gnueabihf-"
CPU_NUM=$(grep -c processor /proc/cpuinfo)

OUT_DIR="${PWD}/out"

set -e

mkdir -p ${OUT_DIR}

# distclean
make ARCH=${ARCH} distclean

# defconfig
make \
	ARCH=${ARCH} \
	KBUILD_OUTPUT=${OUT_DIR} \
	bb.org_defconfig

# build
make \
	ARCH=${ARCH} \
	CROSS_COMPILE=${CROSS_COMPILE} \
	KBUILD_OUTPUT=${OUT_DIR} \
	uImage \
	dtbs \
	LOADADDR=0x80008000 \
	-j ${CPU_NUM}

# geneator dtb for module
make \
	-C ${OUT_DIR} \
	ARCH=${ARCH} \
	CROSS_COMPILE=${CROSS_COMPILE} \
	INSTALL_MOD_PATH=${OUT_DIR} \
	modules \
	-j ${CPU_NUM}

make \
	-C ${OUT_DIR} \
	ARCH=${ARCH} \
	INSTALL_MOD_PATH=${OUT_DIR} \
	modules_install

echo "Done!"
