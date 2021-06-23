#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int tam(ifstream &fichero);
void rellenar(ifstream &fich1, ifstream &fich2, double *vec);

int main(){

  string nombre1;
  string nombre2;
  ifstream fichero1;
  ifstream fichero2;
  int tamtot = 0;
  double *vector;
  ofstream resultado;

  cout << "Introduzca el nombre de su primer fichero: ";
  cin >> nombre1;

  cout << endl << "Introduzca el nombre de su segundo fichero: ";
  cin >> nombre2;

  fichero1.open(nombre1);
  fichero2.open(nombre2);

  tamtot = tam(fichero1) + tam(fichero2);

  vector = new double [tamtot];

  fichero1.close();
  fichero2.close();
  fichero1.open(nombre1);
  fichero2.open(nombre2);

  rellenar(fichero1, fichero2, vector);

  fichero1.close();
  fichero2.close();

  resultado.open("Ordenado", ios::out);

  for(int i = 0; i < tamtot; i++){

    resultado << vector[i] << " ";

  }

  resultado.close();

  cout << endl << "SE HA CREADO EL FICHERO RESULTADO CORRECTAMENTE" << endl << endl;



}

int tam(ifstream &fichero){

  bool encontrado = false;
  double datos = 0;
  int contador = 0;

  while(!fichero.eof() && encontrado == false){

    fichero >> datos;

    if(datos != -1){

      contador ++;

    }else{

      encontrado == true;

    }

  }

  return contador;

}



void rellenar(ifstream &fich1, ifstream &fich2, double *vec){

  int contador = 0;
  bool encontrado = false;
  double datos = 0;
  int aux = 0;


  while(!fich1.eof() && encontrado == false){

    fich1 >> datos;

    if(datos != -1){

      vec[contador] = datos;
      contador ++;

    }else{

      encontrado = true;

    }

  }


  encontrado = false;

  while(!fich2.eof() && encontrado == false){

    fich2 >> datos;

    if(datos != -1){

      vec[contador] = datos;
      contador ++;

    }else{

      encontrado = true;

    }

  }

  for(int i = 0; i < contador - 1; i++){

    for(int j = i + 1; j < contador; j++){

      if(vec[i] > vec[j]){

        aux = vec[i];
        vec[i] = vec[j];
        vec[j] = aux;

      }

    }

  }

}
