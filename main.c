#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[10][50];
    float precios[10];
    int numProductos;

    // Ingresar productos
    printf("\nIngrese el numero de productos (maximo %d): ", 10);
    scanf("%d", &numProductos);

    // Validar que el número de productos no supere el máximo
    while (numProductos > 10 || numProductos <= 0) {
        if (numProductos > 10) {
            printf("El numero maximo de productos es %d. Intente de nuevo.\n", 10);
        } else {
            printf("El numero de productos debe ser mayor que 0. Intente de nuevo.\n");
        }
        printf("\nIngrese el numero de productos (maximo %d): ", 10);
        scanf("%d", &numProductos);
    }

    IngresarProductos(nombres, precios, numProductos);

    // Calcular total del inventario
    float total = CalcularTotal(precios, numProductos);
    printf("\nEl precio total del inventario es: %.2f\n", total);

    // Encontrar el producto más caro y más barato
    char masCaro[50] = {0}, masBarato[50] = {0};
    EncontrarMasCaroYmasBarato(nombres, precios, numProductos, masCaro, masBarato);

    printf("El producto más caro es: %s\n", masCaro);
    printf("El producto más barato es: %s\n", masBarato);

    // Calcular el promedio de precios
    float promedio = CalcularPromedio(precios, numProductos);
    printf("El precio promedio de los productos es: %.2f\n", promedio);

    // Buscar un producto por su nombre
    char nombreBuscado[50];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf(" %[^\n]", nombreBuscado);

    float precioBuscado = BuscarProducto(nombres, precios, numProductos, nombreBuscado);
    if (precioBuscado >= 0) {
        printf("El precio de %s es: %.2f\n", nombreBuscado, precioBuscado);
    } else {
        printf("Producto no encontrado.\n");
    }

    return 0;
}