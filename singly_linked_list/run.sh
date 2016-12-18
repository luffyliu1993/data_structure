#!/bin/bash

gcc-6 -w -g singly_linked_list.c main.c -c
gcc-6 -w main.o singly_linked_list.o -o main
rm -rf *.o
./main
