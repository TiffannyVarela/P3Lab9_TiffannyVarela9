#include "Pieza.h"
#include "Movimiento.h"
#include <string>
#include <typeinfo>
using namespace std;

#pragma once
class Caballo:public Pieza
{
public:
	Caballo();
	virtual bool validarMovimiento(Movimiento*,char **);
	~Caballo();
	
};