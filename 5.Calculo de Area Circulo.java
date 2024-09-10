// Haz una aplicación que calcule el área de un círculo(pi*R2). 
//El radio se pedirá por teclado (recuerda pasar de String a double con Double.parseDouble). 
//Usa la constante PI y el método pow de Math.
import java.util.Scanner;
//import java.text.DecimalFormat;
public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    float radio = 0;

    System.out.println("Introduce un numero: ");
    do{
      try {
        radio = Float.parseFloat(input.nextLine());
        break;
      } catch (NumberFormatException e) {
        System.out.println("Error: Ingrese un numero");
      }
    }while(true);
    

    System.out.println("El area de un circulo de radio " + radio + " es: " + Math.PI * Math.pow(radio, 2));
    input.close();
  }
}