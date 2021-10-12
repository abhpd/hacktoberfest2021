/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tugas1;

import java.util.Scanner;


/**
 *
 * @author doyatama
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Tiket data = new Tiket();
        //Tiket Deklarasi variabel tim
        String arrKelas[] = {"Bisnis", "Ekonomi", "Eklusif"};
        
        float arrHarga[] = {15000, 12000, 20000};
        int arrKode[] = {1, 2, 3};
        int arrJt[] = {20, 30, 50};
        //Perulangan untuk mengisi masing-masing data yang telah di instansiasi
        for (int i = 0; i < arrKelas.length; i++) {
            String kelas = arrKelas[i];
            float harga = arrHarga[i];
            int kode = arrKode[i];
            int jt = arrJt[i];
            //Instansiasi untuk mengisi data yang ada di dalam class
            Tiket pm  = new Tiket(kelas, harga, kode, jt);
            data.listTk[i] = pm;
        }
        
        
        System.out.println();
        System.out.println("Data Tiket Sebelum Sorting = ");
        data.tampil();
        
        System.out.println("=============================");
        System.out.println("=       Pilih sortir        =");
        System.out.println("=============================");
        System.out.println("1. Harga yang termurah");
        System.out.println("2. Keluar");
        System.out.println("=============================");
        System.out.print("Pilih menu > ");
        int pilih = sc.nextInt();
        if(pilih == 1){
            System.out.println("Data Tiket setelah di urutkan dari murah hingga mahal (bubble sort)");
            data.bubbleSort();
            data.tampil();
            System.out.println();
            System.out.println("Data Tiket setelah di urutkan dari murah hingga mahal (selection sort)");
            data.selectionSort();
            data.tampil();
        }else if(pilih == 2){
            System.exit(0);
        }else{
            System.out.println("Data yang anda inputkan salah");
        }
    }
}
