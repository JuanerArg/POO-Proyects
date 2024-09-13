// Modifica el ejercicio anterior, para que en lugar de pedir un número, pida un carácter (char) y muestre su código en la tabla ASCII.
import java.util.Scanner;
import java.util.InputMismatchException;
//import java.text.DecimalFormat;
public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    char value = 0;
    System.out.println("Introduce un caracter: ");
    do{
      try {
        String line = input.nextLine(); // Read the entire line
        if (line.length() != 1) {
          System.out.println("Error: Ingrese un caracter");
          continue; // Restart the loop
        }
        value = line.charAt(0);
        break;
      } catch (InputMismatchException e) {
        System.out.println("Error: Ingrese un caracter");
      }
    }while(true);

    System.out.println("El codigo ASCII de " + value + " es: " + (int)value);
    input.close();
  }
}