#include "Pieza.h"
#include "Partida.h"
#include "Movimiento.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstlib>
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


int main(int argc, char const *argv[])
{
    int resp=0;
    int opc=0, opc2=0;

    do//inicio do while
    {
        switch(opc=menu()){//inicio switch

            case 1://inicio case 1
            break;//fin case 1

            case 2://inicio case 2
            break;//fin case 2

        }//fin switch
    } while (resp!=2);//fin do while

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
             << "3.- Dama" << endl
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

