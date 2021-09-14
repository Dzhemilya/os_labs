#!/bin/bash
for i in {1..10}; do ./ex1; done

# running the program 10 times we create 10 processes which forks. That shows that the parent processes have differents PID numbers while child processes always have 0 PID number
