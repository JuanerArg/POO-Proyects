import java.util.Scanner;

public class Ejercicio29 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder cadenaCompleta = new StringBuilder();
        String frase;

        do {
            System.out.print("Introduce una frase (deja vacío para salir): ");
            frase = scanner.nextLine();
            cadenaCompleta.append(frase).append(" ");
        } while (!frase.isEmpty());

        System.out.println("Frase resultante: " + cadenaCompleta.toString().trim());
        scanner.close();
    }
}
