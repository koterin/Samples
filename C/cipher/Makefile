CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../build && pwd)

all: cipher logging_cipher

cipher: cipher.c
	$(CC) $(CFLAGS) cipher.c -o $(OUT_DIR)/cipher

clean:
	rm -f *.o $(OUT_DIR)/*

rebuild: clean make

logging_cipher: cipher.c log_levels.h logger.c logger.h
	$(CC) $(CFLAGS) cipher.c logger.c -DLOG -o $(OUT_DIR)/logging_cipher
