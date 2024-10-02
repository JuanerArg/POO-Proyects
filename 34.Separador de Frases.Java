import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Introduce una frase: ");
        String frase = scanner.nextLine();

        String[] palabras = frase.split(" ");
        System.out.println("Las palabras separadas son:");
        for (String palabra : palabras) {
            System.out.println(palabra);
        }

        scanner.close();
    }
}
