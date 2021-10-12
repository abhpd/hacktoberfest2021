/**
 *
 * @author doyatama
 */
public class DaftarPremierLeague {
    public PremierLeague listPM[] = new PremierLeague[20];
    public int idx;
    
    
    //setelah ini tuliskan method tambah()
    public void tambah(PremierLeague pm){
        if(idx < listPM.length){
            listPM[idx] = pm;
            idx++;
        }else{
            System.out.println("Data sudah penuh!!");
        }
    }
    
    //setelah ini tuliskan method tampil()
    public void tampil(){
        for (PremierLeague_1941720030 pm : listPM) {
            pm.tampil();
            System.out.println("------------------------------");
        }
    }

    //setelah ini tuliskan method insertionSort()
    public void  insertionSortKecilBesar(){
        int i, j;
        for (i = 1; i < listPM.length; i++) {
            PremierLeague_1941720030 temp = new PremierLeague();
            temp = listPM[i];
            j = i;
            while((j > 0) && (listPM[j-1].pts > temp.pts)){
                listPM[j] = listPM[j-1];
                j--;
            }
            listPM[j] = temp;
        }
    }
    public void  insertionSortBesarKecil(){
        int i, j;
        for (i = 1; i < listPM.length; i++) {
            PremierLeague_1941720030 temp = new PremierLeague();
            temp = listPM[i];
            j = i;
            while((j > 0) && (listPM[j-1].pts < temp.pts)){
                listPM[j] = listPM[j-1];
                j--;
            }
            listPM[j] = temp;
        }
    }
}
