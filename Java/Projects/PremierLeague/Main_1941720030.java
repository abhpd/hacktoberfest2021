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
public class Main {
    public static void main(String[] args) {
        DaftarPremierLeague data = new DaftarPremierLeague();
        //Deklarasi variabel tim
        String arrTim[] = {"Liverpool",
                        "Manchester City",
                        "Leicester City", 
                        "Chelsea", 
                        "Wolverhampton Wanderers", 
                        "Sheffield United",
                        "Manchester United",
                        "Tottenham Hotspur",
                        "Arsenal",
                        "Burnley",
                        "Crystal Palace",
                        "Everton",
                        "Newcastle United",
                        "Southampton",
                        "Brighton & Hove Albion",
                        "West Ham United",
                        "Watford",
                        "AFC Bournemouth",
                        "Aston Villa",
                        "Norwich City"};
        
        int arrP[] = {29, 27, 28, 29, 29, 28, 28, 29, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 27, 29};
        int arrGd[] = {45, 39, 26, 9, 7, 5, 12, 7, 4, -6, -6, -6, -16, -17, -8, -15, -17, -18, -18, -27};
        int arrPts[] = {82, 57, 50, 48, 43, 43, 42,41, 40, 39, 39, 37, 35, 34, 29, 27, 27, 27, 25, 21};
        //Perulangan untuk mengisi masing-masing data yang telah di instansiasi
        for (int i = 0; i < arrTim.length; i++) {
            String tim = arrTim[i];
            int p = arrP[i];
            int gd = arrGd[i];
            int pts = arrPts[i];
            //Instansiasi untuk mengisi data yang ada di dalam class
            PremierLeague_1941720030 pm  = new PremierLeague(tim, p, gd, pts);
            data.tambah(pm);
        }
        System.out.println();
        System.out.println("Data Premier League Sebelum Sorting = ");
        data.tampil();
    
        System.out.println("Data mahasiswa setelah di Insertion Sort (dari kecil ke besar)= ");
        data.insertionSortKecilBesar();
        data.tampil();
        
        System.out.println("Data mahasiswa setelah di Insertion Sort (dari besar ke kecil)= ");
        data.insertionSortBesarKecil();
        data.tampil();
    }
}