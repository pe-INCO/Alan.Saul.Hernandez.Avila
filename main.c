//
//  main.c
//  matriz
//
//  Created by Alan Saul Hernandez Avila on 20/04/26.
//

#include <stdio.h>

int main(void)

{
    // Definimos constantes para las dimensiones
    const int ESTUDIANTES = 3;
    const int MATERIAS = 4;
    
    // Declaramos la matriz de números reales
    float notas[ESTUDIANTES] [MATERIAS];
    int i, j;
    
    printf("=== Registro de Notas (Matriz 3x4) ===\n");
    
    // Bloque de entrada de datos
    for (i = 0; i < ESTUDIANTES; i++) {
        printf("\nNotas para el Estudiante #%d:\n", i + 1);
        for (j = 0; j < MATERIAS; j++) {
            printf("  Materia %d: ", j + 1);
            // Leemos el valor real y lo guardamos en la dirección de memoria
            scanf("%f", &notas[i][j]);
        }
    }
    
    // Bloque de salida de datos (Mostrar la matriz)
    printf("MATRIZ COMPLETA DE NOTAS\n");
    
    // Encabezados de columnas
    printf("            ");
    for (j = 0; j < MATERIAS; j++) {
        printf("Mat %d     ", j + 1);
    }
    
    for (i = 0; i < ESTUDIANTES; i++) {
        printf("Est. %d |  ", i + 1);
        for (j = 0; j < MATERIAS; j++) {
            // %8.2f reserva 8 espacios y muestra 2 decimales para alinear
            printf("%8.2f  ", notas[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
