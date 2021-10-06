
/**
 * Author:  ARUN BALAJI R
 * Date:    05 July 2021 (Monday)
 */


import java.util.*;
public class SnakePattern{
	    public static void main(String[] args) {
	    int size = 4,p = 23;
	    //3,11
	    

	    int count = 1;
	    int rows = (p%2==0) ? p/size : (p+1)/size;
		int[][] arr = new int[rows][size];
	    for(int i=0;i<rows;i++){
	    	if(i%2==0){
	    		for(int j=0;j<size;j++){
	    			arr[i][j] = count<=p ? count++ : 0;
				}
			}else{
	    		for(int j=size-1;j>=0;j--){
					arr[i][j] = count<=p ? count++: 0;
				}
			}

		}

	    for(int i=0;i<rows;i++){
	    	for(int j=0;j<size;j++){
	    		System.out.print(arr[i][j]+"\t");
			}
	    	System.out.println();
		}
    }


}

