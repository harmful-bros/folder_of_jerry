#!/bin/bash
##To run this script do
##1. chmod +x usbnet.sh 
##2. ./usbnet.sh 

HOST="wlp3s0"
TARGET="enx0cb2b7d043fe"

iptables --table nat --append POSTROUTING --out-interface ${HOST} -j MASQUERADE
iptables --append FORWARD --in-interface ${HOST} -j ACCEPT
iptables --append FORWARD --in-interface ${TARGET} -j ACCEPT
echo 1 > /proc/sys/net/ipv4/ip_forward
