/*////////////////////////////////////////////////////////

*Incluido verificar si el tablero esta lleno mediante movimientos
* Verificar si algun jugador gano 
* Verificar si se esta colocando en una posicion valida 

*        URL A GITHUB: https://github.com/Zeistxz/Main-test
/////////////////////////////////////////////////////*/

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int eleccion() {
	char opcion;
	while (true) {
		cout << "Elija si desea ser X u O: ";                                                   //Pide al usuario si desea ser X u O
		cin >> opcion;
		if (opcion != 'X' && opcion != 'O' && opcion != 'x' && opcion != 'o') {
			cout << "Debe introducir X u O, no sea bestia" << endl;
		}
		else {
			cout << "Usted ha decidido ser " << opcion << "\n";

			if (opcion == 'X' || opcion == 'x')
				return 1; 
			else
				return 2;

		}
	}
	return -1;
}


void Tablero(int tabla[3][3]) {                                                     //Forma del tablero 
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << tabla[i][j] << "|";
		}

		cout << "\n----- \n";
	}


}

void turnobot() {
	while (true) {
		int turnobotl = (rand() % 9) + 1;
		int filab = (turnobotl - 1) / 3;
		int columnab = (turnobotl - 1) % 3;
	}
}


int ganadorx(int tabla[3][3])                             //Verifica si gano jugador x
{
	if (((tabla[0][0] == 1) && (tabla[0][1] == 1) && (tabla[0][2] == 1)) || ((tabla[1][0] == 1) && (tabla[1][1] == 1)
		&& (tabla[1][2] == 1)) || ((tabla[2][0] == 1) && (tabla[2][1] == 1) && (tabla[2][2] == 1)))
		return 1;
	else if (((tabla[0][0] == 1) && (tabla[1][0] == 1) && (tabla[2][0] == 1)) || ((tabla[0][1] == 1) && (tabla[1][1] == 1)
		&& (tabla[2][1] == 1)) || ((tabla[0][2] == 1) && (tabla[1][2] == 1) && (tabla[2][2] == 1)))
		return 1;
	else if (((tabla[0][0] == 1) && (tabla[1][1] == 1) && (tabla[2][2] == 1)) || ((tabla[0][2] == 1)
		&& (tabla[1][1] == 1) && (tabla[2][0] == 1)))
		return 1;
	else return 0;
}

int ganadoro(int tabla[3][3])                        //Verifica si gano jugador o
{
	if (((tabla[0][0] == 2) && (tabla[0][1] == 2) && (tabla[0][2] == 2)) || ((tabla[1][0] == 2) && (tabla[1][1] == 2)
		&& (tabla[1][2] == 2)) || ((tabla[2][0] == 2) && (tabla[2][1] == 2) && (tabla[2][2] == 2)))
		return 1;
	else if (((tabla[0][0] == 2) && (tabla[1][0] == 2) && (tabla[2][0] == 2)) || ((tabla[0][1] == 2) && (tabla[1][1] == 2)
		&& (tabla[2][1] == 2)) || ((tabla[0][2] == 2) && (tabla[1][2] == 2) && (tabla[2][2] == 2)))
		return 1;
	else if (((tabla[0][0] == 2) && (tabla[1][1] == 2) && (tabla[2][2] == 2)) || ((tabla[0][2] == 2) && (tabla[1][1] == 2)
		&& (tabla[2][0] == 2)))
		return 1;
	else return 0;
}

int main() {

	int i, j;
	int tabla[3][3];
	int opcion = eleccion();
	int fila, columna;
	int error = 0;
	int movimientosT = 0;                                                 //Verifica la cantidad de movimientos de ambos jugadores, siendo 5 el maximo
	int juegonuevo = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			tabla[i][j] = 0;
		}
	}

	cout << "==== Empezo el juego ===" << endl << endl;

	do {
		if (juegonuevo == 1) { cout << endl << endl; }

		do {
			Tablero(tabla);
			cout << endl;
			cout << "Jugador 1, escriba la fila de la casilla que desea marcar: ";
			cin >> fila;
			cout << "Inserte la columna: "; cin >> columna;
			if (tabla[fila - 1][columna - 1] != 0) {
				error = 1;
				cout << endl << "Error, elija una casilla sin marcar" << endl << endl;
			}
			else {
				tabla[fila - 1][columna - 1] = 1;
				error = 0;
				movimientosT = movimientosT + 1;
			}

		} while (error == 1);

		if (ganadorx(tabla) != 1) {
			do {
				cout << endl << endl;
				Tablero(tabla);
				cout << endl;
				cout << "Jugador 2, escriba la fila de la casilla que desea marcar: ";
				cin >> fila;
				cout << "Inserte la columna: "; cin >> columna;
				if (tabla[fila - 1][columna - 1] != 0)
				{
					error = 1;
					cout << endl << "Error, elija una casilla sin marcar";
				}
				else {
					tabla[fila - 1][columna - 1] = 2;
					error = 0;
					cout << endl << endl;
				}

			} while (error == 1);
		}
	} while ((ganadorx(tabla) != 1) && (ganadoro(tabla) != 1) && (movimientosT <= 5));

	if (ganadorx(tabla) == 1) {
		cout << endl << "Jugador 1 gana!!" << endl;
		Tablero(tabla);
	}
	else {
		if (ganadoro(tabla) == 1) {
			cout << endl << "Jugador 2 gana!!" << endl;
			Tablero(tabla);
		}
		else
		{
			cout << endl << "Esto es un empate";
		}

	}


	cout << "Gracias por jugar";
	cout << endl << endl << "Jugar otra vez? (Si=1 No=0): ";
	cin >> juegonuevo; while (juegonuevo == 1);



	return 0;
}
