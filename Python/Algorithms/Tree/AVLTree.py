"""
Before going through the code, have a look at the following blog about AVL Tree:
https://en.wikipedia.org/wiki/AVL_tree

@author: lashuk1729

"""
class Node():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.height = 1

class AVL_Tree():
    def get_height(self, root):
        if root is None:
            return 0
        return root.height
    
    def get_balance(self, root):
        """
        Checks whether the given tree is balanced or not, i.e., 
        difference between height of left_subtree and right_subtree should lie between -1 & 1
        """
        if root is None:
            return 0
        return self.get_height(root.left) - self.get_height(root.right)
    
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.val, end = " -> ")
            self.inorder(root.right)
    
    def preorder(self, root):
        if root:
            print(root.val, end = " -> ")
            self.preorder(root.left)
            self.preorder(root.right)
    
    def right_rotate(self, z):
        y = z.left
        T3 = y.right
        y.right = z
        z.left = T3
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y
    
    def left_rotate(self, z):
        y = z.right
        T3 = y.left
        y.left = z
        z.right = T3
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y
    
    def get_min(self, root):
        while root.left is not None:
            root = root.left
        return root
    
    def insert(self, root, key):
        if root is None:
            return Node(key)
        elif root.val > key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
        
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))
        balance = self.get_balance(root)
        # Left-left case
        if balance > 1 and key < root.left.val:
            return self.right_rotate(root)
        # Right-right case
        if balance < -1 and key > root.right.val:
            return self.left_rotate(root)
        # Left-right case
        if balance > 1 and key > root.left.val:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)
        # Right-left case
        if balance < -1 and key < root.right.val:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)
        return root
    
    def delete(self, root, key):
        if root is None:
            return root
        elif root.val > key:
            root.left = self.delete(root.left, key)
        elif root.val < key:
            root.right = self.delete(root.right, key)
        else:
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp
            temp = self.get_min(root.right)
            root.key = temp.key
            root.right = self.delete(root.right, temp.key)
            
        if root is None:
            return root
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))
        balance = self.get_balance(root)
        # Left-left case
        if balance > 1 and self.get_balance(root.left) >= 0:
            return self.right_rotate(root)
        # Right-right case
        if balance < -1 and self.get_balance(root.right) <= 0:
            return self.left_rotate
        # Left-right case
        if balance > 1 and self.get_balance(root.left) < 0:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)
        # Right-left case
        if balance < -1 and self.get_balance(root.right) > 0:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)
        return root
    
if __name__=='__main__':
    myTree = AVL_Tree() 
    root = None

    nums = [9, 5, 10, 0, 6, 11, -1, 1, 2]

    for num in nums:
        root = myTree.insert(root, num)

    # Preorder Traversal
    print("AVL tree after insertion is: ", end = "") 
    myTree.preorder(root) 
    print('X')
    
    key = 10
    root = myTree.delete(root, key)
    
    # Preorder Traversal
    print("AVL tree after deletion is: ", end = "")
    myTree.preorder(root)
    print('X')
