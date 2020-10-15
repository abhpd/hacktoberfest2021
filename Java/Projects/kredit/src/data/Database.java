package data;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.swing.JOptionPane;

public class Database {
    public static String reportLocation = System.getProperty("user.dir") + "/src/app/";
    private String driver, database, user, password;
    
    public Database (String driver, String url, String user, String pass) {
    this.driver     = driver;
    this.database   = url;
    this.user       = user;
    this.password   = pass;
  }

  public Connection connect () {
    boolean loop   = false;
    int peringatan = 0;
    do {
        try {
          Class.forName (this.driver);
          return DriverManager.getConnection (this.database, this.user, this.password);
        }
        catch (ClassNotFoundException error) {
          JOptionPane.showMessageDialog(null, "Maaf Anda belum membuka aplikasi XAMPP.");
        }
        catch (SQLException error) {
          JOptionPane.showMessageDialog(null, "Maaf Anda belum membuka aplikasi XAMPP atau Mengaktifkan MySql.");
          JOptionPane.showMessageDialog(null, "Caranya : \n 1. Tekan tombol Windows. \n 2. Ketikkan XAMPP. \n 3. Klik XAMPP Control Panel. \n 4. Klik Start pada MySQL");
          loop = true;
          peringatan++;
          if (peringatan > 1) {
              int exit = JOptionPane.showConfirmDialog(null, "Apakah Anda ingin menghentikan proses aplikasi ini ? ");
              if (exit == 0) {
                  System.exit(0);
              }
          }
        }
    } while (loop);
    return null;
  }

  public void disconnect (Connection connect) {
    if (connect != null) {
      try {
        connect.close ();
      }
      catch (SQLException error) {
      
      }
    }
  }
}
