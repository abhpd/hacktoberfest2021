package game;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyManager implements KeyListener{
	
	public boolean left,right;
	private boolean Kleft,Kright;
	
	public void tick() {
		left = Kleft;
		right = Kright;
	}

	@Override
	public void keyPressed(KeyEvent e) {
	
		if(e.getExtendedKeyCode() == KeyEvent.VK_LEFT) {
			Kleft = true;
		}
		if(e.getExtendedKeyCode() == KeyEvent.VK_RIGHT) {
			Kright = true;
		}
		
	}

	@Override
	public void keyReleased(KeyEvent e) {
		if(e.getExtendedKeyCode() == KeyEvent.VK_LEFT) {
			Kleft = false;
		}
		if(e.getExtendedKeyCode() == KeyEvent.VK_RIGHT) {
			Kright = false;
		}
		
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

}
