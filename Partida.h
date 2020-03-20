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
	vector <string> movimientos;
public:
	Partida();
	Partida(string,string,vector<string>);

	string getNombre();

	void setPieza(string);
	string getPieza();

	vector <string> getMovimientos();
	void setMovimientos(vector<string>);

	void guardarPartida();

	~Partida();
	
};