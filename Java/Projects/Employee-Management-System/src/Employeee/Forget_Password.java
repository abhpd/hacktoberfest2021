/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Employeee;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Forget_Password implements ActionListener
{
JFrame f;
JTextField t,t2,t3;
JLabel l,l1,l2,l3,l4,l5;
JButton b,b1,b2;

Forget_Password()
{
f=new JFrame("Forget");

f.setBackground(Color.green);
f.setLayout(null);

l5=new JLabel();
l5.setBounds(0,0,500,500);
l5.setLayout(null);
ImageIcon img=new ImageIcon("5.jpg");
l5.setIcon(img);


l=new JLabel("Id");
l.setVisible(true);
l.setBounds(50,200,50,30);
l.setForeground(Color.white);
Font F1=new Font("serif",Font.BOLD,20);
l.setFont(F1); 
l5.add(l);
f.add(l5);
l.setVisible(false);

l1=new JLabel(" Nick name");
l1.setBounds(50,50,150,30);
l1.setForeground(Color.white);
Font F2=new Font("serif",Font.BOLD,30); 
l1.setFont(F2);
l5.add(l1);

l2=new JLabel("New Password");
l2.setBounds(50,250,200,30);
l2.setForeground(Color.white);
Font F3=new Font("serif",Font.BOLD,20); 
l2.setFont(F3);
l2.setVisible(false);
l5.add(l2);


l3=new JLabel("Confirm Password");
l3.setBounds(50,300,250,30);
l3.setForeground(Color.white);
Font F4=new Font("serif",Font.BOLD,20); 
l3.setFont(F4);
l3.setVisible(false);
l5.add(l3);

t=new JTextField();
t.setBounds(250,50,150,30);
l5.add(t);

 l4=new JLabel("admin@123");
l4.setBounds(300,200,150,30);
Font F5=new Font("serif",Font.BOLD,20); 
l4.setForeground(Color.white);
l4.setFont(F5);
l4.setVisible(false);
l5.add(l4);


 t2=new JTextField();
t2.setBounds(300,250,150,30);
t2.setVisible(false);
l5.add(t2);

 t3=new JTextField();
t3.setBounds(300,300,150,30);
t3.setVisible(false);
l5.add(t3);

b=new JButton("Search");
b.setBounds(250,100,100,30);
b.addActionListener(this);
l5.add(b);


b1=new JButton("Submit");
b1.setBounds(120,370,100,30);
b1.addActionListener(this);
l5.add(b1);
b1.setVisible(false);

b2=new JButton("Cancel");
b2.setBounds(260,370,100,30);
b2.addActionListener(this);
l5.add(b2);
b2.setVisible(false);

f.setSize(500,500);
f.setLocation(300,50);
f.setVisible(true);

}

public void actionPerformed(ActionEvent ae)
{

if(ae.getSource()==b2)
{
f.setVisible(false);
login l=new login();
}

if(ae.getSource()==b)
{
l.setVisible(true);
l2.setVisible(true);
l3.setVisible(true);
l4.setVisible(true);
b1.setVisible(true);
b2.setVisible(true);
}

}
public static void main(String[]ar)
{
Forget_Password f=new Forget_Password();
}
}