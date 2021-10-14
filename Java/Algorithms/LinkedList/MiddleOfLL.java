/**PROBLEM STATEMENT
* MIDDLE OF LINKED LIST
* we have to find the middle of given linked list. */ */

/* Example :
* I/O - 10->5->20->15->25
* O/P - 20

* I/O - 10->20->30->40->50->60
* O/P - 40

* I/P - 10
* O/P - 10*/

import java.io.*;
import java.util.*;

class Node(){
    int data;
    Node next;
    Node(int data){
        this.data = data;
        next = null;
    }
}
class MiddleOfLL{
    static void printList(Node node){
        while(node != null){
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0){
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            for(int i = 0; i< n-1; i++){
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }
            Solution sol = new Solution();
            int ans = sol.printMiddleNaive(head);
            int ans2 = sol.printMiddleNaive(head);
            System.out.println(ans);
            System.out.println(ans2);
            t--;
        }
        
    }
}

class Solution{

    /*Naive approach
    * This approach require two traversal
    * The idea is first find the length of Linked List
    * and the find the middle node and prints its data */
    void printMiddleNaive(Node head){
        if(head == null) return;
        int count = 0;
        Node curr;
        for(curr = head; curr != null, curr = curr.next){
            count++;
        }
        curr = head;
        for(int i = 0; i< count/2; i++){
            curr = curr.next;
        }
        System.out.println(curr.data);
    }

    /* EFFICIENT approach
    * Require Only 1 traversal
    The idea is to maintain two pointers one is slow and other is fast.
    fast move 2 node at a time and slow move one node at a time.
    * When fast becomes null , slow is the middle one. */

    void printMiddleEff(Node head){
        if(head == null) return;
        Node slow = head, fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        System.out.println(slow.data);
    }
}
