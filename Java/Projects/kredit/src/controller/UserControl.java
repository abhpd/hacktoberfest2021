package controller;

import static java.lang.Thread.sleep;
import java.util.Calendar;
import java.util.GregorianCalendar;
import javax.swing.JOptionPane;

public class UserControl {
    
    public static String createNumberRandom () {
        Calendar time = new GregorianCalendar();
            
        int detik = time.get(Calendar.SECOND);
        int menit = time.get(Calendar.MINUTE);
        int jam   = time.get(Calendar.HOUR);
        int day   = time.get(Calendar.DATE);
        
        String view_detik, view_menit, view_jam;
        
        if (detik < 10) view_detik = "0" + Integer.toString(time.get(Calendar.SECOND));
        else view_detik = Integer.toString(time.get(Calendar.SECOND));
        if (menit < 10) view_menit = "0" + Integer.toString(time.get(Calendar.MINUTE));
        else view_menit = Integer.toString(time.get(Calendar.MINUTE));
        if (jam < 10) view_jam = "0" + Integer.toString(time.get(Calendar.HOUR));
        else view_jam = Integer.toString(time.get(Calendar.HOUR));
        
        return ""+ view_detik + view_jam + day + view_menit;
    }
    
    public static void clock(javax.swing.JLabel lbl_time) {
        Thread now;
        now = new Thread () {
            @Override
            public void run () {
                while(true) {                  
                    Calendar time = new GregorianCalendar();
                    int detik = time.get(Calendar.SECOND);
                    int menit = time.get(Calendar.MINUTE);
                    int jam   = time.get(Calendar.HOUR);

                    String view_detik;
                    String view_menit;
                    String view_jam;
                    
                    if(time.get(Calendar.AM_PM) == 1)
                        jam += 12;

                    if (detik < 10) view_detik = "0" + Integer.toString(time.get(Calendar.SECOND));
                    else view_detik = Integer.toString(time.get(Calendar.SECOND));
                    if (menit < 10) view_menit = "0" + Integer.toString(time.get(Calendar.MINUTE));
                    else view_menit = Integer.toString(time.get(Calendar.MINUTE));
                    if (jam < 10) view_jam = "0" + Integer.toString(time.get(Calendar.HOUR));
                    else view_jam = Integer.toString(jam);
                    
                    lbl_time.setText(view_jam + ":" + view_menit + ":" + view_detik);
                    
                    try {
                        sleep(1);
                    }
                    catch (Exception error) {
                        JOptionPane.showMessageDialog(null, error);
                    }
                }
            }
        };
        now.start();
    }
}
