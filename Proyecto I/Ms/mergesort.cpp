
/** 
 * @file mergesort.cpp
 * @author Jose Alberto Barrantes B50881 Alejandro Cedeño B41672
 * 
 */

#include <cstdlib>
#include "head.h"
using namespace std;

/**
 * @brief Funcion la cual recibe el arreglo y por medio de dos contadores a cada lado del arreglo al terminar su ejecucion deja el arreglo original a ordenado. 
 * Funcion recibe un arreglo a el cual por medio de dos contadores uno a la izquierda y otro a la derecha se recorre el arreglo por ambos lados revisando que los valores
 * del lado izquierdo deben ser menores a los del lado derecho. Luego cuando ambos contadores de juntan se revisa si la variable ini la cual simboliza la cantidad de elementos que ya fueron
 * menores al lado derecho es mayor al valor mid; si esto sucede significa que todos los elementos del lado derecho fueron menores a los del izquier y solo faltan copiar los valores de ini hasta end.
 * Faltan copiar el resto de elementos sobre el arreglo result, de forma similar si ini es menor a mid.
 * 
 * @param a Arreglo a ordenar.
 * @param beg Indice de inicio del arreglo.
 * @param end Indice de final del arreglo.
 * @param mid Indice punto medio del arreglo 
 * @return 0 para decir que todo salio bien.
 */
int * merge (int a[], int beg, int end, int mid) {
    int* result = new int[end+1-beg];
    int mitad = mid + 1;
    int i = 0;
    int ini = beg;
    while ((ini<=mid) && (mitad<=end)) {
            
        if (a[ini]<=a[mitad]) {
            result[i] = a[ini];
            ini++;
        }
        else {
            result[i] = a[mitad];
            mitad++;
        }
        i++;
    }
    if(ini>mid)  
    {  
        for(int k = mitad;k<=end;k++)  
        {  
            result[i]=a[k];  
            i++;  
        }  
    }  
    else  
    {  
        for(int k = ini;k<=mid;k++)  
        {  
            result[i]=a[k];  
            i++;  
        }  
    } 
    for(int z=0;z<=end-beg;z++)   
    {  
        a[z+beg]=result[z];  
    } 
    delete result;
    return 0;
    
}
/**
 * Funcion para imprimir el arreglo.
 * @param p Arreglo 
 * @param size Tamaño de este
 */
void imprimir(int p[], int size) {
    cout << "[";
    for (int i = 0; i<size-1; i++) {
        
        cout << p[i] << " " << ",";
    }
    cout <<p[size-1];
    cout << "]" << endl;
    
}
/**
 * @brief Funcion la llama la funcion sort sobre ambas mitades del arreglo de forma recursiva hasta tener un arreglo de tamaño 1.
 * @param a Arreglo a ordenar
 * @param beg Indice de inicio del arreglo (usualmente 0)
 * @param end Indice de final
 * @return 
 */
int * sort (int a[], int beg, int end) {
    int mid;
    if (beg<end) {
        mid = (beg+end)/2;
        sort(a,beg,mid);
        sort(a,mid+1,end);
        return merge(a,beg,end,mid);
        
    }
    else {
        return 0;
    }
}
/**
 * Funcion utlizada para obtener el tiempo de procesamiento en milisegundos.
 * @param clock1 Tiempo inicial
 * @param clock2 Tiempo final
 * @return returna la diferencia de final-inicial.
 */
double get_CPU_time_usage(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks*1000)/CLOCKS_PER_SEC;
    return diffms;
}

int main(int argc, char** argv) {
    
    srand(time(NULL));
    ofstream data;
    data.open("mergesort.txt", ios::app);
    int tam;
    cout << "-----------------------mergesort------------------" << endl;
    cout << "Tamaño del arreglo: " << endl;
    cin >> tam;
    int a[tam];
    for (int i = 0; i<tam; i++) {
        a[i] = rand() % tam;
    }
    cout << "Arreglo aleatorio --------" << endl;
    imprimir(a,tam);
    clock_t begin = clock();
    sort(a,0,tam-1);
    clock_t end = clock();
    double time = get_CPU_time_usage(begin,end);
    data << tam << "\t";
    data << -time << "\t\n";
    cout << "CPU time in ms:" << -time << endl;
    cout << "Arreglo ordenado ----------" << endl;
    imprimir(a,tam);
    data.close();
    return 0;
}

