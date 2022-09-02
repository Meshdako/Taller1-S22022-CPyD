#include <iostream>
#include "funciones.h"

using namespace std;

/**
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * */


int main(int argc, char **argv)
{
   if(argc > 1){
      string input;
      input.append(argv[1]);

      cout << input << endl;

      float func[50][2];
      float func_deri[50][2];

      int terminos = 0;

      stringtomatriz(input, func, terminos);
      functoderivade(func, func_deri, terminos);

      float x = 0;
      float xnew = 1;
      int iteraciones = 0;
      while (tolerancia(x, xnew) == false)
      {
         if (iteraciones > 0){
            x = xnew;
         }

         if(evaluacion(func_deri,x,terminos)==0){
            cout<<"Error: \n\tEvaluación de la derivada de f(x) tiene como resultado = 0";
            return 0;
         }

         xnew = x - (evaluacion(func, x, terminos) / evaluacion(func_deri, x, terminos));
         cout << xnew << " iteracion:" << iteraciones + 1 << "\n";
         iteraciones++;
      }
   }
   else{
      cout << "Ingresa un polinomio." << endl;
   }

   Integrantes();
}
