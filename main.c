//
//  main.c
//  matriz
//
//  Created by Alan Saul Hernandez Avila on 20/04/26.
//

#include <stdio.h>

#define ESTUDIANTES 3
#define MATERIAS 4

int main(void)
{
    float notas[ESTUDIANTES][MATERIAS];
    float suma_estudiante, suma_materia;
    float nota_maxima;
    int fila_max, col_max;
    
    //  Ingresar notas
    printf(" Ingreso de Calificaciones \n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < MATERIAS; j++) {
            printf("Estudiante %d, Materia %d: ", i + 1, j + 1);
            scanf("%f", &notas[i][j]);
        }
        printf("\n");
    }
    
    //  Mostrar la matriz completa
    printf("\n Matriz de Notas \n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < MATERIAS; j++) {
            printf("%.2f\t", notas[i][j]);
        }
        printf("\n");
    }
    
    //  Calcular y mostrar el promedio de cada estudiante (por fila)
    printf("\n Promedios por Estudiante \n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        suma_estudiante = 0;
        for (int j = 0; j < MATERIAS; j++) {
            suma_estudiante += notas[i][j];
        }
        printf("Estudiante %d: %.2f\n", i + 1, suma_estudiante / MATERIAS);
    }
    
    //  Calcular y mostrar el promedio de cada materia (por columna)
    printf("\n Promedios por Materia \n");
    for (int j = 0; j < MATERIAS; j++) {
        suma_materia = 0;
        for (int i = 0; i < ESTUDIANTES; i++) {
            suma_materia += notas[i][j];
        }
        printf("Materia %d: %.2f\n", j + 1, suma_materia / ESTUDIANTES);
    }
    
    //  Encontrar la nota más alta y su posición
    nota_maxima = notas[0][0];
    fila_max = 0;
    col_max = 0;
    
    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < MATERIAS; j++) {
            if (notas[i][j] > nota_maxima) {
                nota_maxima = notas[i][j];
                fila_max = i;
                col_max = j;
            }
        }
    }
    
    printf("\n Nota Mas Alta \n");
    printf("La nota mas alta es %.2f (Estudiante %d, Materia %d)\n",
           nota_maxima, fila_max + 1, col_max + 1);
    
    return 0;
    
}
