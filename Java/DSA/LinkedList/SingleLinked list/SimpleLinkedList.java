package DataStructure;

class Node {
	int data;
	Node next;
	Node (int x){
		data = x;
		next = null;
	}
}
public class SimpleLinkedList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Node head = new Node(10);
		Node temp1 = new Node(20);
		Node temp2 = new Node(30);
		
		head.next = temp1;
		temp1.next = temp2;
		display(head);

	}
	public static void display(Node head) {
		Node pos = head;
		while(pos!= null) {
			System.out.print(pos.data + "->");
			pos = pos.next;
		}
	}

}
