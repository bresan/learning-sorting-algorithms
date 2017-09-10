#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int size);

void bubbleSort(int a[], int size);

void processSelectedOption(int option);

void insertionSort(int a[], int size);

void printArray(int a[], int size);

void restoreArrayValues();

const int originalArray[] = {2, 6, 7, 3, 4, 1};
int a[] = {2, 6, 7, 3, 4, 1};

static const int OPTION_SELECTION_SORT = 1;
static const int OPTION_BUBBLE_SORT = 2;
static const int OPTION_INSERTION_SORT = 3;
static const int OPTION_EXIT = 0;

int main() {
    int selectedOption = -1;
    do {
        printf("\n\nWelcome to the super-duper-amazing sort program I've made because I couldn't remember almost any"
                       " kind of sorting algorithm :D\n\n");

        printf("Options:\n");
        printf("1. Use selection sort\n");
        printf("2. Use bubble sort\n");
        printf("3. Use insertion sort\n");
        printf("0. Exit\n\n");

        scanf("\n%d", &selectedOption);

        processSelectedOption(selectedOption);

    } while (selectedOption != 0);

    return 0;
}

void processSelectedOption(int option) {

    printf("\nArray before sorting: \n");
    int size = sizeof(a) / sizeof(a[0]);

    printArray(a, size);
    switch (option) {
        case OPTION_SELECTION_SORT:
            selectionSort(a, size);
            break;

        case OPTION_BUBBLE_SORT:
            bubbleSort(a, size);
            break;

        case OPTION_INSERTION_SORT:
            insertionSort(a, size);
            break;

        case OPTION_EXIT:
            exit(0);

        default:
            printf("Not a valid option");
    }

    printf("\n\nArray after sorting: \n");
    printArray(a, size);
    restoreArrayValues();
}

void restoreArrayValues() {
    int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++) {
        a[i] = originalArray[i];
    }
}

void printArray(int receivedArray[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d ", receivedArray[i]);
    }
}

void selectionSort(int a[], int size) {
    int i, j, pos, min;

    for (i = 0; i <= size - 1; i++) {
        min = a[i];
        pos = i;

        for (j = pos + 1; j <= size - 1; j++) {
            if (a[j] < min) {
                min = a[j];
                pos = j;
            }
        }

        a[pos] = a[i];
        a[i] = min;
    }
}

void bubbleSort(int a[], int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int a[], int size) {
    int value, holeIndex = 0;
    for (int i = 1; i < size; i++) {
        value = a[i];
        holeIndex = i;

        while (holeIndex > 0 && a[holeIndex - 1] > value) {
            a[holeIndex] = a[holeIndex - 1];
            holeIndex--;
         }

        a[holeIndex] = value;
    }
}