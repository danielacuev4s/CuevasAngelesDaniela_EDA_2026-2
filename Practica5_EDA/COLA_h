#ifndef COLA_H
#define COLA_H

//Se define la estructura que utilizara cola
typedef struct {
    int identificador; //Numero para identificar el dato
    char nombre[40]; // Se define una cadena de caracteres
} Dato;

/* Declaración adelantada */
typedef struct Nodo Nodo;

/* Cola FIFO basada en lista ligada simple */
typedef struct Cola {
    Nodo *frente; /* head: Apunta al primer elemento (sale primero) */
    Nodo *final;  /* tail: Apunta al último elemento (entra último) */
    int   tam;    /* tamaño como entero, para el tamaño actual de la cola */
} Cola;

/* Interfaz, prototipos de las funciones que se utilizaran */
//Función que inicializa la cola
void cola_init(Cola *c);
//Función para verificar si la cola esta vacía
int  cola_esta_vacia(Cola *c);
//Función para devolver el tamaño
int  cola_tamano(Cola *c);

//Función para insertar un elemento al final de la cola
int  cola_encolar(Cola *c, Dato valor);        /* enqueue O(1) */ //Se cambian los datos de tipo entero definidos anteriormente, por datos de tipo "Dato", que es la estructura
//Eliminar el elemento del frente
int  cola_desencolar(Cola *c, Dato *salida);   /* dequeue O(1) */
//Consultar el elemento que esta al frente pero sin eliminarlo
int  cola_frente(Cola *c, Dato *salida); /* peek O(1) */

//Funciones para vaciar la cola, limpiar y la segunda para liberar la memoria de cola
void cola_clear(Cola *c);
void cola_destroy(Cola *c);

#endif /* COLA_H */
