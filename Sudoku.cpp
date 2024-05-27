#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Sudoku {
private:
    vector<vector<int>> tablero; // Matriz 9x9 para el tablero de Sudoku

    // Verifica si es seguro colocar un numero en la posicion dada
    bool esSeguro(int fila, int columna, int num) const {
        // Verificar la fila y columna
        for (int x = 0; x < 9; ++x) {
            if (tablero[fila][x] == num || tablero[x][columna] == num) {
                return false;
            }
        }
        // Verificar el subcuadro 3x3
        int inicioFila = fila - fila % 3;
        int inicioColumna = columna - columna % 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i + inicioFila][j + inicioColumna] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    // Resolver el Sudoku usando backtracking
    bool resolverSudoku() {
        for (int fila = 0; fila < 9; ++fila) {
            for (int columna = 0; columna < 9; ++columna) {
                if (tablero[fila][columna] == 0) { // Encontrar una celda vacia
                    for (int num = 1; num <= 9; ++num) {
                        if (esSeguro(fila, columna, num)) {
                            tablero[fila][columna] = num; // Colocar el numero
                            if (resolverSudoku()) {
                                return true;
                            }
                            tablero[fila][columna] = 0; // Deshacer y probar el siguiente numero
                        }
                    }
                    return false; // No se puede colocar ningun numero
                }
            }
        }
        return true; // Sudoku resuelto
    }

    // Verificar si el Sudoku tiene una unica solucion
    bool tieneUnicaSolucion() {
        int soluciones = 0;
        contarSoluciones(soluciones);
        return soluciones == 1;
    }

    // Contar el numero de soluciones posibles para el Sudoku
    bool contarSoluciones(int& soluciones) {
        for (int fila = 0; fila < 9; ++fila) {
            for (int columna = 0; columna < 9; ++columna) {
                if (tablero[fila][columna] == 0) { // Encontrar una celda vacia
                    for (int num = 1; num <= 9; ++num) {
                        if (esSeguro(fila, columna, num)) {
                            tablero[fila][columna] = num; // Colocar el numero
                            contarSoluciones(soluciones);
                            tablero[fila][columna] = 0; // Deshacer
                            if (soluciones > 1) {
                                return false; // Mas de una solucion encontrada
                            }
                        }
                    }
                    return false;
                }
            }
        }
        soluciones++; // Incrementar el contador de soluciones
        return soluciones <= 1;
    }

    // Eliminar celdas aleatoriamente del Sudoku asegurando que permanezca con una unica solucion
    void eliminarCeldas(int numCeldasAEliminar) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 8);

        while (numCeldasAEliminar > 0) {
            int fila = dis(gen);
            int columna = dis(gen);
            while (tablero[fila][columna] == 0) {
                fila = dis(gen);
                columna = dis(gen);
            }
            int respaldo = tablero[fila][columna];
            tablero[fila][columna] = 0;

            // Verificar si la eliminacion mantiene una unica solucion
            if (!tieneUnicaSolucion()) {
                tablero[fila][columna] = respaldo; // Restaurar si no tiene unica solucion
            } else {
                --numCeldasAEliminar; // Decrementar el contador de celdas a eliminar
            }
        }
    }

public:
    // Constructor para inicializar el tablero
    Sudoku() : tablero(9, vector<int>(9, 0)) {}

    // Generar un nuevo Sudoku
    void generarSudoku(int nivel) {
        tablero = vector<vector<int>>(9, vector<int>(9, 0)); // Reiniciar el tablero
        resolverSudoku(); // Resolver el Sudoku completamente

        vector<vector<int>> tableroCompleto = tablero; // Copia del tablero completo

        int numCeldasAEliminar;
        if (nivel == 1) {
            numCeldasAEliminar = 30; // Facil
        } else if (nivel == 2) {
            numCeldasAEliminar = 40; // Medio
        } else {
            numCeldasAEliminar = 50; // Dificil
        }

        // Intentar eliminar celdas y verificar la unicidad de la solucion
        eliminarCeldas(numCeldasAEliminar);

        // Si no se logro un Sudoku valido, restaurar el tablero completo y volver a intentar
        if (!tieneUnicaSolucion()) {
            tablero = tableroCompleto;
            eliminarCeldas(numCeldasAEliminar);
        }
    }

    // Imprimir el Sudoku en formato legible
    void imprimirSudoku() const {
        for (int fila = 0; fila < 9; ++fila) {
            if (fila % 3 == 0 && fila != 0) {
                cout << "------+-------+------" << endl;
            }
            for (int columna = 0; columna < 9; ++columna) {
                if (columna % 3 == 0 && columna != 0) {
                    cout << "| ";
                }
                cout << (tablero[fila][columna] == 0 ? "." : to_string(tablero[fila][columna])) << " ";
            }
            cout << endl;
        }
    }

    // Permitir al usuario ingresar un valor en el tablero
    bool ingresarValor(int fila, int columna, int num) {
        if (fila < 0 || fila >= 9 || columna < 0 || columna >= 9 || num < 1 || num > 9) {
            cout << "Entrada invalida. Intente de nuevo." << endl;
            return false;
        }
        if (tablero[fila][columna] != 0) {
            cout << "La celda ya esta ocupada. Intente de nuevo." << endl;
            return false;
        }
        if (esSeguro(fila, columna, num)) {
            tablero[fila][columna] = num;
            return true;
        } else {
            cout << "Movimiento invalido. Intente de nuevo." << endl;
            return false;
        }
    }

    // Verificar si el tablero esta completamente resuelto
    bool estaResuelto() const {
        for (int fila = 0; fila < 9; ++fila) {
            for (int columna = 0; columna < 9; ++columna) {
                if (tablero[fila][columna] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

void mostrarMenu() {
    cout << "Bienvenido al juego de Sudoku" << endl;
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Empezar un nuevo juego" << endl;
    cout << "2. Salir" << endl;
}

void seleccionarNivel(int& nivel) {
    cout << "Seleccione el nivel de dificultad:" << endl;
    cout << "1. Facil" << endl;
    cout << "2. Medio" << endl;
    cout << "3. Dificil" << endl;
    cin >> nivel;
}

int main() {
    int opcion, nivel;
    Sudoku sudoku;

    while (true) {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            seleccionarNivel(nivel);
            sudoku.generarSudoku(nivel);
            cout << "Sudoku generado:" << endl;
            sudoku.imprimirSudoku();

            int fila, columna, num;
            while (!sudoku.estaResuelto()) {
                cout << "Ingrese la fila, columna y numero (1-9) separados por espacios: ";
                cin >> fila >> columna >> num;
                if (sudoku.ingresarValor(fila - 1, columna - 1, num)) { // Ajustar a indice 0
                    sudoku.imprimirSudoku();
                }
            }

            cout << "Felicitaciones! Has resuelto el Sudoku." << endl;
        } else if (opcion == 2) {
            cout << "Gracias por jugar!" << endl;
            break;
        } else {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
