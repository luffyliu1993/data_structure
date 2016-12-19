#!/bin/bash

gcc -g -w -c main.c
gcc main.o -o main
rm *.o
valgrind --tool=memcheck ./main
