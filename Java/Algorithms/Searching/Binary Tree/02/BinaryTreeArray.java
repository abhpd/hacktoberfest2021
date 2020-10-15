/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jobsheet15.praktikum2;

/**
 *
 * @author Mahatta Maulana
 */
public class BinaryTreeArray {
    int[] data;
    int idxLast;
    int size;
    
    public BinaryTreeArray() {
        this.data = new int[7];
    }
    
    void populateData(int data[], int idxLast) {
        this.data = data;
        this.idxLast = idxLast;
    }
    
    void traverseInOrder(int idxStart) {
        if(idxStart <= idxLast) {
            traverseInOrder(2*idxStart+1);
            System.out.print(data[idxStart] + " ");
            traverseInOrder(2*idxStart+2);
        }
    }
}
