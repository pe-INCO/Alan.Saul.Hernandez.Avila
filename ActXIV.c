//
//  main.c
//  arreglo
//
//  Created by Alan Saul Hernandez Avila on 18/03/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void mostrarArreglo(int arr[], int n) {
    if (n == 0) {
        printf("\nEl arreglo esta vacio\n");
        return;
    }
    printf("\nArreglo: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arreglo[MAX];
    int tamanoActual = 0;
    int opcion, valor, pos;
    // Inicializar semilla para números aleatorios
    srand(time(NULL));
    do {
        printf("\n1. 5 valores aleatorios");
        printf("\n2. Mostrar arreglo");
        printf("\n3. Agregar elemento al final");
        printf("\n4. Insertar en posicion especifica");
        printf("\n5. Eliminar por posicion");
        printf("\n6. Salir");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                tamanoActual = 5;
                for (int i = 0; i < tamanoActual; i++) {
                    arreglo[i] = rand() % 100; // Valores entre 0 y 99
                }
                printf("\nArreglo inicializado con 5 valores\n");
                break;

            case 2:
                mostrarArreglo(arreglo, tamanoActual);
                break;

            case 3:
                if (tamanoActual < MAX) {
                    printf("Ingrese el valor a agregar: ");
                    scanf("%d", &valor);
                    arreglo[tamanoActual] = valor;
                    tamanoActual++;
                } else {
                    printf("\nError: El arreglo esta lleno\n");
                }
                break;

            case 4:
                if (tamanoActual < MAX) {
                    printf("Ingrese posicion (0-%d): ", tamanoActual);
                    scanf("%d", &pos);
                    if (pos >= 0 && pos <= tamanoActual) {
                        printf("Ingrese el valor: ");
                        scanf("%d", &valor);
                        // Desplazar elementos a la derecha
                        for (int i = tamanoActual; i > pos; i--) {
                            arreglo[i] = arreglo[i - 1];
                        }
                        arreglo[pos] = valor;
                        tamanoActual++;
                    } else {
                        printf("Posicion invalida\n");
                    }
                } else {
                    printf("\nError: Arreglo lleno\n");
                }
                break;

            case 5:
                if (tamanoActual > 0) {
                    printf("Ingrese posicion a eliminar (0-%d): ", tamanoActual - 1);
                    scanf("%d", &pos);
                    if (pos >= 0 && pos < tamanoActual) {
                        // Desplazar elementos a la izquierda
                        for (int i = pos; i < tamanoActual - 1; i++) {
                            arreglo[i] = arreglo[i + 1];
                        }
                        tamanoActual--;
                        printf("Elemento eliminado\n");
                    } else {
                        printf("Posicion invalida\n");
                    }
                } else {
                    printf("\nEl arreglo esta vacio\n");
                }
                break;

            case 6:
                printf("Saliendo\n");
                break;

            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 6);

    return 0;
}
