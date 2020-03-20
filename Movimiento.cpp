#include "Movimiento.h"
#include <iostream>
using namespace std;

Movimiento::Movimiento(){

}

Movimiento::Movimiento(int px, int py){
    this -> x = px;
    this -> y = py;
}


int Movimiento::getX(){
    return x;
}

void Movimiento::setX(int px){
    x = px;
}

int Movimiento::getY(){
    return y;
}

void Movimiento::setY(int py){
    y = py;
}

Movimiento::~Movimiento(){
	cout<<"Movimiento Eliminado"<<endl;
}