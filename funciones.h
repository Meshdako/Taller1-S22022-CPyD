#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <math.h>
#include <cmath>
#include <string>

using namespace std;

void Integrantes();

// Extrae el coeficiente y el grado de un término, además de guardarlos en la matriz.
void stringfragtomatriz(string inputfrag, float func[50][2], int indice);

// Separa los términos y utiliza la función stringfragtomatriz().
void stringtomatriz(string input, float func[50][2], int &terminos);

// Realiza los cálculos de la derivada y guarda los datos en otra matriz.
void functoderivade(float func[50][2], float funcderi[50][2], int terminos);

// Realiza una evaluación de un función en el valor x y devuelve el valor.
float evaluacion(float funcion[50][2], float x, int terminos);

// Realiza el cálculo de tolerancia 0.00001 y devuelve un booleano.
bool tolerancia(float x, float xnew);

#endif //FUNCIONES_H