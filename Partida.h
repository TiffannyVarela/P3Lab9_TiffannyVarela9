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
	~Partida();
	
};