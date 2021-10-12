// Solution for the question https://leetcode.com/problems/copy-list-with-random-pointer/
class Solution {
    public Node copyRandomList(Node head) {
        // create a HashMap with value and key as Node
       HashMap<Node,Node> map = new HashMap<>();
       // store the head into curr
       Node curr = head;
       // traverse through the linked list
       while(curr!=null){
           // store the Node of the linked list as key and make the new node with same value and store it as value
           map.put(curr,new Node(curr.val));
           // move the next pointer
           curr=curr.next;
       }
       // traverse through the map
       for(Map.Entry<Node, Node> entry : map.entrySet()){
           // store the key next node in Node p
           Node p = entry.getKey().next;
           // put the value of Node p next to the curr node
           entry.getValue().next = map.get(p);
           // Same for random pointer
           Node q = entry.getKey().random;
           entry.getValue().random=map.get(q);
       }
       // return value at head 
       return map.get(head);
    }
}
// time complexity -- O(n)
// space complexity -- O(n)