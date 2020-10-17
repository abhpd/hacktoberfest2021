import java.io.*;
import java.util.*;

public class Main{
  

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = Integer.parseInt(br.readLine());
    }

    // code
    
    int[] rightBoundary = new int[a.length];    // next smaller index on right
    Stack<Integer>st = new Stack<>();
    /* in this we will travel from right to left */
    
    st.push(a.length-1);
    rightBoundary[a.length-1] = a.length;
    
    for(int i= a.length-2;i>=0;i--){
        while(st.size() > 0 && a[i] <= a[st.peek()]){
            st.pop();
        }
        if(st.size()==0){
            rightBoundary[i] = a.length;
        }else{
            rightBoundary[i] = st.peek();
        }
        st.push(i);
    }
    
    int[]leftBoundary = new int[a.length];  // next smaller index on the left
    st = new Stack<>();
    
    /* in this we will travel from left to right */
    st.push(0);
    leftBoundary[0]= -1;
    
    for(int i= 1;i<a.length;i++){
        while(st.size() > 0 && a[i] <= a[st.peek()]){
            st.pop();
        }
        if(st.size()==0){
            leftBoundary[i] = -1;
        }else{
            leftBoundary[i] = st.peek();
        }
        st.push(i);
    }
    
    
    int maxArea=0;
    for(int i=0;i<a.length;i++){
        int width = rightBoundary[i] - leftBoundary[i] -1;
        int area = a[i] * width;
        if(area > maxArea){
            maxArea = area;
        }
    }
    System.out.println(maxArea);
    
    
    
    
    
    
 }
}
