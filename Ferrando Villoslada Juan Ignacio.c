#include <stdio.h>

int main() {
  int ejercicio;
  do {
    printf("\nIngrese el ejercicio que desea ejecutar: ");
    printf("\n1. Anio bisiesto?");
    printf("\n2. Tabla de un entero positivo");
    printf("\n3. Descuentos para entradas");
    printf("\n4. Precios servicio de catering");
    printf("\n5. Uvas");
    printf("\n6. Salir\n");
    scanf("%d", &ejercicio);

    switch (ejercicio) {
    case 1: {
      // verificamos si el año es bisiesto o no
      int anio;
      printf("Ingrese un anio: ");
      scanf("%d", &anio);
      if (anio % 4 == 0) {
        if (anio % 100 != 0) {
          printf("\nEl anio es bisiesto");
    	}
      }else{
		printf("El anio no es bisiesto");
		}
      break;
    }
    case 2: {
      // se verifica que el num ingresado sea entero y positivo
      // mostrar su tabla de multiplicar
      int num;
      int i, n = 10;
      int multiplicacion;
      printf("Ingrese un numero: ");
      scanf("%d", &num);
      if (num > 0) {
        for (i = 0; i <= n; i++) {
          multiplicacion = num * i;
          printf("%d x %d = %d\n", num, i, multiplicacion);
        }
      }
      break;
    }
    case 3: {
      int entradas; // tienen que ser 4 max
      // si se compran 2 hay 10% de descuento
      // si se compran 3 hay 15% de descuento
      // si se compran 4 hay 20% de descuento
      int precio = 100;

      printf("El precio de cada entrada es de 100 pesos\n");
      printf("\nCuantas entradas vas a comprar?\n");
      scanf("%d", &entradas);

      // verificamos que sean 4 max
      if (entradas > 4) {
        printf("No se pueden comprar mas de 4 entradas\n");
        break;
      }

      // verificamos que sean al menos 1
      if (entradas == 0) {
        printf("No se puede comprar 0 entradas\n");
        break;
      }
      // switch para cada cantidad de entradas
      switch (entradas) {
      case 1: {
        printf("No se aplica descuento\n");
        printf("Son 100 pesos\n");
        break;
      }
      case 2: {
        printf("Se aplica un 10%% de descuento");
        printf("\nSon %2.f pesos", precio * entradas * 0.9);
        break;
      }
      case 3: {
        printf("Se aplica un 15%% de descuento");
        printf("\nSon %2.f pesos", precio * entradas * 0.85);
        break;
      }
      case 4: {
        printf("Se aplica 20%% de descuento");
        printf("\nSon %2.f pesos", precio * entradas * 0.8);
        break;
      }
      }

      break;
    }
    case 4: {
      /*
      Empresa de catering decide precios segun cantidad de platos que se sirvan
      */
      int plato = 6500;
      int total;
      int personas;

      printf("Cuantas personas asistiran al evento? ");
      scanf("%d", &personas);
      // entre 200 y 300 personas el precio es de 5500 pp
      if (personas > 200 && personas <= 300) {
        plato = 5500;
      }
      // si son mas de 300 personas el precio es de 4500 pp
      if (personas > 300) {
        plato = 4500;
      }
      total = plato * personas;
      // la salida es el precio del catering
      printf("\nEl valor total a pagar es de %d", total);
      break;
    }
    case 5: {
      int precioUva;
      int tipo;   // si es 1 es tipo A y si es 2 es tipo B
      int tamanio; // Tamaños 1 y 2
      int kilos;
      int preciofinal;

      printf("Cuantos kilos de uva vas a vender?");
      scanf("%d", &kilos);
      printf("Que tipo de uva vas a vender? Ingrese 1 para A y 2 para B");
      scanf("%d", &tipo);
      if (tipo != 1 && tipo != 2) {
        printf("Tipo de uva no valido");
        break;
      }
      printf("Que tamaño de uva vas a vender? 1 o 2");
      scanf("%d", &tamanio);
      if (tamanio != 1 && tamanio != 2) {
        printf("Tamaño de uva no valido");
        break;
      }
      if (tipo == 1) {
        if (tamanio == 1) {
          precioUva = 200;
        }
        if (tamanio == 2) {
          precioUva = 300;
        }
      }
      if (tipo == 2) {
        if (tamanio == 1) {
          precioUva = 300;
        }
        if (tamanio == 2) {
          precioUva = 500;
        }
      }

      preciofinal = precioUva * kilos;

      printf("El productor ganara %d en este embarque", preciofinal);

      break;
    }
    default: {
      if (ejercicio != 6) {
        printf("Error 404 xp");
      }
    }
    }
  } while (ejercicio != 6);
  printf("Saliendo del programa...");
  printf("\nGoodbye :p");
}

