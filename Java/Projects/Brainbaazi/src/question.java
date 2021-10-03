import java.awt.BorderLayout;
import java.awt.Checkbox;
import java.awt.CheckboxGroup;
import java.awt.Color;
import java.awt.Component;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JProgressBar;
import javax.swing.Timer;

public class question extends JFrame 
{

	private JPanel contentPane;
	JButton btnSubmit,btnNext;
	public static int count=0;                    //counter for the question no.
	public static int i=10;                      //counter for time left in seconds
	public static int ans_given=0;              //to check if the player has given the answer or not 
	JLabel qno,question;
	CheckboxGroup cbg;
	public static int score=0;                //calculates the score
	public static int lifeline_count=1;      //counter for the no. of lifelines remaining
	Checkbox opt1,opt2,opt3,opt4;
    String q[][]=new String[10][5];           //holds the question along with 4 options
    String qa[][]=new String[10][2];          //holds the question & its respective correct answer
    String pa[][]=new String[10][1];          //holds the answer given by the player
	protected Component frame;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) 
	{
		EventQueue.invokeLater(new Runnable() 
		{
			public void run() {
				try 
				{
					question frame = new question();
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
	public question() 
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 600, 466);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		
	    qno = new JLabel("New label");
	    qno.setFont(new Font("Tahoma", Font.PLAIN, 18));
		qno.setBounds(10, 110, 41, 33);
		contentPane.add(qno);
		
	    question = new JLabel("New label");
	    question.setFont(new Font("Tahoma", Font.PLAIN, 18));
		question.setBounds(40, 110, 534, 33);
		contentPane.add(question);
		
		cbg=new CheckboxGroup(); 
		opt1 = new Checkbox("New radio button",cbg,false);
		opt1.setFont(new Font("Dialog", Font.PLAIN, 16));
		
		opt1.setBounds(59, 190, 172, 23);
		contentPane.add(opt1);
		
		opt2 = new Checkbox("New radio button",cbg,false);
		opt2.setFont(new Font("Dialog", Font.PLAIN, 16));
		opt2.setBounds(319, 190, 172, 23);
		contentPane.add(opt2);
		
		opt3 = new Checkbox("New radio button",cbg,false);
		opt3.setFont(new Font("Dialog", Font.PLAIN, 16));
		opt3.setBounds(59, 264, 172, 23);
		contentPane.add(opt3);
		
		opt4 = new Checkbox("New radio button",cbg,false);
		opt4.setFont(new Font("Dialog", Font.PLAIN, 16));
		opt4.setBounds(319, 264, 172, 23);
		contentPane.add(opt4);
		
		q[0][0]="What is the capital of India?";
		q[0][1]="Mumbai";
		q[0][2]="Delhi";
		q[0][3]="Kolkata";
		q[0][4]="Gujurat";
		
		q[1][0]="Where is Tajmahal located?";
		q[1][1]="Delhi";
		q[1][2]="Bilaspur";
		q[1][3]="Agra";
		q[1][4]="Jaipur";
		
		q[2][0]="Who is the first President of India?";
		q[2][1]="Dr.Rajendra Prasad";
		q[2][2]="Jawaharlal Nehru";
		q[2][3]="Dr.S.Radhakrishnan";
		q[2][4]="Zakir Hussain";
		
		q[3][0]="Which cricketer has scored the highest individual score in ODIs?";
		q[3][1]="Sachin Tendulkar";
		q[3][2]="Virender Sehwag";
		q[3][3]="Rohit Sharma";
		q[3][4]="Virat Kohli";
		
		q[4][0]="When did India achieve its Independence?";
		q[4][1]="August 15,1950";
		q[4][2]="January 26,1947";
		q[4][3]="January 26,1950";
		q[4][4]="August 15,1947";
		
		q[5][0]="Hitler party which came into power in 1933 is known as";
		q[5][1]="Labour Party";
		q[5][2]="Nazi Party";
		q[5][3]="Ku-Klux-Klan";
		q[5][4]="Democratic Party";
		
		q[6][0]="Epsom (England) is the place associated with";
		q[6][1]="Horse racing";
		q[6][2]="Polo";
		q[6][3]="Shooting";
		q[6][4]="Snooker";
		
		q[7][0]="Golf player Vijay Singh belongs to which country?";
		q[7][1]="USA";
		q[7][2]="Fiji";
		q[7][3]="India";
		q[7][4]="UK";
		
		q[8][0]="First Afghan War took place in";
		q[8][1]="1839";
		q[8][2]="1843";
		q[8][3]="1833";
		q[8][4]="1848";
		
		q[9][0]="Each year World Red Cross and Red Crescent Day is celebrated on";
		q[9][1]="May 8";
		q[9][2]="May 18";
		q[9][3]="June 8";
		q[9][4]="June 18";
		
			
		//String qa[][]=new String[10][2];
		//qa[0][0]="What is the capital of India?";
		qa[0][1]="Delhi";
		
		//qa[0][0]="Where is Tajmahal located?";
		qa[1][1]="Agra";
				
		//qa[0][0]="Who is the first President of India?";
		qa[2][1]="Dr.Rajendra Prasad";
		
		//qa[0][0]="Which cricketer has scored the highest individual score in ODIs?";
		qa[3][1]="Rohit Sharma";
				
		//qa[0][0]="When did India achieve its Independence?";
		qa[4][1]="August 15,1947";
		
		//qa[0][0]="Hitler party which came into power in 1933 is known as";
		qa[5][1]="Nazi Party";
		
		//qa[0][0]="Epsom (England) is the place associated with";
		qa[6][1]="Horse racing";
		
		//qa[0][0]="Golf player Vijay Singh belongs to which country?";
		qa[7][1]="Fiji";
		
		//qa[0][0]="First Afghan War took place in";
		qa[8][1]="1839";
		
		//qa[0][0]="Each year World Red Cross and Red Crescent Day is celebrated on";
		qa[9][1]="May 8";
		
		
		btnSubmit = new JButton("Submit");
		btnSubmit.setFont(new Font("Tahoma", Font.PLAIN, 16));
		btnSubmit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) 
			{
				    ans_given=1;                             //player has submitted the answer for the previous question
				    if(cbg.getSelectedCheckbox()==null)      //player has left the question unattempted    
				    {
				    	player_ans_not_given(count);
				    }
				    else                                       //player has attempted the question
				    {
				    	player_ans(count);        //last answer submitted
				    }
	
					for(int i=0;i<pa.length;i++)        
					{
						if(pa[i][0].equals(qa[i][1]))           //player answers compared with the actual answers
						{
							score+=10;              //if correct
						    
						}
						else
						{
							if(pa[i][0].equals(""))              //if unattempted
							{
								score+=0;
							}
							else                                //attempted but wrong
							{
								score-=5;
								
							}
						}
					}
					dispose();
					Score s=new Score();                     //Dispaly the score
					s.setVisible(true);
				
			}
		});
		
		btnSubmit.setBounds(213, 346, 89, 23);
		btnSubmit.setVisible(true);
		btnSubmit.setEnabled(false);
		contentPane.add(btnSubmit);
		
		btnNext = new JButton("Next");
		btnNext.setFont(new Font("Tahoma", Font.PLAIN, 16));
		btnNext.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0) 
			{
				repaint();                                 //reset the timer
				ans_given=1;                              //player has submitted the answer for the previous question
				opt1.setEnabled(true);
				opt2.setEnabled(true);                    //all options visible
				opt3.setEnabled(true);
				opt4.setEnabled(true);
				
				if(count==8)
				{
					btnNext.setEnabled(false);           //next button is not visible for the last question
					btnSubmit.setEnabled(true);          //submit button is visible for the last question
					
				}
				
				if(cbg.getSelectedCheckbox()==null)            //player has left the previous question unattempted   
				{
					player_ans_not_given(count);
					++count;
					start(count);
				}
				else                                          //player has attempted the previous question
				{
					player_ans(count);
					++count;                                 //question number updated
					start(count);                           //moves on to the next question
				}
			}
		});
		btnNext.setBounds(445, 11, 89, 23);
		contentPane.add(btnNext);
		
		JButton btnLifeline = new JButton("50-50 Lifeline");
		btnLifeline.setFont(new Font("Tahoma", Font.PLAIN, 16));
		btnLifeline.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) 
			{
				
				    if(lifeline_count==1)                        //if the player has lifelines left
				    {
				    	if(count==2||count==4||count==6||count==8||count==9)     //if the question no. is 3,5,7,9,10 then options 2 & 3 are removed
						{
				    		opt2.setEnabled(false);
				    		opt3.setEnabled(false);
						}
				    	else                                                    //options 1 & 4 are removed for the remaining questions
				    	{
				    		opt1.setEnabled(false);
				    		opt4.setEnabled(false);
				    	}
				    	--lifeline_count;                                      //lifeline count decreases since lifeline has been used
				    }
				
				    else                                                  //if the player has no lifelines left
				    {
				    	JOptionPane.showMessageDialog(frame,"You dont have any lifelines left");
				    }
			}
		});
		btnLifeline.setBounds(196, 11, 137, 23);
		contentPane.add(btnLifeline);
		
		start(0);              //to start with question 1 when play button is clicked
			
		
	}
		
		public void start(int c)
		{
			
			qno.setText(Integer.toString(c+1)+".");
			question.setText(q[c][0]);
			opt1.setLabel(q[c][1]);
			opt2.setLabel(q[c][2]);
			opt3.setLabel(q[c][3]);
			opt4.setLabel(q[c][4]);
			cbg.setSelectedCheckbox(null);           //all checkboxes are set to blank
		   
	   }
		
	    @Override
		public void paint(Graphics g)
		{
			
	    	super.paint(g);
			g.setColor(Color.red);
			String mssge="Time left-";
			mssge+=Integer.toString(i);
			g.setFont(new Font("Verdana",Font.BOLD,15));
			if(i!=0)                             //if timer count is not equal to 0
			    g.drawString(mssge,30, 60);
			else                                 //if timer count is equal to 0
				g.drawString("Time up!!", 30, 60);
			
			i--;

				try
				{
					Thread.sleep(1000);            //wait for 1 second
					repaint();                     
				}
				catch(Exception ee)
				{
					ee.printStackTrace();
				}
				if(ans_given==1)             //if answer is given by the player then timer resets
				{
					ans_given=0;            
					i=10;
				}
				else if(i==-1)              //if times up
				{
					//System.out.println("Time up");
					i=10;           
					opt1.setEnabled(true);
					opt2.setEnabled(true);
					opt3.setEnabled(true);
					opt4.setEnabled(true);
					if(count==8)
					{
						btnNext.setEnabled(false);             //next button is not visible for the last question
						btnSubmit.setEnabled(true);            //submit button is visible for the last question
					}
					if(count==9)                            //if the last question is reached but player has not clicked on the submit button
					{                                         //does the work which is done when submit button is clicked
						if(cbg.getSelectedCheckbox()==null)                    
					    {
					    	player_ans_not_given(count);
					    }
					    else
					    {
					    	player_ans(count);        //last answer submitted
					    }
						
						for(int i=0;i<pa.length;i++)       
						{
							if(pa[i][0].equals(qa[i][1]))
							{
								score+=10;
							
							}
							else
							{
								if(pa[i][0].equals(""))
								{
									score+=0;
								}
								else
								{
									score-=5;
								}
							}
						}
						dispose();
						Score s=new Score();
						s.setVisible(true);
						
					}
			
					else                                            //if time runs out and the player has not clicked on the next button
					{					                            //does the work which is done when next button is clicked
						if(cbg.getSelectedCheckbox()==null)
						{
							player_ans_not_given(count);
							++count;
							start(count);
						}
						else
						{
							player_ans(count);
							++count;
							start(count);
						}
					}
			    
				}
		
		}

		public void player_ans(int c)
		{
			pa[c][0]=cbg.getSelectedCheckbox().getLabel();
			
		}
		public void player_ans_not_given(int c)
		{
			pa[c][0]="";
		}
		
}

				
	
		

