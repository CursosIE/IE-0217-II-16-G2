/**
* @file ARNaAA.cpp 
* @author Jose Alberto Barrantes
* @date 28 Aug 2016.
* @brief funciones utilizadas para obtener la cadena de aminoacidos a partir de una de ARN. 
* Por el medio de dos funciones Lab1.cc obtiene la cadena de ARN y primero obtiene su equivalente en aminoacidos 
* con la ayuda de la funcion ARNaAA. 
* Luego n cantidad de aminoacidos son impresos con la funcion imprimirArregloDeChar.
* 
*/
#include <iostream>
using namespace std;

/**
 * @brief Funcion para imprimir n terminos del arreglo de aminoacidos.
 * Funcion para imprimir n cantidad de aminoacidos contenidos en 
 * el  arreglo obtenido de la funcion ARNaAA.
 * @code
 *  int i;
    cout << '|' ;
    for (i=0; i<n; i++) {
        cout <<  a[i];
    }
    cout << '|' << endl;
 * @endcode
 * @param n cantidad de aminoacidos a imprimir en la consola; ingresado por el usuario. 
 * 
 */

void imprimirArregloDeChar (char* a, int n) {
    int i;
    cout << '|' ;
    for (i=0; i<n; i++) {
        cout <<  a[i];
    }
    cout << '|' << endl;
}
/** 
 *@brief Funcion que recive un arreglo y su longitud. 
 * Funcion la cual parsea la cadena de ARN ingresada por el usuario y por medio de comparacion llena un arreglo de salida de los 
 * aminoacidos includios en la cadena de ARN. 
 *@code 
 *  char * re = new char [a];
    int i;
    int nextAA;
    
    for (i=3 ; i<(a-3) ;i+=3) {
        if (RNA[i]=='U') {
            if (RNA[i+1]=='U') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C') {
 *                  .
 *                  .
 *                  .
 * 
    return re;
    delete re;
    }
 * @endcode
 * @param re[out] Puntero del tamaño de la cadena de ARN. 
 * @param mextAA contador externo para agregar aminoacidos al arreglo "re". 
 * 
 * 
 */
char* ARNaAA(char * RNA, int a) { 
    char * re = new char [a];
    int i;
    int nextAA;
    
    for (i=3 ; i<(a-3) ;i+=3) {
        if (RNA[i]=='U') {
            if (RNA[i+1]=='U') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C') {
                    re[nextAA] = 'F';
                    
                    nextAA++;
                }
                if (RNA[i+2]=='A' || RNA[i+2]=='G') {
                   
                    re[nextAA] = 'L'; 
                    nextAA++;
                }
            }
            if (RNA[i+1]=='C') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A' || RNA[i+2]=='G') {
                   
                    re[nextAA] = 'S'; 
                    nextAA++;
                }
                
            }
            if (RNA[i+1]=='A') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C') {
                    
                    re[nextAA] = 'Y'; 
                    nextAA++;
                }
            }
            if (RNA[i+1]=='G') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C') {
                   
                    re[nextAA] = 'C'; 
                    nextAA++;
                }
                if (RNA[i+2]=='G') {
                  
                    re[nextAA] = 'W'; 
                    nextAA++;
                }
            }
        }
        if (RNA[i]=='C') {
            if (RNA[i+1]=='U') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A' || RNA[i+2]=='G') {
                   
                    re[nextAA] = 'L'; 
                    nextAA++;
                }

            }
            if (RNA[i+1]=='C') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A' || RNA[i+2]=='G') {
                   
                    re[nextAA] = 'P'; 
                    nextAA++;
                }
            }
            if (RNA[i+1]=='A') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C') {
                   
                    re[nextAA] = 'H'; 
                    nextAA++;
                }
                if (RNA[i+2]=='A' || RNA[i+2]=='G') {
                   
                    re[nextAA] = 'Q'; 
                    nextAA++;
                }
                
            }
            if (RNA[i+1]=='G') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A' || RNA[i+2]=='G') {
                   
                    re[nextAA] = 'R'; 
                    nextAA++;
                }
            }
        }
        if (RNA[i]=='A') {
            if (RNA[i+1]=='U') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A') {
                    
                    re[nextAA] = 'I'; 
                    nextAA++;
                }
                if (RNA[i+2]=='G') {
                   
                    re[nextAA] = 'M'; 
                    nextAA++;
                }
            }
            if (RNA[i+1]=='C') {
                if(RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A' || RNA[i+2]=='G') {
                  
                    re[nextAA] = 'T'; 
                    nextAA++;
                }
            }
            if (RNA[i+1]=='A') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C') {
                    re[nextAA] = 'N'; 
                    nextAA++;
                }
                if (RNA[i+2]=='A' || RNA[i+2]=='G') {
                    re[nextAA] = 'K'; 
                    nextAA++;
                }
            }
            if (RNA[i+1]=='G') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C') {
                    re[nextAA] = 'S'; 
                    nextAA++;
                }
                if (RNA[i+2]=='A' || RNA[i+2]=='G') {
                    re[nextAA] = 'R'; 
                    nextAA++;
                }
            }
        }
        if (RNA[i]=='G') {
            if (RNA[i+1]=='U') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A' || RNA[i+2]=='G') {
                    re[nextAA] = 'V'; 
                    nextAA++;
                }
                    
            }
            if (RNA[i+1]=='C') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A' || RNA[i+2]=='G') {
                    re[nextAA] = 'A'; 
                    nextAA++;
                }
            }
            if (RNA[i+1]=='A') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C') {
                    re[nextAA] = 'D'; 
                    nextAA++;
                }
                if (RNA[i+2]=='A' || RNA[i+2]=='G') {
                    re[nextAA] = 'E'; 
                    nextAA++;
                }
            }
            if (RNA[i+1]=='G') {
                if (RNA[i+2]=='U' || RNA[i+2]=='C' || RNA[i+2]=='A' || RNA[i+2]=='G') {
                    re[nextAA] = 'G'; 
                    nextAA++;
                }
            }
        }
        
    }
   
    return re;
    delete re;
}
