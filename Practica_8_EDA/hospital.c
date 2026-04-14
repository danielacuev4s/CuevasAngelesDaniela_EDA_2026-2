#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hospital.h"

/* ================== AUXILIARES ================== */

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int leerEntero(const char *mensaje) {
    int valor;
    while (1) {
        printf("%s", mensaje);
        if (scanf("%d", &valor) == 1) { 
            limpiarBuffer(); 
            return valor; 
        }
        printf("Entrada invalida. Intente de nuevo.\n");
        limpiarBuffer();
    }
}

void leerCadena(const char *mensaje, char *destino, int tam) {
    char buffer[256];
    printf("%s", mensaje);
    if (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(destino, buffer, tam - 1);
        destino[tam - 1] = '\0';
    }
}

int leerNumero4Digitos(const char *mensaje) {
    int numero;
    do { 
        numero = leerEntero(mensaje);
        if (numero <= 0 || numero > 9999)
            printf("Debe ser de 4 digitos.\n");
    } while(numero <= 0 || numero > 9999);
    return numero;
}

/* ================== INICIALIZACION ================== */

void inicializarHospital(struct HOSPITAL *h) {
    strcpy(h->Nombre, "");
    strcpy(h->Direccion, "");
    h->pacientes = NULL;
    h->doctores = NULL;
    h->intendentes = NULL;
    h->especialidades = NULL;
    h->equipos = NULL;
}

void inicializarSistema(struct SISTEMA *s) {
    s->totalHospitales = 0;
    for (int i=0; i<5; i++) 
        inicializarHospital(&s->hospitales[i]);
}

/* ================== SELECCION HOSPITAL ================== */

int seleccionarHospital(struct SISTEMA *s) {
    if (s->totalHospitales==0) {
        printf("No hay hospitales registrados.\n");
        return -1;
    }
    for (int i=0;i<s->totalHospitales;i++)
        printf("%d. %s\n", i+1, s->hospitales[i].Nombre);
    int h;
    do { 
        h = leerEntero("Seleccione hospital: ");
    } while(h<1 || h>s->totalHospitales);
    return h-1;
}

/* ================== FUNCIONES PARA LISTA DOBLEMENTE CIRCULAR ================== */

// Función para agregar nodo a lista doblemente circular
void agregarNodoPaciente(struct NodoPaciente **lista, struct NodoPaciente *nuevo) {
    if (!(*lista)) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *lista = nuevo;
    } else {
        nuevo->siguiente = (*lista)->siguiente;
        nuevo->anterior = *lista;
        (*lista)->siguiente->anterior = nuevo;
        (*lista)->siguiente = nuevo;
        *lista = nuevo;
    }
}

void agregarNodoDoctor(struct NodoDoctor **lista, struct NodoDoctor *nuevo) {
    if (!(*lista)) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *lista = nuevo;
    } else {
        nuevo->siguiente = (*lista)->siguiente;
        nuevo->anterior = *lista;
        (*lista)->siguiente->anterior = nuevo;
        (*lista)->siguiente = nuevo;
        *lista = nuevo;
    }
}

void agregarNodoIntendente(struct NodoIntendente **lista, struct NodoIntendente *nuevo) {
    if (!(*lista)) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *lista = nuevo;
    } else {
        nuevo->siguiente = (*lista)->siguiente;
        nuevo->anterior = *lista;
        (*lista)->siguiente->anterior = nuevo;
        (*lista)->siguiente = nuevo;
        *lista = nuevo;
    }
}

void agregarNodoEspecialidad(struct NodoEspecialidad **lista, struct NodoEspecialidad *nuevo) {
    if (!(*lista)) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *lista = nuevo;
    } else {
        nuevo->siguiente = (*lista)->siguiente;
        nuevo->anterior = *lista;
        (*lista)->siguiente->anterior = nuevo;
        (*lista)->siguiente = nuevo;
        *lista = nuevo;
    }
}

void agregarNodoEquipo(struct NodoEquipo **lista, struct NodoEquipo *nuevo) {
    if (!(*lista)) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *lista = nuevo;
    } else {
        nuevo->siguiente = (*lista)->siguiente;
        nuevo->anterior = *lista;
        (*lista)->siguiente->anterior = nuevo;
        (*lista)->siguiente = nuevo;
        *lista = nuevo;
    }
}

/* ================== AGREGAR DATOS ================== */

void agregarHospital(struct SISTEMA *s) {
    if (s->totalHospitales >= 5) {
        printf("Limite de hospitales alcanzado.\n");
        return;
    }
    int idx = s->totalHospitales;
    inicializarHospital(&s->hospitales[idx]);
    leerCadena("Nombre del hospital: ", s->hospitales[idx].Nombre, 31);
    leerCadena("Direccion del hospital: ", s->hospitales[idx].Direccion, 41);
    s->totalHospitales++;
    printf("Hospital agregado correctamente.\n");
}

void agregarPaciente(struct HOSPITAL *h) {
    struct NodoPaciente *nuevo = malloc(sizeof(struct NodoPaciente));
    if (!nuevo) { printf("Error de memoria\n"); return; }
    leerCadena("Nombre paciente: ", nuevo->paciente.Nombre, 31);
    nuevo->paciente.Edad = leerEntero("Edad: ");
    nuevo->paciente.NumPaciente = leerNumero4Digitos("Num paciente: ");
    agregarNodoPaciente(&h->pacientes, nuevo);
    printf("Paciente agregado.\n");
}

void agregarDoctor(struct HOSPITAL *h) {
    struct NodoDoctor *nuevo = malloc(sizeof(struct NodoDoctor));
    if (!nuevo) { printf("Error de memoria\n"); return; }
    leerCadena("Nombre doctor: ", nuevo->doctor.Nombre, 31);
    nuevo->doctor.Edad = leerEntero("Edad: ");
    nuevo->doctor.Trabajador.NumTrabajador = leerNumero4Digitos("Num trabajador: ");
    agregarNodoDoctor(&h->doctores, nuevo);
    printf("Doctor agregado.\n");
}

void agregarIntendente(struct HOSPITAL *h) {
    struct NodoIntendente *nuevo = malloc(sizeof(struct NodoIntendente));
    if (!nuevo) { printf("Error de memoria\n"); return; }
    leerCadena("Nombre intendente: ", nuevo->intendente.Nombre, 31);
    nuevo->intendente.Edad = leerEntero("Edad: ");
    agregarNodoIntendente(&h->intendentes, nuevo);
    printf("Intendente agregado.\n");
}

void agregarEspecialidad(struct HOSPITAL *h) {
    struct NodoEspecialidad *nuevo = malloc(sizeof(struct NodoEspecialidad));
    if (!nuevo) { printf("Error de memoria\n"); return; }
    leerCadena("Nombre especialidad: ", nuevo->especialidad.Nombre, 31);
    agregarNodoEspecialidad(&h->especialidades, nuevo);
    printf("Especialidad agregada.\n");
}

void agregarEquipo(struct HOSPITAL *h) {
    struct NodoEquipo *nuevo = malloc(sizeof(struct NodoEquipo));
    if (!nuevo) { printf("Error de memoria\n"); return; }
    leerCadena("Nombre equipo: ", nuevo->equipo.Nombre, 31);
    leerCadena("Marca: ", nuevo->equipo.Marca, 31);
    leerCadena("Modelo: ", nuevo->equipo.Modelo, 31);
    agregarNodoEquipo(&h->equipos, nuevo);
    printf("Equipo agregado.\n");
}

/* ================== VISUALIZACION ================== */

void imprimirPaciente(struct NodoPaciente *n) {
    printf("\n--- PACIENTE ---\n");
    printf("Nombre: %s\n", n->paciente.Nombre);
    printf("Edad: %d\n", n->paciente.Edad);
    printf("NumPaciente: %d\n", n->paciente.NumPaciente);
    printf("----------------\n");
}

void imprimirDoctor(struct NodoDoctor *n) {
    printf("\n--- DOCTOR ---\n");
    printf("Nombre: %s\n", n->doctor.Nombre);
    printf("Edad: %d\n", n->doctor.Edad);
    printf("NumTrabajador: %d\n", n->doctor.Trabajador.NumTrabajador);
    printf("---------------\n");
}

void imprimirIntendente(struct NodoIntendente *n) {
    printf("\n--- INTENDENTE ---\n");
    printf("Nombre: %s\n", n->intendente.Nombre);
    printf("Edad: %d\n", n->intendente.Edad);
    printf("------------------\n");
}

void imprimirEspecialidad(struct NodoEspecialidad *n) {
    printf("\n--- ESPECIALIDAD ---\n");
    printf("Nombre: %s\n", n->especialidad.Nombre);
    printf("--------------------\n");
}

void imprimirEquipo(struct NodoEquipo *n) {
    printf("\n--- EQUIPO MEDICO ---\n");
    printf("Nombre: %s\n", n->equipo.Nombre);
    printf("Marca: %s\n", n->equipo.Marca);
    printf("Modelo: %s\n", n->equipo.Modelo);
    printf("---------------------\n");
}

// Función para recorrer lista doblemente circular (con soporte para 'a' = anterior)
void recorrerPacientes(struct NodoPaciente *lista) {
    if (!lista) {
        printf("No hay pacientes.\n");
        return;
    }
    struct NodoPaciente *actual = lista->siguiente;
    char opcion;
    do {
        imprimirPaciente(actual);
        printf("Presione 's' para siguiente, 'a' para anterior, 'q' para salir: ");
        opcion = getchar();
        limpiarBuffer();
        if (opcion == 's' || opcion == 'S') {
            actual = actual->siguiente;
        } else if (opcion == 'a' || opcion == 'A') {
            actual = actual->anterior;
        }
    } while(opcion != 'q' && opcion != 'Q');
}

void recorrerDoctores(struct NodoDoctor *lista) {
    if (!lista) {
        printf("No hay doctores.\n");
        return;
    }
    struct NodoDoctor *actual = lista->siguiente;
    char opcion;
    do {
        imprimirDoctor(actual);
        printf("Presione 's' para siguiente, 'a' para anterior, 'q' para salir: ");
        opcion = getchar();
        limpiarBuffer();
        if (opcion == 's' || opcion == 'S') {
            actual = actual->siguiente;
        } else if (opcion == 'a' || opcion == 'A') {
            actual = actual->anterior;
        }
    } while(opcion != 'q' && opcion != 'Q');
}

void recorrerIntendentes(struct NodoIntendente *lista) {
    if (!lista) {
        printf("No hay intendentes.\n");
        return;
    }
    struct NodoIntendente *actual = lista->siguiente;
    char opcion;
    do {
        imprimirIntendente(actual);
        printf("Presione 's' para siguiente, 'a' para anterior, 'q' para salir: ");
        opcion = getchar();
        limpiarBuffer();
        if (opcion == 's' || opcion == 'S') {
            actual = actual->siguiente;
        } else if (opcion == 'a' || opcion == 'A') {
            actual = actual->anterior;
        }
    } while(opcion != 'q' && opcion != 'Q');
}

void recorrerEspecialidades(struct NodoEspecialidad *lista) {
    if (!lista) {
        printf("No hay especialidades.\n");
        return;
    }
    struct NodoEspecialidad *actual = lista->siguiente;
    char opcion;
    do {
        imprimirEspecialidad(actual);
        printf("Presione 's' para siguiente, 'a' para anterior, 'q' para salir: ");
        opcion = getchar();
        limpiarBuffer();
        if (opcion == 's' || opcion == 'S') {
            actual = actual->siguiente;
        } else if (opcion == 'a' || opcion == 'A') {
            actual = actual->anterior;
        }
    } while(opcion != 'q' && opcion != 'Q');
}

void recorrerEquipos(struct NodoEquipo *lista) {
    if (!lista) {
        printf("No hay equipos.\n");
        return;
    }
    struct NodoEquipo *actual = lista->siguiente;
    char opcion;
    do {
        imprimirEquipo(actual);
        printf("Presione 's' para siguiente, 'a' para anterior, 'q' para salir: ");
        opcion = getchar();
        limpiarBuffer();
        if (opcion == 's' || opcion == 'S') {
            actual = actual->siguiente;
        } else if (opcion == 'a' || opcion == 'A') {
            actual = actual->anterior;
        }
    } while(opcion != 'q' && opcion != 'Q');
}

void visualizarHospital(struct HOSPITAL *h) {
    printf("\n=== DATOS DEL HOSPITAL ===\n");
    printf("Nombre: %s\n", h->Nombre);
    printf("Direccion: %s\n", h->Direccion);
    printf("==========================\n");
}

/* ================== MENU ================== */

void menuAgregarDatos(struct SISTEMA *s) {
    int op, h;
    do {
        printf("\n=== AGREGAR DATOS ===\n");
        printf("1. Hospital\n");
        printf("2. Paciente\n");
        printf("3. Doctor\n");
        printf("4. Intendente\n");
        printf("5. Especialidad\n");
        printf("6. Equipo\n");
        printf("7. Regresar\n");
        op = leerEntero("Opcion: ");
        switch(op) {
            case 1: agregarHospital(s); break;
            case 2: h = seleccionarHospital(s); if(h!=-1) agregarPaciente(&s->hospitales[h]); break;
            case 3: h = seleccionarHospital(s); if(h!=-1) agregarDoctor(&s->hospitales[h]); break;
            case 4: h = seleccionarHospital(s); if(h!=-1) agregarIntendente(&s->hospitales[h]); break;
            case 5: h = seleccionarHospital(s); if(h!=-1) agregarEspecialidad(&s->hospitales[h]); break;
            case 6: h = seleccionarHospital(s); if(h!=-1) agregarEquipo(&s->hospitales[h]); break;
        }
    } while(op != 7);
}

void menuVisualizarDatos(struct SISTEMA *s) {
    int op, h;
    do {
        printf("\n=== VISUALIZAR DATOS ===\n");
        printf("1. Hospital\n");
        printf("2. Pacientes\n");
        printf("3. Doctores\n");
        printf("4. Intendentes\n");
        printf("5. Especialidades\n");
        printf("6. Equipos\n");
        printf("7. Regresar\n");
        op = leerEntero("Opcion: ");
        switch(op) {
            case 1: h = seleccionarHospital(s); if(h!=-1) visualizarHospital(&s->hospitales[h]); break;
            case 2: h = seleccionarHospital(s); if(h!=-1) recorrerPacientes(s->hospitales[h].pacientes); break;
            case 3: h = seleccionarHospital(s); if(h!=-1) recorrerDoctores(s->hospitales[h].doctores); break;
            case 4: h = seleccionarHospital(s); if(h!=-1) recorrerIntendentes(s->hospitales[h].intendentes); break;
            case 5: h = seleccionarHospital(s); if(h!=-1) recorrerEspecialidades(s->hospitales[h].especialidades); break;
            case 6: h = seleccionarHospital(s); if(h!=-1) recorrerEquipos(s->hospitales[h].equipos); break;
        }
    } while(op != 7);
}

/* ================== LIBERAR MEMORIA ================== */

void liberarPacientes(struct NodoPaciente *lista) {
    if (!lista) return;
    struct NodoPaciente *inicio = lista->siguiente;
    struct NodoPaciente *actual = inicio;
    struct NodoPaciente *siguienteNodo;
    do {
        siguienteNodo = actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    } while(actual != inicio);
}

void liberarDoctores(struct NodoDoctor *lista) {
    if (!lista) return;
    struct NodoDoctor *inicio = lista->siguiente;
    struct NodoDoctor *actual = inicio;
    struct NodoDoctor *siguienteNodo;
    do {
        siguienteNodo = actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    } while(actual != inicio);
}

void liberarIntendentes(struct NodoIntendente *lista) {
    if (!lista) return;
    struct NodoIntendente *inicio = lista->siguiente;
    struct NodoIntendente *actual = inicio;
    struct NodoIntendente *siguienteNodo;
    do {
        siguienteNodo = actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    } while(actual != inicio);
}

void liberarEspecialidades(struct NodoEspecialidad *lista) {
    if (!lista) return;
    struct NodoEspecialidad *inicio = lista->siguiente;
    struct NodoEspecialidad *actual = inicio;
    struct NodoEspecialidad *siguienteNodo;
    do {
        siguienteNodo = actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    } while(actual != inicio);
}

void liberarEquipos(struct NodoEquipo *lista) {
    if (!lista) return;
    struct NodoEquipo *inicio = lista->siguiente;
    struct NodoEquipo *actual = inicio;
    struct NodoEquipo *siguienteNodo;
    do {
        siguienteNodo = actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    } while(actual != inicio);
}

void liberarSistema(struct SISTEMA *s) {
    for(int i=0; i<s->totalHospitales; i++){
        liberarPacientes(s->hospitales[i].pacientes);
        liberarDoctores(s->hospitales[i].doctores);
        liberarIntendentes(s->hospitales[i].intendentes);
        liberarEspecialidades(s->hospitales[i].especialidades);
        liberarEquipos(s->hospitales[i].equipos);
    }
}
