/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jose
 *
 * Created on November 19, 2016, 9:36 PM
 */

#include <cstdlib>
#include "Cadena.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <iomanip>
using namespace std;

/*
 * 
 */
const std::string Cadena::letras[4] = { "A" , "C" , "G" , "T" };

double get_CPU_time_usage(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks*1000)/CLOCKS_PER_SEC;
    return diffms;
}



int main(int argc, char** argv) {
    string fileIn;
    string outFile;
    if(argc>1) {
        fileIn = argv[1];
    }
    if(argc>2) {
        outFile = argv[2];
    }
    ifstream file(fileIn);
    if(file.is_open())
    {
        string myArray[100];
        string jeje;
        istream_iterator<std::string> in{ file }, end;
        int count = std::distance(in, end);
        file.clear();
        file.seekg(0, ios::beg);
        cout << count << endl;
        for(int i = 0; i < count; ++i)
        {
          getline(file , myArray[i]);   
        }
        
        vector<Cadena> list;
        Cadena out[count];
        for(int k = 0; k<count ; ++k) {
            Cadena in(myArray[k]);
            cout << myArray[k] << endl;
            list.push_back(in);
            out[k] = in;
        } 
        Cadena sum(myArray[0].length());
        for(int j = 0; j < count ; j++) {
            sum.add(out[j]);
        }
        
        
        ofstream data; 
        data.open("Resultados.txt", ios::app);
        data << "La cadena mas larga en comun: ";
        clock_t begin = clock();
        sum.findPVM(count);
        
        data << sum.motif();
        data << "\n";
        data << "Cadena mas probable: ";
        data << sum.cadenaComun();
        data << "\n";
        data << "La cadena degenerada: ";
        data << sum.cadenaDegenerada();
        clock_t fin = clock();
        data << "\n";
        double** exit = sum.matrizPesos();
        double time = get_CPU_time_usage(begin,fin);
        data << "Tiempo de ejecucion: " << "\t";
        data << -time << "\t\n"; 
        data << "\n";
        data << "Matriz de Pesos de las cadenas: " << "\n";
        data <<"\t" <<  "A" << "\t" << "C" << "\t" << "G" << "\t" << "T" << "\t\n";
        
        for(int w = 0; w <myArray[0].length()-1 ; w++ ){
            data << w+1 << " |" << "\t";
        for(int z =0 ; z<4 ; z++) {
            std::cout << std::fixed;
        std::cout << std::setprecision(2);
            data << exit[w][z]  << "\t";
        }
        data << "\t\n";
        }
    }
    
    return 0;
}

