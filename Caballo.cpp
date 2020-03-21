#include "Caballo.h"
#include "Movimiento.h"
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;

Caballo::Caballo():Pieza(){

}


bool Caballo::validarMovimiento (Movimiento* mov, char** matriz){
    if (mov->getX()==mov->getX()+2 && mov->getY1()==mov->getY()+1 || mov->getY1()==mov->getY()-1 || mov->getY()==mov->getY()+2 && mov->getX1()==mov->getX()+1 || mov->getX1()==mov->getX()-1)
    {
    	return true;
    }
    else{
    	return false;
    }
}

Caballo::~Caballo(){
    cout<<"Caballo Eliminado"<<endl;
}