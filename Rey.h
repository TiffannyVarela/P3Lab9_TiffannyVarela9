#include "Pieza.h"
#include "Movimiento.h"
#include <string>
#include <typeinfo>
using namespace std;

#pragma once
class Rey:public Pieza
{
public:
	Rey();
	virtual bool validarMovimiento(Movimiento*,char **);
	~Rey();
	
};