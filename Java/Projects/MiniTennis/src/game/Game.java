package game;

import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import javax.swing.JOptionPane;

import entities.Ball;
import entities.Raquet;

public class Game implements Runnable{
	
	private int height, width;
	private String title;
	
	private Display display;
	private Graphics g;
	private BufferStrategy bs;
	
	private KeyManager keyManager;
	
	private Ball ball;
	public Raquet raquet;
	
	public Game(String title,int width,int height) {
		this.title = title;
		this.height = height;
		this.width = width;
		keyManager = new KeyManager();
	}
	
	private void init() {
		display = new Display(this,title,width,height);
		display.getFrame().addKeyListener(keyManager);
		ball = new Ball(this);
		raquet = new Raquet(this);
	}
	
	public int getHeight() {
		return height;
	}

	public int getWidth() {
		return width;
	}

	public KeyManager getKeyManager() {
		return keyManager;
	}

	public void run() {
		init();
		int fps = 60;
		double timePerTick = 1000000000 / fps;
		double delta = 0;
		long now;
		long lastTime = System.nanoTime();
		
		while(true) {
			now = System.nanoTime();
			delta += (now - lastTime) / timePerTick;
			lastTime = now;
			if(delta >= 1) {
				tick();
				render();
				delta--;
			}
		}
		
	}

	private void render() {
		bs = display.getCanvas().getBufferStrategy();
		if(bs == null) {
			display.getCanvas().createBufferStrategy(2);
			return;
		}
		
		g = bs.getDrawGraphics();
		g.clearRect(0, 0, width, height);
		ball.render(g);
		raquet.render(g);
		bs.show();
		g.dispose();
	}

	private void tick() {
		keyManager.tick();
		ball.tick();
		raquet.tick();
	}
	
	public void gameOver() {
		JOptionPane.showMessageDialog(display.getFrame(), "Your Score is: " + ball.getScore(),
				"Game Over", JOptionPane.YES_NO_OPTION);
		System.exit(1);
	}

	
}
