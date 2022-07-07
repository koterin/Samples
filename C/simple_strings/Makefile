CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: build

build: strlen_tests

strlen_tests: s21_string.c s21_string.h s21_string_test.c
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRLEN -o ../build/Quest_1

s21_string: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o

s21_string_test: s21_string_test.c
	$(CC) $(CFLAGS) -c s21_string_test.c -o s21_string_test.o

clean:
	rm -rf *.o *.a *.so
	rm -rf ../build/Quest*

rebuild: clean build

strcmp_tests: s21_string.c s21_string_test.c s21_string.h
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRCMP -o ../build/Quest_2

strcpy_tests: s21_string.c s21_string.h s21_string_test.c 
	$(CC)  s21_string_test.c s21_string.c -DSTRCPY  -o ../build/Quest_3

strcat_tests: s21_string.c s21_string.h s21_string_test.c
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRCAT -o ../build/Quest_4

strchr_tests: s21_string.c s21_string.h s21_string_test.c
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRCHR -o ../build/Quest_5

strstr_tests: s21_string.c s21_string.h s21_string_test.c
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRSTR -o ../build/Quest_6

strtok_tests: s21_string.c s21_string.h s21_string_test.c
	$(CC) $(CFLAGS) s21_string_test.c s21_string.c -DSTRTOK -o ../build/Quest_7
