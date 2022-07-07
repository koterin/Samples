#include <stdio.h>
#include <time.h>
#include "print_module.h"

char print_char(char ch) {
    return putchar(ch);
}

void print_log(char (*print)(char), char *message) {
    time_t now = time(NULL);
    struct tm *ptm = localtime(&now);
    char *ch = Log_prefix;
    char buffer[10];

    while (*ch != '\0') {
        print(*ch);
        ch++;
    }

    strftime(buffer, 10, " %H:%M:%S ", ptm);

    int i = 0;
    while (i < 10) {
        print(buffer[i]);
        i++;
    }
    while (*message != '\0') {
        print(*message);
        message++;
    }
}
