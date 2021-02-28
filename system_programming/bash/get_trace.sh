#!/bin/bash

FTRACE_PATH="/sys/kernel/debug/tracing"

set -e

echo 0 > ${FTRACE_PATH}/tracing_on
echo "tracing off"

sleep 3

cp ${FTRACE_PATH}/trace
