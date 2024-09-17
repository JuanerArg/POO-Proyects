/*
Realiza una aplicación que nos calcule una ecuación de segundo grado. 
Debes pedir las variables a, b y c por teclado y comprobar antes que el discriminante (operación en la raíz cuadrada). 
Para la raíz cuadrada usa el método sqlrt de Math. 
Te recomiendo que uses mensajes de traza.
*/
import java.lang.NumberFormatException;
import java.util.Scanner;

public class Main {
    public static double Inputs() {
        Scanner input = new Scanner(System.in);
        double value;
        do {
            try {
                value = Double.parseDouble(input.nextLine());
                break;
            } catch (NumberFormatException e) {
                System.out.println("Error: Tipo de dato no válido");
            }
        } while (true);
        
        return value;
    }

    public static void main(String[] args) {
        double a, b, c, discriminante, x1, x2;
      
        System.out.println("Introduce el valor de a:");
        a = Inputs();
      
        System.out.println("Introduce el valor de b:");
        b = Inputs();
      
        System.out.println("Introduce el valor de c:");
        c = Inputs();
      
        discriminante = Math.pow(b, 2) - 4 * a * c;
      
        System.out.println("El discriminante es: " + discriminante);
        if (discriminante >= 0) {
            x1 = (-b + Math.sqrt(discriminante)) / (2 * a);
            x2 = (-b - Math.sqrt(discriminante)) / (2 * a);
            System.out.println("Las soluciones son: " + x1 + " y " + x2);
        } else {
            System.out.println("La ecuación no tiene soluciones reales");
        }
    }
}