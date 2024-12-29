#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;          
    int left = 2 * i + 1;   
    int right = 2 * i + 2;   

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int waterConsumption[] = {150, 120, 200, 80, 250, 60, 180};
    int n = sizeof(waterConsumption) / sizeof(waterConsumption[0]);

    printf("Water consumption data before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", waterConsumption[i]);
    }
    printf("\n");
    heapSort(waterConsumption, n);

    printf("Water consumption data after sorting (highest to lowest):\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", waterConsumption[i]);
    }
    printf("\n");

    return 0;
}
