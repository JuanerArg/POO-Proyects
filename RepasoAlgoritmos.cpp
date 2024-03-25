#include <stdio.h>

int main(void) {
  int n = 0;
  int i = 0;

  do {
  	printf("--------------------------------\n");
    printf("1.Positivo o Negativo\n");
    printf("2. Par o Impar\n");
    printf("3. Multiplo de 2 o 3\n");
    printf("4. Mayor de 3\n");
    printf("5. Salir\n");
    scanf("%d", &i);
    switch (i) {
    case 1: {
      printf("--------------------------------\n");
      printf("Ingrese un numero: ");
      int num;
      scanf("%d", &num);

      if (num >= 0) {
        printf("%d es un numero positivo.\n", num);
      } else {
        printf("%d es un numero negativo.\n", num);
      }
      break;
    }
    case 2: {
      printf("--------------------------------\n");
      printf("Ingrese un numero: ");
      int num;
      scanf("%d", &num);

      if (num % 2 == 0) {
        printf("%d es un numero par.\n", num);
      } else {
        printf("%d es un numero impar.\n", num);
      }
      break;
    }
    case 3: {
      printf("--------------------------------\n");
      printf("Ingrese un numero: ");
      int num;
      scanf("%d", &num);

      if (num % 2 == 0 && num % 3 == 0) {
        printf("%d es multiplo de 2 y 3.\n", num);
      } else if (num % 2 == 0) {
        printf("%d es multiplo de 2.\n", num);
      } else if (num % 3 == 0) {
        printf("%d es multiplo de 3.\n", num);
      } else {
        printf("%d no es multiplo de 2 ni de 3.\n", num);
      }
      break;
    }
    case 4: {
      printf("--------------------------------\n");
      printf("Ingrese tres numeros: ");
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      if (a >= b && a >= c) {
        printf("%d es el mayor de los tres.\n", a);
      } else if (b >= a && b >= c) {
        printf("%d es el mayor de los tres.\n", b);
      } else {
        printf("%d es el mayor de los tres.\n", c);
      }
      break;
    }
    case 5: {
      printf("--------------------------------\n");
      printf("Saliendo del programa...\n");
      printf("Goodbye! ;p");
      n = 6;
      break;
    }
    default:{
    	printf("--------------------------------\n");
    	printf("Error...");
		break;
	}
    }
  } while (n != 6);
  return 0;
}

