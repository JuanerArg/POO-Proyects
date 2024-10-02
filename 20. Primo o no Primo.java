/*
Pide un número por teclado e indica si es un número primo o no. 
Un número primo es aquel solo puede dividirse entre 1 y si mismo. 
Por ejemplo: 25 no es primo, ya que 25 es divisible entre 5, sin embargo, 17 si es primo.
Un buen truco para calcular la raíz cuadrada del numero e ir comprobando que si es divisible desde ese numero hasta 1.
NOTA: Si se introduce un numero menor o igual que 1, directamente es no primo.
*/
import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = 0;

        // Pide al usuario un número entero
        System.out.println("Ingrese un número para saber si es primo o no:");
        try {
            n = input.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Error. Ingrese un número entero.");
            input.close();
            return;
        }

        // Verifica si el número es menor o igual a 1
        if (n <= 1) {
            System.out.println(n + " no es un número primo.");
        } else {
            // Verifica si el número es primo
            boolean esPrimo = true;
            for (int divisor = 2; divisor <= Math.sqrt(n); divisor++) {
                if (n % divisor == 0) {
                    esPrimo = false;
                    break;
                }
            }

            // Muestra el resultado
            if (esPrimo) {
                System.out.println(n + " es un número primo.");
            } else {
                System.out.println(n + " no es un número primo.");
            }
        }

        input.close();
    }
}
