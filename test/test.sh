#!/bin/bash



# Caso 1: Ingreso de productos y precios válidos
# Simulamos la entrada de datos con echo y redireccionamos la salida a un archivo
echo -e "Producto1\n100\nProducto2\n200\nProducto3\n300\nProducto4\n400\nProducto5\n500\nProducto6\n600\nProducto7\n700\nProducto8\n800\nProducto9\n900\nProducto10\n1000" | ./main > salida.txt

# Verificamos si la salida es la esperada
# En este caso el total del inventario debería ser 5500
total_esperado="Total del inventario: 5500.00"
salida=$(grep "Total del inventario" salida.txt)

if [ "$salida" == "$total_esperado" ]; then
    echo "Prueba 1 (Productos y Precios válidos): Éxito"
else
    echo "Prueba 1 (Productos y Precios válidos): Fallo"
fi