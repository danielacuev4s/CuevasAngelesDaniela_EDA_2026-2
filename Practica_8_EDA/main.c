//Programa de lista doblemente circular
//Collin Torres Ana Ivonne
//Cuevas Angeles Daniela
//Ortiz Vallado Naomi Abril
//Victoriano Escalante Emma Paola

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hospital.h"

/* ================== MAIN ================== */
int main() {
    struct SISTEMA sistema;
    inicializarSistema(&sistema);
    int op;

    do {
        printf("\n=== SISTEMA DE HOSPITALES ===\n");
        printf("1. Agregar datos\n");
        printf("2. Visualizar datos\n");
        printf("3. Salir\n");
        op = leerEntero("Seleccion: ");
        switch(op){
            case 1: menuAgregarDatos(&sistema); break;
            case 2: menuVisualizarDatos(&sistema); break;
        }
    } while(op != 3);

    liberarSistema(&sistema);
    printf("Saliendo... Hasta luego!\n");
    return 0;
}
