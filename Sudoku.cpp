#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
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
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Asignamos a la variable hConsole el identificador del búfer de pantalla activo de la consola de Windows
        SetConsoleTextAttribute(hConsole, color); //Establecemos los atributos de los caracteres escritos en el búfer de pantalla de la consola
#endif
    }

void resetColor() {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 7); // 7 es el color base
#endif
    }

class Sudoku {//generamos una clase para todas las funciones que abarquen el sudoku
private:
    vector<vector<int>> tablero; // Matriz 9x9 para el tablero de Sudoku
    //Funcion para verificar si el numero ingresado en la posicion ingresada es valido
    bool esSeguro(int fila, int columna, int num) const {
        //recorremos la fila y la columna de la posicion para verificar que no haya ninguno ya puesto
        for (int x = 0; x < 9; ++x) {
            if (tablero[fila][x] == num || tablero[x][columna] == num) {
                return false;
            }
        }
        int inicioFila = fila - fila % 3;
        int inicioColumna = columna - columna % 3;
        //recorremos el subcuadrado 3x3 de la posicion para verificar que no haya ninguno ya puesto
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i + inicioFila][j + inicioColumna] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    bool resolverSudoku() {//Función para resolver un tablero de Sudoku utilizando la técnica de backtracking*1.
        for (int fila = 0; fila < 9; ++fila) {//iteramos las filas
            for (int columna = 0; columna < 9; ++columna) {//iteramos las columnas
                if (tablero[fila][columna] == 0) {//si no es un espacio vacio
                    for (int num = 1; num <= 9; ++num) {//iterar 9 veces
                        if (esSeguro(fila, columna, num)) {//si el num en la fila y columna es valido para un sudoku
                            tablero[fila][columna] = num; //se asigna el numero
                            if (resolverSudoku()) {
                                return true;//si el sudoku es resolvible se devuelve true
                            }
                            tablero[fila][columna] = 0;//sino se vacia el espacio
                        }
                    }
                    return false; //si es un espacio vacio y no es seguro/resolvible, devuelve false|
                }
            }
        }
        return true;
    }

    //cuenta las posibles soluciones para saber si hay mas de 1 solucion con la funcion tieneUnicaSolucion();
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

    //verifica que haya una unica solución
    bool tieneUnicaSolucion() {
        int soluciones = 0;
        contarSoluciones(soluciones);
        return soluciones == 1;
    }
    //selecciona celdas aleatorias del tablero y las elimina si no afectan la unicidad de la solución
    void eliminarCeldas(int numCeldasAEliminar) {
        random_device rd; //semilla para generar numero aleatorio basado en hardware
        mt19937 gen(rd());//pseudo generador de numeros aleatorios usando la semilla para la generacion
        uniform_int_distribution<> dis(0, 8); //maneja una distribución uniforme de números enteros
        //mientras haya celdas para eliminar:
        while (numCeldasAEliminar > 0) {
            int fila = dis(gen);//generamos un número aleatorio utilizando el generador gen y siguiendo la distribución definida por dis
            int columna = dis(gen);
            //Si el espacio esta vacio, asignar a fila y columna otro numero aleatorio
            while (tablero[fila][columna] == 0) {
                fila = dis(gen);
                columna = dis(gen);
            }
            int respaldo = tablero[fila][columna];//guardar respaldo del tablero antes de borrar el espacio
            tablero[fila][columna] = 0;//borrar el espacio

            if (!tieneUnicaSolucion()) {//si genera que el sudoku sea inresolvible, se activa el respaldo
                tablero[fila][columna] = respaldo;
            } else {
                --numCeldasAEliminar;//si el espacio borrado no afecta, se reduce el numero de celdas a eliminar
            }
        }
    }

public:
    Sudoku() : tablero(9, vector<int>(9, 0)) {} //inicializamos un miembro de la clase en el cuerpo de su constructor utilizando la lista de inicialización

    void generarSudoku(int nivel) {
        tablero = vector<vector<int>>(9, vector<int>(9, 0));
        resolverSudoku();

        vector<vector<int>> tableroCompleto = tablero;

        int numCeldasAEliminar;
        if (nivel == 1) {
            numCeldasAEliminar = 30; // Facil
        } else if (nivel == 2) {
            numCeldasAEliminar = 40; // Medio
        } else {
            numCeldasAEliminar = 50; // Dificil
        }

        eliminarCeldas(numCeldasAEliminar);

        if (!tieneUnicaSolucion()) {
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
            cout << "Entrada invalida. Intente de nuevo." << endl;
            resetColor();
            return false;
        }
        if (tablero[fila][columna] != 0) {
            setColor(12);
            cout << "La celda ya esta ocupada. Intente de nuevo." << endl;
            resetColor();
            return false;
        }
        if (esSeguro(fila, columna, num)) {
            tablero[fila][columna] = num;
            return true;
        } else {
            setColor(12);
            cout << "Movimiento invalido. Intente de nuevo." << endl;
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
        cout << "1. El objetivo es rellenar una cuadricula de 9x9 con digitos del 1 al 9.\n";
        cout << "2. Cada fila, columna y subcuadro de 3x3 debe contener todos los numeros del 1 al 9 sin repetirse.\n";
        cout << "3. Los Sudokus tienen una unica solucion.\n";
    }
};

void mostrarMenu() {
    cout << "\033[1;36m====== MENU ======\033[0m\n";
    cout << "1. Empezar un nuevo juego\n";
    cout << "2. Mostrar reglas\n";
    cout << "3. Salir\n";
    cout << "\033[1;36m=================\033[0m\n";
    cout << "Seleccione una opcion: ";
}

void seleccionarNivel(int& nivel) {
    cout << "Seleccione el nivel de dificultad:\n";
    cout << "1. Facil\n";
    cout << "2. Medio\n";
    cout << "3. Dificil\n";
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
    int opcion, nivel;
    Sudoku sudoku;

    while (true) {
        mostrarMenu();
        cin >> opcion;
        limpiarPantalla();

        if (opcion == 1) {
            seleccionarNivel(nivel);
            limpiarPantalla();
            sudoku.generarSudoku(nivel);
            cout << "Sudoku generado:\n";

            int cursorFila = 0, cursorColumna = 0;
            while (!sudoku.estaResuelto()) {
                limpiarPantalla();
                sudoku.imprimirSudoku(cursorFila, cursorColumna);
                cout << "Use las flechas para moverse y Enter para ingresar un numero.\n";
                int tecla = capturarTecla();
                if (tecla == 1 && cursorFila > 0) cursorFila--; // Flecha arriba
                if (tecla == 2 && cursorFila < 8) cursorFila++; // Flecha abajo
                if (tecla == 3 && cursorColumna > 0) cursorColumna--; // Flecha izquierda
                if (tecla == 4 && cursorColumna < 8) cursorColumna++; // Flecha derecha
                if (tecla == '\r' || tecla == '\n') { // Enter key
                    int num;
                    cout << "Ingrese el numero (1-9): ";
                    cin >> num;
                    if (sudoku.ingresarValor(cursorFila, cursorColumna, num)) {
                        limpiarPantalla();
                        sudoku.imprimirSudoku(cursorFila, cursorColumna);
                    }
                }
            }
            cout << "\033[1;32mFELICITACIONES! HAS RESUELTO EL SUDOKU!\033[0m\n";
            cout << "Quieres jugar otra vez? (s/n): ";
            char jugarOtraVez;
            cin >> jugarOtraVez;
            if (jugarOtraVez != 's' && jugarOtraVez != 'S') {
                break;
            }
        } else if (opcion == 2) {
            sudoku.mostrarReglas();
            cout << "Presione Enter para volver al menu...";
            cin.ignore();
            cin.get();
            limpiarPantalla();
        } else if (opcion == 3) {
            cout << "Gracias por jugar!\n";
            break;
        } else {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }

    return 0;
}

// Referencias
// 1.Backtracking https://www.youtube.com/watch?v=ip2jC_kXGtg&pp=ygUMYmFja3RyYWNraW5n
