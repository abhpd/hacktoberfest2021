import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;

import javax.swing.JTextField;
import javax.swing.Timer;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Login extends JFrame
{

	private JPanel contentPane;
	private JTextField textField;
	protected Component frame;
    public static String username;
    ImageIcon ii; 
    public static int i=0;
    Image bg;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) 
	{
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Login frame = new Login();
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
	public Login() 
	{
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 600, 466);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblEnterUsername = new JLabel("Enter Username");
		lblEnterUsername.setBackground(new Color(211, 211, 211));
		lblEnterUsername.setForeground(new Color(139, 0, 0));
		lblEnterUsername.setFont(new Font("Mongolian Baiti", Font.BOLD | Font.ITALIC, 18));
		lblEnterUsername.setBounds(213, 155, 145, 41);
		contentPane.add(lblEnterUsername);
		
		textField = new JTextField();
		textField.setBounds(169, 207, 230, 27);
		contentPane.add(textField);
		textField.setColumns(10);
		
		JButton btnRules = new JButton("Rules");
		btnRules.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnRules.setForeground(new Color(139, 0, 0));
		btnRules.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) 
			{
				dispose();
				welcome w=new welcome();             //welcome page ie. Rules page
				w.setVisible(true);
				
			}
		});
		btnRules.setBounds(158, 277, 89, 23);
		contentPane.add(btnRules);
		
		JButton btnPlay = new JButton("Play");
		btnPlay.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnPlay.setForeground(new Color(139, 0, 0));
		btnPlay.addActionListener(new ActionListener() 
		{
			

			public void actionPerformed(ActionEvent e) 
			{
				if(textField.getText()!=null && !textField.getText().trim().isEmpty())         //Checks if username is not blank
				{
					username=textField.getText();
					dispose();
					question q=new question();                  
					question.count=0;
					question.i=10;
					question.ans_given=0;
					question.score=0;
					question.lifeline_count=1;
					q.setVisible(true);
					
				}
				else
				{
					JOptionPane.showMessageDialog(frame,"Username cannot b blank");
				}
			}
		});
		btnPlay.setBounds(310, 277, 89, 23);
		contentPane.add(btnPlay);
		
		JButton btnExit = new JButton("Exit");
		btnExit.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnExit.setForeground(new Color(139, 0, 0));
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) 
			{
			      System.exit(0);                           //Closes Brainbaazi
			}
		});
		btnExit.setBounds(231, 326, 89, 23);
		contentPane.add(btnExit);
		
		JLabel lblBrainbaazi = new JLabel("BRAINBAAZI");
		lblBrainbaazi.setForeground(new Color(139, 0, 0));
		lblBrainbaazi.setFont(new Font("Viner Hand ITC", Font.BOLD, 28));
		lblBrainbaazi.setBounds(182, 70, 244, 41);
		contentPane.add(lblBrainbaazi);
		
		JLabel lblNewLabel = new JLabel("New label");
		lblNewLabel.setIcon(new ImageIcon("C:\\Users\\USER\\eclipse-workspace\\Brainbaazi\\src\\new2.jpg"));       //sets the background image for the Login page
		lblNewLabel.setBounds(0, 0, 584, 428);
		contentPane.add(lblNewLabel);
	}
			
}
