//
//  main.c
//  fifolifo
//
//  Created by Alan Saul Hernandez Avila on 16/04/26.
//

#include <stdlib.h>
#include <stdio.h>

int main()
{
    // Variables para LIFO (Pila)
    int pila[5];
    int top = -1;

    // Variables para FIFO (Cola)
    int cola[5];
    int frente = -1, final = -1;

    int opcion = 0;
    int valor;

    // Bucle principal
    while (opcion != 5) {
        printf("\n--- MENU LIFO (Pila) y FIFO (Cola) ---");
        printf("\n1. Push (LIFO - Meter)");
        printf("\n2. Pop  (LIFO - Sacar)");
        printf("\n3. Enqueue (FIFO - Meter)");
        printf("\n4. Dequeue (FIFO - Sacar)");
        printf("\n5. Salir");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        // --- LÓGICA LIFO (Pila) ---
        if (opcion == 1) {
            if (top == 4) {
                printf("Error: La Pila esta llena.\n");
            } else {
                printf("Valor a ingresar a Pila: ");
                scanf("%d", &valor);
                top++;
                pila[top] = valor;
                printf("Agregado a Pila.\n");
            }
        }
        else if (opcion == 2) {
            if (top == -1) {
                printf("Error: La Pila esta vacia.\n");
            } else {
                printf("Sacado de Pila: %d\n", pila[top]);
                top--;
            }
        }

        // --- LÓGICA FIFO (Cola) ---
        else if (opcion == 3) {
            if (final == 4) {
                printf("Error: La Cola esta llena.\n");
            } else {
                printf("Valor a ingresar a Cola: ");
                scanf("%d", &valor);
                if (frente == -1) frente = 0;
                final++;
                cola[final] = valor;
                printf("Agregado a Cola.\n");
            }
        }
        else if (opcion == 4) {
            if (frente == -1 || frente > final) {
                printf("Error: La Cola esta vacia.\n");
                frente = -1; // Reset de seguridad
                final = -1;
            } else {
                printf("Sacado de Cola: %d\n", cola[frente]);
                frente++;
            }
        }
        
        else if (opcion == 5) {
            printf("Saliendo...\n");
        }
        else {
            printf("Opcion no valida.\n");
        }
    }
    return 0;
}
