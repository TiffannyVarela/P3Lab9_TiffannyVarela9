#include "Partida.h"
#include "Movimiento.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Partida::Partida(){

}

Partida::Partida(string nombre, string pieza, vector<Movimiento*> movimientos){
	this->nombre=nombre;
	this->pieza=pieza;
	this->movimientos=movimientos;

}

string Partida::getNombre(){
	return nombre;
}

void Partida::setPieza(string p){
	pieza=p;
}

string Partida::getPieza(){
	return pieza;
}

vector <Movimiento*> Partida::getMovimientos(){
	return movimientos;
}

void Partida::setMovimientos(vector<Movimiento*> m){
	movimientos=m;
}

Partida::~Partida(){
	cout<<"Partida Eliminada"<<endl;
}