#include "Peon.h"
#include "Movimiento.h"
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;

Peon::Peon():Pieza(){

}


bool Peon::validarMovimiento (Movimiento* mov, char** matriz){
    bool retval = false;
    if(mov->getY()==1 || mov -> getY()==6){
        if(mov->getY1()==(mov->getY()+2)){
            retval=true;
        }
    }
    else if (mov->getY1()==(mov->getY()+1))
    {
        retval=true;
    }
    else{
        retval=false;
    }
    
    return retval;
}

Peon::~Peon(){
    cout<<"Peon Eliminado"<<endl;
}