
/**
 * Author:  ARUN BALAJI R
 * Date:    07 July 2021 (Wednesday)
 */


import java.util.*;
import java.util.LinkedList;
public class InbuiltLinkedList{
	public static void main(String args[]){
		LinkedList ll = new LinkedList();
		LinkedList ll2 = new LinkedList();
		ll.add(3);
		ll.add(5);
		ll.add(1,4);

		//ll2
		ll2.add(9);
		ll2.add(0,23);

		//ll+ll2
		ll.addAll(ll2);

		ll.remove(4);

		ll.removeAll(ll2);

		ll.removeFirst();

		ll.removeLast();

		ll.add(4);
		ll.add(4);

		ll.removeFirstOccurrence(4);
		ll.removeLastOccurrence(4);

		ll.clear();

		ll.add(100);
		ll.add(10);

		




		Iterator<Integer> itr = ll.iterator();

		while(itr.hasNext()){
			System.out.println(itr.next());
		}
	}
}




