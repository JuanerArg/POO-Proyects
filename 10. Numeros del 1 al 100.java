//  Muestra los números del 1 al 100 (ambos incluidos). Usa un bucle while.
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
  int value = 0;
  do {
    value += 1;
    System.out.println(value);
  }while (value < 100);
  }
}