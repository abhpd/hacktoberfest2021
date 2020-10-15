package view;

// import local library
import controller.UserControl;
import controller.GetData;
import data.Credit;
import data.Database;
import data.Konsumen;

// import java library
import java.awt.Dimension;
import java.awt.Toolkit;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import net.sf.jasperreports.engine.JRException;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;
import net.sf.jasperreports.engine.data.JRBeanCollectionDataSource;
import net.sf.jasperreports.swing.JRViewer;

public class Main extends javax.swing.JFrame {
    
    private static GetData _get_data;
    private DefaultTableModel _table_konsumen;
    private DefaultTableModel _table_credit;
    
    private void clearTableKonsumen () {
        try {
                for (int i = _table_konsumen.getRowCount() - 1 ; i >= 0 ; i-- ) {
                    _table_konsumen.removeRow(i); 
                }
            }   catch (ArrayIndexOutOfBoundsException error) { }
    }
    
    private void clearTableCredit () {
        try {
                for (int i = _table_credit.getRowCount() - 1 ; i >= 0 ; i-- ) {
                    _table_credit.removeRow(i); 
                }
            }   catch (ArrayIndexOutOfBoundsException error) { }
    }
    
    private void showAllKonsumen () {
        
        _table_konsumen = (DefaultTableModel)this.table_konsumen.getModel();
        try {
            String sql = "SELECT * FROM konsumen ORDER BY nama";
            ArrayList<Konsumen> list_select = _get_data.getDataKonsumen (sql);

            clearTableKonsumen();

            Object[] field = new Object[4];
              
            for (int i = 0 ; i < list_select.size() ; i++) {                    
                field[0] = list_select.get(i).getId();
                field[1] = list_select.get(i).getNama();
                field[2] = list_select.get(i).getNoHp();
                field[3] = list_select.get(i).getAlamat();
                  
                _table_konsumen.addRow(field);
            }
        }
        catch (NumberFormatException error) { }
        catch (ArrayIndexOutOfBoundsException error) { }
    }

    public Main() {
        
        // load componen JFrame Main.java
        initComponents();
        _table_credit = (DefaultTableModel)table_angsuran.getModel();
        showAllKonsumen();
        clearTableCredit();
        
        // Set Aplication interface full screen
        Dimension dimensi = Toolkit.getDefaultToolkit().getScreenSize();
        this.setSize(dimensi.width, dimensi.height);
        
        // Hide button tambah and hapus
        this.button_tambahKonsumen.setEnabled(false);
        this.button_hapusKonsumen.setEnabled(false);
        button_getBarang.setEnabled(false);
        jButton2.setEnabled(false);
        
        UserControl.clock(lbl_time);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        combo_neworlateKonsumen = new javax.swing.JComboBox<String>();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        check_nama = new javax.swing.JCheckBox();
        check_noHp = new javax.swing.JCheckBox();
        check_alamat = new javax.swing.JCheckBox();
        txt_idKonsumen = new javax.swing.JTextField();
        txt_namaKonsumen = new javax.swing.JTextField();
        txt_noHpKonsumen = new javax.swing.JTextField();
        txt_alamatKonsumen = new javax.swing.JTextField();
        radio_tambahBarang = new javax.swing.JRadioButton();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        button_tambahKonsumen = new javax.swing.JButton();
        button_hapusKonsumen = new javax.swing.JButton();
        txt_namaBarang = new javax.swing.JTextField();
        combo_tipeAngsuran = new javax.swing.JComboBox<String>();
        txt_uangAngsuran = new javax.swing.JTextField();
        button_getBarang = new javax.swing.JButton();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        table_konsumen = new javax.swing.JTable();
        jScrollPane2 = new javax.swing.JScrollPane();
        table_angsuran = new javax.swing.JTable();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();
        lbl_time = new javax.swing.JLabel();
        button_cariKonsumen = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jLabel14 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        jButton2 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("KREDIT SOFTWARE");

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 36)); // NOI18N
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("KREDIT SOFTWARE");

        combo_neworlateKonsumen.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Konsumen Lama", "Konsumen Baru" }));
        combo_neworlateKonsumen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                combo_neworlateKonsumenActionPerformed(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel2.setText("Id Konsumen");

        jLabel3.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel3.setText("Nama");

        jLabel4.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel4.setText("No Hp");

        jLabel5.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel5.setText("Alamat");

        check_nama.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        check_nama.setText("Nama");

        check_noHp.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        check_noHp.setText("No Hp");

        check_alamat.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        check_alamat.setText("Alamat");

        txt_idKonsumen.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        txt_idKonsumen.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusLost(java.awt.event.FocusEvent evt) {
                txt_idKonsumenFocusLost(evt);
            }
        });
        txt_idKonsumen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txt_idKonsumenActionPerformed(evt);
            }
        });

        txt_alamatKonsumen.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N

        radio_tambahBarang.setText("Tambah Barang");
        radio_tambahBarang.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                radio_tambahBarangActionPerformed(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel6.setText("Nama Barang");

        jLabel7.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel7.setText("Tipe Ansuran");

        jLabel8.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel8.setText("Uang Angsuran");

        button_tambahKonsumen.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        button_tambahKonsumen.setText("Tambah");
        button_tambahKonsumen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                button_tambahKonsumenActionPerformed(evt);
            }
        });

        button_hapusKonsumen.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        button_hapusKonsumen.setText("Hapus");
        button_hapusKonsumen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                button_hapusKonsumenActionPerformed(evt);
            }
        });

        txt_namaBarang.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N

        combo_tipeAngsuran.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "60", "90", "120", "180" }));

        txt_uangAngsuran.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N

        button_getBarang.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        button_getBarang.setText("Simpan data dan Cetak Nota");
        button_getBarang.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                button_getBarangActionPerformed(evt);
            }
        });

        jLabel9.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel9.setText("Konsumen Lama/Baru");

        jLabel10.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jLabel10.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel10.setText("Data Konsumen");

        table_konsumen.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "ID", "Nama", "Alamat", "No Hp"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(table_konsumen);

        table_angsuran.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Barang", "Tipe Angsuran", "Uang Angsuran", "waktu"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane2.setViewportView(table_angsuran);

        jLabel11.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jLabel11.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel11.setText("Riwayat Kredit Barang");

        jLabel12.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel12.setText("Cari Berdasarkan");

        jLabel13.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel13.setText("Waktu");

        lbl_time.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        lbl_time.setText("jLabel14");

        button_cariKonsumen.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        button_cariKonsumen.setText("Cari");
        button_cariKonsumen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                button_cariKonsumenActionPerformed(evt);
            }
        });

        jButton1.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jButton1.setText("Refres");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel14.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jLabel14.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel14.setText("\"There is no one who loves pain itself, who seeks after it and wants to have it, simply because it is pain...\" ");

        jLabel15.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel15.setText("Jl. Hatta Maulana 23 Kediri Hp 081 234 567 910");

        jButton2.setText("Update");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(jLabel15, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel14, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.PREFERRED_SIZE, 611, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(11, 11, 11)
                        .addComponent(radio_tambahBarang))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(11, 11, 11)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel2)
                                    .addComponent(jLabel3)
                                    .addComponent(jLabel4)
                                    .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 63, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel12)
                                    .addComponent(jLabel6)
                                    .addComponent(jLabel7)
                                    .addComponent(jLabel8)
                                    .addComponent(jLabel13)
                                    .addComponent(jButton1))
                                .addGap(51, 51, 51))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(jLabel9)
                                .addGap(32, 32, 32)))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(lbl_time, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(txt_uangAngsuran, javax.swing.GroupLayout.PREFERRED_SIZE, 450, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(txt_namaBarang, javax.swing.GroupLayout.PREFERRED_SIZE, 450, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(combo_tipeAngsuran, javax.swing.GroupLayout.PREFERRED_SIZE, 450, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(combo_neworlateKonsumen, javax.swing.GroupLayout.PREFERRED_SIZE, 450, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addComponent(txt_namaKonsumen, javax.swing.GroupLayout.DEFAULT_SIZE, 450, Short.MAX_VALUE)
                                        .addComponent(txt_noHpKonsumen, javax.swing.GroupLayout.DEFAULT_SIZE, 450, Short.MAX_VALUE)
                                        .addComponent(txt_alamatKonsumen, javax.swing.GroupLayout.DEFAULT_SIZE, 450, Short.MAX_VALUE)
                                        .addComponent(button_getBarang)
                                        .addComponent(txt_idKonsumen, javax.swing.GroupLayout.DEFAULT_SIZE, 450, Short.MAX_VALUE)
                                        .addGroup(layout.createSequentialGroup()
                                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                                .addComponent(button_cariKonsumen)
                                                .addGroup(layout.createSequentialGroup()
                                                    .addComponent(check_nama)
                                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                    .addComponent(check_noHp)
                                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                                    .addComponent(check_alamat)))
                                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(button_tambahKonsumen)
                                            .addGap(14, 14, 14)
                                            .addComponent(jButton2)
                                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                            .addComponent(button_hapusKonsumen))))
                                .addGap(0, 0, Short.MAX_VALUE)))))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(8, 8, 8)
                        .addComponent(jLabel10, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 494, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel11, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 494, Short.MAX_VALUE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel10)
                .addGap(10, 10, 10)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel14)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel15)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(combo_neworlateKonsumen, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel9))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(txt_idKonsumen, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3)
                            .addComponent(txt_namaKonsumen, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel4)
                            .addComponent(txt_noHpKonsumen, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel5)
                            .addComponent(txt_alamatKonsumen, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(check_nama)
                            .addComponent(check_noHp)
                            .addComponent(check_alamat)
                            .addComponent(jLabel12))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(button_hapusKonsumen)
                            .addComponent(button_tambahKonsumen)
                            .addComponent(button_cariKonsumen)
                            .addComponent(jButton1)
                            .addComponent(jButton2))
                        .addGap(5, 5, 5)
                        .addComponent(radio_tambahBarang)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel6)
                            .addComponent(txt_namaBarang, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel7)
                            .addComponent(combo_tipeAngsuran, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel8)
                            .addComponent(txt_uangAngsuran, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel13)
                            .addComponent(lbl_time)))
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(button_getBarang)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel11)
                        .addGap(3, 3, 3)
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 62, Short.MAX_VALUE)
                        .addContainerGap())))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void combo_neworlateKonsumenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_combo_neworlateKonsumenActionPerformed
        // get value item from combo box
        String item = this.combo_neworlateKonsumen.getSelectedItem().toString();
        
        if (item.equals("Konsumen Lama")) {
            // Hide button tambah and hapus
            button_tambahKonsumen.setEnabled(false);
            button_hapusKonsumen.setEnabled(false);
            button_cariKonsumen.setEnabled(true);
            jButton2.setEnabled(false);
            txt_idKonsumen.setEditable(true);
            txt_idKonsumen.setText("");
            txt_namaKonsumen.setText("");
            txt_noHpKonsumen.setText("");
            txt_alamatKonsumen.setText("");
        } else if (item.equals("Konsumen Baru")) {
            // Show button tambah and hapus
            button_tambahKonsumen.setEnabled(true);
            button_hapusKonsumen.setEnabled(false);
            button_cariKonsumen.setEnabled(false);
            jButton2.setEnabled(false);
            txt_idKonsumen.setEditable(false);
            txt_idKonsumen.setText(UserControl.createNumberRandom());
            txt_namaKonsumen.setText("");
            txt_noHpKonsumen.setText("");
            txt_alamatKonsumen.setText("");
        }
    }//GEN-LAST:event_combo_neworlateKonsumenActionPerformed

    private void txt_idKonsumenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txt_idKonsumenActionPerformed

    }//GEN-LAST:event_txt_idKonsumenActionPerformed

    private void txt_idKonsumenFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_txt_idKonsumenFocusLost
        // 
        String input_id = this.txt_idKonsumen.getText();
        
        if (!input_id.equals("")) {
            button_hapusKonsumen.setEnabled(true);
            jButton2.setEnabled(true);
            button_cariKonsumen.setEnabled(false);
        }
        
        try {
            String sql1 = "SELECT * FROM konsumen WHERE id='" + input_id + "'";
            String sql2 = "SELECT * FROM credit WHERE id_konsumen='" + input_id + "'";
            ArrayList<Konsumen> list_konsumen = _get_data.getDataKonsumen (sql1);
            ArrayList<Credit> list_credit    = _get_data.getDataCredit(sql2);
            
            clearTableKonsumen();
            clearTableCredit();

            if (list_konsumen.size() == 0) {
                JOptionPane.showMessageDialog(null, "Maaf, tidak ada konsumen yang mempunyai ID ' " + input_id + " '");
                txt_idKonsumen.setText("");
                button_hapusKonsumen.setEnabled(false);
                button_cariKonsumen.setEnabled(true);
            } else {
                Object[] field_konsumen = new Object[4];
                for (int i = 0 ; i < list_konsumen.size() ; i++) {                    
                    field_konsumen[0] = list_konsumen.get(i).getId();
                    field_konsumen[1] = list_konsumen.get(i).getNama();
                    field_konsumen[2] = list_konsumen.get(i).getNoHp();
                    field_konsumen[3] = list_konsumen.get(i).getAlamat();

                    txt_namaKonsumen.setText(list_konsumen.get(i).getNama());
                    txt_noHpKonsumen.setText(list_konsumen.get(i).getNoHp());
                    txt_alamatKonsumen.setText(list_konsumen.get(i).getAlamat());

                    _table_konsumen.addRow(field_konsumen);
                }
                Object[] field_credit = new Object[4];
                for (int i = 0 ; i < list_credit.size() ; i++) {                    
                    field_credit[0] = list_credit.get(i).getBarang();
                    field_credit[1] = list_credit.get(i).getTipe();
                    field_credit[2] = list_credit.get(i).getUang();
                    field_credit[3] = list_credit.get(i).getTime();

                    _table_credit.addRow(field_credit);
                }
            }
        }
        catch (NumberFormatException error) { }
        catch (ArrayIndexOutOfBoundsException error) { }
        txt_namaBarang.setFocusable(true);
    }//GEN-LAST:event_txt_idKonsumenFocusLost

    private void radio_tambahBarangActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_radio_tambahBarangActionPerformed
        if (radio_tambahBarang.isSelected()) {
            if (txt_idKonsumen.getText().equals("")) {
                button_getBarang.setEnabled(false);
                txt_namaBarang.setEditable(false);
                txt_uangAngsuran.setEditable(false);
                txt_namaBarang.setText("Harap Masukkan Id Konsumen !");
                txt_uangAngsuran.setText("Harap Masukkan Id Konsumen !");
            } else {
                button_getBarang.setEnabled(true);
            }
        } else {
            button_getBarang.setEnabled(false);
            txt_namaBarang.setEditable(true);
            txt_uangAngsuran.setEditable(true);
            txt_namaBarang.setText("");
            txt_uangAngsuran.setText("");
        }
    }//GEN-LAST:event_radio_tambahBarangActionPerformed

    private void button_tambahKonsumenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_button_tambahKonsumenActionPerformed
        String sql = "INSERT INTO konsumen (id, nama, no_hp, alamat) VALUES (" + 
                Integer.valueOf(txt_idKonsumen.getText())  +
                ", '" + txt_namaKonsumen.getText() + "'"     +
                ", '" + txt_noHpKonsumen.getText() + "'"     +
                ", '" + txt_alamatKonsumen.getText() + "'"   +
                ")"; 
        if (_get_data.insert(sql)) {
            JOptionPane.showMessageDialog(null, "Berhasil Menambahkan Data");
            showAllKonsumen();
        } else {
            JOptionPane.showMessageDialog(null, "Maaf Ada yang salah dalam input data");
        }
    }//GEN-LAST:event_button_tambahKonsumenActionPerformed

    private void button_getBarangActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_button_getBarangActionPerformed

        if (txt_idKonsumen.getText().equals("")) {
            JOptionPane.showMessageDialog(null, "Maaf Id Tidak Boleh Kosong");
        } else if (txt_namaBarang.getText().equals("")) {
            JOptionPane.showMessageDialog(null, "Maaf Id Tidak Boleh Kosong");
        } else if (txt_uangAngsuran.getText().equals("")) {
            JOptionPane.showMessageDialog(null, "Maaf Id Tidak Boleh Kosong");
        } else {
            try {
                String sql = "INSERT INTO credit (id_konsumen, barang, tipe_angsuran, uang_angsuran) VALUES (" + 
                    Integer.valueOf(txt_idKonsumen.getText())  +
                    ", '" + txt_namaBarang.getText() + "'"        +
                    ", " + Integer.valueOf(combo_tipeAngsuran.getSelectedItem().toString()) +
                    ", " + Integer.valueOf(txt_uangAngsuran.getText()) +
                    ")"; 
                if (_get_data.insert(sql)) {
                    int confirm = JOptionPane.showConfirmDialog(null, "Cetak Nota Sekarang");
                    if (confirm == 0) {
                        // Script Report
                        try {
                            // Bahan yang akan di print
                            int id          = Integer.valueOf(txt_idKonsumen.getText());
                            String nama     = txt_namaKonsumen.getText();
                            String nohp     = txt_noHpKonsumen.getText();
                            String alamat   = txt_alamatKonsumen.getText();
                            String barang   = txt_namaBarang.getText();
                            int tipe        = Integer.valueOf(combo_tipeAngsuran.getSelectedItem().toString());
                            int uang        = Integer.valueOf(txt_uangAngsuran.getText());

                            String reportLocation = System.getProperty("user.dir") + "/src/view/print.jasper";
                            Map parameter = new HashMap ();
                            
                            JasperPrint JPrint = JasperFillManager.fillReport(reportLocation, parameter, new JRBeanCollectionDataSource (bean.Factory.generateCollections(tipe, id, barang, nama, nohp, alamat, uang)));
                            JRViewer JViewer = new JRViewer(JPrint);
                            java.awt.EventQueue.invokeLater(new Runnable() {
                                public void run() {
                                    ShowPdf previewPdf = new ShowPdf(JViewer);
                                    previewPdf.setVisible(true);
                                }
                            });
                        }
                        catch (JRException error) { error.printStackTrace(); }
                        catch (SQLException error) { error.printStackTrace(); }
                        
                        
                        // End Script Report
                    } else if (confirm == 1) {
                        JOptionPane.showMessageDialog(null, "Data Tersimpan di dalam Penyimpanan Data.");
                    }
                } else {
                    JOptionPane.showMessageDialog(null, "Maaf Ada yang salah dalam input data");
                }
            }
            catch (NumberFormatException error) { }
        }
    }//GEN-LAST:event_button_getBarangActionPerformed

    private void button_hapusKonsumenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_button_hapusKonsumenActionPerformed
        String sql1 = "DELETE FROM konsumen WHERE id=" + Integer.valueOf(txt_idKonsumen.getText());
        String sql2 = "DELETE FROM credit WHERE id_konsumen='"+ txt_idKonsumen.getText() +"'";
        if (_get_data.delete(sql1)) {
            JOptionPane.showMessageDialog(null, "Berhasil, Menghapus Data Konsumen.");
            txt_idKonsumen.setText("");
            txt_namaKonsumen.setText("");
            txt_noHpKonsumen.setText("");
            txt_alamatKonsumen.setText("");
            showAllKonsumen();
            if (_get_data.delete(sql2)) {
                clearTableCredit();
            } else {
                JOptionPane.showMessageDialog(null, "Maaf, Ada Kesalahan dalam Menghapus Riwayat Kredit Barang.");
            }
        } else {
            JOptionPane.showMessageDialog(null, "Maaf, Ada Kesalahan dalam Menghapus Data Konsumen.");
        }
    }//GEN-LAST:event_button_hapusKonsumenActionPerformed

    private void button_cariKonsumenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_button_cariKonsumenActionPerformed
        String nama, no_hp, alamat;
        nama = txt_namaKonsumen.getText();
        no_hp = txt_noHpKonsumen.getText();
        alamat = txt_alamatKonsumen.getText();
        
        boolean f_nama, f_nohp, f_alamat, ifelse = true;
        f_nama = this.check_nama.isSelected();
        f_nohp = this.check_noHp.isSelected();
        f_alamat = this.check_alamat.isSelected();
        // SELECT * FROM konsumen WHERE nama LIKE $nama
        try {
        String sql = "";
                
        if (f_nama && f_nohp && f_alamat) {
            sql = "SELECT * FROM konsumen WHERE nama LIKE '%" + nama + "%' OR no_hp LIKE '%" + no_hp + "%' OR alamat LIKE '%" + alamat + "%'";
        } else if (f_nama && f_nohp) {
            sql = "SELECT * FROM konsumen WHERE nama LIKE '%" + nama + "%' OR no_hp LIKE '%" + no_hp + "%'";
        } else if (f_nama) {
            sql = "SELECT * FROM konsumen WHERE nama LIKE '%" + nama + "%'";
        } else if (f_nohp && f_alamat) {
            sql = "SELECT * FROM konsumen WHERE no_hp LIKE '%" + no_hp + "%' OR alamat LIKE '%" + alamat + "%'";
        } else if (f_nama && f_alamat) {
            sql = "SELECT * FROM konsumen WHERE nama LIKE '%" + nama + "%' OR alamat LIKE '%" + alamat + "%'";
        } else if (f_nohp) {
            sql = "SELECT * FROM konsumen WHERE no_hp LIKE '%" + no_hp + "%'";
        } else if (f_alamat) {
            sql = "SELECT * FROM konsumen WHERE alamat LIKE '%" + alamat + "%'";
        } else {
            JOptionPane.showMessageDialog(null, "Centang Pilihan diatas");
            ifelse = false;
        }
        
         if (ifelse) {
            ArrayList<Konsumen> list_select = _get_data.getDataKonsumen(sql);

            clearTableKonsumen();

            Object[] field = new Object[4];
            for (int i = 0 ; i < list_select.size() ; i++) {                    
                field[0] = list_select.get(i).getId();
                field[1] = list_select.get(i).getNama();
                field[2] = list_select.get(i).getNoHp();
                field[3] = list_select.get(i).getAlamat();
                  
                _table_konsumen.addRow(field);
            }
          }
        }
        catch (NumberFormatException error) { }
        catch (ArrayIndexOutOfBoundsException error) { }
    }//GEN-LAST:event_button_cariKonsumenActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        txt_idKonsumen.setText("");
        txt_namaKonsumen.setText("");
        txt_noHpKonsumen.setText("");
        txt_alamatKonsumen.setText("");
        showAllKonsumen();
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        String sql = "UPDATE konsumen SET nama='"+ txt_namaKonsumen.getText() +"', no_hp='"+ txt_noHpKonsumen.getText() +"', alamat='"+ txt_alamatKonsumen.getText() +"' WHERE id='"+ txt_idKonsumen.getText() +"'";
        if (_get_data.update(sql)) {
            JOptionPane.showMessageDialog(null, "Berhasil, Mengupdate data Konsumen.");
            showAllKonsumen();
        } else {
            JOptionPane.showMessageDialog(null, "Maaf Ada Kesalahan untuk input data.");
        }
    }//GEN-LAST:event_jButton2ActionPerformed

    public static void main(String args[]) {

        // Add Component Style.
        styleJFrame();

        _get_data = new GetData();
        _get_data.tesKoneksi();

            // Load component swing Main.java
            java.awt.EventQueue.invokeLater(new Runnable() {
                public void run() {
                    new Main().setVisible(true);
                }
            });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton button_cariKonsumen;
    private javax.swing.JButton button_getBarang;
    private javax.swing.JButton button_hapusKonsumen;
    private javax.swing.JButton button_tambahKonsumen;
    private javax.swing.JCheckBox check_alamat;
    private javax.swing.JCheckBox check_nama;
    private javax.swing.JCheckBox check_noHp;
    private javax.swing.JComboBox<String> combo_neworlateKonsumen;
    private javax.swing.JComboBox<String> combo_tipeAngsuran;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JLabel lbl_time;
    private javax.swing.JRadioButton radio_tambahBarang;
    private javax.swing.JTable table_angsuran;
    private javax.swing.JTable table_konsumen;
    private javax.swing.JTextField txt_alamatKonsumen;
    private javax.swing.JTextField txt_idKonsumen;
    private javax.swing.JTextField txt_namaBarang;
    private javax.swing.JTextField txt_namaKonsumen;
    private javax.swing.JTextField txt_noHpKonsumen;
    private javax.swing.JTextField txt_uangAngsuran;
    // End of variables declaration//GEN-END:variables
    
    private static void styleJFrame () {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
    }
    
}
