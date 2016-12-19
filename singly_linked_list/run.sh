#!/bin/bash

gcc -w -g singly_linked_list.c main.c -c
gcc -w main.o singly_linked_list.o -o main
rm -rf *.o
valgrind --tool=memcheck ./main
