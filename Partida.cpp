#include "Partida.h"
#include "Movimiento.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

Partida::Partida(){

}

Partida::Partida(string nombre, string pieza, vector<string> movimientos){
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

vector <string> Partida::getMovimientos(){
	return movimientos;
}

void Partida::setMovimientos(vector<string> m){
	movimientos=m;
}

void Partida::guardarPartida(){
	ofstream outfile;
	outfile.open("bitacoraPartidas.txt", std::ios::app);
    outfile<<nombre<<endl;
    outfile<<pieza<<endl;
    for (int i = 0; i < movimientos.size(); ++i)
    {
    	outfile<<movimientos[i];
    	if (i<movimientos.size()-1)
    	{
    		outfile<<";";
    	}
    }
    outfile<<"#";
    outfile<<"--------------------------------------------------------------"<<endl;
	outfile.close();
}

Partida::~Partida(){
	cout<<"Partida Eliminada"<<endl;
}