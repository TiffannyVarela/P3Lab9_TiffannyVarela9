#include "Pieza.h"
#include "Partida.h"
#include "Movimiento.h"
#include "Alfil.h"
#include "Peon.h"
#include "Torre.h"
#include "Rey.h"
#include "Reina.h"
#include "Caballo.h"
#include <iostream>
#include <fstream>
//#include <ofstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int menu();

//Provisionar la matriz de chars
char **provisionarMatriz(int);

//liberar memoria de la matriz
void liberarMatriz(char **&, int);

//imprimir la matriz
void printMatrix(char **, int);

//leer la matriz
char **readMatriz(char **, int, int);

int menu2();

string Pieza(int);

int sacar1(string);
int sacar2(string);


int main(int argc, char const *argv[])
{
    int resp=0;
    int opc=0, opc2=0, opc3=0,salir=0;
    int cont=2;
    char **tablero = NULL;
    int size =8;
    string nombre, pieza;
    string coordenada, letra1,coor1,letra2,coor2;
    int x1,y1, x2,y2;
    Movimiento* mov, mov2;
    vector <Movimiento*> movimientos;
    vector <string> text;
    Alfil* alfil;
    Caballo* caballo;
    Peon* peon;
    Reina* reina;
    Rey* rey;
    Torre* torre;
    Partida* partida;

    ifstream texto("bitacoraPartidas.txt");
    string line="";
    vector<string>nombres;
    vector<string>piesas;
    string nom_jug, nom_piec;

    do//inicio do while
    {
        switch(opc=menu()){//inicio switch

            case 1://inicio case 1
                tablero = provisionarMatriz(size);
                cout<<"Nombre de la partida: ";
                cin>>nombre;
                cout<<"Pieza: ";
                opc2=menu2();
                pieza=Pieza(opc2);
                readMatriz(tablero,size,opc2);
                printMatrix(tablero,size);
                do//inicio do while case 1
                {
                    if (cont%2!=0)
                    {
                        cout<<"Ingresar Coordenada NEGRO: ";
                        cin>>coordenada;
                        letra1 = coordenada.substr(1,1);
                        coor1 = coordenada.substr(2,1);
                        y1=sacar1(letra1);
                        x1=sacar2(coor1);

                        letra2 = coordenada.substr(4,1);
                        coor2 = coordenada.substr(5,1);
                        y2=sacar1(letra2);
                        x2=sacar2(coor2);

                        while (x1==20 || y1==20 || x2==20 || y2==20)
                        {
                            cout<<"Coordenada Invalida (Salio del Tablero)"<<endl;
                            cout<<"Ingresar Coordenada: ";
                            cin>>coordenada;
                            letra1 = coordenada.substr(1, 1);
                            coor1 = coordenada.substr(2, 1);
                            y1=sacar1(letra1);
                            x1=sacar2(coor1);

                            letra2 = coordenada.substr(4,1);
                            coor2 = coordenada.substr(5,1);
                            y2=sacar1(letra2);
                            x2=sacar2(coor2);
                        }
                        for (int i = 0; i < size; i++)
                        {
                            for (int j = 0; j < size; j++)
                            {
                                if (i==x1 && j==y1 || i==x2 && j==y2)
                                {
                                    while(tablero[x1][y1] == ' ' || tablero[x2][y2] != ' '){
                                        cout<<"Coordenada Invalida (Primero Posicion Vacia o Segunda Posicion Llena)"<<endl;
                                        cout<<"Ingresar Coordenada: ";
                                        cin>>coordenada;
                                        letra1 = coordenada.substr(1, 1);
                                        coor1 = coordenada.substr(2, 1);
                                        y1=sacar1(letra1);
                                        x1=sacar2(coor1);

                                        letra2 = coordenada.substr(4,1);
                                        coor2 = coordenada.substr(5,1);
                                        y2=sacar1(letra2);
                                        x2=sacar2(coor2);
                                        cout<<tablero[x1][y1]<<endl;
                                    }
                                }
                            }
                        }
                        while(tablero[x1][y1]!='K' && tablero[x1][y1]!='T' && tablero[x1][y1]!='A' && tablero[x1][y1]!='Q' && tablero[x1][y1]!='C' && tablero[x1][y1]!='P' ){
                            cout<<"Coordenada Invalida (Pieza No Perteneciente al Jugador)"<<endl;
                            cout<<"Ingresar Coordenada: ";
                            cin>>coordenada;
                            letra1 = coordenada.substr(1, 1);
                            coor1 = coordenada.substr(2, 1);
                            y1=sacar1(letra1);
                            x1=sacar2(coor1);

                            letra2 = coordenada.substr(4,1);
                            coor2 = coordenada.substr(5,1);
                            y2=sacar1(letra2);
                            x2=sacar2(coor2);
                        }
                        mov= new Movimiento(x1,y1,x2,y2);
                        
                        if (opc2==1)
                        {
                            if (torre->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }

                        if (opc2==2)
                        {
                            if (alfil->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }

                        if (opc2==3)
                        {
                            if (reina->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }

                        if (opc2==4)
                        {
                            if (caballo->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }

                        if (opc2==5)
                        {
                            if (peon->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }
                        
                        cout << "Desea salir? \n1.Si \n2.No\n:";
                        cin >> opc3;
                        if (opc3 == 1)
                        {
                            salir = -4;
                        }
                        else
                        {
                            salir = 0;
                            cont++;
                        }
                    }

                    if (cont%2==0)
                    {
                        cout<<"Ingresar Coordenada BLANCO: ";
                        cin>>coordenada;
                        letra1 = coordenada.substr(1,1);
                        coor1 = coordenada.substr(2,1);
                        y1=sacar1(letra1);
                        x1=sacar2(coor1);

                        letra2 = coordenada.substr(4,1);
                        coor2 = coordenada.substr(5,1);
                        y2=sacar1(letra2);
                        x2=sacar2(coor2);

                        while (x1==20 || y1==20 || x2==20 || y2==20)
                        {
                            cout<<"Coordenada Invalida (Salio del Tablero)"<<endl;
                            cout<<"Ingresar Coordenada: ";
                            cin>>coordenada;
                            letra1 = coordenada.substr(1, 1);
                            coor1 = coordenada.substr(2, 1);
                            y1=sacar1(letra1);
                            x1=sacar2(coor1);

                            letra2 = coordenada.substr(4,1);
                            coor2 = coordenada.substr(5,1);
                            y2=sacar1(letra2);
                            x2=sacar2(coor2);
                        }
                        for (int i = 0; i < size; i++)
                        {
                            for (int j = 0; j < size; j++)
                            {
                                if (i==x1 && j==y1 || i==x2 && j==y2)
                                {
                                    while(tablero[x1][y1] == ' ' || tablero[x2][y2] != ' '){
                                        cout<<"Coordenada Invalida (Primero Posicion Vacia o Segunda Posicion Llena)"<<endl;
                                        cout<<"Ingresar Coordenada: ";
                                        cin>>coordenada;
                                        letra1 = coordenada.substr(1, 1);
                                        coor1 = coordenada.substr(2, 1);
                                        y1=sacar1(letra1);
                                        x1=sacar2(coor1);

                                        letra2 = coordenada.substr(4,1);
                                        coor2 = coordenada.substr(5,1);
                                        y2=sacar1(letra2);
                                        x2=sacar2(coor2);
                                        cout<<tablero[x1][y1]<<endl;
                                    }
                                }
                            }
                        }
                        while(tablero[x1][y1]!='k' && tablero[x1][y1]!='t' && tablero[x1][y1]!='a' && tablero[x1][y1]!='q' && tablero[x1][y1]!='c' && tablero[x1][y1]!='p' ){
                            cout<<"Coordenada Invalida (Pieza No Perteneciente al Jugador)"<<endl;
                            cout<<"Ingresar Coordenada: ";
                            cin>>coordenada;
                            letra1 = coordenada.substr(1, 1);
                            coor1 = coordenada.substr(2, 1);
                            y1=sacar1(letra1);
                            x1=sacar2(coor1);

                            letra2 = coordenada.substr(4,1);
                            coor2 = coordenada.substr(5,1);
                            y2=sacar1(letra2);
                            x2=sacar2(coor2);
                        }
                        mov= new Movimiento(x1,y1,x2,y2);
                        
                        if (opc2==1)
                        {
                            torre = new Torre();
                            if (torre->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }

                        if (opc2==2)
                        {
                            alfil = new Alfil();
                            if (alfil->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }

                        if (opc2==3)
                        {
                            reina = new Reina();
                            if (reina->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }

                        if (opc2==4)
                        {
                            caballo = new Caballo();
                            if (caballo->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }

                        if (opc2==5)
                        {
                            peon = new Peon();
                            if (peon->validarMovimiento(mov,tablero)==true)
                            {
                                text.push_back(coordenada);
                                movimientos.push_back(mov);
                                tablero[x2][y2] = tablero[x1][y1];
                                tablero[x1][y1] = ' ';
                                printMatrix(tablero, size);
                            }
                            else{
                                cout<<"Movimiento Invalido"<<endl;
                            }
                        }
                        cont++;
                    }

                } while (salir!=-4);//fin do while case 1
                partida = new Partida(nombre, pieza, text);
                partida->guardarPartida();
                liberarMatriz(tablero,size);
                cont=1;
                if (opc2==1)
                {
                    delete torre;
                }
                if (opc2==2)
                {
                    delete alfil;
                }
                if (opc2==3)
                {
                    delete reina;
                }
                if (opc2==4)
                {
                    delete caballo;
                }
                if (opc2==5)
                {
                    delete peon;
                }
                for (int i = 0; i < movimientos.size(); i++)
                {
                    delete movimientos[i];
                    movimientos[i] = NULL;
                }
                movimientos.clear();
            break;//fin case 1

            case 2://inicio case 2
                /*if (texto.is_open)
                {
                    while(texto.get()!='#'){
                        texto.unget();
                        getline(texto,nom_jug, '\n');
                        nombres.push_back(nom_jug);
                        getline(texto,nom_piec, '\n');
                        piesas.push_back(nom_piec);
                        //while(texto.get()!='#'){}
                    }
                }*/
            break;//fin case 2

        }//fin switch
        cout<<"Terminar el programa? \n1.Si \n2.No\n:";
        cin>>resp;
    } while (resp!=1);//fin do while
    delete partida;
    cout<<"Finalizado"<<endl;
    return 0;
}

int menu()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Jugar Partida" << endl
             << "2.- Recrear Partida" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 2)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese 1 o 2" << endl;
        }
    } //end del while
    return 0;
}

int menu2()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Torre" << endl
             << "2.- Alfil" << endl
             << "3.- Reina" << endl
             << "4.- Caballo" << endl
             << "5.- Peon" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 5)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese 1 o 5" << endl;
        }
    } //end del while
    return 0;
}

char **provisionarMatriz(int size)
{
    char **matrix = new char *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new char[size];
    }
    return matrix;
}

char **readMatriz(char **matriz, int size, int opc2)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matriz[0][4] = 'K';
            matriz[7][4] = 'k';

            if (opc2 == 1)
            {
                matriz[0][7] = 'T';
                matriz[7][0] = 't';
            }
            if (opc2 == 2)
            {
                matriz[0][5] = 'A';
                matriz[7][2] = 'a';
            }
            if (opc2 == 3)
            {
                matriz[0][3] = 'Q';
                matriz[7][3] = 'q';
            }
            if (opc2 == 4)
            {
                matriz[0][6] = 'C';
                matriz[7][1] = 'c';
            }
            if (opc2 == 5)
            {
                matriz[1][4] = 'P';
                matriz[6][4] = 'p';
            }
            else
            {
                matriz[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
        }
    }
    return matriz;
}

void liberarMatriz(char **&matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix[i] != NULL)
        {
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }

    if (matrix != NULL)
    {
        delete[] matrix;
        matrix = NULL;
    }
}

void printMatrix(char **matriz, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << "[" << matriz[i][j] << "]";

        cout << endl;
    }
}

string Pieza(int opc2){
    string p="";
    if (opc2==1)
    {
        p="Torre";
    }
    if (opc2==2)
    {
        p="Alfil";
    }
    if (opc2==3)
    {
        p="Reina";
    }
    if (opc2==4)
    {
        p="Caballo";
    }
    if (opc2==5)
    {
        p="Peon";
    }
    return p;
}

int sacar1(string coor)
{
    int parte1;
    if (coor == "A" || coor == "a")
    {
        parte1 = 0;
    }
    else if (coor == "B" || coor == "b")
    {
        parte1 = 1;
    }
    else if (coor == "C" || coor == "c")
    {
        parte1 = 2;
    }
    else if (coor == "D" || coor == "d")
    {
        parte1 = 3;
    }
    else if (coor == "E" || coor == "e")
    {
        parte1 = 4;
    }
    else if (coor == "F" || coor == "f")
    {
        parte1 = 5;
    }
    else if (coor == "G" || coor == "g")
    {
        parte1 = 6;
    }
    else if (coor == "H" || coor == "h")
    {
        parte1 = 7;
    }
    else
    {
        parte1 = 20;
    }

    return parte1;
}

int sacar2(string coor)
{
    int parte2;
    if (coor == "1")
    {
        parte2 = 7;
    }
    else if (coor == "2")
    {
        parte2 = 6;
    }
    else if (coor == "3")
    {
        parte2 = 5;
    }
    else if (coor == "4")
    {
        parte2 = 4;
    }
    else if (coor == "5")
    {
        parte2 = 3;
    }
    else if (coor == "6")
    {
        parte2 = 2;
    }
    else if (coor == "7")
    {
        parte2 = 1;
    }
    else if (coor == "8")
    {
        parte2 = 0;
    }
    else
    {
        parte2 = 20;
    }

    return parte2;
}



