
/**
 * @file quicksort.cpp
 * @author Jose Alberto Barrantes B50881 Alejando Cedeño B41672
 */

#include <cstdlib>
#include "head.h"
using namespace std;

/**
 * Funcion quicksort la cual recive un arreglo, su indice derecho y izquierdo. Luego dependiendo de la implementacion calcula un valor pivot para comparar los valores del arreglo.
 * Con dos ciclos while se recurre el arreglo, se asume que los valores del lado derecho son mayores al pivot y del lado derecho menores; si esto no se cumple se cambiar los elementos.
 * Luego si al recorrer ambos ciclos las variables i y j no son mayores o menores a right o left dependiendo del caso significa que el arreglo no esta ordenado por ende se llama quicksort de manera recursiva
 * sobre ambos lados del arreglo. 
 * @param arg Arreglo a ordenar. 
 * @param left Indice de la izquierda
 * @param right Indice de la derecha
 */
void quickSort (int arg[], int left, int right) {
    int tmp;
    int i = left;
    int j = right;
    int pivot = arg[(left+right)/2];
    while (i<=j) {
        while (arg[i]<pivot) {
            i++;
        }
        while (arg[j]>pivot) {
            j--;
        }
        if (i<=j) {
            tmp = arg[i];
            arg[i] = arg[j];
            arg[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(arg, left, j);
    }
    if (i < right) {
        quickSort(arg, i, right);
    }
}
/**
 * Funcion para calcular el tiempo del procesador
 * @param clock1 Tiempo inicial
 * @param clock2 Tiempo final
 * @return Diferencia entre final-inicial en milisegundos. 
 */
double get_CPU_time_usage(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks*1000)/CLOCKS_PER_SEC;
    return diffms;
}
/**
 * Funcion para imprimir algun arreglo p.
 * @param p Arreglo a imprimir
 * @param size Tamaño de este.
 */
void imprimir(int p[], int size) {
    cout << "[";
    for (int i = 0; i<size; i++) {
        cout<< p[i] << " " << ",";
    }
    cout<< p[size-1];
    cout << "]"<< endl;
}

int main(int argc, char** argv) {

    int tam;
    cout << "---------------------------quicksort-------------------" << endl;
    cout << "Tamaño del arreglo: " << endl;
    cin >> tam;
    int a[tam];
    ofstream data;
    data.open("quickSort.txt", ios::app);
    srand(time(NULL));
    for (int i = 0; i<tam; i++) {
        a[i] = rand() %tam+2;
    }
    cout << "Arreglo sin ordenar -------" << endl;
    imprimir(a,tam);
    clock_t begin = clock();
    quickSort(a , 0 , tam-1);
    clock_t end = clock(); 
    double time = get_CPU_time_usage(begin,end);
    data << tam << "\t" ;
    data << -time << "\t\n";
    cout << "Arreglo ordenado------------" << endl;
    imprimir(a,tam);
    cout << "CPU time " << -time << " ms " << endl;
    data.close();
    return 0;
}

