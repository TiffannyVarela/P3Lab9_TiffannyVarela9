#pragma once
#include "Movimiento.h"

class Pieza
{
protected:
	char**tablero;
	Movimiento* mov1,mov2;
public:
	Pieza();

	virtual bool validarMovimiento(Movimiento*, Movimiento*, char**);
	~Pieza();
	
};