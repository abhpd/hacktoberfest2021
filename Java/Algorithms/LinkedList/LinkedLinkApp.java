public class LinkedListApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
//-------------------------------------
//Node class
class Node {
	 int data;
	 Node next;
	 
//constructor of node class
	 Node(int item) {
		 this.data=item;
		 this.next=null;
	 }
	 
//Display the node data
	 void displayNode() {
	  System.out.print(this.data + " ");
	 } 
	}
//------------------------------------------

// LinkedList Class
	class LinkList {
		
	 private Node head;

//constructor
	 public void LinkList() {
	 head = null;
	 }
	 
	 
	 public boolean isEmpty() {
		 return (this.head==null); 
	 }

	 public void insertFirst(int i) {
		
		 Node newNode = new Node(i);
		 newNode.next =head;
		 head = newNode;
	 
	 }
	 

	 public Node deleteFirst() {
		 if(isEmpty()) {
			 System.out.println("List is Empty , Nothing to delete");
		 }
		 Node temp = head;
		 head = head.next;
		 temp.next = null;
		 return temp;
	 
	 }
	 
	 public void displayList() {
		 if(isEmpty()) {
			 System.out.println("List is empty, Nothing to diplay");
		 }
		 Node current = head;
		 while(current != null) {
			 current.displayNode();
			 current = current.next;
		 }
		 System.out.println();
	 }
	 
	 
	 public Node find(int key) {
		 Node current =head;
		 int count =1;
		 while(current!=null) {
			 if(count==key) {
				 return current;
				 
			 }
			 current =current.next;
			 count++;
		 }
		 System.out.println("Item not Found");
		 return null;
	 }
	 
	 public void delete(int key) {
	        
	        Node curr = this.head;
	        Node prev = this.head;
	        int count = 1;
	        
	        while(curr!=null){
	            
	            if(count == key){
	                if(count == 1){
	                    this.deleteFirst();
	                }else{
	                    prev.next = curr.next;
	                    curr.next = null;
	                }
	            }
	            
	            prev = curr;
	            curr = curr.next;
	            count++;
	        }
	 
	 }
	 
} 
	 
	 
	 
