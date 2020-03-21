#include "Rey.h"
#include "Movimiento.h"
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;

Rey::Rey():Pieza(){

}


bool Rey::validarMovimiento (Movimiento* mov, char** matriz){
    if (mov->getX1()==mov->getX()+1 || mov->getX1()==mov->getX()-1 || mov->getY1()==mov->getY()+1 || mov->getY1()==mov->getY()-1 || mov->getX1()==mov->getX()+1 && mov->getY1()==mov->getY()+1 || mov->getX1()==mov->getX()-1 && mov->getY1()==mov->getY()-1)
    {
        return true;
    }
    else{
        return false;
    }
}

Rey::~Rey(){
    cout<<"Rey Eliminado"<<endl;
}