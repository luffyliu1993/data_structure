#!/bin/bash

gcc -w -g main.c -c
gcc -w main.o -o main
rm -rf *.o
valgrind --tool=memcheck ./main
