/**
 * @author chirayu-joshi 
 * */


class TreeNode {
	
	int data;
	TreeNode left;
	TreeNode right;
	
	public TreeNode(int data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}
	
}


class BST {
	
	private TreeNode root;
	
	public BST() {
		this.root = null;
	}
	
	public BST(int data) {
		this.root = new TreeNode(data);
	}
	
	public BST(TreeNode root) {
		this.root = root;
	}
	
	public boolean search(int data) {
		return search(root, data);
	}
	
	private boolean search(TreeNode root, int data) {
		while (root != null) {
			if (root.data == data) {
				return true;
			}
			if (root.data < data) {
				root = root.right;
			} else {
				root = root.left;
			}
		}
		return false;
	}
	
	public void insert(int data) {
		TreeNode newNode = new TreeNode(data);
		TreeNode curr = root;
		TreeNode parent = null;
		
		if (root == null) {
			root = newNode;
			return;
		}
		
		while(curr != null) {
			parent = curr;
			if (curr.data > data) {
				curr = curr.left;
			} else if (curr.data < data) {
				curr = curr.right;
			} else {
				return;
			}
		}
		
		if (parent.data > data) {
			parent.left = newNode;
		} else {
			parent.right = newNode;
		}
	}
	
	public boolean delete(int data) {
		if (!search(this.root, data)) {
			return false;
		}
		delete(root, data);
		return true;
	}
	
	private TreeNode delete(TreeNode root, int data) {
		if (root == null) {
			return null;
		}
		if (root.data > data) {
			root.left = delete(root.left, data);
		} else if (root.data < data) {
			root.right = delete(root.right, data);
		} else {
			if (root.left == null) {
				return root.right;
			} else if (root.right == null) {
				return root.left;
			} else {
				TreeNode successor = getSuccessor(root);
				root.data = successor.data;
				root.right = delete(root.right, successor.data);
			}
		}
		return root;
	}
	
	private TreeNode getSuccessor(TreeNode curr) {
		curr = curr.right;
		while (curr != null && curr.left != null) {
			curr = curr.left;
		}
		return curr;
	}
	
	public void inorderTraversal() {
		inorderTraversal(root);
		System.out.println();
	}
	
	private void inorderTraversal(TreeNode root) {
		if (root == null) {
			return;
		}
		inorderTraversal(root.left);
		System.out.print(root.data + " ");
		inorderTraversal(root.right);
	}
	
}


public class BinarySearchTree {
	
	public static void main(String[] args) {
		/* BST:
		
		           50
		          /  \
		         30  60
		        /  \
		       10  40
		         \
		         20
		         
		*/
		
		BST bst = new BST();
		
		bst.insert(50);
		bst.insert(30);
		bst.insert(10);
		bst.insert(40);
		bst.insert(20);
		bst.insert(60);
		
		System.out.println("Before delete(30)");
		bst.inorderTraversal();
		bst.delete(30);
		System.out.println("After delete(30)");
		bst.inorderTraversal();
		
	}
	
}
