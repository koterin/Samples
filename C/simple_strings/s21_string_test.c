#include "s21_string.h"
#include <stdio.h>
#define NMAX 100

void s21_strlen_test(const char *s, size_t len);
void s21_strcmp_test(const char *s1, const char *s2, int res);
void s21_strcpy_test(char *s1, const char *s2);
void s21_strcat_test(char *s1, const char *s2, const char *s3);
void s21_strchr_test(char *string1, const char *char2, char *ptr);
void s21_strstr_test(char *str, char *substr, char *ptr);
void s21_strtok_test(char *str, const char *delim, int token);

void string_output(const char *s);
void pointer_output(char *ptr);
void test_strlen();
void test_strcmp();
void test_strcpy();
void test_strcat();
void test_strchr();
void test_strstr();
void test_strtok();

// TEST DATA
// STRLEN
const char *test_string1 = "test";
size_t test_len1 = 4;
const char *test_string2 = "/ /";
size_t test_len2 = 3;
const char *test_string3 = "";
size_t test_len3 = 0;
const char *test_string4 = "\n";
size_t test_len4 = 1;
const char *test_string5 = "\0";
size_t test_len5 = 0;

// STRCMP
const char *test_string6 = "testing";
const char *test_string7 = "testing";
int result6 = 1;
int result7 = -1;
int result8 = 0;

// STRCPY
char blank_string[NMAX];

// STRCAT
char test_string8[NMAX] = "cool";
char *res_string8 = "cooltest";
char test_string9[NMAX] = "111111.1";
char *res_string9 = "111111.1/ /";
char test_string10[NMAX] = "";

// STRCHR
const char *test_char1 = "o";
char *test_ptr1 = test_string8 + 1;
char test_string11[NMAX] = "./49hgyt3";
const char *test_char2 = "9";
char *test_ptr2 = test_string11 + 3;
char *test_ptr3 = NULL;

// STRSTR
char test_string12[NMAX] = "supertetesting";
char *test_ptr4 = test_string12 + 7;
char test_string13[NMAX] = "fisting/ass/";
char test_substr1[NMAX] = "/ass";
char *test_ptr5 = test_string13 + 7;
char test_string14[NMAX] = "three111Hundred111Bucks";
char test_substr2[NMAX] = "1113";
char *test_ptr6 = NULL;


// STRTOK
char test_string15[NMAX] = "Wake Up Neo";
char test_delim1[NMAX] = " ";
int test_token1 = 3;
char test_string16[NMAX] = "/-kill-4me-please3-.";
char test_delim2[NMAX] = "-";
int test_token2 = 5;
char test_string17[NMAX] = "who/is/the/king/of/pirates.../LuFfi";
char test_delim3[NMAX] = "/";
int test_token3 = 7;


int main() {
    #ifdef STRLEN
    test_strlen();
    #endif

    #ifdef  STRCMP
    test_strcmp();
    #endif

    #ifdef STRCPY
    test_strcpy();
    #endif

    #ifdef STRCAT
    test_strcat();
    #endif

    #ifdef STRCHR
    test_strchr();
    #endif

    #ifdef STRSTR
    test_strstr();
    #endif

    #ifdef STRTOK
    test_strtok();
    #endif

    return 0;
}

void test_strtok() {
    s21_strtok_test(test_string15, test_delim1, test_token1);
    printf("\n");
    s21_strtok_test(test_string16, test_delim2, test_token2);
    printf("\n");
    s21_strtok_test(test_string17, test_delim3, test_token3);
}

void test_strstr() {
    s21_strstr_test(test_string12, (char *)test_string1, test_ptr4);
    printf("\n");
    s21_strstr_test(test_string13, test_substr1, test_ptr5);
    printf("\n");
    s21_strstr_test(test_string14, test_substr2, test_ptr6);
}

void test_strchr() {
    s21_strchr_test(test_string8, test_char1, test_ptr1);
    printf("\n");
    s21_strchr_test(test_string11, test_char2, test_ptr2);
    printf("\n");
    s21_strchr_test(test_string11, test_char1, test_ptr3);
}

void test_strcat() {
    s21_strcat_test(test_string8, test_string1, res_string8);
    printf("\n");
    s21_strcat_test(test_string10, test_string1, test_string1);
    printf("\n");
    s21_strcat_test(test_string9, test_string2, res_string9);
}

void test_strcpy() {
    s21_strcpy_test(blank_string, test_string1);
    printf("\n");
    s21_strcpy_test(blank_string, test_string2);
    printf("\n");
    s21_strcpy_test(blank_string, test_string3);
    printf("\n");
    s21_strcpy_test(blank_string, test_string5);
}

void test_strlen() {
    s21_strlen_test(test_string1, test_len1);
    printf("\n");
    s21_strlen_test(test_string2, test_len2);
    printf("\n");
    s21_strlen_test(test_string3, test_len3);
    printf("\n");
    s21_strlen_test(test_string4, test_len4);
    printf("\n");
    s21_strlen_test(test_string5, test_len5);
}

void test_strcmp() {
    s21_strcmp_test(test_string6, test_string1, result6);
    printf("\n");
    s21_strcmp_test(test_string2, test_string1, result7);
    printf("\n");
    s21_strcmp_test(test_string6, test_string7, result8);
}

void s21_strlen_test(const char *s, size_t len) {
    printf("INPUT: ");
    string_output(s);

    printf("\nOUTPUT: ");
    size_t final = s21_strlen(s);
    printf("%zu", final);

    printf("\nRESULT: ");
    if (final != len) {
        printf("FAIL");
    } else {
        printf("SUCCESS");
    }
    return;
}

void s21_strcmp_test(const char *s1, const char *s2, int res) {
    printf("INPUT: ");
    string_output(s1);
    printf(" ");
    string_output(s2);

    printf("\nOUTPUT: ");
    int final = s21_strcmp(s1, s2);
    printf("%d", final);
    printf("\nRESULT: ");

    if ((final > 0 && res > 0)
           || (final < 0 && res < 0) || (final == 0 && res == 0)) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    return;
}

void string_output(const char *s) {
    int i = 0;
    while (s[i]) {
        printf("%c", s[i]);
        i++;
    }
}

void s21_strcpy_test(char *s1, const char *s2) {
    printf("INPUT: ");
    string_output(s2);
    printf(" ");

    printf("\nOUTPUT: ");
    char *final = s21_strcpy(s1, s2);
    string_output(final);
    printf("\nRESULT: ");

    int flag = 1;
    while (*final) {
        if (*final != *s2) {
            flag = 0;
            break;
        }
        final++;
        s2++;
    }
    if (flag == 1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    return;
}

void s21_strcat_test(char *s1, const char *s2, const char *s3) {
    printf("INPUT: ");
    string_output(s1);
    printf(" ");
    string_output(s2);

    printf("\nOUTPUT: ");
    char *final = s21_strcat(s1, s2);
    string_output(final);
    printf("\nRESULT: ");

    int flag = 1;
    while (*final) {
        if (*final != *s3) {
            flag = 0;
            break;
        }
        final++;
        s3++;
    }
    if (flag == 1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    return;
}

void s21_strchr_test(char *string1, const char *char2, char *ptr) {
    printf("INPUT: ");
    string_output(string1);
    printf(" ");
    string_output(char2);

    printf("\nOUTPUT: ");
    char *final = s21_strchr(string1, char2);
    pointer_output(final);
    printf("\nRESULT: ");

    if (final == ptr) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    return;
}

void pointer_output(char *ptr) {
    printf("%p", ptr);
}

void s21_strstr_test(char *str, char *substr, char *ptr) {
    printf("INPUT: ");
    string_output(str);
    printf(" ");
    string_output(substr);

    printf("\nOUTPUT: ");
    char *final = s21_strstr(str, substr);
    pointer_output(final);
    printf("\nRESULT: ");

    if (final == ptr) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    return;
}

void s21_strtok_test(char *str, const char *delim, int token) {
    printf("INPUT: ");
    string_output(str);
    printf(" ");
    string_output(delim);

    printf("\nOUTPUT: ");
    char *final = NULL;
    final = s21_strtok(str, delim);
    int flag = 0;
    while (final != NULL) {
        string_output(final);
        printf(" | ");
        final = s21_strtok(NULL, delim);
        flag++;
    }
    printf("\nRESULT: ");
    final = NULL;
    if (flag == token) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    return;
}
