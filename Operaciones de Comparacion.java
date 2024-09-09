//Declara 2 variables numéricas (con el valor que desees), he indica cual es mayor de los dos. Si son iguales indicarlo también. Ves cambiando los valores para comprobar que funciona.
import java.util.Scanner;
//import java.text.DecimalFormat;
public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    float x = 0;
    float y = 0;
    
    System.out.println("Ingrese el primer número: ");
    x = input.nextFloat();

    System.out.println("Ingrese el segundo número: ");
    y = input.nextFloat();
    //DecimalFormat df = new DecimalFormat("#.00");

    if(x > y){
      System.out.println("El número mayor es: " + x);
    }
    else if(y > x){
      System.out.println("El número mayor es: " + y);
    }
    else{
      System.out.println("Los números son iguales");
    }
    
    input.close();
  }
}