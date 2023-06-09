/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tugas1;

/**
 *
 * @author doyatama
 */
public class Tiket {
    public Tiket listTk[] = new Tiket[3];
    public String kelas;
    public float harga;
    public int kode, jumlahTiket;

    public Tiket() {
    }
    
    public Tiket(String kls, float hrg, int kd, int jml) {
        this.kelas = kls;
        this.harga = hrg;
        this.kode = kd;
        this.jumlahTiket = jml;
    }
    
    public void tampil(){
        for (int i = 0; i < listTk.length; i++) {
            System.out.println("Jenis Tiket = "+listTk[i].kelas);
            System.out.println("Harga Tiket = "+listTk[i].harga);
        }
    }
    
    //setelah ini tuliskan method bubbleSort()
    public void bubbleSort(){
        for (int i = 0; i < listTk.length-1; i++) {
            for (int j = 1; j < listTk.length-i; j++) {
                if(listTk[j].harga < listTk[j-1].harga){
                    Tiket tmp = listTk[j];
                    listTk[j] = listTk[j-1];
                    listTk[j-1] = tmp;
                }   
            }
        }
    }
    
    //setelah ini tuliskan method selectionSort()
    public void selectionSort(){
        for (int i = 0; i < listTk.length-1; i++) {
            int idxMin = i;
            for (int j = i+1; j < listTk.length; j++) {
                if(listTk[j].harga < listTk[idxMin].harga){
                    idxMin = j;
                }
            }
            //swap
            Tiket tmp = listTk[idxMin];
            listTk[idxMin] = listTk[i];
            listTk[i] = tmp;
        }
    }
 
}
