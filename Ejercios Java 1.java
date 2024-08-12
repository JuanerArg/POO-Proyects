import java.util.Scanner;

public class EjerciciosJava1 {
    public static void main(String[] args) {
        // Crear un objeto Scanner para leer la entrada del usuario
        Scanner scanner = new Scanner(System.in);
        int choice; // Variable para almacenar la opción seleccionada por el usuario
        
        do {
            // Mostrar el menú de opciones
            System.out.println("Menú:");
            System.out.println("1. Mostrar números del 1 al 100 e informar si son pares o impares.");
            System.out.println("2. Mostrar números del 50 al 100 e informar si son primos o sus divisores.");
            System.out.println("3. Pedir números hasta que uno sea mayor a 100 y primo.");
            System.out.println("4. Realizar operaciones aritméticas.");
            System.out.println("5. Usar for-each para mostrar elementos de un arreglo.");
            System.out.println("6. Salir.");
            System.out.print("Selecciona una opción (1-6): ");
            choice = scanner.nextInt(); // Leer la opción seleccionada
            
            // Procesar la opción seleccionada por el usuario
            switch (choice) {
                case 1:
                    // Mostrar números del 1 al 100 e informar si son pares o impares
                    for (int i = 1; i <= 100; i++) {
                        if (i % 2 == 0) {
                            System.out.println(i + " es par");
                        } else {
                            System.out.println(i + " es impar");
                        }
                    }
                    break;
                    
                case 2:
                    // Mostrar números del 50 al 100 e informar si son primos o sus divisores
                    for (int i = 50; i <= 100; i++) {
                        if (isPrime(i)) {
                            System.out.println(i + " es primo");
                        } else {
                            System.out.print(i + " no es primo, sus divisores son: ");
                            printDivisors(i);
                        }
                    }
                    break;
                    
                case 3:
                    // Pedir números hasta que uno sea mayor a 100 y primo
                    int number;
                    do {
                        System.out.print("Introduce un número: ");
                        number = scanner.nextInt();
                    } while (!isPrime(number) || number <= 100);
                    
                    System.out.println("El número " + number + " es mayor a 100 y es primo.");
                    break;
                    
                case 4:
                    // Realizar operaciones aritméticas
                    System.out.print("Introduce el primer número: ");
                    double num1 = scanner.nextDouble();
                    
                    System.out.print("Introduce el segundo número: ");
                    double num2 = scanner.nextDouble();
                    
                    System.out.print("Introduce la operación (+, -, *, /): ");
                    char operation = scanner.next().charAt(0);
                    
                    double result;
                    switch (operation) {
                        case '+':
                            result = num1 + num2;
                            break;
                        case '-':
                            result = num1 - num2;
                            break;
                        case '*':
                            result = num1 * num2;
                            break;
                        case '/':
                            if (num2 != 0) {
                                result = num1 / num2;
                            } else {
                                System.out.println("Error: División por cero.");
                                continue; // Continuar con la siguiente iteración del menú
                            }
                            break;
                        default:
                            System.out.println("Operación no válida.");
                            continue; // Continuar con la siguiente iteración del menú
                    }
                    
                    System.out.println("El resultado de " + num1 + " " + operation + " " + num2 + " es " + result);
                    break;
                    
                case 5:
                    // Usar for-each para mostrar elementos de un arreglo
                    int[] numbers = {1, 2, 3, 4, 5};
                    
                    System.out.println("Elementos del arreglo:");
                    // Bucle for-each para iterar sobre cada elemento del arreglo
                    for (int numberInArray : numbers) {
                        System.out.println(numberInArray);
                    }
                    break;
                    
                case 6:
                    // Mensaje de salida
                    System.out.println("Saliendo...");
                    break;
                    
                default:
                    // Mensaje de opción no válida
                    System.out.println("Opción no válida. Por favor, selecciona una opción del 1 al 6.");
            }
            
            // Imprimir una línea en blanco para mejorar la legibilidad
            System.out.println();
        } while (choice != 6); // Continuar mostrando el menú hasta que el usuario seleccione la opción 6
        
        // Cerrar el objeto Scanner para liberar recursos
        scanner.close();
    }
    
    // Método para verificar si un número es primo
    public static boolean isPrime(int number) {
        if (number <= 1) return false; // Los números menores o iguales a 1 no son primos
        if (number == 2) return true;  // El número 2 es primo
        if (number % 2 == 0) return false; // Los números pares mayores que 2 no son primos
        // Verificar divisibilidad desde 3 hasta la raíz cuadrada del número
        for (int i = 3; i <= Math.sqrt(number); i += 2) {
            if (number % i == 0) return false; // Si el número es divisible por i, no es primo
        }
        return true; // El número es primo
    }
    
    // Método para imprimir los divisores de un número
    public static void printDivisors(int number) {
        // Imprimir todos los divisores desde 1 hasta la mitad del número
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                System.out.print(i + " ");
            }
        }
        // Imprimir el número mismo, ya que también es divisor
        System.out.println(number);
    }
}
