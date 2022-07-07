#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdlib.h>

size_t s21_strlen(const char *s);
int s21_strcmp(const char *s1, const char *s2);
char *s21_strcpy(char *s1, const char *s2);
char *s21_strcat(char *s1, const char *s2);
char *s21_strchr(char *s1, const char *s2);
char *s21_strstr(char *str, char *substr);
char *s21_strtok(char *str, const char *delim);

#endif  // SRC_S21_STRING_H_

