/*
Pide por teclado dos números y genera 10 números aleatorios entre esos números.
Usa el método Math.random para generar un número entero aleatorio.
*/
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Ingrese el primer número: ");
        int num1 = input.nextInt();

        System.out.println("Ingrese el segundo número: ");
        int num2 = input.nextInt();
        
        // Aseguramos que num1 sea siempre menor o igual que num2 para evitar problemas.
        int min = Math.min(num1, num2);
        int max = Math.max(num1, num2);
        
        System.out.println("Generando 10 números aleatorios entre " + min + " y " + max + ":");
        for (int i = 0; i < 10; i++) {
            // Generamos un número aleatorio en el rango [min, max]
            int aleatorio = (int) (Math.random() * (max - min + 1)) + min;
            System.out.println(aleatorio);
        }
        input.close();
    }
}
