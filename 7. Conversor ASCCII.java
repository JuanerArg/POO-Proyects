// Lee un número por teclado y muestra por consola, el carácter al que pertenece en la tabla ASCII. Por ejemplo: si introduzco un 97, me muestre una a.
import java.util.Scanner;
//import java.text.DecimalFormat;
public class Main {
  public static void main(String[] args) {
    
    Scanner input = new Scanner(System.in);
    
    int value = 0;
    
    System.out.println("Introduce un numero: ");
    do{
      try {
        value = Integer.parseInt(input.nextLine());
        break;
      } catch (NumberFormatException e) {
        System.out.println("Error: Ingrese un numero");
      }
    }while(true);
    
    char ASCCIIvalue = (char)value;
    
    System.out.println("El caracter correspondiente es: " + ASCCIIvalue);
    
    input.close();
  }
}