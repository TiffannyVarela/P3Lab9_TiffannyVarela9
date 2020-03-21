#include "Pieza.h"
#include "Movimiento.h"
#include <string>
#include <typeinfo>
using namespace std;

#pragma once
class Reina:public Pieza
{
public:
	Reina();
	virtual bool validarMovimiento(Movimiento*,char **);
	~Reina();
	
};