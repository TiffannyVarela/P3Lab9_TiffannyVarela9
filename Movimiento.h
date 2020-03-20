#pragma once
#include <string>

class Movimiento
{
protected:
	int x,y,x1,y1;
public:
	Movimiento();
	Movimiento(int,int,int,int);

	int getX();
    void setX(int);

    int getY();
    void setY(int);

    int getX1();
    void setX1(int);

    int getY1();
    void setY1(int);

	~Movimiento();
	
};