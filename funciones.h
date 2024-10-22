#ifndef FUNCIONES_H
#define FUNCIONES_H

// Funciones para el manejo del inventario
void IngresarProductos(char nombres[10][50], float precios[10], int n);
float CalcularTotal(float precios[10], int n);
void EncontrarMasCaroYmasBarato(char nombres[10][50], float precios[10], int n, char masCaro[50], char masBarato[50]);
float CalcularPromedio(float precios[10], int n);
float BuscarProducto(char nombres[10][50], float precios[10], int n, char nombreBuscado[]);

#endif

