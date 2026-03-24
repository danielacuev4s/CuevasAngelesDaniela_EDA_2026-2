#include <stdio.h> //Biblioteca de entrada y salida
#include "cola.h" //Incluye la interfaz de la cola

int main() {
    Cola c; //Declara la cola
    cola_init(&c); //Inicializa la cola

    //Verifica si la cola esta vacia
    printf("¿Cola vacía? %d\n", cola_esta_vacia(&c));

    /* Encolar algunos valores */
    // Valores con el formato de la estructura
    Dato d1 = {1, "Ana"};
    Dato d2 = {2, "Daniela"};
    Dato d3 = {3, "Naomi"};
    Dato d4 = {4, "Emma"};

    //Inserta los elementos en la cola
    cola_encolar(&c, d1);
    cola_encolar(&c, d2);
    cola_encolar(&c, d3);
    cola_encolar(&c, d4);
    //Muestra el tamaño despues de insertar
    printf("Tamaño tras encolar: %d\n", cola_tamano(&c));

    /* Consultar el frente (peek) */
    Dato a;
    if (cola_frente(&c, &a))
        printf("Frente actual: %d - %s\n", a.identificador, a.nombre);

    /* Desencolar todos, saca elementos uno por uno */
    Dato b;
    while (cola_desencolar(&c, &b)) {
        printf("Desencolado: %d - %s (tam=%d)\n", b.identificador, b.nombre, cola_tamano(&c));
    }

    //Verifica si la cola esta vacía
    printf("¿Cola vacía al final? %d\n", cola_esta_vacia(&c));

    cola_destroy(&c); //libera memoria
    return 0;
}
