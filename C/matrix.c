#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int input_cmd(int *n);
int input_size(int *row, int *col);
int static_input(int a[NMAX][NMAX], int row, int col);
int input(int *a, int n);
void output_matrix(int **a, int row, int col);
int static_matrix(int ar[NMAX][NMAX], int row, int col);
void output_matrix_static(int ar[NMAX][NMAX], int row, int col);
int dynamic1(int row, int col);
int dynamic2(int row, int col);
int dynamic3(int row, int col);

int main() {
    int row, col, switcher;

    // Inputing a mode
    if (input_cmd(&switcher) == 0) {
        printf("n/a");
        return 1;
    }

    // Inputing rows and columns
    if (input_size(&row, &col) == 0) {
        printf("n/a");
        return 1;
    }
    if (switcher == 1) {
        int ar[NMAX][NMAX];
        if (static_matrix(ar, row, col) == 0) {
            printf("n/a");
            return 1;
        }
    }
    if (switcher == 2) {
        if (dynamic1(row, col) == 0) {
            printf("n/a");
            return 1;
        }
    }
    if (switcher == 3) {
        if (dynamic2(row, col) == 0) {
            printf("n/a");
            return 1;
        }
    }
    if (switcher == 4) {
        if (dynamic3(row, col) == 0) {
            printf("n/a");
            return 1;
        }
    }
    return 0;
}

int input_size(int *row, int *col) {
    char err;
    err = 0;

    if (scanf("%d%c", row, &err) != 2)
        return 0;
    if (err != '\n' && err != ' ')
        return 0;
    if ((*row <= 0) || (*row > NMAX))
        return 0;
    if (scanf("%d%c", col, &err) != 2)
        return 0;
    if (err != '\n')
        return 0;
    if ((*col <= 0) || (*col > NMAX))
        return 0;

    return 1;
}

int input_cmd(int *n) {
    char err;
    err = 0;
    if (scanf("%d%c", n, &err) != 2)
        return 0;
    if (err != '\n' && err != ' ')
        return 0;
    if (*n != 1 && *n != 2 && *n != 3 && *n != 4)
        return 0;
    return 1;
}

int static_matrix(int ar[NMAX][NMAX], int row, int col) {
    if (static_input(ar, row, col) == 0)
        return 0;
    output_matrix_static(ar, row, col);
    return 1;
}

int dynamic1(int row, int col) {
    int **dr = malloc(row * col * sizeof(int) + row * sizeof(int *));
    if (dr == NULL) {
        printf("n/a");
        return 0;
    }
    int *ptr = (int *)(dr + row);
    for (int i = 0; i < row; i++) {
        dr[i] = ptr + col * i;
        if (input(dr[i], col) == 0) {
            free(dr);
            return 0;
        }
    }
    output_matrix(dr, row, col);

    free(dr);
    return 1;
}

int static_input(int a[NMAX][NMAX], int row, int col) {
    char err;
    err = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                if (scanf("%d", &(a[i][j])) != 1)
                    return 0;
                if ((scanf("%c", &err) != EOF) && (err != '\n'))
                    return 0;
            } else {
                if (scanf("%d%c", &a[i][j], &err) != 2)
                    return 0;
                if (err != '\n' && err != ' ')
                    return 0;
            }
        }
    }
    return 1;
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
        if (err != '\n' && err != ' ')
            return 0;
        }
    }
    return 1;
}

void output_matrix_static(int ar[NMAX][NMAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((j == (col - 1)) && (i == (row - 1))) {
                printf("%d", ar[i][j]);
            } else if (j == (col - 1)) {
                printf("%d\n", ar[i][j]);
            } else {
                printf("%d ", ar[i][j]);
            }
        }
    }
    return;
}

void output_matrix(int **dr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((j == (col - 1)) && (i == (row - 1))) {
                printf("%d", dr[i][j]);
            } else if (j == (col - 1)) {
                printf("%d\n", dr[i][j]);
            } else {
                printf("%d ", dr[i][j]);
            }
        }
    }
    return;
}

int dynamic2(int row, int col) {
    int **dr = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        dr[i] = malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        if (input(dr[i], col) == 0) {
            for (int j = 0; j < row; j++)
                free(dr[j]);
            free(dr);
            return 0;
        }
    }

    output_matrix(dr, row, col);

    for (int i = 0; i < row; i++)
        free(dr[i]);
    free(dr);
    return 1;
}

int dynamic3(int row, int col) {
    int **dr = malloc(row * sizeof(int *));
    int *values = malloc(row * col * sizeof(int));
    for (int i = 0; i < row; i++) {
        dr[i] = values + col * i;
    }

    for (int i = 0; i < row; i++) {
        if (input(dr[i], col) == 0) {
            free(values);
            free(dr);
            return 0;
        }
    }

    output_matrix(dr, row, col);

    free(values);
    free(dr);
    return 1;
}
