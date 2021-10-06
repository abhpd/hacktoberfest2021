class Node:
	def __init__(self,data,next=None):
		self.data=data
		self.next=next

class LinkedList:
	def __init__(self):
		self.head = None

	# Utility Function to print List
	def printList(self):
		ptr = self.head
		while(ptr):
			print(ptr.data)
			ptr = ptr.next

	# Utility Function to get length of the List
	def length(self):
		listLength = 0
		ptr = self.head
		while(ptr):
			listLength = listLength + 1
			ptr = ptr.next
		return listLength

	# Append data at the Beginning of the List

	def appendStart(self,data):
		# Creating a new Node 
		newNode = Node(data)

		newNode.next = self.head
		self.head = newNode

	# Append data at the End of the List

	def appendEnd(self,data):
		# Creating a new Node
		newNode = Node(data)

		if(self.head):
		# if linked list has data
			ptr = self.head
			while(ptr.next):
				# Traversing till the end of the List
				ptr = ptr.next
			ptr.next = newNode
		else:
		# If linked List was Empty
			self.head = newNode

	# Insert data at given index

	def insert(self,data,index):
		# Creating a new Node
		newNode = Node(data)
		if(index <= 0):
			newNode.next = self.head
			self.head = newNode
		else:
			ptr = self.head
			index=index-1
			while(index and ptr.next):
				ptr = ptr.next
				index=index-1
			if(index>0):
				print("Index Out of Range")
			else:
				newNode.next = ptr.next
				ptr.next = newNode

	def deletefirst(self):
		if(self.head):
			print(self.head.data)
			self.head = self.head.next
		else:
			print("Empty List")

	def deleteEnd(self):
		if(self.head):
			ptr = self.head
			while(ptr.next.next):
				ptr=ptr.next
			data = ptr.next.data
			ptr.next = None
			return data

	def deleteAtIndex(self,index):
		if(self.head):
			if(index==0):
				print(self.head.data)
				self.head=self.head.next
			else:
				prev = 1
				ptr = self.head
				while(prev<index and ptr):
					prev = prev+1
					ptr = ptr.next
				if(ptr):
					print("Index out of Range")
				else:
					print(ptr.next.data)
					ptr.next = ptr.next.next
		else:
			print("Empty List")
