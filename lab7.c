#include <stdio.h>

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        swaps[arr[i]] += 1;
    }
}

void bubbleSort(int a[], int length, int swaps[]) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < (length - 1); j++) {
            if (a[j] > a[j + 1]) {
                swaps[a[j]]++;
                swaps[a[j + 1]]++;

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int length = 9;

    int swaps1[100] = {0};
    int swaps2[100] = {0};
    int swaps3[100] = {0};
    int swaps4[100] = {0};

    // bubble sort
    printf("array1 bubble sort:\n");
    bubbleSort(array1, length, swaps1);
    for (int i = 0; i < length; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    int totalSwaps1 = 0;
    for (int i = 0; i < 100; i++) {
        totalSwaps1 += swaps1[i];
    }
    totalSwaps1 = totalSwaps1 / 2;
    printf("total # of swaps: %d\n\n", totalSwaps1);

    printf("array2 bubble sort:\n");
    bubbleSort(array2, length, swaps2);
    for (int i = 0; i < length; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    int totalSwaps2 = 0;
    for (int i = 0; i < 100; i++) {
        totalSwaps2 += swaps2[i];
    }
    totalSwaps2 = totalSwaps2 / 2;
    printf("total # of swaps: %d\n\n", totalSwaps2);

    // selection sort
    printf("array1 selection sort:\n");
    selectionSort(array1, length, swaps3);
    for (int i = 0; i < length; i++) {
        printf("%d: %d\n", array1[i], swaps3[array1[i]]);
    }
    int totalSwaps3 = 0;
    for (int i = 0; i < 100; i++) {
        totalSwaps3 += swaps3[i];
    }
    totalSwaps3 = totalSwaps3 / 2;
    printf("total # of swaps: %d\n\n", totalSwaps3);

    printf("array2 selection sort:\n");
    selectionSort(array2, length, swaps4);
    for (int i = 0; i < length; i++) {
        printf("%d: %d\n", array2[i], swaps4[array2[i]]);
    }
    int totalSwaps4 = 0;
    for (int i = 0; i < 100; i++) {
        totalSwaps4 += swaps4[i];
    }
    totalSwaps4 = totalSwaps4 / 2;
    printf("total # of swaps: %d\n", totalSwaps4);

    return 0;
}
