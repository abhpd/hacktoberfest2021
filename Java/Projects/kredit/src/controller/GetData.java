package controller;

// import lokal library
import data.Credit;
import data.Database;
import data.Konsumen;
import view.Main;
import view.ShowPdf;

// import java library
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class GetData {
    
    private Database _db;
    private Connection _conn;
    
    private String db_driver = "com.mysql.jdbc.Driver";
    private String db_url    = "jdbc:mysql://localhost:3306/kredit?verifyServerCertificate=false&useSSL=true";
    private String db_user   = "root";
    private String db_pass   = "nganu";
    
    public GetData () {
        _db = new Database (db_driver, db_url, db_user, db_pass);
    }
    
    public void tesKoneksi () {
        _db.connect();
    }
    
    /*
     * Block Select set data
     */
    
    // Fungsi untuk mengeset data  Credit;
    private Credit setDataCredit (ResultSet result) throws SQLException {
        Credit isi_data = new Credit (
                result.getString("barang"),
                result.getInt("tipe_angsuran"),
                result.getInt("uang_angsuran"),
                result.getString("waktu")
        );
        
        return isi_data;
    }
    
    // Fungsi untuk mengeset data  konsumen;
    private Konsumen setDataKonsumen (ResultSet result) throws SQLException {
        Konsumen isi_data = new Konsumen(
                result.getInt("id"), 
                result.getString("nama"), 
                result.getString("no_hp"), 
                result.getString("alamat")
        );
        
        return isi_data;
    }
    
    /*
     * Block Select get data
     */
    
    // Fungsi untuk mengeluarkan data konsumen;
    public ArrayList<Credit> getDataCredit (String sql) {
        ArrayList<Credit> get_data = new ArrayList<> ();
        
        try {
            // Memulai Koneksi dengan database
            _conn = _db.connect();
            PreparedStatement statement = _conn.prepareStatement(sql);
            ResultSet result = statement.executeQuery();
           
            while (result.next()) {
                Credit set_data = setDataCredit(result);
                get_data.add(set_data);
            }
            
            // Menghentikan Koneksi dengan database
            _db.disconnect(_conn);
        }
        catch (SQLException error) { }
        catch (NullPointerException error) { }
        
        // return nilai Array List
        return get_data;
    }
    
    // Fungsi untuk mengeluarkan data konsumen;
    public ArrayList<Konsumen> getDataKonsumen (String sql) {
        ArrayList<Konsumen> get_data = new ArrayList<> ();
        
        try {
            // Memulai Koneksi dengan database
            _conn = _db.connect();
            PreparedStatement statement = _conn.prepareStatement(sql);
            ResultSet result = statement.executeQuery();
           
            while (result.next()) {
                Konsumen set_data = setDataKonsumen(result);
                get_data.add(set_data);
            }
            
            // Menghentikan Koneksi dengan database
            _db.disconnect(_conn);
        }
        catch (SQLException error) { }
        catch (NullPointerException error) { }
        
        // return nilai Array List
        return get_data;
    }
    
    /*
     * Insert Data
     */
    
    // Fungsi untuk menambah data konsumen ke dalam database;
    public boolean insert (String sql) {
        try {
            Connection start_connect = _db.connect();
            
            PreparedStatement statement = start_connect.prepareStatement (sql);
            statement.executeUpdate ();
            
            _db.disconnect (start_connect);
          }
          catch (SQLException error) {
            return false;
          }
        catch (NullPointerException error) { }
        return true;
    }
    
    // Fungsi untuk menambah data konsumen ke dalam database;
    public boolean delete (String sql) {
        try {
            Connection start_connect = _db.connect();
            
            PreparedStatement statement = start_connect.prepareStatement (sql);
            statement.executeUpdate ();
            
            _db.disconnect (start_connect);
          }
          catch (SQLException error) {
            return false;
          }
        catch (NullPointerException error) { }
        return true;
    }
    
    // Fungsi untuk menambah data konsumen ke dalam database;
    public boolean update (String sql) {
        try {
            Connection start_connect = _db.connect();
            
            PreparedStatement statement = start_connect.prepareStatement (sql);
            statement.executeUpdate ();
            
            _db.disconnect (start_connect);
          }
          catch (SQLException error) {
            return false;
          }
        catch (NullPointerException error) { }
        return true;
    }
    
}
