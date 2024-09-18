/*
Pide por teclado un número entero positivo y muestra cuántas cifras tiene.
Controla que sea un número positivo.
*/
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numero;
        
        // Controlamos que se ingrese un número positivo
        do {
            System.out.println("Ingrese un número entero positivo: ");
            numero = input.nextInt();
            if (numero <= 0) {
                System.out.println("El número debe ser positivo.");
            }
        } while (numero <= 0);

        // Contamos el número de cifras
        int cifras = String.valueOf(numero).length();
        
        System.out.println("El número " + numero + " tiene " + cifras + " cifras.");
        input.close();
    }
}
