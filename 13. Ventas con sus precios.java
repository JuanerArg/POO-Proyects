// Realiza una aplicación que nos pida un número de ventas a introducir, 
// después nos pedirá tantas ventas por teclado como número de ventas se hayan indicado. 
// Al final mostrara la suma de todas las ventas. 
// Piensa que es lo que se repite y lo que no.

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static String Inputs() {
        Scanner input = new Scanner(System.in);
        String text;
        do {
            try {
                text = input.nextLine();
                break;
            } catch (InputMismatchException e) {
                System.out.println("Error: Tipo de dato no válido");
            }
        } while (true);
        return text;
    }

    public static void main(String[] args) {
        int numSales = 0; // Use an integer for the number of sales
        float saleValue = 0; // Use a float for the sale value
        float acum = 0;

        System.out.println("Introduzca el numero de ventas: ");
        numSales = Integer.parseInt(Inputs()); // Get the number of sales

        for (int cont = 0; cont < numSales; cont++) { // Use a for loop for clarity
            System.out.println("Introduzca el valor de la venta " + (cont + 1) + ": ");
            saleValue = Float.parseFloat(Inputs()); // Get the sale value
            acum += saleValue; // Add the sale value to the accumulator
        }

        System.out.println("El total de las ventas es: " + acum);
    }
}