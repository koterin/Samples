#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "logger.h"

int getmode(int *mode);
int menu();
void input_file(char *filename);
int file_reader(FILE *ptr);
int open_read_file(char *filename);
int input_string(char *input_str);
int open_append_file(char *filename, char *input_str, int len);
int input_string_append(char *filename);
void output_file(FILE *ptr);
void caesar(int shift, char *str);
void print_directory();
void clear_h_files();
void encrypt_files(int shift);
char *get_dir();

int main() {
    if (menu() == 0) {
        printf("n/a");
        return 1;
    }
    return 0;
}

int file_reader(FILE *ptr) {
    int c;
    if ((c = getc(ptr)) == EOF) {
        return 0;
    } else {
        putchar(c);
    }
    while ((c = fgetc(ptr)) != EOF) {
        putchar(c);
    }
    printf("\n");
    return 1;
}

void input_file(char *filename) {
    int i = 0;
    while (1) {
        int c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        } else {
            *(filename + i) = c;
            i++;
        }
    }
    return;
}

int input_string(char *input_str) {
    int i = 0;
    while (1) {
        int c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        } else {
            *(input_str + i) = c;
            i++;
        }
    }
    return i;
}

int open_append_file(char *filename, char *input_str, int len) {
    FILE *ptr = fopen(filename, "a");

    if (ptr == NULL) {
        return 0;
    } else {
        int i = 0;
        while (i < len) {
            fprintf(ptr, "%c", *input_str);
            input_str++;
            i++;
        }
        fclose(ptr);
    }
    return 1;
}

int open_read_file(char *filename) {
    FILE *ptr = fopen(filename, "r");
    if (ptr == NULL) {
        return 0;
    } else {
        if (file_reader(ptr) == 0) {
            fclose(ptr);
            return 0;
        } else {
            fclose(ptr);
            return 1;
        }
    }
    return 1;
}

int getmode(int *mode) {
    int c = getchar();
    if (c >= '0' && c <= '9') {
        *mode = c - '0';
        if ((getchar()) == '\n') {
            return 1;
        }
    } else if (c == '-') {
        c = getchar();
        if (c == '1') {
            *mode = -1;
        }
    } else {
        while (1) {
            c = getchar();
            if (c == '\n' || c == EOF) {
                break;
            }
        }
        printf("n/a\n");
        return 0;
    }
    return 1;
}

char *get_dir() {
    char *str = NULL;
    char c;
    int counter = 1;
    str = (char*) malloc(sizeof(char));
    scanf("%c", &c);
    while ((c != '\n') && (c != ' ')) {
        str[counter - 1] = c;
        counter += 1;
        char *tmp = realloc(str, counter * sizeof(char));
        if (tmp != NULL)
            str = tmp;
        scanf("%c", &c);
    }
    str[counter - 1] = '\0';
    return(str);
}

void encrypt_files(int shift) {
    DIR *d;
    d = opendir("./ai_modules/");
    if (d) {
        struct dirent *dir;
        while ((dir = readdir(d)) != NULL) {
            char *full_path = calloc(150, sizeof(char));
            strcpy(full_path, "ai_modules/");
            strcat(full_path, dir->d_name);
            if (strstr(full_path, ".c") != NULL) {
                FILE *ptr = fopen(full_path, "r");
                char *file_text = calloc(1000, sizeof(char));
                fread(file_text, 1, 1000, ptr);
                caesar(shift, file_text);
                fclose(ptr);

                ptr = fopen(full_path, "w");
                fputs(file_text, ptr);

                fclose(ptr);
                free(file_text);
            }
            free(full_path);
        }
        closedir(d);
    }
}

void clear_h_files() {
    DIR *d;
    d = opendir("./ai_modules/");
    if (d) {
        struct dirent *dir;
        while ((dir = readdir(d)) != NULL) {
            char *full_path = calloc(150, sizeof(char));
            strcpy(full_path, "ai_modules/");
            strcat(full_path, dir->d_name);
            if (strstr(full_path, ".h") != NULL) {
                FILE *ptr = fopen(full_path, "w");
                fclose(ptr);
            }
            free(full_path);
        }
        closedir(d);
    }
}

int menu() {
    int mode;
    int len;
    int shift;
    char err;

    #ifdef LOG
    FILE *log = log_init("logs.txt");
    #endif

    char *filename = calloc(150, sizeof(char));
    char *input_str = calloc(150, sizeof(char));

    while (1) {
        if (getmode(&mode) == 0) {
            continue;
        }
        if (mode == 1) {
            #ifdef LOG
            logcat(log, "User chose menu option 1", info);
            #endif
            input_file(filename);
            if (open_read_file(filename) == 0) {
                #ifdef LOG
                logcat(log, "Couldn't read the specified file", error);
                #endif
                free(filename);
                filename = calloc(150, sizeof(char));
                printf("n/a\n");
            }
        } else if (mode == 2) {
            #ifdef LOG
            logcat(log, "User chose menu option 2", info);
            #endif
            if (filename == NULL) {
                #ifdef LOG
                logcat(log, "The specified file does not exist", error);
                #endif
                printf("n/a\n");
                continue;
            }
            len = input_string(input_str);
            open_append_file(filename, input_str, len);
            if (open_read_file(filename) == 0) {
                #ifdef LOG
                logcat(log, "Couldn't write to a file", error);
                #endif
                printf("n/a\n");
            }
        } else if (mode == 3) {
            #ifdef LOG
            logcat(log, "User chose menu option 3", info);
            #endif
            if (scanf("%d%c", &shift, &err) != 2) {
                #ifdef LOG
                logcat(log, "Incorrect cipher shift value", warning);
                #endif
                printf("n/a\n");
                continue;
            }
            if (err != ' ' && err != '\n') {
                printf("n/a\n");
                continue;
            }
            char *directory = get_dir();
            clear_h_files();
            encrypt_files(shift);
            free(directory);
        } else if (mode == - 1) {
            #ifdef LOG
            logcat(log, "Exit the program", debug);
            #endif
            free(filename);
            free(input_str);
            #ifdef LOG
            log_close(log);
            #endif
            return 1;
        } else {
            printf("n/a\n");
            scanf("%*[^\n]");
            continue;
        }
    }
    #ifdef LOG
    log_close(log);
    #endif
    free(filename);
    free(input_str);
    return 1;
}

void caesar(int shift, char *str) {
    int i;
    shift = shift % 26;
    if (shift < 0) {
        shift = shift + 26;
    }
    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] + shift;
            if (str[i] > 'z') {
                str[i] = str[i] - 'z' + 'a' - 1;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + shift;
            if (str[i] > 'Z') {
                str[i] = str[i] - 'Z' + 'A' - 1;
            }
        }
    }
    return;
}
