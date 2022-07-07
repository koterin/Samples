CC=gcc
CFLAGS=-Wextra -Wall -Werror

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

build: print_module

clean:
	rm -rf *.o *.a *.so
	rm -rf ../build/Quest*

rebuild: clean all

print_module: main_module_entry_point.c print_module.c print_module.h
	$(CC) $(CFLAGS) main_module_entry_point.c print_module.c -DLOG -o ../build/Quest_1

bst_create_test: bst.c bst_create_test.c bst.h
	$(CC) $(CFLAGS) bst.c bst_create_test.c -o ../build/Quest_3

bst_insert_test: bst.c bst_insert_test.c bst.h
	$(CC) $(CFLAGS) bst.c bst_insert_test.c -o ../build/Quest_4

bst_traverse_test: bst.c bst_traverse_test.c bst.h
	$(CC) $(CFLAGS) bst.c bst_traverse_test.c -o ../build/Quest_5

documentation_module: documentation_module.c main_module_entry_point.c documentation_module.h
	$(CC) $(CFLAGS) main_module_entry_point.c documentation_module.c -DDOC -o ../build/Quest_2
