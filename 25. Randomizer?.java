import java.util.Random;

public class Ejercicio25 {
    public static void main(String[] args) {
        Random random = new Random();
        int suma = 0;

        System.out.println("Números aleatorios generados:");
        for (int i = 0; i < 10; i++) {
            int numero = random.nextInt(11); // Genera números entre 0 y 10
            System.out.print(numero + " ");
            suma += numero;
        }

        System.out.println("\nSuma total: " + suma);
    }
}
