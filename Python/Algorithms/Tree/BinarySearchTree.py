# -*- coding: utf-8 -*-
"""
@author: lashuk1729
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        
class BST:
    def __init__(self):
        self.root = None
        
    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(self.root, data)
    
    def _insert(self, curr, data):
        if curr.val>data:
            if curr.left:
                self._insert(curr.left, data)
            else:
                curr.left = Node(data)
                
        elif curr.val<data:
            if curr.right:
                self._insert(curr.right, data)
            else:
                curr.right = Node(data)
                
        else:
            print("The value already exists")
            
    def search(self, get_val):
        self._search(self.root, get_val)
    
    def _search(self, cur, get_val):
        if cur:
            if cur.val==get_val:
                print()
                print(True)
            elif cur.val<get_val:
                self._search(cur.right, get_val)
            else:
                self._search(cur.left, get_val)
                
                
    def inorder(self):
        if self.root:
            self._inorder(self.root)
            
    def _inorder(self, cur):
        if cur:
            self._inorder(cur.left)
            print(cur.val, end=" ")
            self._inorder(cur.right)     
            
    def postorder(self):
        if self.root:
            self._postorder(self.root)
            
    def _postorder(self, cur):
        if cur:
            self._postorder(cur.left)
            self._postorder(cur.right)   
            print(cur.val, end=" ")
                
    def preorder(self):
        if self.root:
            self._preorder(self.root)
            
    def _preorder(self, cur):
        if cur:
            print(cur.val, end=" ")
            self._preorder(cur.left)
            self._preorder(cur.right)   
            
             
bst = BST()

A = 0

while A!=8:
    print()
    print("Choose,your option: ")
    print("1. Insert a node")
    print("2. Print inorder")
    print("3. Print preorder")
    print("4. Print postorder")
    print("5. Search")
    print("8. You are done!")
    A = int(input())
    
    if A==1:
        print("Input value of node to be added")
        val = int(input())
        bst.insert(val)
        
    elif A==2:
        bst.inorder()
        
    elif A==3:
        bst.preorder()
        
    elif A==4:
        bst.postorder()
        
    elif A==5:
        print("Input value of node to be searched")
        val = int(input())
        bst.search(val)
        
    elif A==8:
        pass
    
    else:
        print("Choose one of the given options which are 1-5 and 8")
