#include <stdio.h>

int main() {
    char alimentos[10][30];
    float precios[10];     
    int cantidades[10] = {0}; 
    int opcion, cantidad, num_alimentos = 0;
    float total = 0;

    printf("Ingrese el número de alimentos (max. 10): ");
    scanf("%d", &num_alimentos);
    for (int i = 0; i < num_alimentos; i++) {
        printf("Ingrese el nombre del alimento %d: ", i + 1);
        scanf("%s", alimentos[i]);
        printf("Ingrese el precio del alimento %d: ", i + 1);
        scanf("%f", &precios[i]);
    }

    printf("\nMenú:\n");
    for (int i = 0; i < num_alimentos; i++) {
        printf("%d: %s - $%.2f\n", i, alimentos[i], precios[i]);
    }
    printf("%d: Terminar\n", num_alimentos);


    do {
        printf("\nElige el alimento (0 a %d): ", num_alimentos - 1);
        scanf("%d", &opcion);
        
        if (opcion >= 0 && opcion < num_alimentos) {
            printf("Cantidad: ");
            scanf("%d", &cantidad);
            cantidades[opcion] += cantidad;
        }
    } while (opcion != num_alimentos);

   
    printf("\nResumen de cuenta:\n");
    for (int i = 0; i < num_alimentos; i++) {
        if (cantidades[i] > 0) {
            float subtotal = cantidades[i] * precios[i];
            printf("%s - $%.2f x %d = $%.2f\n", alimentos[i], precios[i], cantidades[i], subtotal);
            total += subtotal;
        }
    }
    printf("Total a pagar: $%.2f\n", total);

    return 0;
}
