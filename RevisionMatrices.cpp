#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void mostrarMenu() {
    cout << "==================== MENU ====================" << endl;
    cout << "1. Transpuesta de una matriz 2x2" << endl;
    cout << "2. Determinante de una matriz 3x3" << endl;
    cout << "3. Matriz adjunta de una matriz 3x3" << endl;
    cout << "4. Matriz inversa de una matriz 3x3" << endl;
    cout << "5. Producto de dos matrices 2x2" << endl;
    cout << "6. Sistema de ecuaciones 3x3 por método de Gauss" << endl;
    cout << "7. Meses con 30 días" << endl;
    cout << "8. Salir" << endl;
    cout << "==============================================" << endl;
    cout << "Seleccione una opción: ";
}

void transpuesta2x2() {
    int matriz[2][2], transpuesta[2][2];
    cout << "Ingrese los elementos de una matriz 2x2:" << endl;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            transpuesta[j][i] = matriz[i][j];

    cout << "La matriz transpuesta es:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            cout << transpuesta[i][j] << " ";
        cout << endl;
    }
}

int determinante3x3() {
    int matriz[3][3];
    cout << "Ingrese los elementos de una matriz 3x3:" << endl;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }

    int determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
                     - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
                     + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);

    cout << "El determinante de la matriz es: " << determinante << endl;
    return determinante;
}

void matrizAdjunta3x3() {
    int matriz[3][3], adjunta[3][3];
    cout << "Ingrese los elementos de una matriz 3x3:" << endl;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }

    adjunta[0][0] =  matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1];
    adjunta[0][1] = -matriz[1][0] * matriz[2][2] + matriz[1][2] * matriz[2][0];
    adjunta[0][2] =  matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0];
    adjunta[1][0] = -matriz[0][1] * matriz[2][2] + matriz[0][2] * matriz[2][1];
    adjunta[1][1] =  matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0];
    adjunta[1][2] = -matriz[0][0] * matriz[2][1] + matriz[0][1] * matriz[2][0];
    adjunta[2][0] =  matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1];
    adjunta[2][1] = -matriz[0][0] * matriz[1][2] + matriz[0][2] * matriz[1][0];
    adjunta[2][2] =  matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

    cout << "La matriz adjunta es:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << adjunta[i][j] << " ";
        cout << endl;
    }
}

void matrizInversa3x3() {
    int matriz[3][3];
    cout << "Ingrese los elementos de una matriz 3x3:" << endl;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }

    int det = determinante3x3();
    if (det == 0) {
        cout << "La matriz no tiene inversa (determinante es 0)." << endl;
        return;
    }

    int adjunta[3][3];
    matrizAdjunta3x3();
    
    cout << "La matriz inversa es:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << fixed << setprecision(2) << (adjunta[i][j] / static_cast<double>(det)) << " ";
        cout << endl;
    }
}

void producto2x2() {
    int matriz1[2][2], matriz2[2][2], producto[2][2] = {0};
    cout << "Ingrese los elementos de la primera matriz 2x2:" << endl;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz1[i][j];
        }
    
    cout << "Ingrese los elementos de la segunda matriz 2x2:" << endl;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz2[i][j];
        }

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                producto[i][j] += matriz1[i][k] * matriz2[k][j];

    cout << "El producto de las matrices es:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            cout << producto[i][j] << " ";
        cout << endl;
    }
}

void gauss3x4() {
    double matriz[3][4];
    cout << "Ingrese los coeficientes y términos independientes de un sistema de ecuaciones 3x3 (formato aumentada 3x4):" << endl;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }

    for (int i = 0; i < 3; ++i) {
        for (int k = i + 1; k < 3; ++k) {
            double factor = matriz[k][i] / matriz[i][i];
            for (int j = 0; j < 4; ++j)
                matriz[k][j] -= factor * matriz[i][j];
        }
    }

    double x[3];
    for (int i = 2; i >= 0; --i) {
        x[i] = matriz[i][3];
        for (int j = i + 1; j < 3; ++j)
            x[i] -= matriz[i][j] * x[j];
        x[i] /= matriz[i][i];
    }

    cout << "Las soluciones son:" << endl;
    for (int i = 0; i < 3; ++i)
        cout << "x" << i + 1 << " = " << x[i] << endl;
}

void meses30dias() {
    vector<int> meses = {4, 6, 9, 11};
    cout << "Los meses con 30 días son:" << endl;
    for (int mes : meses)
        cout << "Mes " << mes << endl;
}

int main() {
    int opcion;
    bool continuar = true;
    while (continuar) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                transpuesta2x2();
                break;
            case 2:
                determinante3x3();
                break;
            case 3:
                matrizAdjunta3x3();
                break;
            case 4:
                matrizInversa3x3();
                break;
            case 5:
                producto2x2();
                break;
            case 6:
                gauss3x4();
                break;
            case 7:
                meses30dias();
                break;
            case 8:
                continuar = false;      
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

        if (continuar) {
            cout << "¿Desea realizar otra operación? (s/n): ";
            char respuesta;
            cin >> respuesta;
            if (respuesta != 's' && respuesta != 'S') {
                continuar = false;
            }
        }
    }
    return 0;
}
