package entities;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

import game.Game;

public class Ball extends Entity{
	private Game game;
	private int score;
	
	public Ball(Game game) {
		this.game = game;
		width = 30;
		height = 30;
		x = 0;
		y = 30;
		xMove = speed;
		yMove = speed;
		score = 0;
	}

	@Override
	public void tick() {
		getInput();
		move();
	}
	
	private void getInput() {
		if(x + xMove < 0)
			xMove = speed;
		if(x + xMove > game.getWidth() - width)
			xMove = -speed;
		if(y + yMove < 0)
			yMove = speed;
		if(y + yMove > game.getHeight() - game.raquet.getHeight())
			game.gameOver();
		if(game.raquet.getBounds().intersects(getBounds())) {
			yMove = -speed;
			y = game.raquet.getY() - height;
			speed += 0.2;
			score++;
		}
		
	}

	@Override
	public void render(Graphics g) {
		g.drawOval(x, y, width, height);
		g.fillOval(x, y, width, height);
		g.setColor(Color.gray);
		g.setFont(new Font("Verdana", Font.BOLD, 15));
		g.drawString("Score: " + String.valueOf(getScore()), 10, 30);
	}

	public int getScore() {
		return score;
	}
	
	
	
	

}
