#pragma once
#include <string>

class Movimiento
{
protected:
	int x,y;
public:
	Movimiento();
	Movimiento(int,int);

	int getX();
    void setX(int);

    int getY();
    void setY(int);


	~Movimiento();
	
};