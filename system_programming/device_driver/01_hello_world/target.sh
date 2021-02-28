#!/bin/bash

function build()
{
	if [[ "$1" == "" ]]
	then
		return
	fi

	sudo make \
		ARCH=${ARCH} \
		CROSS_COMPILE=${CROSS_COMPILE} \
		-C ${KERNEL_DIR} \
		M=${PWD} \
		$1
}

ARCH="arm"
CROSS_COMPILE="arm-linux-gnueabihf-"
KERNEL_DIR="/home/jerrylee/code_test/tools/ldd/source/linux_bbb_4.14/out"

KO_FILE="hello_world.ko"
TARGET_IP="192.168.7.2"

set -e

build modules
if [[ ! -f "${KO_FILE}" ]]
then
	echo "[ERR] Failed to compile the module!"
	exit 1
fi

sshpass -p "temppwd" scp ${KO_FILE} debian@${TARGET_IP}:~/
sshpass -p "temppwd" ssh ${TARGET_IP} -l debian <<\EOF
echo "temppwd" | sudo -S insmod hello_world.ko
dmesg | tail
echo
echo "temppwd" | sudo -S rmmod hello_world
dmesg | tail
echo
EOF

build clean
echo "Done"
