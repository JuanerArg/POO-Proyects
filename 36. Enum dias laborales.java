public class Main {

    public enum Dia {
        LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO;

        @Override
        public String toString() {
            if (this == SABADO || this == DOMINGO) {
                return this.name() + " no es un día laboral.";
            } else {
                return this.name() + " es un día laboral.";
            }
        }
    }

    public static void main(String[] args) {
        for (Dia dia : Dia.values()) {
            System.out.println(dia.toString());
        }
    }
}
