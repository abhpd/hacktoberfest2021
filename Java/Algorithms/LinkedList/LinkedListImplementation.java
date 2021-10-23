
/**
 * Author:  ARUN BALAJI R
 * Date:    07 July 2021 (Wednesday)
 */


import java.util.*;
public class LinkedListImplementation{
	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		ll.insertAtEnd(4);
		ll.insertAtEnd(5);
		ll.insertAtStart(3);
		ll.insertAtPos(4,2);
		ll.deleteAt(2);

		ll.show();
	}
}


class Node{
	int data;
	Node next;
}

class LinkedList{
	Node head;

	//insertAtEnd
	public void insertAtEnd(int data){
		Node node = new Node();
		node.data = data;
		node.next = null;

		Node n = head;
		if(head==null){
			head = node;
		}else{
			while(n.next!=null){
				n=n.next;
			}
			n.next=node;
		}
	}

	public void insertAtStart(int data){
		Node node = new Node();
		node.data = data;
		node.next = head;
		head = node;	
	}

	public void insertAtPos(int data,int pos){
		if(pos==0){
			insertAtStart(data);
		}else{
			Node node = new Node();
			node.data=data;
			node.next = null;

			Node n= head;
			for(int i=0;i<pos-1;i++){
				n=n.next;
			}
			node.next = n.next;
			n.next = node;

		}
	}

	public void deleteAt(int pos){
		Node n=head;
		Node temp = null;
		if(pos==0){
			head=head.next;
		}else{

			for(int i=0;i<pos-1;i++){
				n=n.next;
			}
			temp = n.next;
			n.next=temp.next;
			temp=null;

		}
	}

	public void show(){
		Node n = head;
		while(n.next!=null){
			System.out.println(n.data);
			n=n.next;
		}
		System.out.println(n.data);


	}
}