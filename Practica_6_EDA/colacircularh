#include "ColaCircular.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Inicializa la cola estableciendo punteros a NULL y tamaño a 0 */
int cola_circ_init(ColaCircular *c, int capacidad) {
    if (!c || capacidad <= 0) return 0;
    c->head = NULL;
    c->tail = NULL;
    c->tam = 0;
    c->capacidad = capacidad;
    return 1;
}

int cola_circ_esta_vacia(ColaCircular *c) {
    return (c == NULL || c->tam == 0);
}

int cola_circ_esta_llena(ColaCircular *c) {
    return (c != NULL && c->tam == c->capacidad);
}

int cola_circ_tamano(ColaCircular *c) {
    return (c ? c->tam : 0);
}

/* Recorre la cola para verificar si el NumProcess ya está registrado */
int id_existe(ColaCircular *c, int id) {
    if (cola_circ_esta_vacia(c)) return 0;
    Nodo *actual = c->head;
    for (int i = 0; i < c->tam; i++) {
        if (actual->numProcess == id) return 1; /* ID encontrado */
        actual = actual->sig;
    }
    return 0; /* ID no encontrado */
}

/* Crea un nuevo nodo y lo inserta al final de la cola */
int cola_circ_encolar(ColaCircular *c, char* nombre, int id, float ram) {
    if (!c || cola_circ_esta_llena(c)) return 0;
    
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo)); /* Reserva memoria para el proceso */
    if (!nuevo) return 0;

    /* Asignación de datos al nuevo nodo */
    strncpy(nuevo->nombre, nombre, 15);
    nuevo->nombre[15] = '\0';
    nuevo->numProcess = id;
    nuevo->ramRequerida = ram;

    if (cola_circ_esta_vacia(c)) {
        c->head = nuevo;
        c->tail = nuevo;
    } else {
        c->tail->sig = nuevo; /* El actual último apunta al nuevo */
        c->tail = nuevo;      /* El nuevo es ahora el último */
    }
    c->tail->sig = c->head;   /* Mantiene la circularidad */
    c->tam++;
    
    printf("\n>>> ENCOLADO: [%s] ID:%04d RAM:%.2fGB\n", nuevo->nombre, nuevo->numProcess, nuevo->ramRequerida);
    return 1;
}

/* Elimina el nodo del frente y copia sus datos a la estructura de salida */
int cola_circ_desencolar(ColaCircular *c, Nodo *salida) {
    if (!c || cola_circ_esta_vacia(c)) return 0;

    Nodo *temp = c->head;
    if (salida) { /* Copiamos los datos antes de liberar la memoria */
        strcpy(salida->nombre, temp->nombre);
        salida->numProcess = temp->numProcess;
        salida->ramRequerida = temp->ramRequerida;
    }

    if (c->tam == 1) {
        c->head = NULL;
        c->tail = NULL;
    } else {
        c->head = c->head->sig; /* El frente avanza al siguiente */
        c->tail->sig = c->head; /* Se reconecta el final con el nuevo frente */
    }

    free(temp); /* Liberamos el nodo procesado */
    c->tam--;
    return 1;
}

/* Libera todos los nodos restantes en la memoria */
void cola_circ_destroy(ColaCircular *c) {
    if (!c) return;
    Nodo dummy;
    while (cola_circ_desencolar(c, &dummy)); /* Desencola hasta que esté vacía */
    c->capacidad = 0;
}
