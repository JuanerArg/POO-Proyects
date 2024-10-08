package Pruebas_Jframe;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.FlowLayout;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextArea;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Test01 extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField textNameField;
	private JTextField textAgeField;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Test01 frame = new Test01();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Test01() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 654, 471);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);

		JTextArea txtS = new JTextArea();
		txtS.setBounds(10, 72, 618, 349);
		contentPane.add(txtS);
		
		JLabel lblNewLabel = new JLabel("Ingrese Nombre:");
		lblNewLabel.setBounds(10, 11, 134, 23);
		contentPane.add(lblNewLabel);
		
		JLabel lblIngreseEdad = new JLabel("Ingrese Edad:");
		lblIngreseEdad.setBounds(10, 38, 134, 23);
		contentPane.add(lblIngreseEdad);
		
		textNameField = new JTextField();
		textNameField.setBounds(145, 12, 206, 20);
		contentPane.add(textNameField);
		textNameField.setColumns(10);
		
		textAgeField = new JTextField();
		textAgeField.setColumns(10);
		textAgeField.setBounds(145, 39, 206, 20);
		contentPane.add(textAgeField);
		
		JButton btnSendMessage = new JButton("Show Message");
		btnSendMessage.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String Msj = "hola mundo, mi primer Jframe \n"; 
				txtS.append(Msj);
				String Name = textNameField.getText();
				txtS.append(Name + "\n");
				String Age = textAgeField.getText();
				txtS.append(Age + "\n");
			}
		});
		btnSendMessage.setBounds(467, 22, 150, 23);
		contentPane.add(btnSendMessage);
	}
}
