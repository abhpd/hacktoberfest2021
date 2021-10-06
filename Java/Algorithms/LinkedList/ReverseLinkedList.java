
/**
 * Author:  ARUN BALAJI R
 * Date:    07 July 2021 (Wednesday)
 */


import java.util.*;
public class ReverseLinkedList{
	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		ll.insert(34);
		ll.insert(21);
		ll.insert(2);
		ll.insert(84);
		//[34,21,2,84]
		// ll.show();
		ll.reverse();
		ll.show();
	}
}

class Node{
	int data;
	Node next;
}


class LinkedList{
	Node head;

	public  void insert(int data){
		Node node = new Node();
		node.data = data;
		node.next = null;

		if(head == null){
			head = node;
		}else{
			Node n = head;
			while(n.next!=null){
				n = n.next;
			}
			n.next = node;
		}
	}

	//reverse linkedlist
	public void reverse(){
		Node current = head;
		Node previous = null;
		Node next = null;
		while(current!=null){
			next = current.next;
			current.next = previous;
			previous = current;
			current = next;
		}
		head=previous;
	}

	public void show(){
		Node node = head;
		while(node.next!=null){
			System.out.print(node.data+"  ");
			node=node.next;
		}
		System.out.print(node.data+"  ");
	}


}