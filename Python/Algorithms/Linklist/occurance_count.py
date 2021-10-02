
# Node class
class Node:

	# Constructor to initialize the node object
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:

	# Function to initialize head
	def __init__(self):
		self.head = None

	# Counts the no . of occurrences of a node
	# (search_for) in a linked list (head)
	def count(self, search_for):
		current = self.head
		count = 0
		while(current is not None):
			if current.data == search_for:
				count += 1
			current = current.next
		return count

	# Function to insert a new node at the beginning
	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	# Utility function to print the linked LinkedList
	def printList(self):
		temp = self.head
		while(temp):
			print (temp.data),
			temp = temp.next


# Driver program
llist = LinkedList()
llist.push(1)
llist.push(3)
llist.push(1)
llist.push(2)
llist.push(1)

# Check for the count function
print( "count of 1 is % d" %(llist.count(5)))

