#!/bin/bash

FTRACE_PATH="/sys/kernel/debug/tracing"

set -e

su -

echo 0 > ${FTRACE_PATH}/tracing_on
sleep 1
echo "tracing off"

echo 0 > ${FTRACE_PATH}/events/enable
sleep 1
echo "events disabled"

echo secondary_start_kernel > ${FTRACE_PATH}/set_ftrace_filter
sleep 1
echo "set_ftrace_filter init"

echo function > ${FTRACE_PATH}/current_tracer
sleep 1
echo "function tracer enabled"

echo dwc_otg_common_irq > ${FTRACE_PATH}/set_ftrace_filter
sleep 1
echo "set_ftrace_filter enabled"

echo 1 > ${FTRACE_PATH}/events/irq/irq_handler_entry/enable
echo 1 > ${FTRACE_PATH}/events/irq/irq_handler_exit/enable
echo "event enabled"

echo 1 > ${FTRACE_PATH}/options/func_stack_trace
echo "function stack trace enabled"

echo 1 > ${FTRACE_PATH}/tracing_on
echo "tracing of"
