package Package;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class New_Window extends JFrame {
    // Constructor de la clase New_Window

    private double value1;
    private double value2;
    private String operador;
    private double resultado;
    public New_Window() {

        // Configuración básica del JFrame
        setTitle("Calculadora");  // Título de la ventana
        setSize(400, 300);               // Dimensiones (ancho x alto)
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  // Acción al cerrar
        setLocationRelativeTo(null);     // Centra la ventana en la pantalla
        setLayout(null);

        JPanel panel = new JPanel();
        panel.setLayout(null);
        panel.setBounds(0, 0, 400, 300);

        JTextField IngresoDeNumeros = new JTextField(20);
        String IngresoDeNumerosText = "";
        IngresoDeNumeros.setText(IngresoDeNumerosText);
        IngresoDeNumeros.setBounds(0, 0, 201, 30);
        panel.add(IngresoDeNumeros);

        JButton Clean = new JButton("C");
        Clean.setBounds(0, 30, 50, 40);
        panel.add(Clean);

        JButton Division = new JButton("/");
        Division.setBounds(50, 30, 50, 40);
        panel.add(Division);

        JButton Multiplicacion = new JButton("*");
        Multiplicacion.setBounds(100, 30, 50, 40);
        panel.add(Multiplicacion);

        JButton Resta = new JButton("-");
        Resta.setBounds(150, 30, 50, 40);
        panel.add(Resta);

        JButton suma = new JButton("+");
        suma.setBounds(150,70,50,80);
        panel.add(suma);

        JButton igual = new JButton("=");
        igual.setBounds(150,150,50,80);
        panel.add(igual);

        JButton uno = new JButton("1");
        uno.setBounds(0,70,50,40);
        panel.add(uno);

        JButton dos = new JButton("2");
        dos.setBounds(50,70,50,40);
        panel.add(dos);

        JButton tres = new JButton("3");
        tres.setBounds(100,70,50,40);
        panel.add(tres);

        JButton cuatro = new JButton("4");
        cuatro.setBounds(0,110,50,40);
        panel.add(cuatro);

        JButton cinco = new JButton("5");
        cinco.setBounds(50,110,50,40);
        panel.add(cinco);

        JButton seis = new JButton("6");
        seis.setBounds(100,110,50,40);
        panel.add(seis);

        JButton siete = new JButton("7");
        siete.setBounds(0,150,50,40);
        panel.add(siete);

        JButton ocho = new JButton("8");
        ocho.setBounds(50,150,50,40);
        panel.add(ocho);

        JButton nueve = new JButton("9");
        nueve.setBounds(100,150,50,40);
        panel.add(nueve);

        JButton cero = new JButton("0");
        cero.setBounds(0,190,100,40);
        panel.add(cero);

        JButton punto = new JButton(".");
        punto.setBounds(100,190,50,40);
        panel.add(punto);

        cero.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        punto.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        Clean.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText("");
            }
        });

        Division.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                operador = "/";
                value1 = Double.parseDouble(IngresoDeNumeros.getText());
                IngresoDeNumeros.setText("");
        }});

        Multiplicacion.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                operador = "*";
                value1 = Double.parseDouble(IngresoDeNumeros.getText());
                IngresoDeNumeros.setText("");
            }});

        suma.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                operador = "+";
                value1 = Double.parseDouble(IngresoDeNumeros.getText());
                IngresoDeNumeros.setText("");
            }});

        Resta.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                operador = "-";
                value1 = Double.parseDouble(IngresoDeNumeros.getText());
                IngresoDeNumeros.setText("");
            }});

        igual.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                value2 = Double.parseDouble(IngresoDeNumeros.getText());
                switch (operador){
                    case "/":
                        resultado = value1 / value2;
                        break;
                    case "*":
                        resultado = value1 * value2;
                        break;
                    case "+":
                        resultado = value1 + value2;
                        break;
                    case "-":
                        resultado = value1 - value2;
                        break;
                }
                IngresoDeNumeros.setText(String.valueOf(resultado));
            }
        });

        uno.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        dos.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        tres.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        cuatro.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        cinco.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        seis.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        siete.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        ocho.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        nueve.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                IngresoDeNumeros.setText(IngresoDeNumeros.getText()+e.getActionCommand());
            }
        });

        //JLabel label = new JLabel();
        //label.setBounds(100, 200, 200, 20);
        //panel.add(label);

        //Calcular.addActionListener (new ActionListener() {
        //    @Override
        //    public void actionPerformed(ActionEvent e) {
        //        String TextoIngesado = IngresoDeNumeros.getText();
        //        label.setText(TextoIngesado);
        //    }
        //});

        add(panel);

        setVisible(true);
    }
}
