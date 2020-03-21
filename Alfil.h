#include "Pieza.h"
#include "Movimiento.h"
#include <string>
#include <typeinfo>
using namespace std;

#pragma once
class Alfil:public Pieza
{
public:
	Alfil();
	virtual bool validarMovimiento(Movimiento*,char **);
	~Alfil();
	
};