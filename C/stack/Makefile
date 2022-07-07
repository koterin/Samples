CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: build

build: door_struct list_test stack_test

door_struct: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) dmanager_module.c -o ../build/Quest_1

clean:
	rm -rf *.o *.a *.so
	rm -rf ../build/Quest*

list_test: list_test.c list.c list.h
	$(CC) $(CFLAGS) list_test.c list.c -o ../build/Quest_2

stack_test: stack_test.c stack.c stack.h
	$(CC) $(CFLAGS) stack_test.c stack.c -o ../build/Quest_3

rebuild: clean door_struct list_test stack_test
