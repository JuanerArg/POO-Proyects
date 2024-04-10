#include <stdio.h>

main() {
  int a, b, c;

  for (int a = 1; a <= 500; a++) {
    for (int b = a; b <= 500; b++) {
      for (int c = b; c <= 500; c++) {
        if (a * a + b * b == c * c) {
          printf("-------------------\n");
          printf("Cateto Opuesto: %d\n", a);
          printf("Cateto Adyacente: %d\n", b);
          printf("Hipotenusa: %d\n", c);
          printf("-------------------\n");
        }
      }
    }
  }
}