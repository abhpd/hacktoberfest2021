
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class LruCacheAdvanceProblem {
public static class LRU {

    public static class ListNode{
        int key;
        int value;
        ListNode prev;
        ListNode next;
        
        ListNode(){
            
        }
        ListNode(int key,int value,ListNode prev,ListNode next){
            this.key=key;
            this.value=value;
            this.prev=prev;
            this.next=next;
        }
        
    }
    
    HashMap<Integer,ListNode> map;
    ListNode head;
    ListNode tail;
    int size=0;
    
    int limit=0;
    
    public LRU(int capacity) {
        
        limit=capacity;
        map=new HashMap<>();
        
    }
    
    public int get(int key) {
       
        if(map.containsKey(key)==false){
            return -1;
        }else{
            ListNode node=map.get(key);
            
            remove(node);
            addLast(node);
            
            return node.value;
        }
        
    }
    
    public void put(int key, int value) {
        
        if(map.containsKey(key)==false){
            ListNode node=new ListNode(key,value,null,null);
            map.put(key,node);
            addLast(node);
            
            if(size>limit){
                int hd=removeFirst();
                map.remove(hd);
            }
            
            
        }else{
            ListNode node=map.get(key);
            
            remove(node);
            addLast(node);
            
            node.value=value;
        }
    }
    
        
     private void addLast(ListNode node){
        
        if(size==0){
            head=tail=node;
        }else{
            tail.next=node;
            node.prev=tail;
            tail=node;
        }
        size++;
        
    }
        private int removeFirst(){
        
        if(size==0){
            return -1;
        }
        int data=head.key;
            if(size==1){
            head=tail=null;
                
        }else{
                
                ListNode hn=head.next;
                head.next=null;
                hn.prev=null;
                
                head=hn;
                
            }
            size--;    
            return data;
        
        
    }
     private void remove(ListNode node){
         
         if(size==0){
             return;
         }
         
         
         if(node==head){
             removeFirst();
         }else if(node==tail){
            removeLast();
         }else{
             
             ListNode pr=node.prev;
             ListNode nxt=node.next;
             
             pr.next=nxt;
             nxt.prev=pr;
             
             node.next=null;
             node.prev=null;
             
             size--;
                 
         }
         
         
         
         
         
         
     }
    private int removeLast(){
        
        if(size==0){
            return -1;
        }
     int data=tail.key;
            if(size==1){
            head=tail=null;
                
        }else{
                
                ListNode tp=tail.prev;
                tail.prev = null;
                tp.next = null;
                
                tail=tp;
                
            }
            size--;    
            return data;
        
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();
    LRU obj = new LRU(Integer.parseInt(str.split(" ")[1]));

    while (true) {
      str = br.readLine();
      String inp[] = str.split(" ");
      if (inp.length == 1) {
        break;
      } else if (inp.length == 2) {
        System.out.println(obj.get(Integer.parseInt(inp[1])));
      } else if (inp.length == 3) {
        obj.put(Integer.parseInt(inp[1]), Integer.parseInt(inp[2]));
      }
    }
  }
}