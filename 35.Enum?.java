import java.util.Scanner;

public class Ejercicio35 {

    public enum Dia {
        LUNES(true), MARTES(true), MIERCOLES(true), JUEVES(true), VIERNES(true),
        SABADO(false), DOMINGO(false);

        private boolean esLaboral;

        Dia(boolean esLaboral) {
            this.esLaboral = esLaboral;
        }

        public boolean esLaboral() {
            return esLaboral;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Introduce un día de la semana: ");
        String diaInput = scanner.nextLine().toUpperCase();

        try {
            Dia dia = Dia.valueOf(diaInput);
            if (dia.esLaboral()) {
                System.out.println(diaInput + " es un día laboral.");
            } else {
                System.out.println(diaInput + " no es un día laboral.");
            }
        } catch (IllegalArgumentException e) {
            System.out.println("El día introducido no es válido.");
        }

        scanner.close();
    }
}
