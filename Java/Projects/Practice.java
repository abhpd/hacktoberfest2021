import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JTextField;

import java.awt.Color;

public class Practice {
	
	static Connection mycon=null;
	static String url="jdbc:mysql://localhost:3306";
	static String dbname="/airline";
	static String driver="com.mysql.jdbc.Driver";
	static String userName="root";
	static String password="manju";
	Connection con=null;

	
	PreparedStatement pst=null;
	private JFrame frame;
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;
	private JTextField textField_4;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Practice window = new Practice();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Practice() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame("CANCELLATION");
		frame.getContentPane().setBackground(new Color(255, 153, 204));
		frame.setBounds(100, 100, 801, 472);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblCancellation = new JLabel("CANCELLATION");
		lblCancellation.setFont(new Font("Tahoma", Font.PLAIN, 31));
		lblCancellation.setBounds(195, 24, 259, 38);
		frame.getContentPane().add(lblCancellation);
		
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setIcon(new ImageIcon("C:\\Users\\Mithun\\Downloads\\images.jpg"));
		lblNewLabel.setBounds(510, 80, 248, 266);
		frame.getContentPane().add(lblNewLabel);
		
		JLabel lblPassengerNo = new JLabel("PASSENGER NO");
		lblPassengerNo.setFont(new Font("Tahoma", Font.PLAIN, 17));
		lblPassengerNo.setBounds(60, 103, 132, 26);
		frame.getContentPane().add(lblPassengerNo);
		
		JLabel lblCancellationNo = new JLabel("CANCELLATION NO");
		lblCancellationNo.setFont(new Font("Tahoma", Font.PLAIN, 17));
		lblCancellationNo.setBounds(51, 151, 152, 31);
		frame.getContentPane().add(lblCancellationNo);
		
		JLabel lblCancellationDate = new JLabel("CANCELLATION DATE");
		lblCancellationDate.setFont(new Font("Tahoma", Font.PLAIN, 17));
		lblCancellationDate.setBounds(51, 206, 166, 26);
		frame.getContentPane().add(lblCancellationDate);
		
		JLabel lblTicketid = new JLabel("TICKET_ID");
		lblTicketid.setFont(new Font("Tahoma", Font.PLAIN, 17));
		lblTicketid.setBounds(79, 256, 126, 26);
		frame.getContentPane().add(lblTicketid);
		
		JLabel lblFlightcode = new JLabel("FLIGHT_CODE");
		lblFlightcode.setFont(new Font("Tahoma", Font.PLAIN, 17));
		lblFlightcode.setBounds(68, 300, 124, 38);
		frame.getContentPane().add(lblFlightcode);
		
		JButton btnCancel = new JButton("CANCEL");
		btnCancel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		btnCancel.setBounds(209, 382, 139, 26);
		frame.getContentPane().add(btnCancel);
		
		textField = new JTextField();
		textField.setBounds(236, 106, 152, 26);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setBounds(236, 159, 152, 23);
		frame.getContentPane().add(textField_1);
		textField_1.setColumns(10);
		
		textField_2 = new JTextField();
		textField_2.setBounds(236, 206, 157, 27);
		frame.getContentPane().add(textField_2);
		textField_2.setColumns(10);
		
		textField_3 = new JTextField();
		textField_3.setBounds(236, 262, 157, 23);
		frame.getContentPane().add(textField_3);
		textField_3.setColumns(10);
		
		textField_4 = new JTextField();
		textField_4.setBounds(236, 312, 157, 26);
		frame.getContentPane().add(textField_4);
		textField_4.setColumns(10);
		try{
		Class.forName(driver);
		 mycon=DriverManager.getConnection(url+dbname,userName,password); 
		 Statement stmt=mycon.createStatement(); 
		}
		catch (ClassNotFoundException | SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		 
		 
			
			btnCancel.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent ae)
				{
					String passenger_no=(String)textField.getText();
					String cancellation_no=(String)textField_1.getText();
					String cancellation_date=(String)textField_2.getText();
					String ticket_id=(String)textField_3.getText();
					String flight_code=(String)textField_4.getText();
					
					try {
						Class.forName(driver);
						
						
						 con=DriverManager.getConnection(url+dbname,userName,password);
					} catch (ClassNotFoundException | SQLException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					
					
					try {						
						pst=con.prepareStatement("INSERT INTO `airline`.`cancellation` (`pnr_no`, `cancellation_no`, `cancellation_date`, `ticket_id`, `fli_code`) VALUES (?, ?, ?, ?, ?);");
						pst.setString(1,passenger_no);
						pst.setString(2, cancellation_no);
						pst.setString(3,cancellation_date);
						pst.setString(4,ticket_id);
						pst.setString(5,flight_code);
						
						
						pst.executeUpdate();
						
						
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					
				
				}
			});
			
			
			frame.setSize(960,586);
			frame.setVisible(true);
			
			
	}
		
		
	}
