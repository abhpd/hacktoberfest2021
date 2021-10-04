//Floyd’s Cycle-Finding Algorithm:- To find a loop in linked list


public class LinkedList {
    Node head;
    class Node {		//creation of a node
        int data;
        Node next;
        Node(int d)
        {
            data = d;
            next = null;
        }
    }
    public void push(int new_data)	//insertion of a new node
    {
        Node new_node = new Node(new_data);
        new_node.next = head;
        head = new_node;
    }
 
    void detectLoop()			//floyd's cycle finding algorithm using two pointers
    {
        Node slow_p = head, fast_p = head;
        int flag = 0;
        while (slow_p != null && fast_p != null
               && fast_p.next != null) {
            slow_p = slow_p.next;
            fast_p = fast_p.next.next;
            if (slow_p == fast_p) {		//if two pointers are same then there is a loop
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            System.out.println("Loop found");
        else
            System.out.println("Loop not found");
    }
    public static void main(String args[])		//main method
    {
        LinkedList llist = new LinkedList();
 
        llist.push(20);
        llist.push(4);
        llist.push(15);
        llist.push(10);
        llist.head.next.next.next.next = llist.head;
 
        llist.detectLoop();
    }
}

//Time Complexity - O(n)
//Space Complexity - O(1)