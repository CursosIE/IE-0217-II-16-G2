#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "stack.h"
#include "queue.h"
#include <random>
#include <chrono>
#include <list>
/**
@file casino.cpp
@author Jose Alberto Barrantes B50881 Alejandro Cedeño
"date 1 de Noviembre del 2016"

*/


/**
Clase que representa los colores y los valores de una carta utilizando enums. Esto facilita el manejo de impresion del color y el valor de una carta. 
*/
class Card
{
public:
    enum Rango {
        Ace = 1, Two, Three, Four, Five, Six, Seven,
        Eight, Nine, Ten, Jack, Queen, King, RangoEnd
    };
    enum Color { Spades, Hearts, Diamonds, Clubs, ColorEnd };

    Card() {

    }

    Card( Rango value, Color suit )
        : m_value(value), m_suit(suit)
    {

    }

/**
Funcion para obtener el valor de una carta.
*/
    Rango value() const { return m_value; }
    /**
    Funcion para obtener el color de una carta.*/
    Color suit() const { return m_suit; }

    friend std::ostream& operator<<( std::ostream &os, const Card &card )
    {
        return os << card.cRangos[card.m_value] << card.cColors[card.m_suit];
      return os << card.sRangos[card.m_value] << " of " << card.sColors[card.m_suit];
    }
    /**
    Funcion para saber si dos cartas son iguales.*/
    bool operator==(Card& a) {
         if(this->m_value == a.m_value && this->m_suit == a.m_suit ) {
    return true;
    }
    else {
    return false;   
    }
 
    }

private:
    static const std::string sRangos[14];
    static const std::string sColors[4];
    static const char cRangos[14];
    static const char cColors[4];
    Rango m_value;
    Color m_suit;
};

const std::string Card::sRangos[14] = {
    "\0", "Ace", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete",
    "Echo", "Nueve", "Diez", "J", "Q", "K"
};
const std::string Card::sColors[4] = { "Espada", "Corazones", "Diamante", "Trebol" };
const char Card::cRangos[14] = {
    '\0', 'A', '2', '3', '4', '5', '6', '7',
    '8', '9', 'T', 'J', 'Q', 'K'
};
const char Card::cColors[4] = { 'E', 'C', 'D', 'T' };

/**
Funcion utlizada para cuando se desea incrementar el valor de una carta.*/
Card::Rango& operator++( Card::Rango &value )
{
    return value = Card::Rango( static_cast<int>(value) + 1 );
}
/**Funcion para "incrementar" el color de una carta.*/
Card::Color& operator++( Card::Color &suit )
{
    return suit = Card::Color( static_cast<int>(suit) + 1 );
}


/**
Clase pilaDeCartas la cual crea una pila con 52 cartas cada una con sus propiedades color y valor, las guarda en un queue donde solo se puede accesar al valor de arriba de la pila.*/
class pilaDeCartas : public Card {
public: 
    std::vector<Card> pila;
    queue<Card> pile;
    pilaDeCartas() {
     for( Card::Color suit = Card::Spades; suit < Card::ColorEnd; ++suit )
        for( Card::Rango value = Card::Ace; value < Card::RangoEnd; ++value ) {
            pila.push_back( Card(value, suit) );
            pile.enqueue(Card(value,suit));
        }
    }
    /**Aleatoriza la baraja*/
    void barajar() { 
        std::srand (std::time(NULL));
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        shuffle (pila.begin(), pila.end(), std::default_random_engine(seed));
        shuffle (&pile.data[0] , &pile.data[pile.tam] , std::default_random_engine(seed));
        //std::random_shuffle(pila.begin(),pila.end());
    }
    /**Saca una carta*/
    Card play() {
        barajar();
        return pile.dequeue();
        pila.pop_back();
    }
    /**Rellena la pila si es un nuevo juego.*/
    void refill() {
        pile.nuevo();
        for( Card::Color suit = Card::Spades; suit < Card::ColorEnd; ++suit )
            for( Card::Rango value = Card::Ace; value < Card::RangoEnd; ++value ) {
                pile.enqueue(Card(value,suit));
            }
    }
    /**Retorna el valor de la carta sacada.*/
    int draw() {
        barajar();
        return pile.dequeue().value();
    }

};

/**
Clase para representar a cada jugador, cada uno de ellos tiene una cantidad de juegos jugados.
Los turnos tomados y su prioridad.*/
class jugador {
public:
    int prioridad; 
    int turno;
    char id;
    int gamesplayed = 1;

    jugador() {
        turno = 0;
    }
    jugador(char a) {
        turno = 0;
        id = a;

    }
    int mano;
    /**Suma el valor de la cartada obtenida a la mano del jugador.*/
    void getCard(int val) {
            mano += val;
            turno ++;
            std::cout << "Mano Actual: " << mano << ' ' << "Player "<< id << ' ' << "Game : " << gamesplayed<< std::endl;
    }

    void newgame() {
        gamesplayed++;
        turno = 0;
        mano = 0;
    }
private: 
    
};

/**
Clase mesa que tiene su propia baraja de cartas, cada mesa tiene un vector de jugadores de tamaño maximo 3.*/
class mesa : public pilaDeCartas {
public:
    std::vector<jugador> ingame;

    //queue<jugador> players;
    int capacity;
    int id;
    int eliminado;
    bool gaem = true;
    int partidas;

    mesa() {
        capacity = 3; 
        ingame.reserve(3);
        id = 1;
    }
    mesa(int num) {
        id = num;
        capacity = 3;
        ingame.reserve(3);
        //std::cout << ingame.size() << std::endl;
    }
    /**Ingresa un jugador a una mesa si hay campo.*/
    void ingresarmesa( jugador Jin) {
        if(capacity > 0) {
           // game.agregar(Jin);
            ingame.push_back(Jin);
            capacity--;

        }
    }
    /**Saca un jugador de la mesa.*/
    void elimplayer(int k) {
        ingame.erase(ingame.begin()+k);    
        capacity++;
    }
    /**Encuentra el ganador de Blackjack.*/
    void findwinner() {
        int temp;
        for(int i = 0 ; i < ingame.size() ; i++) {
            if(ingame[i].mano > temp && ingame[i].mano <= 21) {
                temp = ingame[i].mano;

            }
        }
        std::cout << "Mesa " << this->id <<" Jugadores actuales: " << 3 - capacity <<  std::endl;
        std::cout << "Win Score: " << temp << std::endl;
        for (int k = 0 ; k < ingame.size() ; k++) {
            if(ingame[k].mano > temp || ingame[k].mano < temp || ingame[k].mano != temp) {
                std::cout << "Player: " << ingame[k].id << " Eliminated." << std::endl;
                ingame.erase(ingame.begin()+k);    
                capacity++;
            } 
            if(ingame[k].mano == temp) {
                std::cout << "Player: " << ingame[k].id << "Wins " <<std::endl;
                ingame[k].newgame();
            }

        }
        temp = 0;
    }
    /**Simula una partida hasta que el final del turno donde algun jugador no pida mas cartas.*/
    void partida() {
        while(gaem) {
            for (int i = 0 ; i < ingame.size() ; i++) {
                if(ingame[i].turno == 0) {
                    for (int j = 0 ; j < ingame.size() ; j++) {
                        ingame[j].getCard(draw());
                        ingame[j].getCard(draw());
                        if(ingame[j].mano >= 19) {
                            gaem=false;
                        }
                    }
                   
                }
                if((ingame[i].turno >= 1) && (ingame[i].mano < 19)) {    
                        ingame[i].getCard(draw());
                }
                    if (ingame[i].mano >= 19 ) {
                        gaem = false;
                    }
            }
        }
        findwinner();
        refill();
        gaem = true;
    }

    /**Corre el juego mientras hayan jugadores.*/
    void correrJuego() {
       // std::cout << "Mesa "<< "Partida  " << partidas <<"Espacios Disponibles: "<<capacity <<  std::endl;
        while (capacity != 3) {

        
        partida();
       // partidas++;
        } if (capacity == 3) {
            ingame.clear();
        }

    }

};

/**
Funcion utlizada para llenar una mesa con jugadores.*/
void filltables(std::vector<jugador>& a, mesa& tables) {
    if(tables.capacity > 0) {
        for(int k = 0; k< a.size()+1; k++) {
            tables.ingresarmesa(a[k]);
            a.erase(a.begin()+k);
        }
    }
}

/**La idea es ordenar el string de entrada al correr el programa segun la prioridad 2:1:05.*/
queue<char> ordener(std::string in) {
	int Tra=0;
	int Des=0;
	int Eje=0;
	int i=0;
	queue<char> orden;
	int tam = in.size();
	while(tam > 0) {
			if(Eje<2 && in[i]=='E') {
				orden.enqueue(in[i]);
				std::cout << in[i] << std::endl;
				Eje++;
				i++;
				tam--;
				if(i==tam) {
					i=0;
				}
			}
			else if( Eje/2 == 1 && in[i]=='T' || Eje==0 && in[i]=='T' ) {
				orden.enqueue(in[i]);
				std::cout << in[i] << std::endl;
				Tra++;
				Eje=0;
				i++;
				tam--;
				if(i==tam) {
					i=0;
				}
			}
			else if(Eje%2 == 0 && Tra%2==0 && in[i]=='D') {
				orden.enqueue(in[i]);
				Des++;
				Tra=0;
				i++;
				tam--;
				if(i==tam) {
					i=0;
				}
			}
			else {
				Eje=0;
				Tra=0;
				Des=0;
				i++;

			}
		
	}
	
	return orden;
}
/**Me crea un jugador con id de E, T, D dependiendo si es un Ejecutivo, Trabajador o Desempleados.*/
std::vector<jugador> crearJugadores(queue<char> lista) {
	std::vector<jugador> out;
	for(int i = 0 ; i<lista.size() ; i++) {
		jugador j(lista.data[i]);
		out.push_back(j);
	}
	return out;
}

int main(int argc, char** argv) {
    std::vector<jugador> a;
    mesa table1;
    mesa table2(2);
    mesa table3(3);
    queue<char> fila;
    std::string file = argv[1];
    int size = file.length();
    a = crearJugadores(ordener(file));
    filltables(a,table1);
    if (table1.capacity==0) {
    	filltables(a, table2);
    }
    if(table2.capacity==0) {
    	filltables(a,table3);
    }
    table1.correrJuego();
    table2.correrJuego();
    table3.correrJuego();
	



}
