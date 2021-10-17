package utilities;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.PasswordAuthentication;
import java.text.SimpleDateFormat;
import java.util.Properties;
import java.util.Scanner;
import java.util.Date;

import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;


import java.sql.*;
import com.mysql.cj.*;

public class SendMail {
	
	String email;
	String name;
	String subject; 
	String messageBody;
	String DisplaydateAndTime;
	String sendState;
	
	public void getData(String email, String subject, String messageBody) {
		this.email = email;
		this.subject = subject;
		this.messageBody = messageBody;
	}
	
	public Connection makeConnection() throws ClassNotFoundException, SQLException {
		Class.forName("com.mysql.jdbc.Driver"); // load the jdbc drivers
		Connection conn = 	DriverManager.getConnection("jdbc:mysql://localhost:3307/test","root","");
		return conn;
	}

	public void Send(){
		// TODO Auto-generated method stub
			
		final String senderEmail = "sac*******@gmail.com";
		final String Password = "**********";
		
		Properties props = new Properties();
		props.put("mail.smtp.auth", "true");
		props.put("mail.smtp.starttls.enable", "true");
		props.put("mail.smtp.host", "smtp.gmail.com");
		props.put("mail.smtp.port", "587");
		
		Session session = Session.getInstance(props,			//login to email
				new javax.mail.Authenticator(){
			protected javax.mail.PasswordAuthentication getPasswordAuthentication() {
				return new javax.mail.PasswordAuthentication(senderEmail, Password);			//authenticate the email and password
			}
		});
		
		try {
			Message message = new MimeMessage(session);
			message.setFrom(new InternetAddress(email));
			message.setRecipients(Message.RecipientType.TO,InternetAddress.parse(email));
			message.setSubject(subject);
			message.setText(messageBody);
			
			Transport.send(message);
			
			System.out.println("Email send");
			
			SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
			Date date = new Date();
			DisplaydateAndTime = sdf.format(date);
			
			sendState = "Send Successfully";
			
			
			
		} catch(MessagingException e){
			sendState = e + "Send Failed";
			throw new RuntimeException(e);
			
		}
	}
	
	public void Store() {
		try {
			//Class.forName("com.mysql.jdbc.Driver"); // load the jdbc drivers
			//Connection conn = 	DriverManager.getConnection("jdbc:mysql://localhost:3307/test","root",""); //make connection with database
			PreparedStatement ps = makeConnection().prepareStatement("insert into maildetails(email,subject,message,send_date_time,send_status) values(?,?,?,?,?);");
			ps.setString(1,email);
			ps.setString(2,subject);
			ps.setString(3,messageBody);
			ps.setString(4,DisplaydateAndTime);
			ps.setString(5,sendState);
			
			int x = ps.executeUpdate();
			if(x>0) {
				System.out.println("Saved");
			}
			else {
				System.out.println("Error");
			}
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
	
	public void DisplayData() {
		try {
			//Class.forName("com.mysql.jdbc.Driver");
			//Connection conn = 	DriverManager.getConnection("jdbc:mysql://localhost:3307/test","root","");
			Statement stmp = makeConnection().createStatement();
			ResultSet rs = stmp.executeQuery("select * from maildetails");
			
			while(rs.next()) {
				String id = rs.getString("id");
				System.out.print(id + " | ");
				
				String email = rs.getString("email");
				System.out.print(email + " | ");
				
				String subject = rs.getString("subject");
				System.out.print(subject + " | ");
				
				String message = rs.getString("message");
				System.out.print(message + " | ");
				
				String send_date_time = rs.getString("send_date_time");
				System.out.print(send_date_time + " | ");
				
				String send_status = rs.getString("send_status");
				System.out.print(send_status + " | ");
				
				System.out.println("");
			}
			
			
					
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}

}
