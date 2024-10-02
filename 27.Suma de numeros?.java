import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int contador = 0;
        int numero;

        do {
            System.out.print("Introduce un número (-1 para salir): ");
            numero = scanner.nextInt();
            if (numero != -1) {
                contador++;
            }
        } while (numero != -1);

        System.out.println("Se han introducido " + contador + " números.");
        scanner.close();
    }
}
