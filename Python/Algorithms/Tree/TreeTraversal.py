# -*- coding: utf-8 -*-
"""
Function for inorder, preorder and postorder traversal of trees
Time complexity: O(n) where n is number of nodes in the tree

@author: lashuk1729
"""

class Node: 
    """
    Data Structure to define a node in tree
    """
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
  
  
def printInorder(root): 
    """
    Prints inorder traversal of the tree
    """
    if root: 
        # Recur on left child 
        printInorder(root.left) 
        print(root.val) 
        # Recur on right child 
        printInorder(root.right) 
  
  
  

def printPostorder(root): 
    """
    Prints postorder traversal of the tree
    """
    if root: 
        # Recur on left child 
        printPostorder(root.left) 
        # Recur on right child 
        printPostorder(root.right) 
        print(root.val) 
  
  

def printPreorder(root): 
    """
    Prints preorder traversal of the tree
    """
    if root: 
        print(root.val), 
  	# Recur on left child 
        printPreorder(root.left) 
        # Recur on right child 
        printPreorder(root.right) 
  
  
"""
Driver code to initialize a tree
"""
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 

print "Preorder traversal of binary tree is"
printPreorder(root) 
  
print "\nInorder traversal of binary tree is"
printInorder(root) 
  
print "\nPostorder traversal of binary tree is"
printPostorder(root) 
