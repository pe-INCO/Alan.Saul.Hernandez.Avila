//
//  main.c
//  encuentra
//
//  Created by Alan Saul Hernandez Avila on 25/03/26.
//

#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>

int main()
{
    int arreglo[10] = {5, 8, 12, 3, 7, 9, 15, 20, 1, 6};
    int numero, i;
    int encontrado = 0;

    printf("Ingresa el numero a buscar: ");
    scanf("%d", &numero);

    // Búsqueda secuencial
    for(i = 0; i < 10; i++) {
        if(arreglo[i] == numero) {
            printf("Numero encontrado en la posicion (indice): %d\n", i);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado) {
        printf("Numero no encontrado en el arreglo.\n");
    }

    return 0;
}
