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

public class Score extends JFrame {

	private JPanel contentPane;
	int score;
    String name;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Score frame = new Score();
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
	public Score() 
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 600, 466);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel Score_mssge = new JLabel("New label");
		Score_mssge.setForeground(new Color(255, 0, 0));
		Score_mssge.setFont(new Font("Jokerman", Font.PLAIN, 22));
		Score_mssge.setBounds(46, 36, 528, 48);
		contentPane.add(Score_mssge);
		
		score=question.score;
		name=Login.username;
		Score_mssge.setText("Thank You "+name+" for playing Brainbaazi!!");
		
		JLabel lblNewLabel_1 = new JLabel("New label");
		lblNewLabel_1.setFont(new Font("Jokerman", Font.BOLD, 24));
		lblNewLabel_1.setForeground(new Color(199, 21, 133));
		lblNewLabel_1.setBounds(150, 117, 314, 38);
		lblNewLabel_1.setText("Your Score is "+score);
		contentPane.add(lblNewLabel_1);
		
		JButton btnNewButton = new JButton("Play Again");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) 
			{
				dispose();
				Login l=new Login();
				Login.i=0;
				l.setVisible(true);
			}
		});
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 16));
		btnNewButton.setBounds(323, 370, 202, 38);
		contentPane.add(btnNewButton);
		
		JLabel lblNewLabel = new JLabel("New label");
		lblNewLabel.setIcon(new ImageIcon("C:\\Users\\USER\\eclipse-workspace\\Brainbaazi\\src\\new3.jpg"));
		lblNewLabel.setBounds(0, 0, 584, 428);
		contentPane.add(lblNewLabel);
	}
}
