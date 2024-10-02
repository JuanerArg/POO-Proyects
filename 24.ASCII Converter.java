public class Main {
    public static void main(String[] args) {
        String frase = "La lluvia en Sevilla es una maravilla";

        for (int i = 0; i < frase.length(); i++) {
            int codigoAscii = (int) frase.charAt(i);
            System.out.print(codigoAscii + " ");
        }
    }
}
