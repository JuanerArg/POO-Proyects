// Muestra los números del 1 al 100 (ambos incluidos) divisibles entre 2 y 3. Utiliza el bucle que desees.
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
  int value = 0;
  do {
    value++;
    if (value % 2 == 0 || value % 3 == 0){
      System.out.println(value);
    }
  }while (value < 100);
  }
}