#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void sort(int *a, int n);
void output(int *a, int n);
void swap(int *p1, int *p2);

int main() {
    printf("Input 10 numbers with spaces between them and get them sorted\n\n");

    int data[NMAX];
    int n = NMAX;
    if (input(data, n) == 0) {
        printf("n/a");
        return 1;
    } else {
        sort(data, n);
        output(data, n);
    }
    return 0;
}

int input(int *a, int n) {
    char err;
    err = 0;
    for (int *p = a; p - a < n; p++) {
        if (p - a == n - 1) {
            if (scanf("%d", p) != 1)
                return 0;
            if ((scanf("%c", &err) != EOF) && (err != '\n'))
                return 0;
        } else {
            if (scanf("%d%c", p, &err) != 2)
            return 0;
        }
        if (err != '\n' && err != ' ')
            return 0;
        }
    return 1;
}

void sort(int *a, int n) {
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
    return;
}

void swap(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if ((p - a) == (n - 1)) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
    return;
}

