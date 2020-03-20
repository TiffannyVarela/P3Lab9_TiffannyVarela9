#include "Pieza.h"
#include "Movimiento.h"
#pragma once
#include <string>
#include <vector>
using namespace std;

class Partida
{
protected:
	string nombre;
	string pieza;
	vector <Movimiento*> movimientos;
public:
	Partida();
	Partida(string,string,vector<Movimiento*>);

	string getNombre();

	void setPieza(string);
	string getPieza();

	vector <Movimiento*> getMovimientos();
	void setMovimientos(vector<Movimiento*>);

	~Partida();
	
};