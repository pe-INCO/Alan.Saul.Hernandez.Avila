//
//  main.c
//  Burbuja
//
//  Created by Alan Saul Hernandez Avila on 26/03/26.
//


#include <stdio.h>

int main()
{
    int arreglo[] = {50, 26, 7, 9, 15, 27}, n = 6, t;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arreglo[i] > arreglo[j]) {
                t = arreglo[i]; arreglo[i] = arreglo[j]; arreglo[j] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) printf("%d ", arreglo[i]);
}
