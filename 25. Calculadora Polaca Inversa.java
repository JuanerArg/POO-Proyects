import javax.swing.JOptionPane;

public class CalculadoraPolacaInversaApp {
    public static void main(String[] args) {
        int operando1 = Integer.parseInt(JOptionPane.showInputDialog("Introduce el primer operando:"));
        int operando2 = Integer.parseInt(JOptionPane.showInputDialog("Introduce el segundo operando:"));
        String operacion = JOptionPane.showInputDialog("Introduce la operación (+, -, *, /, ^, %):");

        double resultado = 0;

        switch (operacion) {
            case "+":
                resultado = operando1 + operando2;
                break;
            case "-":
                resultado = operando1 - operando2;
                break;
            case "*":
                resultado = operando1 * operando2;
                break;
            case "/":
                resultado = (double) operando1 / operando2;
                break;
            case "^":
                resultado = Math.pow(operando1, operando2);
                break;
            case "%":
                resultado = operando1 % operando2;
                break;
            default:
                JOptionPane.showMessageDialog(null, "Operación no válida");
                System.exit(0);
        }

        JOptionPane.showMessageDialog(null, "El resultado es: " + resultado);
    }
}
