/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void realizarDeposito();
void verHistorialCompleto();
void calcularSaldoTotal();
void vistaPreviaRapida();

int main() {
    int opcion;

    do {
        printf("\n--- CAJERO AUTOMATICO: REGISTRO DE DEPOSITOS ---\n");
        printf("1. Realizar Deposito (fprintf / fputc)\n");
        printf("2. Ver Historial Completo (fgets)\n");
        printf("3. Calcular Saldo Total (fscanf)\n");
        printf("4. Vista Previa de Caracteres (fgetc)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: realizarDeposito(); break;
            case 2: verHistorialCompleto(); break;
            case 3: calcularSaldoTotal(); break;
            case 4: vistaPreviaRapida(); break;
        }
    } while (opcion != 5);

    return 0;
}

// 1. ESCRITURA: Usa fprintf para datos y fputc para un separador
void realizarDeposito() {
    FILE *archivo = fopen("banco.txt", "a"); // Modo "a" para no borrar lo anterior
    float monto;
    char concepto[50];

    if (archivo == NULL) return;

    printf("Ingrese el monto a depositar: ");
    scanf("%f", &monto);
    printf("Concepto del deposito: ");
    scanf("%s", concepto);

    // Escribimos el formato: MONTO CONCEPTO
    fprintf(archivo, "%.2f %s\n", monto, concepto);
    
    // Usamos fputc para añadir un guion decorativo al final de la operacion
    fputc('-', archivo);
    fputc('\n', archivo);

    fclose(archivo);
    printf("Deposito registrado exitosamente.\n");
}

// 2. LECTURA POR LINEAS: Usa fgets
void verHistorialCompleto() {
    FILE *archivo = fopen("banco.txt", "r");
    char linea[100];

    if (archivo == NULL) {
        printf("No hay registros todavia.\n");
        return;
    }

    printf("\n--- HISTORIAL DE TRANSACCIONES ---\n");
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
}

// 3. LECTURA FORMATEADA: Usa fscanf para sumar los montos
void calcularSaldoTotal() {
    FILE *archivo = fopen("banco.txt", "r");
    float monto, total = 0;
    char concepto[50];
    char basura[2]; // Para saltar el guion '-'

    if (archivo == NULL) return;

    // fscanf lee el numero, luego el string, y luego ignora el guion
    while (fscanf(archivo, "%f %s %s", &monto, concepto, basura) == 3) {
        total += monto;
    }

    printf("\nSaldo Total Acumulado: $%.2f\n", total);
    fclose(archivo);
}

// 4. LECTURA CARACTER A CARACTER: Usa fgetc
void vistaPreviaRapida() {
    FILE *archivo = fopen("banco.txt", "r");
    char c;

    if (archivo == NULL) return;

    printf("\nLectura en crudo (fgetc):\n");
    while ((c = fgetc(archivo)) != EOF) {
        // Imprimimos cada caracter. Los espacios se verán como [ ]
        if (c == '\n') printf("[\\n]\n");
        else printf("[%c]", c);
    }

    fclose(archivo);
}