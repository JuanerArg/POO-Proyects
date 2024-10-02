public class Main {
    public static void main(String[] args) {
        String frase = "La lluvia en Sevilla es una maravilla";
        int contadorVocales = 0;

        for (int i = 0; i < frase.length(); i++) {
            char letra = Character.toLowerCase(frase.charAt(i));
            if (esVocal(letra)) {
                contadorVocales++;
            }
        }

        System.out.println("El número total de vocales es: " + contadorVocales);
    }

    public static boolean esVocal(char letra) {
        return letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u';
    }
}
