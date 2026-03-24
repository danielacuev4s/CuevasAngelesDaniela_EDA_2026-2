#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ColaCircular.c"

/* Función auxiliar para generar un proceso con datos aleatorios */
void generar_proceso_aleatorio(ColaCircular *q) {
    char nombres[][15] = {"System", "Kernel", "Browser", "Editor", "Media", "Game", "Driver"};
    char nombre_azar[16];
    int id_azar;
    float ram_azar;

    /* Generar ID de 4 dígitos (1000-9999) que no se repita en la cola */
    do {
        id_azar = (rand() % 9000) + 1000;
    } while (id_existe(q, id_azar));

    /* Elegir nombre y RAM aleatoria (0.1 a 8.0 GB) */
    strcpy(nombre_azar, nombres[rand() % 7]);
    ram_azar = ((float)rand() / (float)(RAND_MAX)) * 8.0f;

    cola_circ_encolar(q, nombre_azar, id_azar, ram_azar);
}

int main(void) {
    srand(time(NULL)); /* Semilla para números aleatorios */
    ColaCircular q;
    int cap, opcion = 1;
    Nodo proceso_extraido;

    printf("--- SIMULADOR DE COLA DE PROCESOS ---\n");
    printf("Ingrese el tamaño de la cola circular: ");
    if (scanf("%d", &cap) != 1 || cap <= 0) return 1;

    if (!cola_circ_init(&q, cap)) return 1;

    /* Llenado inicial de la cola según la capacidad */
    printf("\nLlenando cola inicial...\n");
    while (!cola_circ_esta_llena(&q)) {
        generar_proceso_aleatorio(&q);
    }

    /* Ciclo de procesamiento */
    while (!cola_circ_esta_vacia(&q)) {
        /* Desencolar proceso */
        if (cola_circ_desencolar(&q, &proceso_extraido)) {
            printf("\n<<< DESENCOLADO (Ejecutando): [%s] ID:%04d RAM:%.2fGB\n", 
                    proceso_extraido.nombre, proceso_extraido.numProcess, proceso_extraido.ramRequerida);
        }

        /* Preguntar si desea agregar otro proceso */
        if (!cola_circ_esta_llena(&q)) {
            printf("\n¿Desea agregar un nuevo proceso aleatorio? (1: Si, 0: No): ");
            scanf("%d", &opcion);
            if (opcion == 1) {
                generar_proceso_aleatorio(&q);
            }
        } else {
            printf("\nLa cola está llena, no se pueden agregar más por ahora.\n");
        }
        
        if (cola_circ_esta_vacia(&q)) {
            printf("\nNo hay más procesos en la cola.\n");
        }
    }

    printf("\nSimulación terminada.\n");
    cola_circ_destroy(&q);
    return 0;
}
