#include "Partida.h"
#include "Movimiento.h"
#include <string>
#include <vector>
using namespace std;

Partida::Partida(){

}

Partida::Partida(string nombre, string pieza, vector<Movimiento*> movimientos){
	this->nombre=nombre;
	this->pieza=pieza;
	this->movimientos=movimientos;

}