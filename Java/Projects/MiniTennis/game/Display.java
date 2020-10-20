package game;

import java.awt.Canvas;
import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class Display {
	
	private JFrame frame;
	private Canvas canvas;

	private String title;
	private int width,height;
	Game game;
	
	public Display(Game game,String title,int width,int height) {
		this.game = game;
		this.title = title;
		this.width = width;
		this.height = height;
		createDisplay();
		
	}
	
	private void createDisplay() {
		frame = new JFrame(title);
		frame.setSize(width+4, height);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setLocationRelativeTo(null);
		
		canvas = new Canvas();
		canvas.setPreferredSize(new Dimension(width,height));
		canvas.setMaximumSize(new Dimension(width,height));
		canvas.setMinimumSize(new Dimension(width,height));
		canvas.setFocusable(false);
		frame.add(canvas);
	}
	
	public Canvas getCanvas() {
		return canvas;
	}

	public JFrame getFrame() {
		return frame;
	}

}
