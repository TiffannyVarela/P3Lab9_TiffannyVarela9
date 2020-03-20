#include "Movimiento.h"
#include <iostream>
using namespace std;

Movimiento::Movimiento(){

}

Movimiento::Movimiento(int px, int py, int px1, int py1){
    this -> x = px;
    this -> y = py;
    this -> x1 = px1;
    this -> y1 = py1;
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

int Movimiento::getX1(){
    return x1;
}

void Movimiento::setX1(int px1){
    x1 = px1;
}

int Movimiento::getY1(){
    return y1;
}

void Movimiento::setY1(int py1){
    y1 = py1;
}

Movimiento::~Movimiento(){
	cout<<"Movimiento Eliminado"<<endl;
}