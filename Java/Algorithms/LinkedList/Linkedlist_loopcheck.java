// Java program to detect loop in a linked list
import java.util.*;
public class LinkedList 
{
	static Node head; // head of list
	/* Linked list Node*/
	static class Node {
		int data;
		Node next;
		Node(int d)
		{
			data = d;
			next = null;
		}
	}
	static public void add(int newData)
	{
		Node newNode = new Node(newData);
		newNode.next = head;
		head = newNode;
	}
	static boolean checkLoop(Node n)
	{
		HashSet<Node> hset = new HashSet<Node>();
		while (n != null) {
			if (hset.contains(n))
				return true;
			hset.add(n);
			n = n.next;
		}
		return false;
	}
	//Driver program
	public static void main(String[] args)
	{
		LinkedList ll = new LinkedList();
		ll.add(8);
		ll.add(12);
		ll.add(15);
		ll.add(21);
		ll.head.next.next.next.next = ll.head;
		if (checkLoop(head))
			System.out.println("Loop found");
		else
			System.out.println("No Loop found");
	}
}
