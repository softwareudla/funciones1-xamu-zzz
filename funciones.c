#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para ingresar los productos
void IngresarProductos(char nombres[10][50], float precios[10], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        scanf(" %[^\n]", nombres[i]); // Lee el nombre del producto
        
        // Verificar que el precio sea no negativo
        do {
            printf("Ingrese el precio del producto %d (no puede ser negativo): ", i + 1);
            scanf("%f", &precios[i]); // Lee el precio del producto
            if (precios[i] < 0) {
                printf("Error: El precio no puede ser negativo. Intente de nuevo.\n");
            }
        } while (precios[i] < 0);
    }
}

// Función para encontrar el producto más caro y el más barato
void EncontrarMasCaroYmasBarato(char nombres[10][50], float precios[10], int n, char masCaro[50], char masBarato[50]) {
    int indiceMasCaro = 0;
    int indiceMasBarato = 0;

    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[indiceMasCaro]) {
            indiceMasCaro = i;
        }
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;
        }
    }

    // Copiar los nombres manualmente
    strcpy(masCaro, nombres[indiceMasCaro]);
    strcpy(masBarato, nombres[indiceMasBarato]);
}

// Función para calcular el precio promedio
float CalcularPromedio(float precios[10], int n) {
    float total = CalcularTotal(precios, n);
    return total / n; // Calcula el promedio
}

// Función para buscar un producto por nombre y mostrar su precio
float BuscarProducto(char nombres[10][50], float precios[10], int n, char nombreBuscado[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            return precios[i]; // Retorna el precio si se encuentra el producto
        }
    }
    return -1;  // Indica que no se encontró el producto
}

// Definición de CalcularTotal
float CalcularTotal(float precios[10], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += precios[i]; // Suma los precios
    }
    return total;
}
