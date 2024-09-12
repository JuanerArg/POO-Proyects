// Lee un número por teclado e indica si es divisible entre 2 (resto = 0). Si no lo es, también debemos indicarlo.
import java.util.Scanner;
//import java.text.DecimalFormat;
public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    float value = 0;
    System.out.println("Introduce un numero: ");
    do{
      try {
        value = Float.parseFloat(input.nextLine());
        break;
      } catch (NumberFormatException e) {
        System.out.println("Error: Ingrese un numero");
      }
    }while(true);
    
    if(value % 2 == 0){
    System.out.println("El numero es divisible entre 2");
    }
    else{
      System.out.println("El numero no es divisible entre 2");
    }
    input.close();
  }
}