//Consider a long alley with a N number of doors on one side. All the doors are closed initially.
//You move to and fro in the alley changing the states of the doors as follows: you open a door that is already closed and you close a door that is already opened.
//You start at one end go on altering the state of the doors till you reach the other end and then you come back and start altering the states of the doors again.
//In the first go, you alter the states of doors numbered 1, 2, 3, … , n.
//In the second go, you alter the states of doors numbered 2, 4, 6…
//In the third go, you alter the states of doors numbered 3, 6, 9 …
//You continue this till the Nth go in which you alter the state of the door numbered N.
//You have to find the number of open doors at the end of the procedure.


// Approach:
//A gate will be open in the end if and only if it has an odd number of factors.
//This is so because each gate is visited by its factors only. For example 100 will be visited by 1,2,4,5,10,20,25,50,100 in that order.  
//Only perfect squares have an odd number of factors (try proving this). 
//Hence the answer for N will be the number of perfect squares less than or equal to N.

// JAVA Solution

class Solution {
   static int noOfOpenDoors(Long N) {
       // code here
       long open = (long)Math.sqrt(N);
       
       return (int)open;
   }
};

//Time Complexity: O(1)
