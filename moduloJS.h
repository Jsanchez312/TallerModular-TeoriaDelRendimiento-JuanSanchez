/**************************************************************************************
 * Fecha:23/09/2025
 * Autor: Juan Pablo Sánchez
 * Profesor: Jhon Corredor
 * Materia: Sistemas Operativos
 * Tema: Teoría del rendimiento
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices.
 * La idea principal, es construir paso a paso la implementación para hacer uso de la
 * biblioteca PTHREAD. Se implementa el Algoritmo Clásico de multiplicación de matrices, para
 * matrices cuadradas, es decir, la dimensión de filas es igual a la de columnas.
 * A continuación se describen los paso
 *  - Reserva de memoria
 *      - Creación de punteros para matrices del tipo doble
 *      - Asignación de memoria
 *      - Ingreso de argumentos de entrada (Dimensión matriz, número de hilos)
 *      - Validación argumentos de entrada
 *      - Inicializar las matrices
 *      - Imprimir las matrices
 *      - Función para inicializar las matrices
 *      - Función para imprimir las matrices
 *      - Algoritmo clásico de multiplicación matrices
 *  - Se verifica el resultado
 *      - Función para multiplicación las matrices
 *      - Declaración vector de hilos
 *      - Creación de hilos según tamaño de vector de hilos
 *      - Crear estructura de datos que encapsule los argumentos de entrada de la función MM
 * Implementación de paralelismo: resolución de la multiplicación de matrices
 *  - Se crea el vector de hilos
 *  - Se tiene pendiente la exclusión de los hilos
 *  - Se pasa a globales las matrices
 *  - Encapsular los datos para enviarlos a la función MxM
 *  - Se desencapsulan los datos dentro de la función MxM (descomprimen)
*************************************************************************************/
#ifndef MODULO_H
#define MODULO_H

// se usa extern para las variables que se van a usar
extern double *mA, *mB, *mC;
extern struct timeval ini, fin;

// funcion para recibir el tiempo inicial
void InicioMuestra();
//función para recibir tiempo final
void FinMuestra();


//funcion para inicializar los valores con un entero (int)
void iniMatriz(int n, double *m1, double *m2);

// funcion para mostrar los valores con la condicion de que el tamaño sea mayor a 9
void imprMatrices(int n, double *matriz);
//funcion para la multiplicacion de matrices
void multimatrizclasica(double *mA, double *mB, double *mC, int N);
 

#endif
