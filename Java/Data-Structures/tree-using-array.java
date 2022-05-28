//Following is the implementation of how to create a tree using array
//copy the following code and paste it in your desired browser and run as ususal

public class treeusingarray{
    static Scanner sc=null;
    public static void main(String[] args){
        sc=new Scanner(System.in);
        createTree();
    }
    static Node createTree(){   //It returns root node
         Node root=null;
         System.out.println("Enter data");
         int data=sc.nextInt();
         if(data==-1) return null;    //if you reached end return null
         root=new Node(data);
         System.out.println("Enter left data for"+data);
         root.left=createTree();
         System.out.println("Enter right data for"+data);
         root.right=createTree();
         return root;
    
    }
}
    class Node{
        Node left,right;
        int data;
        public Node(int data){
            this.data=data;
        }
    }

