#include <stdio.h>
#include <stdarg.h>
#include "print_module.h"
#include "documentation_module.h"

void output(int mask, ...);

int main() {
    #ifdef LOG
    print_log(print_char, Module_load_success_message);
    #endif

    #ifdef DOC
    int availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    // Output availability for each document....
    output(availability_mask, Documents);
    #endif

    return 0;
}

void output(int mask, ...) {
    int i = 0;
    va_list args;
    va_start(args, mask);
    while (i < Documents_count) {
        printf("[%s : ", va_arg(args, char *));
        if ((mask >> (Documents_count - i - 1)) & 1) {
            if (i == Documents_count - 1) {
                printf("available]");
            } else {
                printf("available]\n");
            }
        } else {
            if (i == Documents_count - 1) {
                printf("unavailable]");
            } else {
                printf("unavailable]\n");
            }
        }
        i++;
    }
    va_end(args);
}
