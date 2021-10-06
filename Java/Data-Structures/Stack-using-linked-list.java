//Functionality of this class will be push(),pop(),peek() operation using linked list
//Paste the following code in your editor and write your main function
//Linked list
public class MyLinkedList<E>{    //E represents generic data type
    Node <E> head;      //Initial element
    public void add(E data){
        Node<E> toAdd=new Node<E>(data);   //Node object
        if(isEmpty()){
            head=toAdd;
            return;
        }
        Node<E> temp=head;               
        while(temp.next!=null){          //Last element
            temp=temp.next;
            temp.next=toAdd;            //new element added at the last
        }
    }
        void print(){
            Node<E> temp=head;
            while(temp!=null){
                System.out.print(temp.data+" ");
                temp=temp.next;
            }
        }
        public boolean isEmpty() {
            return head==null;
        }
        public E removeLast() throws Exception{       //It removes last element from our list
            Node<E> temp=head;
            if(temp==null){
                throw new Exception("can't remove last element from empty list");
            }
            if(temp.next==null){   //only one element in the list
                Node<E> toRemove=head;
                head=null;
                return toRemove.data;
            }
            while(temp.next.next!=null){   //Second last element of list
                temp=temp.next;            //continue the iteration
            }
            Node<E> toRemove=temp.next;   
            temp.next=null;
            return toRemove.data;
        }
        //Returns last element
        public E getLast() throws Exception{         
            Node<E> temp=head;
            if(temp==null){
                throw new Exception("can't peek last element");
            }
            while(temp.next!=null){  //last element
                temp=temp.next;
            }
            return toRemove.data;
        }
    
    //Node which contains our linked list element
static class Node<E>{
    E data;
    Node<E> next;  //reference of next node
    public Node(E data){ //constructor
        this.data=data;
        next=null;
    }
}
}

//Stack implementation
public class MyStack<E>{
    private MyLinkedList<E> ll=new MyLinkedList<>();
    void push(E e){
        ll.add(e);
    }
    E pop() throws Exception{
        if(ll.isEmpty()){
            throw new Exception("Popping from empty stack");
        }
        return ll.removeLast();
    }
    E peek() throws Exception{
        if(ll.isEmpty()){
            throw new Exception("Peeking from empty stack");
        }
        return ll.getLast();
    }
}
//Main function 
/*Here you can write your main function. create a object of MyStack class then apply push() pop() and peek()
operation accordingly*/