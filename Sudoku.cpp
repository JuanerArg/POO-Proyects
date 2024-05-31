#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#endif

using namespace std;

void setColor(int color) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Asignamos a la variable hConsole el identificador del búfer de pantalla activo de la consola de Windows
    SetConsoleTextAttribute(hConsole, color); // Establecemos los atributos de los caracteres escritos en el búfer de pantalla de la consola
#endif
}

void resetColor() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7); // 7 es el color base
#endif
}

class Sudoku { // Generamos una clase para todas las funciones que abarquen el sudoku
private:
    vector<vector<int>> tablero; // Matriz 9x9 para el tablero de Sudoku

    // Función para verificar si el número ingresado en la posición ingresada es válido
    bool esSeguro(int fila, int columna, int num) const {
        // Recorremos la fila y la columna de la posición para verificar que no haya ninguno ya puesto
        for (int x = 0; x < 9; ++x) {
            if (tablero[fila][x] == num || tablero[x][columna] == num) {
                return false;
            }
        }
        int inicioFila = fila - fila % 3;
        int inicioColumna = columna - columna % 3;
        // Recorremos el subcuadro 3x3 de la posición para verificar que no haya ninguno ya puesto
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i + inicioFila][j + inicioColumna] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    bool resolverSudoku() { // Función para resolver un tablero de Sudoku utilizando la técnica de backtracking
        for (int fila = 0; fila < 9; ++fila) { // Iteramos las filas
            for (int columna = 0; columna < 9; ++columna) { // Iteramos las columnas
                if (tablero[fila][columna] == 0) { // Si es un espacio vacío
                    for (int num = 1; num <= 9; ++num) { // Iterar 9 veces
                        if (esSeguro(fila, columna, num)) { // Si el número en la fila y columna es válido para un sudoku
                            tablero[fila][columna] = num; // Se asigna el número
                            if (resolverSudoku()) {
                                return true; // Si el sudoku es resolvible se devuelve true
                            }
                            tablero[fila][columna] = 0; // Si no, se vacía el espacio
                        }
                    }
                    return false; // Si es un espacio vacío y no es seguro/resolvible, devuelve false
                }
            }
        }
        return true;
    }

    // Cuenta las posibles soluciones para saber si hay más de 1 solución con la función tieneUnicaSolucion()
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

    // Verifica que haya una única solución
    bool tieneUnicaSolucion() {
        int soluciones = 0;
        contarSoluciones(soluciones);
        return soluciones == 1;
    }

    // Selecciona celdas aleatorias del tablero y las elimina si no afectan la unicidad de la solución
    void eliminarCeldas(int numCeldasAEliminar) {
        random_device rd; // Semilla para generar número aleatorio basado en hardware
        mt19937 gen(rd()); // Pseudo generador de números aleatorios usando la semilla para la generación
        uniform_int_distribution<> dis(0, 8); // Maneja una distribución uniforme de números enteros
        // Mientras haya celdas para eliminar:
        while (numCeldasAEliminar > 0) {
            int fila = dis(gen); // Generamos un número aleatorio utilizando el generador gen y siguiendo la distribución definida por dis
            int columna = dis(gen);
            // Si el espacio está vacío, asignar a fila y columna otro número aleatorio
            while (tablero[fila][columna] == 0) {
                fila = dis(gen);
                columna = dis(gen);
            }
            int respaldo = tablero[fila][columna]; // Guardar respaldo del tablero antes de borrar el espacio
            tablero[fila][columna] = 0; // Borrar el espacio

            if (!tieneUnicaSolucion()) { // Si genera que el sudoku sea irresoluble, se activa el respaldo
                tablero[fila][columna] = respaldo;
            } else {
                --numCeldasAEliminar; // Si el espacio borrado no afecta, se reduce el número de celdas a eliminar
            }
        }
    }

public:
    Sudoku() : tablero(9, vector<int>(9, 0)) {} // Inicializamos un miembro de la clase en el cuerpo de su constructor utilizando la lista de inicialización

    void generarSudoku(int nivel) {
        random_device rd;
        mt19937 gen(rd());
        tablero = vector<vector<int>>(9, vector<int>(9, 0));
        resolverSudoku();
        shuffle(tablero.begin(), tablero.end(), gen);
        for (auto& row : tablero) {
            shuffle(row.begin(), row.end(), gen);
        }

        vector<vector<int>> tableroCompleto = tablero;

        int numCeldasAEliminar;
        if (nivel == 1) {
            numCeldasAEliminar = 30; // Fácil
        } else if (nivel == 2) {
            numCeldasAEliminar = 40; // Medio
        } else {
            numCeldasAEliminar = 50; // Difícil
        }

        eliminarCeldas(numCeldasAEliminar);

        while (!tieneUnicaSolucion()) {
            tablero = tableroCompleto;
            eliminarCeldas(numCeldasAEliminar);
        }
    }

    void imprimirSudoku(int cursorFila, int cursorColumna) const {
        setColor(11); // Light cyan for headers
        cout << "    1 2 3   4 5 6   7 8 9" << endl;
        cout << "  +-------+-------+-------+" << endl;
        resetColor();
        for (int fila = 0; fila < 9; ++fila) {
            if (fila % 3 == 0 && fila != 0) {
                setColor(11);
                cout << "  +-------+-------+-------+" << endl;
                resetColor();
            }
            setColor(11);
            cout << fila + 1 << " | ";
            resetColor();
            for (int columna = 0; columna < 9; ++columna) {
                if (columna % 3 == 0 && columna != 0) {
                    setColor(11);
                    cout << "| ";
                    resetColor();
                }
                if (fila == cursorFila && columna == cursorColumna) {
                    setColor(14); // Yellow for cursor
                } else if (tablero[fila][columna] == 0) {
                    setColor(12); // Red color for empty cells
                } else {
                    setColor(10); // Green color for filled cells
                }
                if (tablero[fila][columna] == 0) {
                    cout << ". ";
                } else {
                    cout << tablero[fila][columna] << " ";
                }
                resetColor();
            }
            setColor(11);
            cout << "|" << endl;
            resetColor();
        }
        setColor(11);
        cout << "  +-------+-------+-------+" << endl;
        resetColor();
    }

    bool ingresarValor(int fila, int columna, int num) {
        if (fila < 0 || fila >= 9 || columna < 0 || columna >= 9 || num < 1 || num > 9) {
            setColor(12); // Red color for error messages
            cout << "Entrada inválida. Intente de nuevo." << endl;
            resetColor();
            return false;
        }
        if (tablero[fila][columna] != 0) {
            setColor(12);
            cout << "La celda ya está ocupada. Intente de nuevo." << endl;
            resetColor();
            return false;
        }
        if (esSeguro(fila, columna, num)) {
            tablero[fila][columna] = num;
            return true;
        } else {
            setColor(12);
            cout << "Movimiento inválido. Intente de nuevo." << endl;
            resetColor();
            return false;
        }
    }

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

    void mostrarReglas() const {
        setColor(14); // Yellow color for headers
        cout << "\nReglas del Sudoku:\n";
        resetColor();
        cout << "1. El objetivo es rellenar una cuadrícula de 9x9 con dígitos del 1 al 9.\n";
        cout << "2. Cada fila, columna y subcuadro de 3x3 debe contener todos los números del 1 al 9 sin repetirse.\n";
        cout << "3. Los Sudokus tienen una única solución.\n";
    }
};

void mostrarMenu() {
    cout << "\033[1;36m====== MENU ======\033[0m\n";
    cout << "1. Empezar un nuevo juego\n";
    cout << "2. Mostrar reglas\n";
    cout << "3. Salir\n";
    cout << "\033[1;36m=================\033[0m\n";
    cout << "Seleccione una opción: ";
}

void seleccionarNivel(int& nivel) {
    cout << "Seleccione el nivel de dificultad:\n";
    cout << "1. Fácil\n";
    cout << "2. Medio\n";
    cout << "3. Difícil\n";
    cin >> nivel;
}

#ifdef _WIN32
void limpiarPantalla() {
    system("cls");
}

int capturarTecla() {
    int c = _getch();
    if (c == 224) {
        c = _getch();
        switch (c) {
            case 72: return 1;  // Flecha arriba
            case 80: return 2;  // Flecha abajo
            case 75: return 3;  // Flecha izquierda
            case 77: return 4;  // Flecha derecha
        }
    }
    return c;
}
#else
void limpiarPantalla() {
    system("clear");
}

int capturarTecla() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int ch = getchar();
    if (ch == 27) {
        getchar();  // skip the [
        switch(getchar()) {
            case 'A': ch = 1; break;  // Flecha arriba
            case 'B': ch = 2; break;  // Flecha abajo
            case 'D': ch = 3; break;  // Flecha izquierda
            case 'C': ch = 4; break;  // Flecha derecha
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

int main() {
    Sudoku juego;
    int opcion = 0;
    int nivel = 1;

    while (opcion != 3) {
        limpiarPantalla();
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                seleccionarNivel(nivel);
                juego.generarSudoku(nivel);
                int cursorFila = 0, cursorColumna = 0;
                while (!juego.estaResuelto()) {
                    limpiarPantalla();
                    juego.imprimirSudoku(cursorFila, cursorColumna);
                    cout << "Use las flechas para moverse. Ingrese un número (1-9) para colocarlo, 'b' para borrar y 'q' para salir.\n";
                    int tecla = capturarTecla();
                    if (tecla == 1 && cursorFila > 0) cursorFila--; // Flecha arriba
                    else if (tecla == 2 && cursorFila < 8) cursorFila++; // Flecha abajo
                    else if (tecla == 3 && cursorColumna > 0) cursorColumna--; // Flecha izquierda
                    else if (tecla == 4 && cursorColumna < 8) cursorColumna++; // Flecha derecha
                    else if (tecla == 'q') break; // Salir
                    else if (tecla >= '1' && tecla <= '9') {
                        int num = tecla - '0';
                        juego.ingresarValor(cursorFila, cursorColumna, num);
                    } else if (tecla == 'b') {
                        juego.ingresarValor(cursorFila, cursorColumna, 0);
                    }
                }
                if (juego.estaResuelto()) {
                    cout << "¡Felicidades! Has completado el Sudoku.\n";
                }
                cout << "Presiona cualquier tecla para volver al menú principal.\n";
                cin.ignore();
                cin.get();
                break;
            }
            case 2:
                limpiarPantalla();
                juego.mostrarReglas();
                cout << "Presiona cualquier tecla para volver al menú principal.\n";
                cin.ignore();
                cin.get();
                break;
            case 3:
                cout << "Saliendo del juego...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                cin.ignore();
                cin.get();
                break;
        }
    }

    return 0;
}

// Referencias
// 1.Backtracking https://www.youtube.com/watch?v=ip2jC_kXGtg&pp=ygUMYmFja3RyYWNraW5n
