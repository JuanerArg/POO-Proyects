#include <stdio.h>

main() {
  int filas, columnas;
  
  // pedimos tamaño de matriz
  printf("Ingrese el número de filas de la matriz: ");
  scanf("%d", &filas);
  printf("Ingrese el número de columnas de la matriz: ");
  scanf("%d", &columnas);

  int A[filas][columnas];
  int i, j;
  printf("Ingrese los elementos de la matriz:\n");

  // bucle para pedir datos de la matriz
  for (i = 0; i < filas; i++) {
    for (j = 0; j < columnas; j++) {
      printf("Ingresa el valor A[%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  // bucle para imprimir en pantalla la matriz
  for (i = 0; i < filas; i++) {
    for (j = 0; j < columnas; j++) {
      /* printf ("%d ", A[i][j]);
      puedo agregar un espacio, pero lo que necesito es que baje cada vez
      que termine la fila y eso lo controla el ciclo for con variable i */

      // caracter de control \t tabulador horizontal
      printf("%d\t", A[i][j]);
    }
    printf("\n");
  }
}