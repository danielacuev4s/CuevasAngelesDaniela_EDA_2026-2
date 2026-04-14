#ifndef HOSPITAL_H_
#define HOSPITAL_H_

/* ================== ESTRUCTURAS ================== */

struct EQUIPO_MEDICO {
    char Nombre[31];
    char Marca[31];
    char Modelo[31];
};

struct ESPECIALIDAD {
    char Nombre[31];
    int CantidadDoctores;
    int CantidadPacientes;
    struct EQUIPO_MEDICO EquipoMedico;
};

struct TRABAJADOR {
    int NumTrabajador;
    int Sindicalizado;
};

struct DOCTOR {
    char Nombre[31];
    int Edad;
    struct ESPECIALIDAD Especialidad;
    struct TRABAJADOR Trabajador;
    int CantidadPacientes;
};

struct INTENDENCIA {
    char Nombre[31];
    int Edad;
    struct TRABAJADOR Trabajador;
};

struct HOSPITAL_BASICO {
    char Nombre[31];
    char Direccion[41];
};

struct PACIENTE {
    char Nombre[31];
    int Edad;
    int NumPaciente;
    struct DOCTOR Doctor;
    struct ESPECIALIDAD Especialidad;
    struct HOSPITAL_BASICO Hospital;
};

/* ================== NODOS DOBLEMENTE CIRCULARES ================== */

struct NodoPaciente { 
    struct PACIENTE paciente; 
    struct NodoPaciente *siguiente;
    struct NodoPaciente *anterior;  // ← NUEVO: puntero anterior
};

struct NodoDoctor { 
    struct DOCTOR doctor; 
    struct NodoDoctor *siguiente;
    struct NodoDoctor *anterior;     // ← NUEVO: puntero anterior
};

struct NodoIntendente { 
    struct INTENDENCIA intendente; 
    struct NodoIntendente *siguiente;
    struct NodoIntendente *anterior; // ← NUEVO: puntero anterior
};

struct NodoEspecialidad { 
    struct ESPECIALIDAD especialidad; 
    struct NodoEspecialidad *siguiente;
    struct NodoEspecialidad *anterior; // ← NUEVO: puntero anterior
};

struct NodoEquipo { 
    struct EQUIPO_MEDICO equipo; 
    struct NodoEquipo *siguiente;
    struct NodoEquipo *anterior;     // ← NUEVO: puntero anterior
};

/* ================== HOSPITAL ================== */

struct HOSPITAL {
    char Nombre[31];
    char Direccion[41];
    struct NodoPaciente *pacientes;
    struct NodoDoctor *doctores;
    struct NodoIntendente *intendentes;
    struct NodoEspecialidad *especialidades;
    struct NodoEquipo *equipos;
};

/* ================== SISTEMA ================== */

struct SISTEMA {
    struct HOSPITAL hospitales[5];
    int totalHospitales;
};

/* ================== PROTOTIPOS ================== */

void limpiarBuffer();
int leerEntero(const char *mensaje);
void leerCadena(const char *mensaje, char *destino, int tam);
int leerNumero4Digitos(const char *mensaje);
void inicializarHospital(struct HOSPITAL *h);
void inicializarSistema(struct SISTEMA *s);
int seleccionarHospital(struct SISTEMA *s);
void agregarHospital(struct SISTEMA *s);
void agregarPaciente(struct HOSPITAL *h);
void agregarDoctor(struct HOSPITAL *h);
void agregarIntendente(struct HOSPITAL *h);
void agregarEspecialidad(struct HOSPITAL *h);
void agregarEquipo(struct HOSPITAL *h);
void visualizarHospital(struct HOSPITAL *h);
void menuAgregarDatos(struct SISTEMA *s);
void menuVisualizarDatos(struct SISTEMA *s);
void liberarSistema(struct SISTEMA *s);

#endif
