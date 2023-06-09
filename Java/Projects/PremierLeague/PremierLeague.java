/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tugas2;

/**
 *
 * @author doyatama
 */
public class PremierLeague {
    public String tim;
    public int p, gd, pts;

    public PremierLeague() {
    }
    
    public PremierLeague(String tim, int p, int gd, int pts) {
        this.tim = tim;
        this.p = p;
        this.gd = gd;
        this.pts = pts;
    }
    public void tampil(){
        System.out.println("Tim = "+tim);
        System.out.println("P = "+p);
        System.out.println("GD = "+gd);
        System.out.println("PTS = "+pts);
    }
}
