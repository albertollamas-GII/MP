#include <iostream>
#include <fstream>
#include <iomanip>
#include "Matriz2D_1.h"

using namespace std;

/*************************************************************************/
/*************************************************************************/

int main (int argc, char * argv[])
{
	
	cout << "/////////////////////////////////////////////////////////" << endl;
	cout << "**********************   SESION 9   *********************" << endl;
	cout << "/////////////////////////////////////////////////////////" << endl;
	cout << endl << endl;

	cout << "Probamos el constructor sin argumentos (matriz vacia)" << endl;

	// Constructor sin argumentos 
	Matriz2D_1 matriz_1;

	cout << "El num. de filas de la matriz es: " << matriz_1.GetFilas() << endl;
	cout << "El num. de columnas de la matriz es: " << matriz_1.GetColumnas()
		 << endl;

	cout << endl;

	cout << "Probamos el constructor con un argumento (matriz 5*5)" << endl;

	// Constructor con un argumento
	Matriz2D_1 matriz_2(5);

	cout << "El num. de filas de la matriz es: " << matriz_2.GetFilas() << endl;
	cout << "El num. de columnas de la matriz es: " << matriz_2.GetColumnas()
		 << endl;

	cout << endl;

	cout << "Probamos el constructor con dos argumentos (matriz 7*4)" << endl;

	// Constructor con dos argumentos
	Matriz2D_1 matriz_3(7,4);

	cout << "El num. de filas de la matriz es: " << matriz_3.GetFilas() << endl;
	cout << "El num. de columnas de la matriz es: " << matriz_3.GetColumnas()
		 << endl;

	cout << endl;

	cout << "Probamos el constructor con tres argumentos (matriz 7*4 cuyo "
		 << "valor es 6 en todas las posiciones)" << endl;

	// Constructor con tres argumentos
	Matriz2D_1 matriz_4(7,4,6);

	cout << "El num. de filas de la matriz es: " << matriz_3.GetFilas() << endl;
	cout << "El num. de columnas de la matriz es: " << matriz_3.GetColumnas()
		 << endl;

	PintaMatriz(matriz_4);

	cout << endl;

	cout << "Probamos el constructor de copia (con matriz anterior)" << endl;

	// Constructor de copia
	Matriz2D_1 matriz_5(matriz_4);

	cout << "El num. de filas de la matriz es: " << matriz_5.GetFilas() << endl;
	cout << "El num. de columnas de la matriz es: " << matriz_5.GetColumnas()
		 << endl;

	cout << matriz_5.LeerValor(3,4) << endl;

	// Pinta matriz
	PintaMatriz(matriz_5);

	cout << endl;

	// Es matriz vacia
	cout << "Vamos a comprobar si la primera y ultima matriz que hemos creado "
		 << "estan vacias o no:" << endl;

	cout << "La matriz 1 ";
	
	if (matriz_1.EsMatrizVacia()) cout << "esta vacia" << endl;
	else cout << "no esta vacia" << endl;

	cout << "La matriz 5 ";
	
	if (matriz_5.EsMatrizVacia()) cout << "esta vacia" << endl;
	else cout << "no esta vacia" << endl;

	cout << endl;

	// Leer valor
	cout << "Vamos a leer el valor de la posicion 3,2 de la matriz 5" << endl;

	cout << "El valor es: " << matriz_5.LeerValor(3,2) << endl;
	
	cout << endl;

	// Modificar valor
	cout << "Vamos a modificar el valor de la posicion 3,2 de la matriz 5, "	
		 << "introducimos el valor 88" << endl;

	matriz_5.ModificarValor(3,2,88);

	PintaMatriz(matriz_5);

	cout << endl << endl;

	cout << "/////////////////////////////////////////////////////////" << endl;
	cout << "**********************   SESION 10   *********************" << endl;
	cout << "/////////////////////////////////////////////////////////" << endl;
	cout << endl << endl;

	cout << "Probamos el operador de asignacion (igualar la matriz 3 con la 5)"	
		 << endl;

	// Operador de asignacion
	matriz_3 = matriz_5;

	PintaMatriz(matriz_3);

	cout << endl;

	cout << "Probamos el operador de asignacion (inicializa matriz 3 a 7)"	
		 << endl;

	// Operador de asignacion
	matriz_3 = 7;

	PintaMatriz(matriz_3);

	cout << endl;

	cout << "Probamos el operador () como lectura: int n = matriz_3(2,1)" 	
		 << endl;

	// Operador ()
	int n = matriz_3(2,1);

	cout << "'n' vale: " << n << endl;

	cout << endl;	

	cout << "Probamos el operador () como escritura: matriz_3(2,1) = 4" 	
		 << endl;

	// Operador ()
	matriz_3(2,1) = 4;

	PintaMatriz(matriz_3);
		
	cout << endl;

	cout << "Probamos el operador unario - : matriz_6 = -matriz_3" << endl;

	// Operador unario -
	Matriz2D_1 matriz_6 = -matriz_3;

	PintaMatriz(matriz_6);

	cout << endl;

	cout << "Suma de dos matrices (operador binario +)" << endl;
	
	Matriz2D_1 matriz_7(matriz_3);

	matriz_7.ModificarValor(2,1,8);
	matriz_7.ModificarValor(3,1,2);
	matriz_7.ModificarValor(4,2,9);

	cout << "Muestro las dos matrices a sumar" << endl;

	PintaMatriz(matriz_3);
	PintaMatriz(matriz_7);
	
	cout << endl;

	// Operador binario + (dos matrices)
	Matriz2D_1 matriz_suma(matriz_3 + matriz_7);

	cout << "Muestro la matriz suma" << endl;

	PintaMatriz(matriz_suma);

	cout << endl;

	cout << "Suma de dos matrices (operador binario +)" << endl;
	
	Matriz2D_1 matriz_8(7,4,88);

	matriz_7.ModificarValor(2,1,8);
	matriz_7.ModificarValor(3,1,2);
	matriz_7.ModificarValor(4,2,9);

	cout << "Muestro las dos matrices a restar" << endl;

	PintaMatriz(matriz_7);
	PintaMatriz(matriz_8);
	
	cout << endl;

	// Operador binario - (dos matrices)
	Matriz2D_1 matriz_resta(matriz_7 - matriz_8);

	cout << "Muestro la matriz resta" << endl;

	PintaMatriz(matriz_resta);

	cout << endl;

	cout << "Sumo a la ultima matriz el valor 100" << endl;

	// Operador binario + (matriz y valor)
	matriz_resta = matriz_resta + 100;

	PintaMatriz(matriz_resta);

	cout << endl;

	cout << "Resto a la ultima matriz el valor 15" << endl;

	// Operador binario - (matriz y valor)
	matriz_resta = matriz_resta - 15;

	PintaMatriz(matriz_resta);

	cout << endl;

	cout << "Sumo a la ultima matriz el valor 16" << endl;

	// Operador binario + (valor y matriz)
	matriz_resta = 16 + matriz_resta;

	PintaMatriz(matriz_resta);

	cout << endl;

	cout << "Resto a 15 los valores de la ultima matriz" << endl;

	// Operador binario - (valor y matriz)
	matriz_resta = 15 - matriz_resta;

	PintaMatriz(matriz_resta);

	cout << endl;

	cout << "Utilizo el operador += para sumar 5 a la ultima matriz" << endl;

	// Operador combinado += 
	matriz_resta += 5;

	PintaMatriz(matriz_resta);

	cout << endl;

	cout << "Utilizo el operador -= para restar 17 a la ultima matriz" << endl;

	// Operador combinado += 
	matriz_resta -= 17;

	PintaMatriz(matriz_resta);

	cout << endl;

	cout << "Vamos a comparar si estas dos matrices son iguales" << endl;

	PintaMatriz(matriz_resta);
	PintaMatriz(matriz_7);

	cout << endl;

	if (matriz_resta == matriz_7) cout << "Son iguales" << endl;
	else cout << "No son iguales" << endl;

	cout << endl;

	cout << "Vamos a comparar si estas dos matrices son iguales" << endl;

	Matriz2D_1 matriz_igual (matriz_resta);

	PintaMatriz(matriz_resta);
	PintaMatriz(matriz_igual);

	cout << endl;

	if (matriz_resta == matriz_igual) cout << "Son iguales" << endl;
	else cout << "No son iguales" << endl;

	cout << endl;
	
	cout << "Vamos a comparar si estas dos matrices son diferentes" << endl;

	PintaMatriz(matriz_resta);
	PintaMatriz(matriz_7);

	cout << endl;

	if (matriz_resta != matriz_7) cout << "Son diferentes" << endl;
	else cout << "No son diferentes" << endl;

	cout << endl;

	cout << "Vamos a comparar si estas dos matrices son diferentes" << endl;

	PintaMatriz(matriz_resta);
	PintaMatriz(matriz_igual);

	cout << endl;

	if (matriz_resta != matriz_igual) cout << "Son diferentes" << endl;
	else cout << "No son diferentes" << endl;

	cout << endl << endl;
	
}
