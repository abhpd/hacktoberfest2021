import java.util.ArrayList;
 
class Main {
//splits arrayList into sub lists.
public static void merge_Sort(ArrayList&lt;Integer&gt; numList){
  int mid;
  ArrayList&lt;Integer&gt; left = new ArrayList&lt;&gt;();
  ArrayList&lt;Integer&gt; right = new ArrayList&lt;&gt;();
   
  if (numList.size() &gt; 1) {
     mid = numList.size() / 2;
        // left sublist
        for (int i = 0; i &lt; mid; i++) 
            left.add(numList.get(i));
  
        //right sublist
        for (int j = mid; j &lt; numList.size(); j++)
            right.add(numList.get(j));
     //recursively call merge_Sort for left and right sublists        
     merge_Sort(left);
     merge_Sort(right);
     //now merge both arrays 
     merge(numList, left, right);
  }
}
private static void merge(ArrayList&lt;Integer&gt; numList, ArrayList&lt;Integer&gt; left, ArrayList&lt;Integer&gt; right){
  //temporary arraylist to build the merged list
  ArrayList&lt;Integer&gt; temp = new ArrayList&lt;&gt;(); 
   
  //initial indices for lists 
  int numbersIndex = 0;    
  int leftIndex = 0;
  int rightIndex = 0;
  //traverse left and righ lists for merging
  while (leftIndex &lt; left.size() &amp;&amp; rightIndex &lt; right.size()) {
    if (left.get(leftIndex) &lt; right.get(rightIndex) ) {
            numList.set(numbersIndex, left.get(leftIndex));
            leftIndex++;
        } else {
            numList.set(numbersIndex, right.get(rightIndex));
            rightIndex++;
        }
        numbersIndex++;
    }
    //copy remaining elements from both lists, if any.
    int tempIndex = 0;
    if (leftIndex &gt;= left.size()) {
        temp = right;
        tempIndex = rightIndex;
    } 
    else {
        temp = left;
        tempIndex = leftIndex;
    }
  
    for (int i = tempIndex; i &lt; temp.size(); i++) {
        numList.set(numbersIndex, temp.get(i));
        numbersIndex++;
    }
 }
public static void main(String[] args) {
    //declare an ArrayList
    ArrayList&lt;Integer&gt; numList = new ArrayList&lt;&gt;();
    int temp;
    //populate the ArrayList with random numbers
    for (int i = 1; i &lt;= 9; i++)
      numList.add( (int)(Math.random() * 50 + 1) );
    //print original ArrayList of random numbers    
    System.out.println("Original ArrayList:");
    for(int val: numList)
      System.out.print(val + " ");
    //call merge_Sort routine 
    merge_Sort(numList);
 
    //print the sorted ArrayList
    System.out.println("\nSorted ArrayList:");
    for(int ele: numList)
      System.out.print(ele + " ");
    System.out.println();
  }
}
