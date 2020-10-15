// int id, String barang, String nama, String noHp, String alamat, int angsuran, int tipe
package bean;

import data.Parameter;
import data.Konsumen;
import data.Credit;
import data.Database;
import controller.GetData;
import view.Main;
import view.ShowPdf;

// import java library
import java.util.ArrayList;
import java.util.Vector;
import java.sql.Connection;
import java.util.Collection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Factory {

    public static Vector generateCollections (int tipe, int id, String barang, String nama, String noHp, String alamat, int angsuran) throws SQLException {
        // initial collection for save data
        java.util.Vector collections = new java.util.Vector();
        
        int     x     = 90;
        int     exe   = 0;
        int[]   array = new int [tipe/3];

        for (int i = 0 ; i <= tipe ; i++) {
            if (i % 3 == 1) {
                array[exe] = i;
                exe++;
            }
        }
        
        // Add data values to collections
        for (int i = 0 ; i < array.length ; i++) {
            collections.add(new Parameter(
                    tipe,
                    id,
                    barang,
                    nama,
                    noHp,
                    alamat,
                    angsuran,
                    array[i]
            ));
        }
        
        // return collections to beans
        return collections;
    }
}