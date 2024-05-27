#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Sudoku {
private:
    vector<vector<int>> tablero;

    bool esSeguro(int fila, int columna, int num) const {
        for (int x = 0; x < 9; ++x) {
            if (tablero[fila][x] == num || tablero[x][columna] == num) {
                return false;
            }
        }
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

    bool resolverSudoku() {
        for (int fila = 0; fila < 9; ++fila) {
            for (int columna = 0; columna < 9; ++columna) {
                if (tablero[fila][columna] == 0) {
                    for (int num = 1; num <= 9; ++num) {
                        if (esSeguro(fila, columna, num)) {
                            tablero[fila][columna] = num;
                            if (resolverSudoku()) {
                                return true;
                            }
                            tablero[fila][columna] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool tieneUnicaSolucion() {
        int soluciones = 0;
        contarSoluciones(soluciones);
        return soluciones == 1;
    }

    bool contarSoluciones(int& soluciones) {
        for (int fila = 0; fila < 9; ++fila) {
            for (int columna = 0; columna < 9; ++columna) {
                if (tablero[fila][columna] == 0) {
                    for (int num = 1; num <= 9; ++num) {
                        if (esSeguro(fila, columna, num)) {
                            tablero[fila][columna] = num;
                            contarSoluciones(soluciones);
                            tablero[fila][columna] = 0;
                            if (soluciones > 1) {
                                return false;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        soluciones++;
        return soluciones <= 1;
    }

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

            if (!tieneUnicaSolucion()) {
                tablero[fila][columna] = respaldo;
            } else {
                --numCeldasAEliminar;
            }
        }
    }

public:
    Sudoku() : tablero(9, vector<int>(9, 0)) {}

    void generarSudoku() {
        tablero = vector<vector<int>>(9, vector<int>(9, 0));
        resolverSudoku();

        // Copia del tablero completo
        vector<vector<int>> tableroCompleto = tablero;

        // Intentar eliminar celdas y verificar la unicidad de la solución
        eliminarCeldas(40);

        // Si no se logró un sudoku válido, restaurar el tablero completo y volver a intentar
        if (!tieneUnicaSolucion()) {
            tablero = tableroCompleto;
            eliminarCeldas(40);
        }
    }

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
};

int main() {
    Sudoku sudoku;
    sudoku.generarSudoku();
    cout << "Sudoku generado:" << endl;
    sudoku.imprimirSudoku();
    return 0;
}

