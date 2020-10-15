package data;

public class Konsumen {
    private int id;
    private String nama;
    private String noHp;
    private String alamat;
    
    public Konsumen (int id, String nama, String nohp, String alamat) {
        this.id = id;
        this.nama = nama;
        this.noHp = nohp;
        this.alamat = alamat;
    }
    
    /*
     * this block get more
     * ===================
     */
    
    public String getNama () {
        return this.nama;
    }

    public String getNoHp () {
        return this.noHp;
    }
    
    public String getAlamat () {
        return this.alamat;
    }
    
    public Integer getId () {
        return this.id;
    }
    
    /*
     * this block set more
     * ===================
     */
        
    public void setNama (String nama) {
        this.nama = nama;
    }
    
    public void setNoHp (String no_hp) {
        this.noHp = no_hp;
    }
    
    public void setAlamat (String alamat) {
        this.alamat = alamat;
    }
    
    public void setId (int id) {
        this.id = id;
    }

// this end the class
}
