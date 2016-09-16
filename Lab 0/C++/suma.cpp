/**
* @file suma.c
* @author Jose Alberto
* @date 19 Aug 2016 
* @brief Programa para sumar argumentos flotantes ingresados. 
*
* Metodo el cual suma los argumentos flotantes ingresados a la hora de correr el programa, luego 
* retorna el resultado de dicha suma de argumentos. 
*/ 
#include <stdio.h>
#include <iostream>

using namespace std;
float sumar(int a, char **b) {
	/** 
* @brief Funcion para sumar argumentos
* @code 
* for (int i=1;i<a;i++) {
*		float num;
*		sscanf(b[i], "%f", &num);
*		suma+=num; 
*	}
*	return suma;
*
* @endcode
* @param num Variable para guardar temporalmente cada argumento ingresado para sumarse.
* @param suma Variable la cual recibe y guarda el resultado de la suma de la fila de argumentos *   ingresados.  
* @return Funcion devuelve el resultado de la suma 
*/
	float suma=0.0;
	for(int i=1;i<a;i++) {
		float num;
		sscanf(b[i], "%f", &num);
		suma+=num;
	}
	return suma;
}
int main(int argc, char **argv){
/** 
* @brief Funcion principal que corre el programa. 
* @code 
*float result= sumar(argc, argv);
*	printf("%.6f\n",result);
*	return 0;
* @endcode
* @return Devuelve un 0 para mostrar que todo se corrio bien.
*/
	float result = sumar(argc , argv);
	cout<<result<<endl;
	return 0;
}

