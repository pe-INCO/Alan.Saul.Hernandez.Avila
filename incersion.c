//
//  main.c
//  incersion
//
//  Created by Alan Saul Hernandez Avila on 13/04/26.
//

#include <stdio.h>

// Función para intercambiar dos números
void intercambiar(int* a, int* b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

// Función que coloca el pivote en su lugar y mueve menores a la izquierda
int particion(int arreglo[], int bajo, int alto) {
    int pivote = arreglo[alto];
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
        if (arreglo[j] < pivote) {
            i++;
            intercambiar(&arreglo[i], &arreglo[j]);
        }
    }
    intercambiar(&arreglo[i + 1], &arreglo[alto]);
    return (i + 1);
}

// Función principal de Quick Sort
void quickSort(int arreglo[], int bajo, int alto) {
    if (bajo < alto) {
        int indiceParticion = particion(arreglo, bajo, alto);
        quickSort(arreglo, bajo, indiceParticion - 1);
        quickSort(arreglo, indiceParticion + 1, alto);
    }
}

int main() {
    int datos[] = {15, 3, 9, 1, 12, 8};
    int n = sizeof(datos) / sizeof(datos[0]);

    quickSort(datos, 0, n - 1);

    printf("Quick Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", datos[i]);
    return 0;
}
