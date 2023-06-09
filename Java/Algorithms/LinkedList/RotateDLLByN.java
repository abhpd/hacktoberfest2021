package linkedList;

public class RotateDLLByN {

	static Node head;
	static class Node {
	    int data;
	    Node next, prev;
	    Node(int data)
	    {
	        this.data = data;
	        this.next = null;
	        this.prev = null;
	    }
	}
	
	static void printList(Node node) {
		while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        } 
        System.out.println();
    }
	
	// 24 : Rotate DoublyLinked list by N nodes.
	static Node rotate(Node head, int N) {
		if (N == 0) return head;
		
		Node cutNode = head, tail=null;
		int i=1;
		
		while (cutNode != null) {
			tail = cutNode;
			cutNode = cutNode.next;
		}
		
		cutNode = head;
		while (cutNode.next != null) {
			if (i == N) {
				tail.next = head;
				head.prev = tail;
				head = cutNode.next;
				cutNode.next.prev = null;
				cutNode.next = null;
				return head;
			}
			cutNode = cutNode.next;
			i++;
		}
		
		return head;
	}
	
	public static void main(String[] args) {
		head = new Node(1);
		
		head.next = new Node(2);
		head.next.prev = head;
		
		head.next.next = new Node(3);
		head.next.next.prev = head.next;
		
		head.next.next.next = new Node(4);
		head.next.next.next.prev = head.next.next;
		
		head.next.next.next.next = new Node(5);
		head.next.next.next.next.prev = head.next.next.next;
		
		head.next.next.next.next.next = new Node(6);
		head.next.next.next.next.next.prev = head.next.next.next.next;
		
		head.next.next.next.next.next.next = new Node(7);
		head.next.next.next.next.next.next.prev = head.next.next.next.next.next;
		
		printList(head);
		head = rotate(head, 3);
		printList(head);
	}

}
