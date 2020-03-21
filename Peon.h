#include "Pieza.h"
#include "Movimiento.h"
#include <string>
#include <typeinfo>
using std::string;
#pragma once

class Peon:public Pieza
{
public:
	Peon();
	virtual bool validarMovimiento(Movimiento*,char **);
	~Peon();
};