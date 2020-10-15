package data;

public class Parameter {
    private int tipe;
    private int id;
    private String barang;
    private String nama;
    private String no_hp;
    private String alamat;
    private int angsuran;
    private int kwitansi;
    
    public Parameter (int tipe, int id, String Barang, String nama, String no_hp, String alamat, int angsuran, int kwitansi) {
        this.tipe       = tipe;
        this.id         = id;
        this.barang     = Barang;
        this.nama       = nama;
        this.no_hp      = no_hp;
        this.alamat     = alamat;
        this.angsuran   = angsuran;
        this.kwitansi   = kwitansi;
    }
    
    public Integer getId () {
        return id;
    }
    
    public String getBarang () {
        return barang;
    }
    
    public String getNama () {
        return nama;
    }
    
    public String getNoHp () {
        return no_hp;
    }
    
    public String getAlamat () {
        return alamat;
    }
    
    public Integer getAngsuran () {
        return angsuran;
    }
    
    public Integer getKwitansi () {
        return kwitansi;
    }
    
    public Integer getTipe () {
        return tipe;
    }
}
