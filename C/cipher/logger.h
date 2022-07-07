#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_

#include <stdlib.h>
#include <stdio.h>
#include "logger.h"
#include "log_levels.h"

FILE *log_init(char *filename);
int logcat(FILE *log_file, char *message, log_level level);
int log_close(FILE *log_file);
char *get_log_enum(log_level level);

#endif  // SRC_LOGGER_H_
