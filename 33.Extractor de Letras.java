import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Introduce una cadena con al menos 5 caracteres: ");
        String cadena = scanner.nextLine();

        if (cadena.length() >= 5) {
            String subcadena = cadena.substring(3, 5);
            System.out.println("La cuarta y quinta letra son: " + subcadena);
        } else {
            System.out.println("La cadena no tiene suficientes caracteres.");
        }

        scanner.close();
    }
}
