#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    fflush(stdout);
}

int *getInput(char *argv[], int argc, int *length) {
    if (!length) {
        return NULL;
    }

    *length = argc - 1;
    int *numbers = calloc(sizeof(int), *length);
    if (!numbers) {
        return NULL;
    }

    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = atoi(argv[i]);
    }

    return numbers;
}
