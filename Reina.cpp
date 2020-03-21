#include "Reina.h"
#include "Movimiento.h"
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;

Reina::Reina():Pieza(){

}


bool Reina::validarMovimiento (Movimiento* mov, char** matriz){
    return true;
}

Reina::~Reina(){
    cout<<"Reina Eliminado"<<endl;
}