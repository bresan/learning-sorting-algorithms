#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int size);

void bubbleSort(int a[], int size);

void insertionSort(int a[], int size);

void mergeSort(int a[], int size);

void merge(int *array, int *leftArray, int leftCount, int *rightArray, int rightCount);

void quickSort(int a[], int start, int end);

int partition(int a[], int start, int end);

void processSelectedOption(int option);

void printArray(int a[], int size);

void restoreArrayValues();

const int originalArray[] = {2, 6, 7, 3, 4, 1};
int sampleArray[] = {2, 6, 7, 3, 4, 1};

static const int OPTION_SELECTION_SORT = 1;
static const int OPTION_BUBBLE_SORT = 2;
static const int OPTION_INSERTION_SORT = 3;
static const int OPTION_MERGE_SORT = 4;
static const int OPTION_QUICK_SORT = 5;
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
        printf("4. Use merge sort\n");
        printf("5. Use quick sort\n");
        printf("0. Exit\n\n");

        scanf("\n%d", &selectedOption);

        processSelectedOption(selectedOption);

    } while (selectedOption != 0);

    return 0;
}

void processSelectedOption(int option) {

    int size = sizeof(sampleArray) / sizeof(sampleArray[0]);
    if (option != 0) {
        printf("\nArray before sorting: \n");
        printArray(sampleArray, size);
    }

    switch (option) {
        case OPTION_SELECTION_SORT:
            selectionSort(sampleArray, size);
            break;

        case OPTION_BUBBLE_SORT:
            bubbleSort(sampleArray, size);
            break;

        case OPTION_INSERTION_SORT:
            insertionSort(sampleArray, size);
            break;

        case OPTION_MERGE_SORT:
            mergeSort(sampleArray, size);
            break;

        case OPTION_QUICK_SORT:
            quickSort(sampleArray, 0, size - 1);
            break;

        case OPTION_EXIT:
            exit(0);

        default:
            printf("\n\n\nNot a valid option");
    }


    printf("\n\nArray after sorting: \n");
    printArray(sampleArray, size);
    restoreArrayValues();
}


void restoreArrayValues() {
    int size = sizeof(sampleArray) / sizeof(sampleArray[0]);
    for (int i = 0; i < size; i++) {
        sampleArray[i] = originalArray[i];
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

void mergeSort(int a[], int size) {
    int middle;
    int *leftArray, *rightArray;

    if (size < 2) {
        return;
    }

    middle = size / 2;

    leftArray = (int *) malloc(middle * sizeof(int));
    rightArray = (int *) malloc((size - middle) * sizeof(int));

    for (int i = 0; i < middle; i++) {
        leftArray[i] = a[i];
    }

    for (int i = middle; i < size; i++) {
        rightArray[i - middle] = a[i];
    }

    mergeSort(leftArray, middle);
    mergeSort(rightArray, size - middle);

    merge(a, leftArray, middle, rightArray, size - middle);
    free(leftArray);
    free(rightArray);
}

void merge(int *array, int *leftArray, int leftCount, int *rightArray, int rightCount) {
    int indexLeft, indexRight, indexMerged;
    indexLeft = indexRight = indexMerged = 0;

    while (indexLeft < leftCount && indexRight < rightCount) {
        if (leftArray[indexLeft] < rightArray[indexRight]) {
            array[indexMerged] = leftArray[indexLeft];
            indexMerged++;
            indexLeft++;
        } else {
            array[indexMerged] = rightArray[indexRight];
            indexMerged++;
            indexRight++;
        }
    }

    while (indexLeft < leftCount) {
        array[indexMerged] = leftArray[indexLeft];
        indexMerged++;
        indexLeft++;
    }

    while (indexRight < rightCount) {
        array[indexMerged] = rightArray[indexRight];
        indexMerged++;
        indexRight++;
    }
}

void quickSort(int array[], int start, int end) {
    int pivotIndex;

    if (start < end) {
        pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, end);
    }
}

int partition(int array[], int start, int end) {
    int pivot, i, pivotIndex, temp, temp2;

    pivot = array[end];
    pivotIndex = start;

    for (i = start; i < end; i++) {
        if (array[i] <= pivot) {
            temp = array[i];
            array[i] = array[pivotIndex];
            array[pivotIndex] = temp;

            pivotIndex++;
        }
    }

    temp2 = array[pivotIndex];
    array[pivotIndex] = array[end];
    array[end] = temp2;
    return pivotIndex;
}