#include <stdio.h>
#include <stdlib.h>

#include "shared.h"

void bubbleSort(int arr[], int length){
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]){
    if (argc <= 1) {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }

    int length = 0;
    int *numbers = getInput(argv, argc, &length);

    printf("unsorted: ");
    printArray(numbers, length);

    bubbleSort(numbers, length);

    printf("sorted: ");
    printArray(numbers, length);

    free(numbers);

    return 0;
}
