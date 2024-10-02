import java.util.Scanner;

public class Main {

    public enum Mes {
        ENERO(1, 31), FEBRERO(2, 28), MARZO(3, 31), ABRIL(4, 30),
        MAYO(5, 31), JUNIO(6, 30), JULIO(7, 31), AGOSTO(8, 31),
        SEPTIEMBRE(9, 30), OCTUBRE(10, 31), NOVIEMBRE(11, 30), DICIEMBRE(12, 31);

        private int orden;
        private int dias;

        Mes(int orden, int dias) {
            this.orden = orden;
            this.dias = dias;
        }

        public int getOrden() {
            return orden;
        }

        public int getDias() {
            return dias;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Introduce el número de días: ");
        int dias = scanner.nextInt();

        for (Mes mes : Mes.values()) {
            if (mes.getDias() == dias) {
                System.out.println("Mes: " + mes.name() + ", Orden: " + mes.getOrden() + ", Días: " + mes.getDias());
            }
        }

        scanner.close();
    }
}
