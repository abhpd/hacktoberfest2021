/*

Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.
*/

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
      
       Arrays.sort(intervals , (a,b) -> a[0]==b[0] ? b[1]-a[1] : a[0]-b[0]);
        
        int count=0; //here count is used to count the total engulfing intervals (cover whole)
        int b=intervals[0][1]; //starting case
        
        for(int i=1;i<intervals.length;i++){
            if(intervals[i][1]<=b){ //if next (b) element is lesser or equal then count++
                count++;
            }
            else{
                b=intervals[i][1]; //whenever next b element has high limit than prev than update it
            }
        }
        return intervals.length-count; //as we need to find remaining intervals after removing covered intervals
    }
}
