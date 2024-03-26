/*
Un vendedor recibe un sueldo base más un 10% extra por comisión de sus ventas,
el vendedor desea saber cuánto dinero obtendrá por concepto de comisiones por
las tres ventas que realiza en el mes y el total que recibirá en el mes tomando
en cuenta su sueldo base y comisiones
*/

#include <stdio.h>

int main(void) {
  int menu_option;
  do {
    printf("\n---------------------------------------\n");
    printf("Ingrese el ejercicio que quiere ejecutar\n");
    printf("1. Ejercicio 1\n");
    printf("2. Ejercicio 2\n");
    printf("3. Ejercicio 3\n");
    printf("4. Ejercicio 4\n");
    printf("5. Ejercicio 5\n");
    printf("6. Salir\n");
    scanf("%d", &menu_option);

    switch (menu_option) {
    case 1: {
      int alumnos;
      float PpA;
      int Total;
      printf("Cuantos alumnos hay?\n");
      scanf("%d", &alumnos);

      if (alumnos >= 100) {
        Total = alumnos * 500;

        printf("El costo por alumno es de $500\n");
        printf("El costo total es de $");
        printf("%d\n", Total);
      } else if (alumnos >= 50 && alumnos <= 99) {
        Total = alumnos * 400;

        printf("El costo por alumno es de $400\n");
        printf("El costo total es de $");
        printf("%d\n", Total);
      } else if (alumnos >= 30 && alumnos <= 49) {
        Total = alumnos * 300;

        printf("El costo por alumno es de $300\n");
        printf("El costo total es de $");
        printf("%d\n", Total);
      } else if (alumnos < 29) {
        Total = 6000;
        PpA = 6000 / alumnos;

        printf("El costo por alumno es de $%f\n", PpA);
        printf("El costo total es de $");
        printf("%d\n", Total);
      }
      break;
    }
    case 2: {
      float sueldo;
      int ventas = 0;
      float venta = 0;
      int i = 0;
      float acum;

      printf("Cuanto es el sueldo base?\n");
      scanf("%f", &sueldo);

      for (i = 0; i < 3; i++) {
        printf("Cuanto hizo en la venta %d", ventas);
        scanf("%f", &venta);

        float comision = venta * 0.1;

        acum = acum + comision;
        ventas++;
        venta = 0;
        comision = 0;
      }
      float ganancia = sueldo + acum;

      printf("La ganancia total es de $");
      printf("%f\n", ganancia);

      break;
    }
    /*Un alumno desea saber cuál será su calificación final en la materia de
    Algoritmos. Dicha calificación se compone de los siguientes porcentajes: 55%
    del promedio de sus tres calificaciones parciales. 30% de la calificación
    del examen final. 15% de la calificación de un trabajo final
    */
    case 3: {
      int i = 0;
      int calificacionp = 0;
      int calificacion = 0;
      float calificacionpf = 0;

      for (i = 0; i < 3; i++) {
        printf("Ingrese la calificacion de la prueba %d\n", i);
        scanf("%d", &calificacion);
        calificacionp = calificacionp + calificacion;
        calificacionpf = (calificacionp / 3) * 0.55;
      }
      printf("Ingrese la calificacion del examen final\n");
      scanf("%d", &calificacion);

      float calificationef = calificacion * 0.3;

      printf("Ingrese la calificacion del trabajo final\n");
      scanf("%d", &calificacion);

      int calificaciontpf = calificacion * 0.15;

      float califfinal = calificacionpf + calificationef + calificaciontpf;

      printf("La calificacion final es de: %f", califfinal);

      break;
    }
      /*
        Escribir un programa que imprima todos los números pares entre dos números que se le pida al usuario.
      */
	case 4: {
		int num1, num2;

    	printf("Ingrese dos numeros: ");
    	scanf("%d %d", &num1, &num2);

    	printf("Numeros pares entre %d y %d:\n", num1, num2);
    	for (int i = num1; i <= num2; i++) {
        	if (i % 2 == 0) {
            	printf("%d ", i);
        	}
    	}
  		break;
	}
    default: {
      printf("Error :(");
      break;
    }
    }
  } while (menu_option != 6);
  return 0;
}