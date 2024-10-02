public class Ejercicio39 {
    public static void main(String[] args) throws InterruptedException {
        while (true) {
            java.util.Date fecha = new java.util.Date();
            System.out.printf("%tT\n", fecha);
            Thread.sleep(1000);
        }
    }
}
