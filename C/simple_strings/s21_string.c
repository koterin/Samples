#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *s) {
    size_t n = 0;
    while (s[n]) {
        ++n;
    }
    return n;
}

int s21_strcmp(const char *s1, const char *s2) {
    while ((*s1) && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*(const unsigned char *)s1 > *(const unsigned char *)s2)
        - (*(const unsigned char *)s2 > *(const unsigned char *)s1);
}

char *s21_strcpy(char *s1, const char *s2) {
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

char *s21_strtok(char *str, const char *delim) {
    static char *input = NULL;
    if (str != NULL)
        input = str;
    if (input == NULL)
        return NULL;
    char *result = input + s21_strlen(input) + 1;
    int i = 0;
    for (; input[i] != '\0'; i++) {
        if (input[i] != *delim) {
            result[i] = input[i];
        } else {
            result[i] = '\0';
            input = input + i + 1;
            return result;
        }
    }
    result[i] = '\0';
    input = NULL;
    return result;
}

char *s21_strcat(char *s1, const char *s2) {
    char *res = s1;
    while (*res != '\0') {
        res++;
    }
    while (*s2 != '\0') {
        *res = *s2;
        res++;
        s2++;
    }
    *res = '\0';
    res = s1;
    return res;
}

char *s21_strchr(char *s1, const char *s2) {
    int flag = 0;
    while (*s1 != '\0') {
        if (*s1 == *s2) {
            flag = 1;
            break;
        }
        s1++;
    }
    if (flag == 1) {
        return s1;
    } else {
        return NULL;
    }
}

char *s21_strstr(char *str, char *substr) {
    while (*str) {
        char *begin = str;
        char *pattern = substr;
        while (*str && *pattern && *str == *pattern) {
            str++;
            pattern++;
        }
        if (!*pattern) {
            return begin;
        }
        str = begin + 1;
    }
    return NULL;
}




