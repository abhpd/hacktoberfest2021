// Java program to check if a given tree is BST.
class Sol
{

// A binary tree node has data, pointer to
//left child && a pointer to right child /
static class Node
{
	int data;
	Node left, right;
};

// Returns true if given tree is BST.
static boolean isBST(Node root, Node l, Node r)
{
	// Base condition
	if (root == null)
		return true;

	// if left node exist then check it has
	// correct data or not i.e. left node's data
	// should be less than root's data
	if (l != null && root.data <= l.data)
		return false;

	// if right node exist then check it has
	// correct data or not i.e. right node's data
	// should be greater than root's data
	if (r != null && root.data >= r.data)
		return false;

	// check recursively for every node.
	return isBST(root.left, l, root) &&
		isBST(root.right, root, r);
}

// Helper function that allocates a new node with the
//given data && null left && right pointers. /
static Node newNode(int data)
{
	Node node = new Node();
	node.data = data;
	node.left = node.right = null;
	return (node);
}

// Driver code
public static void main(String args[])
{
	Node root = newNode(3);
	root.left = newNode(2);
	root.right = newNode(5);
	root.left.left = newNode(1);
	root.left.right = newNode(4);

	if (isBST(root,null,null))
		System.out.print("Is BST");
	else
		System.out.print("Not a BST");
}
}

// This code is contributed by Arnab Kundu
