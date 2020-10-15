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
public class BinaryTreeArrayMain {
    public static void main(String[] args) {
        BinaryTreeArray bta = new BinaryTreeArray();
        bta.populateData(new int[]{8, 3, 10, 1, 6, 9, 14}, 6);
        bta.traverseInOrder(0);
    }
}
