//Declara dos variables numéricas (con el valor que desees), muestra por consola la suma, resta, multiplicación, división y módulo (resto de la división).
import java.util.Scanner;
import java.text.DecimalFormat;

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    float x = 0;
    float y = 0;

    System.out.println("Ingrese el primer número: ");
    x = input.nextFloat();

    System.out.println("Ingrese el segundo número: ");
    y = input.nextFloat();

    DecimalFormat df = new DecimalFormat("#.00");

    System.out.println("Suma: " + df.format(x + y));
    System.out.println("Resta: " + df.format(x - y));
    System.out.println("Multiplicacion: " + df.format(x * y));
    System.out.println("Division: " + df.format(x / y));
    System.out.println("Modulo: " + df.format(x % y));

    input.close();
  }
}