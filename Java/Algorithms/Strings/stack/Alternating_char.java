/*You are given a string containing characters  and  only. Your task is to change it into a string such that there are no matching adjacent characters. 
To do this, you are allowed to delete zero or more characters in the string.
Your task is to find the minimum number of required deletions.
Input Format
The first line contains an integer , the number of queries.
The next q lines each contain a string s.
Output Format
For each query, print the minimum number of deletions required on a new line.
Sample Input
5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB
Sample Output
3
4
0
0
4 */

public class Solution {
    //alternatingCharacters function below.
    static int alternatingCharacters(String s){
        int count=0,i=0;
        char c;
        Stack<Character> stack=new Stack<>();
        while(i<s.length()){
            c = s.charAt(i);
            if(stack.empty()){
                stack.push(c);
                i++;
            }
            else if(stack.peek()==c){
                stack.push(c);
                stack.pop();
                count++;
                i++;
            }
            else{
                stack.push(c);
                i++;
            }
        }
        return count;
}
