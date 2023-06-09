class node:
    def __init__(self,data):
        self.data=data
        self.link=None
        
class Queue:
    def __init__(self):
        self.last=None
        
    def enqueue(self,value):
        temp=node(value)
        if(self.last==None):
            self.last=temp
            temp.link=temp
            
        else:
            
            temp.link=self.last.link
            self.last.link=temp
            self.last=temp
            
    def dequeue(self):
        if(self.last==None):
            print("empty")
        if(self.last.link==None):
            self.last=None
        else:
            self.last.link=self.last.link.link
            
    def display(self):
        
        
        if(self.last==None):
            print("Is empty")
        
        else:
            temp=self.last.link
            while True:
                print(temp.data, end=" ")
                temp=temp.link
                if temp==self.last.link:
                    break
                
q=Queue()
q.display()
print()
q.enqueue(10)
q.enqueue(20)
q.enqueue(30)
q.enqueue(40)
q.display()
print()
print("After dequeue: ", end=" ")
q.dequeue()
q.display()
