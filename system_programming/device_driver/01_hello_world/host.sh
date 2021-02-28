#!/bin/bash

function check_dmesg()
{
	echo
	dmesg | tail
	echo
}

TARGET="hello_world.ko"

KERNEL_VER=$(uname -r)
make -C /lib/modules/${KERNEL_VER}/build M=${PWD} modules
if [[ ! -f "${TARGET}" ]]
then
	echo "[ERR] Failed to compile the module!"
	exit 1
fi

sudo insmod ${TARGET}
check_dmesg
sudo rmmod ${TARGET}
check_dmesg

make -C /lib/modules/${KERNEL_VER}/build M=${PWD} clean
