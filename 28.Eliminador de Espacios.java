import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Introduce una frase: ");
        String frase = scanner.nextLine();

        String fraseSinEspacios = frase.replace(" ", "");
        System.out.println("Frase sin espacios: " + fraseSinEspacios);

        scanner.close();
    }
}
