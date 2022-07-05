#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n);
int abs(int c);
void leftRotate(const int *a, int *b, int n, int c);
void rightRotate(const int *a, int *b, int n, int c);

int main() {
    int n, c, data[NMAX];
    if (input(data, &n, &c) == 0) {
        printf("n/a");
        return 1;
    } else {
        int newB[NMAX];
        if (abs(c) > n)  // Checking if it's more than one cycle
            c = c % n;
        if (c > 0) {
            leftRotate(data, newB, n, c);
        } else {
            rightRotate(data, newB, n, c);
        }
        output(newB, n);
    }
    return 0;
}

int input(int *a, int *n, int *c) {
    char err;
    err = 0;
    if (scanf("%d%c", n, &err) != 2) return 0;
    if (err != '\n' && err != ' ') return 0;
    if ((*n > NMAX) || (*n < 1)) {
        return 0;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (p - a == *n - 1) {
                if (scanf("%d%c", p, &err) != 2)
                    return 0;
            } else {
            if (scanf("%d%c", p, &err) != 2)
                return 0;
            if (err != '\n' && err != ' ')
                return 0;
            }
        }
    if (scanf("%d", c) != 1)
        return 0;
    if ((scanf("%c", &err) != EOF) && (err != '\n'))
        return 0;
    }
    return 1;
}

int abs(int c) {
    if (c > 0)
        return (c);
    if (c < 0)
        return (-c);
    return 0;
}

void rightRotate(const int *a, int *b, int n, int c) {
    int j = 0;
    for (int i = (c + n); i < n; i++) {
        b[j] = a[i];
        j++;
    }
    for (int i = 0; i < (n - abs(c)); i++) {
        b[j] = a[i];
        j++;
    }
    return;
}

void leftRotate(const int *a, int *b, int n, int c) {
    int j = 0;
    for (int i = c; i < n; i++) {
        b[j] = a[i];
        j++;
    }
    for (int i = 0; i < c; i++) {
        b[j] = a[i];
        j++;
    }
    return;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i == (n - 1)) {
            printf("%d", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    return;
}
