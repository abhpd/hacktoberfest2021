import java.io.*;


public class DeleteByPosition {
	
	  Node head;
	
	static class Node{
		int data;
		Node next;
		
		Node(int data){
			this.data = data;
		    this.next = null;
		}
	}
	
	public static  DeleteByPosition deleteAtPosition(DeleteByPosition list , int index) {
		
		Node currNode = list.head;
		Node prev = null;
		
		
		if(index == 0 && currNode != null) {
			list.head = currNode.next;
			return list;
		}
		
		int counter = 0;
		
		while(currNode != null) {
			if(counter == index) {
				prev.next = currNode.next;
				break;
			}else {
			prev = currNode;
			currNode = currNode.next;
			counter++;
		}
	
		
	}
		
		if(currNode == null) {
			return list;
		}
		return list;
		}
	
	 public static void printList(DeleteByPosition list)
	    {
	        Node currNode = list.head;
	 
	        System.out.print("LinkedList: ");
	 
	        // Traverse through the LinkedList
	        while (currNode != null) {
	            // Print the data at current node
	            System.out.print(currNode.data + " ");
	 
	            // Go to next node
	            currNode = currNode.next;
	        }
	 
	        System.out.println();
	    }


	public static void main(String[] args) {
		
         
         DeleteByPosition l = new DeleteByPosition();
         

          l.head = new Node(1);
         Node First = new Node(2);
         Node third = new Node(3);
         Node Fouth = new Node(4);
         
         l.head.next = First; 
         First.next = third;
         third.next = Fouth;
         Fouth.next = null;
         
         
         printList(l);
         
         deleteAtPosition(l,1);
         
         printList(l);
         
         deleteAtPosition(l,2);
         
         printList(l);
         
         deleteAtPosition(l,4);
         
         printList(l);
      /*   SinglyLinkedList s = new SinglyLinkedList();
		 
 		s.head = new ListNode(1);
 		ListNode second = new ListNode(2);
 		
 		s.head.next = second;*/
         
         
	}

}
