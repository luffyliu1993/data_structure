gcc-6 -g -w -c main.c linked_stack.c ../singly_linked_list/singly_linked_list.c
gcc-6 main.o -o main singly_linked_list.o linked_stack.o
rm *.o
./main