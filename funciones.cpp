#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <math.h>
#include <cmath>
#include <string>

using namespace std;

void Integrantes()
{
    cout << "\n=====Integrantes=====" << endl;
    cout << "* Martín Sobarzo" <<  endl;
    cout << "* Cristóbal Abarca" <<  endl;
    cout << "* Rodrigo Ubilla" <<  endl;
    cout << "* Renato Palominos" <<  endl;
    cout << "* Matías Álvarez" <<  endl;
    cout << "=====================" << endl;
}

void stringfragtomatriz(string inputfrag, float func[50][2], int indice)
{
    /**
     * Definición de variable a utilizar
     * grado_text se iniciliza en 0
     * Por el posible caso de un término tipo "3"
     * */

    string coeficient_text;
    string grado_text = "0";
    int i = 0;

    // Extrae el coeficiente en caso de que el primer elemento del segmento sea 'x' se asume que el coeficiente es 1.
    if (inputfrag[i] == 'x'){
        coeficient_text = "1";
        i += 3;
    }
    else{
        /**
         * En caso contrario se evalua si el primer elemento del segmento es un carácter "-" o un número.
         * Luego se agrega el siguiente elemento hasta que se termine o se encuentre un elemento distinto de un número o un punto.
         * */
        
        if (inputfrag[i] == '1' || inputfrag[i] == '2' || inputfrag[i] == '3' || inputfrag[i] == '4' || inputfrag[i] == '5' || inputfrag[i] == '6' || inputfrag[i] == '7' || inputfrag[i] == '8' || inputfrag[i] == '9' || inputfrag[i] == '0' || inputfrag[i] == '-')
        {
            coeficient_text = inputfrag[i];
            while (inputfrag[i + 1] == '1' || inputfrag[i + 1] == '2' || inputfrag[i + 1] == '3' || inputfrag[i + 1] == '4' || inputfrag[i + 1] == '5' || inputfrag[i + 1] == '6' || inputfrag[i + 1] == '7' || inputfrag[i + 1] == '8' || inputfrag[i + 1] == '9' || inputfrag[i + 1] == '0' || inputfrag[i + 1] == '.')
            {
                coeficient_text = coeficient_text + inputfrag[i + 1];
                i++;
            }
            if (coeficient_text == "-")
            {
                coeficient_text += '1';
            }
            i += 4;
        }
    }

    // Extraer el grado y se verifica que los siguientes elemntos sean números o puntos.
    if (inputfrag[i - 3] == 'x'){
        grado_text = "1";
    }
    if (inputfrag[i] == '1' || inputfrag[i] == '2' || inputfrag[i] == '3' || inputfrag[i] == '4' || inputfrag[i] == '5' || inputfrag[i] == '6' || inputfrag[i] == '7' || inputfrag[i] == '8' || inputfrag[i] == '9' || inputfrag[i] == '-'){
        grado_text = inputfrag[i];
        while (inputfrag[i + 1] == '1' || inputfrag[i + 1] == '2' || inputfrag[i + 1] == '3' || inputfrag[i + 1] == '4' || inputfrag[i + 1] == '5' || inputfrag[i + 1] == '6' || inputfrag[i + 1] == '7' || inputfrag[i + 1] == '8' || inputfrag[i + 1] == '9' || inputfrag[i + 1] == '0' || inputfrag[i + 1] == '.'){
            grado_text = grado_text + inputfrag[i + 1];
            i++;
        }
    }

    // Se define dos variables y inicilizan con el valor numérico de las varibles anteriores, las cuales son almacenadas en la matriz.
    float coeficiente_num = stof(coeficient_text);
    float grado_num = stof(grado_text);
    func[indice][0] = coeficiente_num;
    func[indice][1] = grado_num;
}

void stringtomatriz(string input, float func[50][2], int &terminos)
{
    string fraginput;
    for (int i = 0; i < input.length(); i++){
        if (fraginput != ""){
            if (input[i] == '+'){
                stringfragtomatriz(fraginput, func, terminos);
                fraginput = "";
                terminos++;
            }
            else{
                fraginput += input[i];
                if (input[i + 1] == 0){
                    stringfragtomatriz(fraginput, func, terminos);
                    fraginput = "";
                    terminos++;
                }
            }
        }
        else{
            // Si fraginput está vacio, el primer elemento se guarda.
            fraginput = input[i];
            
            /**
             * Si el siguiente elemento es nulo se manda a la función stringfragtomatriz(). 
             * Se vacía la variable fraginput.
             * */
            if (input[i + 1] == 0){
                stringfragtomatriz(fraginput, func, terminos);
                fraginput = "";
                terminos++;
            }
        }
    }
}

void functoderivade(float func[50][2], float funcderi[50][2], int terminos)
{
    for (int i = 0; i < terminos; i++)
    {
        if (func[i][1] != 0)
        {
            funcderi[i][0] = func[i][0] * func[i][1];
            funcderi[i][1] = func[i][1] - 1.0;
        }
        else
        {
            funcderi[i][0] = 0;
            funcderi[i][1] = func[i][1];
        }
    }
}

float evaluacion(float funcion[50][2], float x, int terminos)
{
    float sum = 0.0;
    for (int i = 0; i < terminos; i++)
    {
        sum += funcion[i][0] * pow(x, funcion[i][1]);
    }
    return sum;
}

bool tolerancia(float x, float xnew)
{
    if (abs(xnew - x) < 0.00001)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif //FUNCIONES_H