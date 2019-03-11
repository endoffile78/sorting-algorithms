#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "shared.h"

bool isSorted(int arr[], int length){
    bool ret = true;

    for (int i = 0; i < length - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            ret = false;
            break;
        }
    }

    return ret;
}

void bogoSort(int arr[], int length){
    while (!isSorted(arr, length)) {
        for (int i = 0; i < length; i++) {
            int index = (int)((double)rand() / ((double)RAND_MAX + 1) * length) - 1;
            if (arr[index] > arr[index + 1]) {
                int temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }
        }
        printArray(arr, length);
    }
}

int main(int argc, char *argv[]){
    if (argc <= 1) {
        printf("Usage: %s <numbers>", argv[0]);
        return 1;
    }

    int length = 0;
    int *numbers = getInput(argv, argc, &length);

    bogoSort(numbers, length);

    free(numbers);

    return 0;
}
