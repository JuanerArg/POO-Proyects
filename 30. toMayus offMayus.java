import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Introduce una frase: ");
        String frase = scanner.nextLine();

        System.out.print("¿Convertir a mayúsculas o minúsculas? (m/M): ");
        char opcion = scanner.next().charAt(0);

        if (opcion == 'M' || opcion == 'm') {
            System.out.println("Frase en mayúsculas: " + frase.toUpperCase());
        } else {
            System.out.println("Frase en minúsculas: " + frase.toLowerCase());
        }

        scanner.close();
    }
}
