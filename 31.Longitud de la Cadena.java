import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Introduce una cadena: ");
        String cadena = scanner.nextLine();

        System.out.println("La longitud de la cadena es: " + cadena.length());
        scanner.close();
    }
}
