/**
* @file Lab1.cc
* @author Jose Alberto Barrantes
* @date 28 Aug 2016.
* @brief Programa para obtener la cadena de aminoacidos a partir de una de RNA. 
* Por el medio de dos funciones la cadena ARN obtiene su equivalente en aminoacidos 
* con la ayuda de la funcion ARNaAA. 
* Luego n cantidad de aminoacidos son impresos con la funcion imprimirArregloDeChar.
*
*/
#include "lab1.h"

/**
*  Funcion principal que revisa si la cadena de ARN es multiplo de 3 para correr el programa o no. 
* @code 
*  
    int i;
    int j;
    int aaAImprimir;
    cout << "" << endl;
    int longitud = strlen(argv[1]);
    if (longitud % 3 == 0) {
        cout << "Numero de Aminoacidos a imprimir: " ;
        cin >>  aaAImprimir;
        cout << endl;
        imprimirArregloDeChar(ARNaAA(argv[1] , strlen(argv[1])), aaAImprimir ); 
    }
    else {
        throw invalid_argument("Cadena de multiplo diferente de tres");
    }
   
    return 0;
 * @endcode
 * @param longitud[in] Se utiliza para hacer entero la funcion strlen(). Luego se revisa si es multiplo de 3.
 * @param argc
 * @param argv
 * @param aaImprimir[in] Cantidad de aminoacidos a imprimir del total traducido de la cadena ARN original. 
 * @return Devuelve un 0 en funcion de señal que todo salio bien.
 */
int main(int argc, char**argv) {
    
    int i;
    int j;
    int aaAImprimir;
    cout << "" << endl;
    int longitud = strlen(argv[1]);
    if (longitud % 3 == 0) {
        cout << "Numero de Aminoacidos a imprimir: " ;
        cin >>  aaAImprimir;
        cout << endl;
        imprimirArregloDeChar(ARNaAA(argv[1] , strlen(argv[1])), aaAImprimir ); 
    }
    else {
        throw invalid_argument("Cadena de multiplo diferente de tres");
    }
   
    return 0;
    
}
