package DataStructure;


class Node {
	int data;
	Node next;
	Node (int x){
		data = x;
		next = null;
	}
}
public class InsertBegin {
	static Node head;
	
	public static void insertBegin( int x) {
		Node temp = new Node(x);
		temp.next = head;
		head = temp;
	}
	public static void insertEnd( int x) {
		Node temp = new Node(x);
		if(head == null) {
			return temp;
		}
		Node pos = head;
		while(pos.next!= null) {
			pos = pos.next;
			
		}
		pos.next = temp;
		System.out.print(head);
	}
	public static void display() {
		Node pos = head;
		while(pos!= null) {
			System.out.print(pos.data + "->");
			pos = pos.next;
		}
	}
	public static void main(String[] args) {
		 InsertBegin l = new  InsertBegin();
		l.insertBegin(20);
		l.insertBegin(19);
		l.insertEnd(40);
		l.display();
		
	}

}
