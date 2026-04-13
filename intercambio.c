//
//  main.c
//  intercambio
//
//  Created by Alan Saul Hernandez Avila on 13/04/26.
//

#include <stdio.h>

// Función para intercambiar dos valores
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Función de partición
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Algoritmo principal Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int data[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Quick Sort (Original): ");
    for(int i=0; i<n; i++) printf("%d ", data[i]);

    quickSort(data, 0, n - 1);

    printf("\nQuick Sort (Ordenado): ");
    for(int i=0; i<n; i++) printf("%d ", data[i]);
    printf("\n");

    return 0;
}
