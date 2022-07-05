// Copyright 2022 laynadre

#include <stdio.h>

int main() {
    char ai_name[] = "";
    scanf("%s", ai_name);
    if (ai_name[0] == '\0') {
        printf("n/a");
        return 1;
    } else {
        printf("Hello, %s!", ai_name);
        return 0;
    }
}
