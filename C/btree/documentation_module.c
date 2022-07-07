#include <stdarg.h>
#include "documentation_module.h"

int validate(char *data) {
    int validation_result = !s21_strcmp(data, Available_document);
    return validation_result;
}

int s21_strcmp(const char *s1, const char *s2) {
    while ((*s1) && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*(const unsigned char *)s1 > *(const unsigned char *)s2)
        - (*(const unsigned char *)s2 > *(const unsigned char *)s1);
}

int check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list args;
    int i = 0;
    int res = 0;

    va_start(args, document_count);
    while (i < document_count) {
        res = res | (validate(va_arg(args, char *)) << (document_count - i - 1));
        i++;
    }
    va_end(args);
    return res;
}
