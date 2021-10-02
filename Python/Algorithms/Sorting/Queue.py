class myPythonqueue:
    
    def __init__(self):
        self.data = []
        
    def length(self):
        return len(self.data)
    
    def enque(self, element): 
        if len(self.data) < 5:
            return self.data.append(element)
        else:
            return "overflow"
        
    def deque(self): 
        if len(self.data) == 0:
             return "underflow"
        else:
            self.data.pop(0)
            
b = myPythonqueue()
b.enque(2) 
b.enque(3)
b.enque(4)
b.enque(5)
print(b.data)
b.deque()
print(b.data)