import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.ImageIcon;
import java.awt.Color;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class welcome extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					welcome frame = new welcome();
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
	public welcome() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 600, 466);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblWelcomeToBrainbaazi = new JLabel("Welcome to Brainbaazi!!!");
		lblWelcomeToBrainbaazi.setFont(new Font("Jokerman", Font.PLAIN, 18));
		lblWelcomeToBrainbaazi.setBounds(168, 23, 242, 28);
		contentPane.add(lblWelcomeToBrainbaazi);
		
		String mssge="1. This game is very easy to play.You'll be asked some general knowledge questions";
		
		JLabel lblNewLabel_1 = new JLabel("New label");
		lblNewLabel_1.setForeground(new Color(255, 0, 0));
		lblNewLabel_1.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_1.setBounds(10, 93, 476, 14);
		lblNewLabel_1.setText(mssge);
		contentPane.add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("New label");
		lblNewLabel_2.setForeground(new Color(255, 0, 0));
		lblNewLabel_2.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_2.setBounds(10, 118, 414, 14);
		mssge="and the right answer is to be chosen among the four options provided.";
		lblNewLabel_2.setText(mssge);
		contentPane.add(lblNewLabel_2);
		
		JLabel lblNewLabel_3 = new JLabel("New label");
		lblNewLabel_3.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_3.setForeground(new Color(199, 21, 133));
		lblNewLabel_3.setBounds(10, 153, 440, 14);
		mssge="2.  Remember that you will get only 10 seconds to answer the question and if you run out";
		lblNewLabel_3.setText(mssge);
		contentPane.add(lblNewLabel_3);
		
		JLabel lblNewLabel_4 = new JLabel("New label");
		lblNewLabel_4.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_4.setForeground(new Color(199, 21, 133));
		lblNewLabel_4.setBounds(10, 178, 414, 14);
		mssge="of time then you cannot lock your answer.";
		lblNewLabel_4.setText(mssge);
		contentPane.add(lblNewLabel_4);
		
		JLabel lblNewLabel_5 = new JLabel("New label");
		lblNewLabel_5.setForeground(new Color(0, 0, 128));
		lblNewLabel_5.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_5.setBounds(10, 207, 462, 14);
		mssge="3.  Once the answer is chosen,click on next button to submit your answer and move on to";
		lblNewLabel_5.setText(mssge);
		contentPane.add(lblNewLabel_5);
		
		JLabel lblNewLabel_6 = new JLabel("New label");
		lblNewLabel_6.setForeground(new Color(0, 0, 128));
		lblNewLabel_6.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_6.setBounds(10, 232, 414, 14);
		mssge=" the next question";
		lblNewLabel_6.setText(mssge);
		contentPane.add(lblNewLabel_6);
		
		JLabel lblNewLabel_7 = new JLabel("New label");
		lblNewLabel_7.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_7.setForeground(new Color(255, 0, 255));
		lblNewLabel_7.setBounds(10, 267, 414, 14);
		mssge="4.  You can also use the 50-50 lifeline once in the game. ";
		lblNewLabel_7.setText(mssge);
		contentPane.add(lblNewLabel_7);
		
		JLabel lblNewLabel_8 = new JLabel("New label");
		lblNewLabel_8.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_8.setForeground(new Color(139, 0, 0));
		lblNewLabel_8.setBounds(10, 300, 414, 14);
		mssge="5.Once you have reached the end of the quiz,click on the submit button.Your score";
		lblNewLabel_8.setText(mssge);
		contentPane.add(lblNewLabel_8);
		
		JLabel lblNewLabel_9 = new JLabel("New label");
		lblNewLabel_9.setFont(new Font("Tahoma", Font.ITALIC, 11));
		lblNewLabel_9.setForeground(new Color(139, 0, 0));
		lblNewLabel_9.setBounds(10, 325, 414, 14);
		mssge="will be calculated and displayed";
		lblNewLabel_9.setText(mssge);
		contentPane.add(lblNewLabel_9);
		
		JLabel lblNewLabel_10 = new JLabel("New label");
		lblNewLabel_10.setForeground(new Color(255, 0, 0));
		lblNewLabel_10.setFont(new Font("Rockwell Condensed", Font.PLAIN, 18));
		lblNewLabel_10.setBounds(226, 350, 123, 28);
		mssge="\t\tBEST OF LUCK!!!";
		lblNewLabel_10.setText(mssge);
		contentPane.add(lblNewLabel_10);
		
		JButton btnBack = new JButton("Back");
		btnBack.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) 
			{
				dispose();
				Login l=new Login();
				l.setVisible(true);
			}
		});
		btnBack.setBounds(10, 405, 89, 23);
		contentPane.add(btnBack);
		
		JLabel lblNewLabel = new JLabel("New label");
		lblNewLabel.setIcon(new ImageIcon("C:\\Users\\USER\\eclipse-workspace\\Brainbaazi\\src\\new1.jpeg"));
		lblNewLabel.setBounds(0, 0, 584, 428);
		contentPane.add(lblNewLabel);
	}

}
