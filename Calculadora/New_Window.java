package Package;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class New_Window extends JFrame {
    // Constructor de la clase New_Window
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
        IngresoDeNumeros.setBounds(0, 0, 200, 30);
        panel.add(IngresoDeNumeros);

        JButton Calcular = new JButton("Calcular");
        Calcular.setBounds(200,0,200,30);
        panel.add(Calcular);

        JButton uno = new JButton("1");
        uno.setBounds(0,30,50,30);
        panel.add(uno);

        JButton dos = new JButton("2");
        dos.setBounds(50,30,50,30);
        panel.add(dos);

        JButton tres = new JButton("3");
        tres.setBounds(100,30,50,30);
        panel.add(tres);

        JButton cuatro = new JButton("4");
        cuatro.setBounds(0,60,50,30);
        panel.add(cuatro);

        JButton cinco = new JButton("5");
        cinco.setBounds(50,60,50,30);
        panel.add(cinco);

        JButton seis = new JButton("6");
        seis.setBounds(100,60,50,30);
        panel.add(seis);

        JButton siete = new JButton("7");
        siete.setBounds(0,90,50,30);
        panel.add(siete);

        JButton ocho = new JButton("8");
        ocho.setBounds(50,90,50,30);
        panel.add(ocho);

        JButton nueve = new JButton("9");
        nueve.setBounds(100,90,50,30);
        panel.add(nueve);

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
