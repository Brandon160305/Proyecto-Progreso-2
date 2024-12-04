#include <stdio.h>
#include "inventario.h"

int main() {
    // Declarar matrices para almacenar los datos
    char producto[100][100], marca[100][100], modelo[100][100]; 
    int año[100], cantidad[100], f = 0, x = 0; // f es el contador de productos
    float precio[100];

    // Menu de opciones
    do {
        printf("\n---------Menú---------\n");
        printf("1. Ingresar producto\n2. Editar producto\n3. Eliminar producto\n4. Listar Inventario\n5. Salir\n");
        printf("----------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &x);

        switch (x) {
            case 1: // Opción para ingresar un producto nuevo
                ingresar(producto, marca, modelo, año, cantidad, precio, &f);
                break;
            case 2: // Opción para editar un producto existente
                editar(producto, marca, modelo, año, cantidad, precio, &f);
                break;
            case 3: // Opción para eliminar un producto
                eliminar(producto, marca, modelo, año, cantidad, precio, &f);
                break;
            case 4: // Opción para listar todos los productos del inventario
                listar(producto, marca, modelo, año, cantidad, precio, &f);
                break;
            case 5: // Opción para salir del programa
                printf("Saliendo del programa.\n");
                break;
            default: // Manejo de opciones inválidas
                printf("Ingrese una opcion valida.\n");
        }
    } while (x != 5); // Repetir el menú hasta que el usuario elija salir
    return 0;
}
