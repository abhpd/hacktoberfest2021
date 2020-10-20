package entities;

import java.awt.Color;
import java.awt.Graphics;

import game.Game;

public class Raquet extends Entity{
	
	private Game game;
	
	public Raquet(Game game) {
		this.game = game;
		width = 60;
		height = 10;
		x = 0;
		y = 330;
		xMove = 0;
		yMove = 0;
	}

	@Override
	public void tick() {
		xMove = 0;
		getInput();
		if(x + xMove > 0 && x + xMove < game.getWidth() - 60) {
			move();
		}

	}
	
	private void getInput() {
		if(game.getKeyManager().left) {
			xMove = -speed;
		}
		if(game.getKeyManager().right) {
			xMove = speed;
		}
	}

	@Override
	public void render(Graphics g) {
		g.setColor(Color.black);
		g.drawRect(x, y, width, height);
		g.fillRect(x, y, width, height);
	}
	
	

}
