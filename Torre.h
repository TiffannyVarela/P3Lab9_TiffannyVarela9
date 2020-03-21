#include "Pieza.h"
#include "Movimiento.h"
#include <string>
#include <typeinfo>
using namespace std;

#pragma once
class Torre:public Pieza
{
public:
	Torre();
	virtual bool validarMovimiento(Movimiento*,char **);
	~Torre();
	
};