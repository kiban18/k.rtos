#!/bin/bash

# Signal 2 is Ctrl+C
trap "echo Ctrl+C was pressed" 2
IMAGE=$1
if [[ "${IMAGE}" == "" ]]; then
	echo "Usage : $0 <IMAGE_NAME>"
	echo "    ex) $0 zImage"
	exit 1
fi

QEMU=qemu-system-arm
MACHINE="-M versatilepb"
MEMORY="-m 128M"
DISPLAY=-nographic
#DEBUG="-s -S"
KERNEL="-kernel ${IMAGE}"

${QEMU} ${MACHINE} ${MEMORY} ${DISPLAY} ${DEBUG} ${KERNEL}
