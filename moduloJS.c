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
#include <stdio.h>     
#include <stdlib.h>     
#include <sys/time.h>   
#include "moduloJS.h"     

// variables para las matrices
double *mA, *mB, *mC;
struct timeval ini, fin;


// esta funcion recibe el tiempo inicial

void InicioMuestra(){
	gettimeofday(&ini, (void *)0); 
}


// esta función toma el tiempo final
// calcula el tiempo en microsegundos en vez de segundos

void FinMuestra(){
	gettimeofday(&fin, (void *)0);  
	fin.tv_usec -= ini.tv_usec;      // Resta los microsegundos iniciales de los microsegundos finales
	fin.tv_sec  -= ini.tv_sec;       // Resta los segundos iniciales de los microsegundos finales
	double tiempo = (double)(fin.tv_sec*1000000 + fin.tv_usec); // convierte segundos a microsegundos
	printf("%9.0f \n", tiempo);      // muestra el tiempo calculado
}


// esta función inicializa las dos matrices con valores predeterminados

void iniMatriz(int n, double *m1, double *m2){
   	for(int i=0; i<n*n; i++){
	        m1[i] = i*2.3 + 1.3;
	        m2[i] = i*2.3;
	}
}


// esta funcion muestra la matriz que se recibe como parámetro
// se incluye la condicion de imprimir solo si el tamaño es menor que 9

void imprMatrices(int n, double *matriz){
    if(n<9){
        printf("\n#######################################################\n");
   	for(int i=0; i<n*n; i++){
                if(i%n==0) printf("\n");    
	        printf(" %f ", matriz[i]);     
        }
        printf("\n#######################################################\n");
    }
}


// esta funcion multiplica dos matrices de tamaño N
void multimatrizclasica(double *mA, double *mB, double *mC, int N) {
    for (int i = 0; i < N; i++) {           
        for (int j = 0; j < N; j++) {     
            double sumaTemp = 0.0;          
            double *pA = mA + i * N;       
            double *pB = mB + j;           
            for (int k = 0; k < N; k++, pA++, pB += N) {
                sumaTemp += (*pA) * (*pB);
            }
            mC[j + i * N] = sumaTemp;
        }
    }
}
