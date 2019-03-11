#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

void insertionSort(int arr[], int length){
    for (int i = 0; i < length; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc <= 1) {
        printf("Usage: %s <numbers>", argv[0]);
        return 1;
    }

    int length = 0;
    int *numbers = getInput(argv, argc, &length);

    printf("unsorted: ");
    printArray(numbers, length);

    insertionSort(numbers, length);

    printf("sorted: ");
    printArray(numbers, length);

    free(numbers);

    return 0;
}
