class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None

class DequeUsingDLL:
    def __init__(self):
        self.head=None
        self.tail=None
        self.size=0
    def insertRear(self,data):
        self.size+=1
        newNode=Node(data)
        if(self.head is None):
            self.head=newNode
            self.tail=newNode
            return

        self.tail.next=newNode
        newNode.prev=self.tail
        self.tail=newNode

    def insertFront(self,data):
        self.size+=1
        newNode=Node(data)
        if(self.head is None):
            self.head=newNode
            self.tail=newNode
            return

        newNode.next=self.head
        self.head.prev=newNode
        self.head=newNode
        

    def printDeque(self):
        temp=self.head
        while(temp is not None):
            print(temp.data,end=' ')
            temp=temp.next
        print()

        
    def length(self):
        temp=self.head
        count=0
        while(temp is not None):
            count+=1
            temp=temp.next
        return count
    def deletionFront(self):
        if(self.head is None):
            print("deque  is empty")
            return
        self.size-=1
        temp=self.head.next
        if(temp is None):
            self.head=None
            self.tail=None
            return
        
        self.head.next=None
        temp.prev=None
        self.head=temp
        
    def deletionRear(self):
        if(self.head is None):
            print("linked list is empty")
            return
        temp=self.tail.prev
        temp.next=None
        temp.prev=None
        temp=self.tail
        
def main():
    deque=DequeUsingDLL()
    deque.insertFront(10)
    deque.printDeque()
    deque.insertFront(20)
    deque.printDeque()
    deque.insertFront(30)
    deque.printDeque()
    deque.insertFront(40)
    deque.printDeque()
    deque.insertFront(50)
    deque.printDeque()
    deque.insertFront(60)
    deque.printDeque()
    deque.insertFront(70)
    deque.printDeque()
    deque.insertFront(80)
    deque.printDeque()

    deque.deletionRear()
    deque.printDeque()
    deque.deletionFront()
    deque.printDeque()
    s=deque.length()
    print("length:",s)
main()
