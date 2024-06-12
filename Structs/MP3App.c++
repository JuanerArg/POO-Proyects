#include <iostream>
#include <string>

using namespace std;

// Modificar el programa anterior para que almacene datos de hasta 100
// canciones. El mismo debe contar con un menú que permita las opciones: añadir
// una nueva canción, mostrar el título de todas las canciones, buscar la
// canción que contenga un cierto texto (en el artista o en el título).
struct Duration {
  int Minutes[100];
  int Seconds[100];
};

struct Cancion {
  string Name[100];
  string Artist[100];
  int Size[100];
  Duration Duration;
};

void mp3NewSong(Cancion &cancion, int &songCount) {
  cout << "Ingrese el nombre de la canción: ";
  cin >> cancion.Name[songCount];
  // Validar que el nombre no esté vacío
  while (cancion.Name[songCount].empty()) {
    cout << "Error: El nombre de la canción no puede estar vacío. Intente de "
            "nuevo: ";
    cin >> cancion.Name[songCount];
  }
  cout << "Ingrese el nombre del artista: ";
  cin >> cancion.Artist[songCount];
  cout << "Ingrese la duración de la canción en minutos: ";
  cin >> cancion.Duration.Minutes[songCount];
  cout << "Ingrese los segundos de la duración de la canción: ";
  cin >> cancion.Duration.Seconds[songCount];
  cout << "Ingrese el tamaño de la cancion: ";
  cin >> cancion.Size[songCount];
  // Validar que el tamaño no sea negativo
  while (cancion.Size[songCount] < 0) {
    cout << "Error: El tamaño de la canción no puede ser negativo. Intente de "
            "nuevo: ";
    cin >> cancion.Size[songCount];
  }
  songCount++;
}

void mp3ShowSongs(const Cancion &cancion, int songCount) {
  for (int i = 0; i < songCount; i++) {
    cout << "Canción " << i + 1 << ": " << cancion.Name[i] << endl;
  }
}

void mp3SearchSong(const Cancion &cancion, int songCount) {
  string searchText;
  cout << "Ingrese el texto a buscar: ";
  cin >> searchText;
  for (int i = 0; i < songCount; i++) {
    if (cancion.Name[i].find(searchText) != string::npos ||
        cancion.Artist[i].find(searchText) != string::npos) {
      cout << "Canción " << i + 1 << ": " << cancion.Name[i] << endl;
    }
  }
}

void mp3Menu() {
  Cancion cancion;
  int songCount = 0;
  int option;
  do {
    cout << "\nMenu de opciones:\n";
    cout << "1. Añadir una nueva canción\n";
    cout << "2. Mostrar el título de todas las canciones\n";
    cout << "3. Buscar una canción por texto\n";
    cout << "4. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> option;

    switch (option) {
    case 1:
      mp3NewSong(cancion, songCount);
      break;
    case 2:
      mp3ShowSongs(cancion, songCount);
      break;
    case 3:
      mp3SearchSong(cancion, songCount);
      break;
    case 4:
      cout << "Saliendo del programa...\n";
      cout << "Adios :P\n";
      break;
    default:
      cout << "Opción inválida. Intente de nuevo.\n";
      break;
    }
  } while (option != 4);
}

int main() {
  mp3Menu();
  return 0;
}