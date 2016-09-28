
/* 
 * @File:   Matrix.cpp
 * @Author: jose
 * 
 * @date September 14, 2016, 2:02 PM
 */

#include "Matrix.h"
using namespace std;
/**
 * @brief Me crea una matriz de tamaño ingresado por el usuario y llena sus entradas.
 * Me crea una matriz de tamaño definido por el usuario y luego la llena utilizando dos ciclos "for" que recorre filas y columnas.
 * @code
 * for (i=0; i < this->size; i++ ) {
        mat[i]= new double[this->size];
        for (j=0; j < this->size; j++) {
            cout << "ingrese el numero de la casilla: " << "[" << i << "]" <<"[" <<j<<"]" << endl; 
            cin >> in;
            mat[i][j] = in;
        }
    }
 * @endcode
 * @param mat Es de tipo double** el cual contiene los datos de cada matriz. Es llenada en el constructor
 * @param size Es la dimension de la matriz, solo forma matrices cuadradas. 
 */
Matrix::Matrix() {
    int a;
    cout << "Ingrese dimension de las filas" << endl;
    cin >> a;
    this->filas1 = a;
    int b;
    cout << "Dimension de las columnas: " << endl;
    cin >> b;
    this->columnas = b;
    mat = new double*[this->columnas];
    double in; 
    int i;
    int j;
    for (i=0; i < this->filas1; i++ ) {
        mat[i]= new double[this->filas1];
        for (j=0; j < this->columnas; j++) {
            cout << "ingrese el numero de la casilla: " << "[" << i << "]" <<"[" <<j<<"]" << endl; 
            cout << "Si ingresa algo que no sea un numero el programa se cerrara." << endl;
            cin >> in;
            mat[i][j] = in;
        }
    }
    
    
    
}
/**
 * @brief Constructor utilizado para crear las matrices utilizadas para los resultados de las operaciones.
 * Me crea una matriz nula (puros ceros) de cierta dimension en sus columnas y filas. 
 * @param a Parametro utilizado para diferenciar los constructores
 * @param b Dimension de las filas
 * @param c Dimension de las columnas
 */
Matrix::Matrix(int a, int b, int c) {
    int i;
    int j;
    this->filas1 = b;
    this->columnas = c;
    mat = new double*[this->filas1];
     for (i=0; i < this->filas1; i++ ) {
        mat[i]= new double[this->columnas];
        for (j=0; j < this->columnas; j++) {
            mat[i][j] = 0;
        }
    }
    
}

/**
 * @brief Me crea una matriz de tamaño definido internamente por el usuario y llena sus entradas.
 * Me crea una matriz de tamaño definido por el usuario y luego la llena utilizando dos ciclos "for" que recorre filas y columnas.
 * @code
 * for (i=0; i < this->size; i++ ) {
        mat[i]= new double[this->size];
        for (j=0; j < this->size; j++) {
            cout << "ingrese el numero de la casilla: " << "[" << i << "]" <<"[" <<j<<"]" << endl; 
            cin >> in;
            mat[i][j] = in;
        }
    }
 * @endcode
 * @param mat Es de tipo double** el cual contiene los datos de cada matriz. Es llenada en el constructor
 * @param size Es la dimension de la matriz, solo forma matrices cuadradas.
 * @param a Dimension dado al constructor al inicio para la matriz.
 */
Matrix::Matrix(int a , int b) {
    this->filas1 = a;
    mat = new double*[this->filas1];
    this->columnas = b;
    double in; 
    int i;
    int j;
    for (i=0; i < this->filas1; i++ ) {
        mat[i]= new double[this->columnas];
        for (j=0; j < this->columnas; j++) {
            cout << "ingrese el numero de la casilla: " << "[" << i << "]" <<"[" <<j<<"]" << endl; 
            cin >> in;
            mat[i][j] = in;
        }
    }
    
}
/**
 * @brief Imprime las matriz con este operador.
 */
void  Matrix::operator ~() {
    int i; 
    int j;
    cout << "Resultado: " << endl;
    for (i=0; i < this->filas1 ; i++) {
        cout << "|";
        for (j=0; j < this->columnas ; j++) {
            cout << this->mat[i][j] << " " ;
        }
        cout << "|" << endl;
        cout << endl;
    }
}
/**
 * @brief Me sume cada entrada de this->mat con other.mat y me imprime el resultado de la suma de estas.
 * @code
 * Matrix result(0, this->filas1, this->columnas);
    int i;
    int j;
    if (this->filas1 == other.filas1 && this->columnas == other.columnas) {
        for (i=0; i < this->filas1; i++ ) {
            for (j=0; j < this->columnas; j++) {
                result.mat[i][j]= this->mat[i][j]+other.mat[i][j]; 
            }
        }
    }
 * @endcode
 * @param other Matriz a sumarse con la original.
 */
Matrix Matrix::operator +(const Matrix &other) {
    Matrix result(0, this->filas1, this->columnas);
    int i;
    int j;
    if (this->filas1 == other.filas1 && this->columnas == other.columnas) {
        for (i=0; i < this->filas1; i++ ) {
            for (j=0; j < this->columnas; j++) {
                result.mat[i][j]= this->mat[i][j]+other.mat[i][j]; 
            }
        }
    }
    else {
        throw invalid_argument("No se puede sumar matrices si no tiene la misma cantidad de filas al igual que columnas.");
    }
    cout << "Suma:" << endl;
    ~result;
    return result;
    
}
/**
 * @brief Me resta cada entrada de this->mat con other.mat y me imprime el resultado de la resta de estas.
 * 
 * @param other Matriz a restarse con la original.
 */
Matrix Matrix::operator -(const Matrix& other) {
    Matrix result(0, this->filas1, this->columnas);
    int i;
    int j;
    if (this->filas1 == other.filas1 && this->columnas == other.columnas) {
        for (i=0; i < this->columnas; i++ ) {
            for (j=0; j < this->columnas; j++) {
                result.mat[i][j]= this->mat[i][j]-other.mat[i][j]; 
            }
        }
    }
    else {
        throw invalid_argument("No se puede restar matrices si no tiene la misma cantidad de filas al igual que columnas.");
    }
    cout << "Resta" << endl;
    ~result;
    return result;
   
}

/**
 * @brief Me multiplica las matrices y me imprime el resultado de estas.
 * @param other Matriz a multiplicarse con la primera (la multiplicacion de matrices no permuta).
 * @code
 * int i;
    int j;
    int k;
    double ** result = new double*[this->size];
    for(i=0; i<this->size; ++i){
        result[i] = new double[this->size];
        for(j=0; j<this->size; ++j) {
            for(k=0; k<this->size; ++k) {
                result[i][j]+=this->mat[i][k]*other.mat[k][j];
            }
        }
    }
    Matrix::imprimir(result);
    delete result;
 * @endcode
 */
Matrix Matrix::operator *(const Matrix& other) {
    Matrix result(0, this->filas1, other.columnas);
    int i;
    int j;
    int k;
    if (this->columnas == other.filas1) {
        for(i=0; i<this->filas1; ++i){
            for(j=0; j<other.columnas; ++j) {
                for(k=0; k<this->columnas; ++k) {
                    result.mat[i][j]+=this->mat[i][k]*other.mat[k][j];
                }
            }
        }
       
    }
    else {
        throw invalid_argument("Las matrices no se pueden multiplicar ya que no cumplen columnas de la primera matriz igual a filas de la segunda");
    }
    cout << "Multiplicar" << endl;
    ~result;
    
    return result;
    
}
/**
 * @brief Me divide la entrada de cada matriz con la entrada de la otra matriz si no tienen la misma cantidad de columnas y filas el programa se detiene
 * @param other Matriz a dividir con la primera (la division no permuta).
 */
Matrix Matrix::operator /(const Matrix& other) {
    Matrix result(0, this->filas1 , this->columnas);
    int i;
    int j;
    if (this->filas1 == other.filas1 && this->columnas == other.columnas) {
        for (i=0; i < this->columnas; i++ ) {
            for (j=0; j < this->columnas; j++) {
                result.mat[i][j]= this->mat[i][j]/other.mat[i][j]; 
            }
        }
        cout << "Division" << endl;
        ~result;
        return result;
    }
    else {
        throw invalid_argument("No se puede dividir matrices si no tiene la misma cantidad de filas al igual que columnas.");
    }
}

Matrix::Matrix(const Matrix& orig) {
}

Matrix::~Matrix() {
    delete mat;
}

