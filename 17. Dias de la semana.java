/*
Crea una aplicación que nos pida un día de la semana y que nos diga si es un día laboral o no.
Usa un switch para ello.
*/
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Ingrese un día de la semana (ejemplo: lunes): ");
        String dia = input.nextLine().toLowerCase(); // Convertimos a minúsculas para evitar problemas con el case.

        switch (dia) {
            case "lunes":
            case "martes":
            case "miércoles":
            case "jueves":
            case "viernes":
                System.out.println("Es un día laboral.");
                break;
            case "sábado":
            case "domingo":
                System.out.println("No es un día laboral.");
                break;
            default:
                System.out.println("Día no válido.");
                break;
        }
        input.close();
    }
}
