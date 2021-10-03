
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

class BouncingBall extends JPanel {

	int x=0;
	int y=0;
	int angleX=1;
	int angleY=1;
	
	private  void move() {
		if(x+angleX<0)
		{
			angleX=1;
		}
	else if(x+angleX>getWidth() - 50) 
		{
			angleX=-1;
		}
		else if(y+angleY<0)
		{
			angleY=1;
		}
		else if(y+angleY>getHeight() - 50)
		{
			angleY=-1;
		}
		 										//
		x+=angleX;
		y+=angleY;
				
	}
	
	public void paint(Graphics g) {
		
		super.paint(g);
		
		g.fillOval(x, y, 50, 50);
		
	}
	
	public static void main(String args[]) throws InterruptedException
	{
		
		
		JFrame frame= new JFrame("Bouncing Ball Elastic Collision");
		frame.setSize(400,400);
		frame.setVisible(true);
		
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		 
		BouncingBall b= new BouncingBall();
		frame.add(b);
		
		while(true)
		{
			b.move();
			b.repaint();
			Thread.sleep(2);
			
			
		}
	}
}
