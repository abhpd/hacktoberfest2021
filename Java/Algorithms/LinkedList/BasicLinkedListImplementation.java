
/**
 * Author:  ARUN BALAJI R
 * Date:    06 July 2021 (Tuesday)
 */


import java.util.*;
public class BasicLinkedListImplementation{
	public static void main(String args[]){
		LinkedList list = new LinkedList();
		list.insert(5);
		list.insert(6);
		list.insert(12);
		list.insertAtStart(25);
		list.insertAt(11,2);  //inserting 11
		list.deleteAt(2);		//deleting 11
		list.show();
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

	//insertatstart
	public void insertAtStart(int data){
		Node node = new Node();
		node.data = data;
		node.next = head;
		head = node;
	}
	
	//insert at pos
	public void insertAt(int data,int pos){
		Node node = new Node();
		node.data=data;
		node.next = null;
		
		if(pos == 0){
			insertAtStart(data);
		}else{
			Node n = head;
			for(int i=0;i<pos-1;i++){
				n = n.next;
			}
			node.next = n.next;
			n.next = node;	
		}

		
	}

	//deleteAt
	public void deleteAt(int pos){
		if(pos==0){
			head = head.next;
		}else{
			Node n = head;
			Node n1 = null;
			for(int i=0;i<pos-1;i++){

				n = n.next;

			}
			n1 = n.next;
			n.next = n1.next;
			n1 = null;	
		}
			
	}

	public void show(){
		Node node = head;
		while(node.next!=null){
			System.out.println(node.data);
			node=node.next;
		}
		System.out.println(node.data);
	}
}