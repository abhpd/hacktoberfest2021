package airline.management.system;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class Airline extends JFrame{
    private JFrame frame;
    private JTextField textField;
    private JPasswordField passwordField;

    public static void main(String[] args) {
        new Airline();
    }

    public Airline() {
        initialize();
    }

    public void initialize() {
        frame = new JFrame("MYLOGIN");
		frame.getContentPane().setFont(new Font("Tahoma", Font.PLAIN, 21));
		frame.getContentPane().setBackground(new Color(255, 153, 204));
		frame.getContentPane().setForeground(new Color(100, 149, 237));
		frame.setBounds(100, 100, 866, 452);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblLogin = new JLabel("LOGIN");
		lblLogin.setFont(new Font("Tahoma", Font.PLAIN, 19));
		lblLogin.setBounds(111, 138, 100, 25);
		frame.getContentPane().add(lblLogin);
		
		JLabel lblPassword = new JLabel("PASSWORD");
		lblPassword.setFont(new Font("Tahoma", Font.PLAIN, 19));
		lblPassword.setBounds(81, 217, 100, 25);
		frame.getContentPane().add(lblPassword);
		
		JButton btnOk = new JButton("OK");
		btnOk.setFont(new Font("Tahoma", Font.PLAIN, 19));
		btnOk.setBounds(236, 296, 80, 25);
		frame.getContentPane().add(btnOk);
		
		frame.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
		frame.getContentPane().add(btnOk);
		
		textField = new JTextField();
		textField.setBounds(206, 138, 189, 25);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		
		passwordField = new JPasswordField();
		passwordField.setBounds(206, 217, 189, 25);
		frame.getContentPane().add(passwordField);
		
		Label label = new Label("LOGIN FORM");
		label.setFont(new Font("Dialog", Font.PLAIN, 44));
		label.setBounds(236, 10, 413, 44);
		frame.getContentPane().add(label);
		
		JLabel label_1 = new JLabel("");
		label_1.setIcon(new ImageIcon("C:\\Users\\Mithun\\Downloads\\20171109195143.jpg"));
		label_1.setBounds(435, 115, 382, 258);
		frame.getContentPane().add(label_1);

	
		btnOk.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent ae)
			{
				frame.dispose();
				new Mainframe();
			}
		});
		
		
		
		frame.setSize(960,586);
		frame.setVisible(true);
	}
}