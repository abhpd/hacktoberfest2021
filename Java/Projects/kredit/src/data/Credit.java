package data;

public class Credit {
    private String barang;
    private int tipe;
    private int uang;
    private String waktu;
    
    public Credit (String barang, int tipe, int uang, String waktu) {
        this.barang = barang;
        this.tipe = tipe;
        this.uang = uang;
        this.waktu = waktu;
    }
    
    /*
     * this block get more
     * ===================
     */
    
    public String getBarang () {
        return this.barang;
    }

    public Integer getTipe () {
        return this.tipe;
    }
    
    public Integer getUang () {
        return this.uang;
    }
    
    public String getTime () {
        return this.waktu;
    }
    
    /*
     * this block set more
     * ===================
     */
        
    public void setBarang (String nama) {
        this.barang = nama;
    }
    
    public void setTipe (int no_hp) {
        this.tipe = no_hp;
    }
    
    public void setUang (int alamat) {
        this.uang = alamat;
    }
    
    public void setTime (String waktu) {
        this.waktu = waktu;
    }
}
