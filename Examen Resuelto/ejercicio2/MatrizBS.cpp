#include <iostream>
#include <cmath>

using namespace std;

class MatrizBS{

  private:

    int *valores;
    int n;
    int opcional;


  public:

    MatrizBS(){

      n = 4;
      opcional = 0;

      valores = new int [n];

      for(int i = 0; i < n; i++){

        valores[i] = 1;

      }

    }

  MatrizBS(int n, int *valor, int opcional){

      this->n = n;
      this->opcional = opcional;
      valores = new int [n];

      for(int i = 0; i < n; i++){

        valores[i] = valor[i];

      }

    }

    void Mostrar(){

      int contador = 0;
      int contador2 = 1;
      int **matriz;

      matriz = new int *[n];

      for(int i = 0; i < n; i++){

        matriz[i] = new int [n];

      }

      if(n % 2 != 0){

        for(int i = 0; i <= n / 2; i++){

          for(int j = 0; j < n; j++){

            if(i == j && i <= n / 2){

              matriz[i][j] = *(valores + contador);
              matriz[n - i - 1][j] =  *(valores + contador);
              contador = contador + 2;

            }else if(i + j == n - 1){

              matriz[i][j] =  *(valores + contador2);
              matriz[n - i - 1][j] =  *(valores + contador2);
              contador2 = contador2 + 2;

            }else{

              matriz[i][j] = opcional;
              matriz[n - i - 1][j] = opcional;

            }

          }

        }

      }else{

        for(int i = 0; i < n / 2; i++){

          for(int j = 0; j < n; j++){

            if(i == j && i < n / 2){

              matriz[i][j] =  *(valores + contador);
              matriz[n - i - 1][j] =  *(valores + contador);
              contador = contador + 2;

            }else if(i + j == n - 1){

              matriz[i][j] =  *(valores + contador2);
              matriz[n - i - 1][j] =  *(valores + contador2);
              contador2 = contador2 + 2;

            }else{

              matriz[i][j] = opcional;
              matriz[n - i - 1][j] = opcional;

            }

          }

        }

      }

      cout << endl;

      for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

          cout << matriz[i][j] << "   ";

        }

        cout << endl << endl;

      }

      for(int i = 0; i < n; i++){

        delete [] matriz[i];

      }

      delete [] matriz;

    }

    MatrizBS &operator=(const MatrizBS &mat){

      delete [] this->valores;
      this->opcional = mat.opcional;
      this->valores = new int [this->n];
      this->n = mat.n;

      for(int i = 0; i < n; i++){

        this->valores[i] = mat.valores[i];

      }

      return *this;

    }

    ~MatrizBS(){

      delete [] valores;

    }


};

int main(){

  int tam = 0;
  int *val = 0;
  int num = 0;
  int cont = 0;

  cout << "Introduzca el tamanio n * n de su matriz: ";
  cin >> tam;

  val = new int [tam];

  if(tam % 2 == 0){

    for(int i = 0; i < tam; i = i + 2){

      cout << endl << "Introduzca el valor de la posicion [" << cont << "][" << cont << "]: ";
      cin >> num;
      val[i] = num;

      cout << endl << "Introduzca el valor de la posicion [" << tam - cont - 1 << "][" << tam - cont - 1 << "]: ";
      cin >> num;
      val[i + 1] = num;

      cont ++;

    }

  }else{

    cont = 0;

    for(int i = 0; i < tam - 1; i = i + 2){

      cout << endl << "Introduzca el valor de la posicion [" << cont << "][" << cont << "]: ";
      cin >> num;
      val[i] = num;

      cout << endl << "Introduzca el valor de la posicion [" << tam - cont - 1 << "][" << tam - cont - 1 << "]: ";
      cin >> num;
      val[i + 1] = num;

      cont ++;

    }

    cout << endl << "Introduzca el valor de la posicion [" << (tam - 1) / 2 << "][" << (tam - 1) / 2 << "]: ";
    cin >> num;
    val[tam - 1] = num;

  }

  cout << endl << "Introduzca su valor de relleno: ";
  cin >> num;


  MatrizBS m1(tam, val, num);
  MatrizBS m2;

  cout << endl << "MATRIZ 1: " << endl;
  m1.Mostrar();

  cout << endl << "MATRIZ 2: " << endl;
  m2.Mostrar();

  cout << "MATRIZ 1 IGUAL A MATRIZ 2: " << endl;
  m1 = m2;
  m1.Mostrar();


  delete [] val;

}
