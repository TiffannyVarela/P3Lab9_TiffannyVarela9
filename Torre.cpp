#include "Torre.h"
#include "Movimiento.h"
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;

Torre::Torre():Pieza(){

}


bool Torre::validarMovimiento (Movimiento* mov, char** matriz){
    bool retval;
    int r=0;
    for (int i = 1; i < 7; ++i)
    {
        //cout<<"Retval "<<i<<": "<<retval<<endl;
        if (mov->getX1()==mov->getX()+i && mov->getY1()==mov->getY()|| mov->getY1()==mov->getY()+i && mov->getX1()==mov->getX()|| mov->getX1()==mov->getX()-i && mov->getY1()==mov->getY()|| mov->getY1()==mov->getY()-i && mov->getX1()==mov->getX())
        {
            retval=true;
            i=7;
        }
        else{
            retval=false;
        }
    }
    
    return retval;
}

Torre::~Torre(){
    cout<<"Torre Eliminado"<<endl;
}