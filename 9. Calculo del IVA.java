// Lee un número por teclado que pida el precio de un producto (puede tener decimales) y calcule el precio final con IVA. El IVA sera una constante que sera del 21%.
import java.util.Scanner;
import java.util.InputMismatchException;
//import java.text.DecimalFormat;
public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    float value = 0;
    System.out.println("Introduzca el precio de un producto: ");
    do{
      try {
        value = Float.parseFloat(input.nextLine());// Read the entire line
        break;
      } catch (NumberFormatException e) {
        System.out.println("Error: Ingrese un numero");
      }
    }while(true);

    System.out.println("El precio de ese producto + IVA es de: " + (value + (value * 0.21)));
    input.close();
  }
}