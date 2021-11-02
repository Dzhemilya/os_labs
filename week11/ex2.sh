#!/bin/bash
gcc ex2.c -o ex2
chmod 755 ex2
cat /proc/cpuinfo | ./ex2 -a ex2.txt
