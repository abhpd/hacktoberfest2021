package entities;

import java.awt.Graphics;
import java.awt.Rectangle;

public abstract class Entity {
	protected int width;
	protected int height;
	protected int x,y;
	protected float xMove,yMove;
	protected static float speed = 1f;
	
	public abstract void tick();
	public abstract void render(Graphics g);
	
	public void move() {
		x += xMove;
		y += yMove;
	}
	
	public Rectangle getBounds() {
		return new Rectangle(x,y,width,height);
	}
	
	public int getWidth() {
		return width;
	}
	public int getHeight() {
		return height;
	}
	public int getX() {
		return x;
	}
	public int getY() {
		return y;
	}
	
}
