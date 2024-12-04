#include <stdio.h>
#include <string.h>

void ingresar(char producto[][100], char marca[][100], char modelo[][100], int año[], int cantidad[], float precio[], int *f) {
    if (*f >= 100) {
        printf("No se pueden agregar más productos.\n");
    }else{
        printf("\tINGRESAR PRODUCTOS:\n");
        printf("Ingrese el nombre del producto: ");
        getchar(); // Limpia el buffer del teclado
        fgets(producto[*f], sizeof(producto[*f]), stdin);
        producto[*f][strcspn(producto[*f], "\n")] = '\0'; // Elimina el salto de linea

        printf("Ingrese la marca del vehículo: ");
        fgets(marca[*f], sizeof(marca[*f]), stdin);
        marca[*f][strcspn(marca[*f], "\n")] = '\0'; 

        printf("Ingrese el modelo del vehículo: ");
        fgets(modelo[*f], sizeof(modelo[*f]), stdin);
        modelo[*f][strcspn(modelo[*f], "\n")] = '\0';

        // Validar el año 
        do {
            printf("Ingrese el año del vehículo: ");
            scanf("%d", &año[*f]);
        } while (año[*f] < 1970 || año[*f] > 2025); 

        // Validar cantidad y precio para que no sean negativos
        do {
            printf("Ingrese la cantidad de productos: ");
            scanf("%d", &cantidad[*f]);
        }while (cantidad[*f] < 0 );

        do {
            printf("Ingrese el precio del producto en dólares: ");
            scanf("%f", &precio[*f]);
        }while (precio[*f] < 0 );

        (*f)++; // Incrementar el contador de productos
        
        printf("Producto agregado\n");
    }
}

void editar(char producto[][100], char marca[][100], char modelo[][100], int año[], int cantidad[], float precio[], int *f) {
    char n[100], ma[100], mo[100];
    int a, y = 0;
    // Pedir al usuario los detalles del producto a editar
    printf("\tEDITAR PRODUCTOS:\n");
    printf("Ingrese el nombre del repuesto a editar: ");
    getchar();;
    fgets(n, sizeof(n), stdin);
    n[strcspn(n, "\n")] = '\0';

    printf("Ingrese la marca del repuesto a editar: ");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = '\0';

    printf("Ingrese el modelo del repuesto a editar: ");
    fgets(mo, sizeof(mo), stdin);
    mo[strcspn(mo, "\n")] = '\0';

    do {
        printf("Ingrese el año del repuesto a editar: ");
        scanf("%d", &a);
    } while (a < 1970 || a > 2025); 

    // Buscar el producto en el inventario
    for (int i = 0; i < *f; i++) {
        if (strcmp(producto[i], n) == 0 && strcmp(marca[i], ma) == 0 && strcmp(modelo[i], mo) == 0 && año[i] == a) {
            printf("Ingrese los nuevos valores:\n");

            do {
                printf("Ingrese la cantidad del producto: ");
                scanf("%d", &cantidad[*f]);
            }while (cantidad[*f] < 0 );

            do {
                printf("Ingrese el precio del producto: ");
                scanf("%f", &precio[*f]);
            }while (precio[*f] < 0 );

            printf("Producto actualizado.\n");
            y = 1; // Marca que se encontró el producto
        }
    }

    if(y == 0){
        printf("Repuesto no encontrado.\n");
    }

}

void eliminar(char producto[][100], char marca[][100], char modelo[][100], int año[], int cantidad[], float precio[], int *f) {
    char n[100], ma[100], mo[100];
    int a, y = 0;
    // Pedir al usuario los detalles del producto a eliminar
    printf("\tELIMINAR PRODUCTOS:\n");
    printf("Ingrese el nombre del repuesto a eliminar: ");
    getchar();
    fgets(n, sizeof(n), stdin);
    n[strcspn(n, "\n")] = '\0';

    printf("Ingrese la marca del repuesto a eliminar: ");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = '\0';

    printf("Ingrese el modelo del repuesto a eliminar: ");
    fgets(mo, sizeof(mo), stdin);
    mo[strcspn(mo, "\n")] = '\0';

    do {
        printf("Ingrese el año del repuesto a eliminar: ");
        scanf("%d", &a);
    } while (a < 1970 || a > 2025); 
    // Buscar y eliminar el producto si se encuentra
    for (int i = 0; i < *f; i++) {
        if (strcmp(producto[i], n) == 0 && strcmp(marca[i], ma) == 0 && strcmp(modelo[i], mo) == 0 && año[i] == a) {
            for (int j = i; j < *f - 1; j++) {
                strcpy(producto[j], producto[j + 1]);
                strcpy(marca[j], marca[j + 1]);
                strcpy(modelo[j], modelo[j + 1]);
                año[j] = año[j + 1];
                cantidad[j] = cantidad[j + 1];
                precio[j] = precio[j + 1];
            }
            (*f)--; // Reducir el contador de productos
            printf("Repuesto eliminado.\n");
            y = 1; // Marca que se eliminó el producto
        }
    }

    if(y == 0){
        printf("Repuesto no encontrado.\n");
    }
}

void listar(char producto[][100], char marca[][100], char modelo[][100], int año[], int cantidad[], float precio[], int *f) {
    if (*f == 0) { // Verificar si el inventario está vacío
        printf("No hay repuestos en el inventario.\n");
    } else {
        // Ordenar los productos, modelos y marcas alfabéticamente
        for (int i = 0; i < *f - 1; i++) {
            for (int j = i + 1; j < *f; j++) {
                // Comparar producto primero, luego modelo, y luego marca
                if (strcmp(producto[i], producto[j]) > 0 ||
                    (strcmp(producto[i], producto[j]) == 0 && strcmp(modelo[i], modelo[j]) > 0) ||
                    (strcmp(producto[i], producto[j]) == 0 && strcmp(modelo[i], modelo[j]) == 0 && strcmp(marca[i], marca[j]) > 0)) {
                    
                    // Intercambiar producto
                    char aux[100];
                    strcpy(aux, producto[i]);
                    strcpy(producto[i], producto[j]);
                    strcpy(producto[j], aux);

                    // Intercambiar marca
                    strcpy(aux, marca[i]);
                    strcpy(marca[i], marca[j]);
                    strcpy(marca[j], aux);

                    // Intercambiar modelo
                    strcpy(aux, modelo[i]);
                    strcpy(modelo[i], modelo[j]);
                    strcpy(modelo[j], aux);

                    // Intercambiar año
                    int aux1 = año[i];
                    año[i] = año[j];
                    año[j] = aux1;

                    // Intercambiar cantidad
                    aux1 = cantidad[i];
                    cantidad[i] = cantidad[j];
                    cantidad[j] = aux1;

                    // Intercambiar precio
                    float aux2 = precio[i];
                    precio[i] = precio[j];
                    precio[j] = aux2;
                }
            }
        }

        // Imprime en forma de tabla
        printf("\tINVENTARIO:\n");
        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("| %-20s | %-15s | %-15s | %-5s | %-10s | %-10s |\n", "Producto", "Marca", "Modelo", "Año", "Cantidad", "Precio");
        printf("---------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < *f; i++) {
            printf("| %-20s | %-15s | %-15s | %-4d | %-10d | %-10.2f |\n", producto[i], marca[i], modelo[i], año[i], cantidad[i], precio[i]);
        }
        printf("---------------------------------------------------------------------------------------------\n");
    }
}

