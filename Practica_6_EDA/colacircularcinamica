#ifndef COLA_CIRCULAR_DINAMICA_H
#define COLA_CIRCULAR_DINAMICA_H

/* Estructura que representa un proceso en el Sistema Operativo */
typedef struct Nodo {
    char nombre[16];      /* Nombre del proceso (15 + nulo) */
    int numProcess;       /* ID único de 4 dígitos */
    float ramRequerida;   /* RAM en GB */
    struct Nodo *sig;     /* Puntero al siguiente nodo */
} Nodo;

/* Estructura de control de la cola circular */
typedef struct ColaCircular {
    Nodo *head;           /* Puntero al primer elemento (frente) */
    Nodo *tail;           /* Puntero al último elemento (final) */
    int tam;              /* Contador de elementos actuales */
    int capacidad;        /* Límite máximo definido por el usuario */
} ColaCircular;

/* Prototipos de funciones */
int  cola_circ_init(ColaCircular *c, int capacidad);
int  cola_circ_esta_vacia(ColaCircular *c);
int  cola_circ_esta_llena(ColaCircular *c);
int  cola_circ_tamano(ColaCircular *c);
/* Verifica si un ID de proceso ya existe en la cola */
int  id_existe(ColaCircular *c, int id);
/* Encola un nuevo nodo con datos de proceso */
int  cola_circ_encolar(ColaCircular *c, char* nombre, int id, float ram);
/* Desencola y retorna el nodo (proceso) eliminado */
int  cola_circ_desencolar(ColaCircular *c, Nodo *salida);
void cola_circ_destroy(ColaCircular *c);

#endif
