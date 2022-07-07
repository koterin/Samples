#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "logger.h"
#include "log_levels.h"
#include <time.h>

FILE *log_init(char *filename) {
    FILE *ptr = fopen(filename, "a");
    return ptr;
}

char *get_log_enum(log_level level) {
    if (level == debug) {
        return "[DEBUG]";
    }
    if (level == trace) {
        return "[TRACE]";
    }
    if (level == info) {
        return "[INFO]";
    }
    if (level == warning) {
        return "[WARNING]";
    }
    if (level == error) {
        return "[ERROR]";
    }
    return "nan";
}

int logcat(FILE *log_file, char *message, log_level level) {
    // LOGGING LEVEL
    char *level_string = get_log_enum(level);
    while (strlen(level_string)) {
        fprintf(log_file, "%c", *level_string);
        level_string++;
    }

    int i  = 0;
    // TIME
    char buffer[10];
    time_t now = time(NULL);
    struct tm *ptm = localtime(&now);
    strftime(buffer, 10, " %H:%M:%S ", ptm);

    while (i < 10) {
        fprintf(log_file, "%c", buffer[i]);
        i++;
    }

    // LOGGING MESSAGE
    while (strlen(message)) {
        fprintf(log_file, "%c", *message);
        message++;
    }
    fprintf(log_file, "%c", '\n');
    return 1;
}

int log_close(FILE *log_file) {
    fclose(log_file);
    return 1;
}
