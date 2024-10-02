import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numero, mayor = Integer.MIN_VALUE, menor = Integer.MAX_VALUE;
        int sumaTotal = 0, sumaPositivos = 0, sumaNegativos = 0, cantidad = 0;

        do {
            System.out.print("Introduce un número (-1 para terminar): ");
            numero = scanner.nextInt();

            if (numero != -1) {
                if (numero > mayor) mayor = numero;
                if (numero < menor) menor = numero;
                sumaTotal += numero;
                if (numero > 0) {
                    sumaPositivos += numero;
                } else {
                    sumaNegativos += numero;
                }
                cantidad++;
            }
        } while (numero != -1);

        double media = (double) sumaTotal / cantidad;

        System.out.println("Mayor número: " + mayor);
        System.out.println("Menor número: " + menor);
        System.out.println("Suma total: " + sumaTotal);
        System.out.println("Suma de números positivos: " + sumaPositivos);
        System.out.println("Suma de números negativos: " + sumaNegativos);
        System.out.println("Media de la suma total: " + media);

        scanner.close();
    }
}
