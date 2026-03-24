#include "cola.h" //Se incluye la biblioteca que definimos que contiene la estructuras y prototipos
#include <stdlib.h> //Sirve para usar las funciones de memoria dinámica

/* Nodo privado de la lista, se define el nodo */
struct Nodo {
    Dato dato; //Información almacenada de tipo struct
    Nodo *sig; //Apuntador para el siguiente nodo
    Nodo *ant; //Apuntador para el nodo anterior (doble enlace)
};

//Función que inicializa la cola
void cola_init(Cola *c) {
    if (!c) return; //Verifica que el apuntador no sea NULL
    c->frente = NULL; //No hay elementos al inicio
    c->final  = NULL; //No hay elementos al final
    c->tam    = 0; //Inicializa el tamaño en 0
}

//función para verificar si la cola está vacía
int cola_esta_vacia(Cola *c) {
    if (!c) return 1; //Si no existe, esta vacía
    return (c->tam == 0); //Retorna 1 si esta vacía
}

//Devuelve el tamaño de la cola
int cola_tamano(Cola *c) {
    return c ? c->tam : 0; //Si existe, devuelve el tamaño de la cola y si no, devuelve 0
}

//Función para insertar un elemento al final (cola circular doble)
int cola_encolar(Cola *c, Dato valor) {
    if (!c) return 0; //Verifica que la cola exista

    // Reserva memoria para un nuevo nodo usando malloc
    Nodo nuevo = (Nodo) malloc(sizeof(Nodo));
    if (!nuevo) return 0; // Si falla la memoria, retorna error

    nuevo->dato = valor; // Guarda el dato en el nodo

    //Verifica si la cola está vacía
    if (c->final == NULL) {
        nuevo->sig = nuevo; //Se apunta a sí mismo (circular)
        nuevo->ant = nuevo; //Se apunta a sí mismo (doble)

        c->frente = nuevo; //El nuevo nodo ahora es el primero
        c->final = nuevo;  //Y también el último
    } else {
        nuevo->sig = c->frente; //El nuevo apunta al frente
        nuevo->ant = c->final;  //Apunta al anterior final

        c->final->sig = nuevo;  //El último apunta al nuevo
        c->frente->ant = nuevo; //El frente apunta hacia atrás al nuevo

        c->final = nuevo; //Se actualiza el final
    }

    c->tam++; //Se aumenta el tamaño
    return 1;
}

//Elimina el elemento del principio (frente)
int cola_desencolar(Cola *c, Dato *salida) {
    if (!c || cola_esta_vacia(c)) return 0; //Si esta vacía, error

    Nodo *temp = c->frente; //Guarda el nodo que se desea eliminar

    //Copia el dato si el usuario lo pide
    if (salida)
        *salida = temp->dato;

    //Si solo hay un elemento
    if (c->frente == c->final) {
        c->frente = NULL;
        c->final = NULL;
    } else {
        c->frente = temp->sig; //Avanza el frente

        c->frente->ant = c->final; //Actualiza enlace anterior
        c->final->sig = c->frente; //Mantiene la circularidad
    }

    free(temp); //Libera memoria del nodo que se elimina
    c->tam--; //Disminuye el tamaño

    return 1;
}

// Consulta el elemento del frente sin eliminarlo
int cola_frente(Cola *c, Dato *salida) {
    if (!c || cola_esta_vacia(c)) return 0; // Si está vacía, error

    //Copia el dato del frente
    if (salida)
        *salida = c->frente->dato;

    return 1;
}

//Vacía la cola
void cola_clear(Cola *c) {
    if (!c) return;

    //Mientras haya elementos
    while (!cola_esta_vacia(c)) {
        cola_desencolar(c, NULL); //Elimina uno por uno
    }

    //Reinicia la cola
    c->frente = NULL;
    c->final  = NULL;
    c->tam    = 0;
}

//Elimina o destruye la cola
void cola_destroy(Cola *c) {
    cola_clear(c); //Limpia la memoria
}
