class node {

    int data;
    node next;

    public node(int data) {
        this.data = data;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public node getNext() {
        return next;
    }

    public void setNext(node next) {
        this.next = next;
    }

    public static void detectLoop(node first) {
        node slow = first;
        node fast = first;
        while (slow != null && fast != null && fast.getNext() != null) {
            slow = slow.getNext();
            fast = fast.getNext().getNext();
            if (slow == fast) {
                System.out.println("found loop");
                return;
            }
        }
        System.out.println("loop not found");
    }

    public static void main(String[] args) {
        node l1 = new node(1);
        node l2 = new node(2);
        node l3 = new node(3);
        node l4 = new node(4);
        node l5 = new node(5);

        l1.setNext(l2);
        l2.setNext(l3);
        l3.setNext(l4);
        l4.setNext(l5);
        l5.setNext(l3);

        detectLoop(l1);

    }

}