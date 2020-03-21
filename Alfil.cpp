#include "Alfil.h"
#include "Movimiento.h"
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;

Alfil::Alfil():Pieza(){

}


bool Alfil::validarMovimiento (Movimiento* mov, char** matriz){
    int resp=0;
    for (int i = 1; i < 7; ++i)
    {
        if (mov->getX()!=mov->getX1() && mov->getY()!=mov->getY1() && mov->getX1()==mov->getX()+i && mov->getY1()==mov->getY()+i || mov->getX1()==mov->getX()-i && mov->getY1()==mov->getY()-i)
        {
            resp=2;
        }
    }
    if (resp==2)
    {
        return true;
    }
    else{
        return false;
    }
}

Alfil::~Alfil(){
    cout<<"Alfil Eliminado"<<endl;
}