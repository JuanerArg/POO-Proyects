#include <iostream>

using namespace std;

int main() {
  int opcion;
do{
      while(1){
        cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
        cout << " 1. Programa que pide 4 numeros, calcula y muestra la media aritmética y los datos tecleados\n";
        cout << " 2. Programa que pide 5 numeros y los muestra en orden inverso\n";
        cout << " 3. Programa que muestra el número de días en un mes dado\n";
        cout << " 4. Programa que muestra el número de día del año para una fecha dada\n";
        cout << " 5. Programa que calcula los días restantes hasta el final del año\n";
        cout << " 6. Programa que pide 10 numeros y los muestra en orden inverso usando 'for' \n";
        cout << " 7. Programa que pide 10 numeros reales y muestra los que están por encima de la media\n";
        cout << " 8. Programa que pide 10 numeros enteros y calcula el mayor\n";
        cout << " 9. Programa que calcula la diferencia entre dos vectores en el plano\n";
        cout << "10. Programa que calcula el producto escalar de dos vectores en el espacio\n";
        cout << "11. Programa que calcula el producto vectorial de dos vectores en el espacio\n";
        cout << "12. Programa que determina si dos vectores en el plano son linealmente dependientes\n";
        cout << "13. Salir\n";
        cout << "Elija una opcion: ";
        if(!(cin >> opcion)){
            cout << "Opcion no valida\n";//verificacion de tipo de dato
        }else{break;}
      }

      switch(opcion){
    case 1:{
          cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
          float numeros[4], suma = 0, media;

          cout << "Introduce 4 numeros: ";
          for (int i = 0; i < 4; i++) {
              cin >> numeros[i];
              suma += numeros[i];
          }

          media = suma / 4;

          cout << "Los numeros introducidos son: ";
          for (int i = 0; i < 4; i++) {
              cout << numeros[i] << " ";
          }

          cout << "\nLa media aritmetica es: " << media << endl;
          //printf("La media aritmetica es: %.2f\n", media);")
          break;
        }
    case 2:{
          cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
        int numeros[5];

        cout << "Introduce 5 numeros: ";
        for (int i = 0; i < 5; i++) {
            cin >> numeros[i];
        }

        cout << "Los numeros en orden inverso son: ";
        for (int i = 4; i >= 0; i--) {
            cout << numeros[i] << " ";
        }
        cout << endl;
        break;
      }
    case 3:{
          cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
        int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int mes;

        cout << "Introduce el numero del mes (1-12): ";
        cin >> mes;

        if (mes < 1 || mes > 12) {
            cout << "Mes invalido!" << endl;
        } else {
            cout << "El mes tiene " << diasMes[mes - 1] << " dias." << endl;
        }

        break;
      }
    case 4:{
          cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
        int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int mes, dia, diaDelAno = 0;

        cout << "Introduce el numero del mes (1-12): ";
        cin >> mes;
        cout << "Introduce el dia: ";
        cin >> dia;

        if (mes < 1 || mes > 12 || dia < 1 || dia > diasMes[mes - 1]) {
            cout << "Fecha invalida!" << endl;
        } else {
            for (int i = 0; i < mes - 1; i++) {
                diaDelAno += diasMes[i];
            }
            diaDelAno += dia;
            cout << "El dia " << dia << " del mes " << mes << " es el dia numero " << diaDelAno << " del anio." << endl;
        }
        break;
    }
    case 5:{
          cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
              int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
              int mes, dia, diaDelAno = 0, diasRestantes;

              cout << "Introduce el numero del mes (1-12): ";
              cin >> mes;
              cout << "Introduce el dia: ";
              cin >> dia;

              if (mes < 1 || mes > 12 || dia < 1 || dia > diasMes[mes - 1]) {
                  cout << "Fecha invalida!" << endl;
              } else {
                  for (int i = 0; i < mes - 1; i++) {
                      diaDelAno += diasMes[i];
                  }
                  diaDelAno += dia;
                  diasRestantes = 365 - diaDelAno;
                  cout << "Quedan " << diasRestantes << " dias para finalizar el anio." << endl;
              }
            break;
          }
          case 6:{
                cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
              int numeros[10];

              cout << "Introduce 10 numeros: ";
              for (int i = 0; i < 10; i++) {
                  cin >> numeros[i];
              }

              cout << "Los numeros en orden inverso son: ";
              for (int i = 9; i >= 0; i--) {
                  cout << numeros[i] << " ";
              }
              cout << endl;
              break;
          }
    case 7:{
          cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
              float numeros[10], suma = 0, media;

              cout << "Introduce 10 numeros reales: ";
              for (int i = 0; i < 10; i++) {
                  cin >> numeros[i];
                  suma += numeros[i];
              }

              media = suma / 10;
              cout << "La media es: " << media << endl;
              cout << "Numeros por encima de la media: ";
              for (int i = 0; i < 10; i++) {
                  if (numeros[i] > media) {
                      cout << numeros[i] << " ";
                  }
              }
              cout << endl;
          break;      
    }
          case 8:{
                cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
              int numeros[10], mayor;

              cout << "Introduce 10 numeros enteros: ";
              for (int i = 0; i < 10; i++) {
                  cin >> numeros[i];
              }

              mayor = numeros[0];
              for (int i = 1; i < 10; i++) {
                  if (numeros[i] > mayor) {
                      mayor = numeros[i];
                  }
              }

              cout << "El numero mayor es: " << mayor << endl;
            break;
          }
          case 9:{
                cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
              float vector1[2], vector2[2], diferencia[2];

              cout << "Introduce las coordenadas del primer vector (x y): ";
              cin >> vector1[0] >> vector1[1];

              cout << "Introduce las coordenadas del segundo vector (x y): ";
              cin >> vector2[0] >> vector2[1];

              diferencia[0] = vector1[0] - vector2[0];
              diferencia[1] = vector1[1] - vector2[1];

              cout << "La diferencia de los vectores es: (" << diferencia[0] << ", " << diferencia[1] << ")" << endl;
            break;
          }
          case 10:{
                cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
              float vector1[3], vector2[3], productoEscalar = 0;

              cout << "Introduce las coordenadas del primer vector (x y z): ";
              cin >> vector1[0] >> vector1[1] >> vector1[2];

              cout << "Introduce las coordenadas del segundo vector (x y z): ";
              cin >> vector2[0] >> vector2[1] >> vector2[2];

              for (int i = 0; i < 3; i++) {
                  productoEscalar += vector1[i] * vector2[i];
              }

              cout << "El producto escalar de los vectores es: " << productoEscalar << endl;
            break;
          }
          case 11:{
                cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
              float vector1[3], vector2[3], productoVectorial[3];

              cout << "Introduce las coordenadas del primer vector (x y z): ";
              cin >> vector1[0] >> vector1[1] >> vector1[2];

              cout << "Introduce las coordenadas del segundo vector (x y z): ";
              cin >> vector2[0] >> vector2[1] >> vector2[2];

              productoVectorial[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
              productoVectorial[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
              productoVectorial[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

              cout<<"El producto vectorial de los vectores es: ("<<productoVectorial[0]<<", "<< productoVectorial[1]<<", "<< productoVectorial[2]<<")"<<endl;
            break;
          }
          case 12:{
              cout << "────────────────────────────────────────────────────────────────────────────────────────────────\n";
              float vector1[2], vector2[2], k;
              bool dependientes;

              cout << "Introduce las coordenadas del primer vector (x y): ";
              cin >> vector1[0] >> vector1[1];

              cout << "Introduce las coordenadas del segundo vector (x y): ";
              cin >> vector2[0] >> vector2[1];

              if (vector1[0] != 0) {
                  k = vector2[0] / vector1[0];
                  dependientes = (vector2[1] == k * vector1[1]);
              } else if (vector1[1] != 0) {
                  k = vector2[1] / vector1[1];
                  dependientes = (vector2[0] == k * vector1[0]);
              } else {
                  dependientes = (vector2[0] == 0 && vector2[1] == 0);
              }

              if (dependientes) {
                  cout << "Los vectores son linealmente dependientes." << endl;
              } else {
                  cout << "Los vectores son linealmente independientes." << endl;
              }
          }
      }
}while(opcion!=13);
  return 0;
}