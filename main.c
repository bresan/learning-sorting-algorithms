#include <stdio.h>

void selectionSort(int a[], int size);

int main() {
    printf("Hello, World!\n");
    int i;
    int a[] = {2, 6, 7, 3, 4, 1};

    int size = sizeof(a)/sizeof(a[0]);
    printf("Array before sorting: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    selectionSort(a, size);

    printf("Array after sorting: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void selectionSort(int a[], int size) {
    int i, j, pos, min;

    for (i = 0; i <= size - 1; i++) {
        min = a[i];
        pos = i;

        for (j = i + 1; j <= size - 1; j++) {
            if (a[j] < min) {
                min = a[j];
                pos = j;
            }
        }

        a[pos] = a[i];
        a[i] = min;
    }
}