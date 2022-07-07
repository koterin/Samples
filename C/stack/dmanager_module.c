#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void sort_doors(struct door *doors, int n);
void swap(struct door *door1, struct door *door2);
void initialize_doors(struct door* doors);
void display(struct door *doors, int n);
void closing_doors(struct door *doors, int n);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors(doors, DOORS_COUNT);
    closing_doors(doors, DOORS_COUNT);
    display(doors, DOORS_COUNT);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door *doors, int n) {
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (doors[j].id > doors[j+1].id) {
                swap(&doors[j], &doors[j+1]);
            }
        }
    }
    return;
}

void swap(struct door *door1, struct door *door2) {
    struct door temp;
    temp = *door1;
    *door1 = *door2;
    *door2 = temp;
    return;
}

void display(struct door *doors, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d, %d", doors[i].id, doors[i].status);
        } else {
            printf("%d, %d\n", doors[i].id, doors[i].status);
        }
    }
}

void closing_doors(struct door *doors, int n) {
    for (int i = 0; i < n; i++) {
        if (doors[i].status == 1) {
            doors[i].status = 0;
        }
    }
}
