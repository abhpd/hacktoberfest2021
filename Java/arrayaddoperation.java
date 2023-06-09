public class arrayaddoperation {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
         
        int l;
        System.out.println("Enter the length =>");
        l=in.nextInt();
        int ar [] = new int [l];
        int temp_ar[]=new int[l+1];

        System.out.println("Enter the values in arrAY =");

        for(int row=0;row <l;row++){
            ar[row]=in.nextInt();          
        }
         
        System.out.println("Array =");
        for(int row=0;row <l;row++){
           System.out.println(ar[row]);          
       }
       

       System.out.println("Enter the index to add the element =");
       int index=in.nextInt();
       System.out.println("Enter the element to add the array=");
       int add_element=in.nextInt();

       for(int row=0;row<l+1;row++){
           if(row<index){
               temp_ar[row]=ar[row];
           }
           else if(row == index){
               temp_ar[row]=add_element;
           }
           else{
               temp_ar[row]=ar[row-1];
           }
           
       }
       System.out.println(" After Array =");
       for(int row=0;row <l+1;row++){
          System.out.println(temp_ar[row]);          
      }
    }
}
