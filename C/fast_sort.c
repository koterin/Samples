#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void swap(int *p1, int *p2);
void quickSort(int *a, int left, int right);
void heapSort(int *a, int n);
void heapify(int *a, int n, int i);

// main function
int main() {
    int data[NMAX];
    int n = NMAX;
    if (input(data, n) == 0) {
        printf("n/a");
        return 1;
    } else {
        int data_quick[NMAX];
        int data_heap[NMAX];
        for (int i = 0; i < n; i++) {
            data_quick[i] = data[i];
            data_heap[i] = data[i];
        }
        quickSort(data_quick, 0, n - 1);
        heapSort(data_heap, n);
        output(data_quick, n);
        printf("\n");
        output(data_heap, n);
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
        if (err != '\n' && err != ' ')
            return 0;
        }
    }
    return 1;
}

void swap(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

void quickSort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        while (left <= right) {
            while (a[left] < middle) left++;
            while (a[right] > middle) right--;
            if (left <= right) {
                swap(&(a[left]), &(a[right]));
                left++;
                right--;
            }
        }
        quickSort(a, first, right);
        quickSort(a, left, last);
    }
    return;
}

void heapify(int *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
      largest = left;
    if (right < n && a[right] > a[largest])
      largest = right;
    if (largest != i) {
      swap(&a[i], &a[largest]);
      heapify(a, n, largest);
    }
}

void heapSort(int *a, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--)
      heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
      swap(&a[0], &a[i]);
      heapify(a, i, 0);
    }
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
