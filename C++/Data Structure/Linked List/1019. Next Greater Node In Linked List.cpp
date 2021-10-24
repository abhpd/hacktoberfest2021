// 1019. Next Greater Node In Linked List
// https://leetcode.com/problems/next-greater-node-in-linked-list/

// Brute Force - Create a sepearte array out of list elements and iterate over the array to find out next graeter element using two nested loops.
// Time Complexity O(N^2) Space Complexity O(N)
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {

        // O(N^2)
        /* 
        
        if(!head) return {};
        
        vector <int> ans;
        
        //Creating an array of list elements
        while(head){
            ans.push_back(head->val);
           head= head->next;
        }
        
        //var to check if we have found greater Element or Not         
        bool foundGreater;
        
        //Iterating over the vector 
        for(int i = 0; i<ans.size()-1; i++)
        {
            
            foundGreater = false;
            
            //for index i we iterate over the vector to find any greater element than itself 
            for(int j = i; j <ans.size(); j++)
            {
                    //If found put that into vector and marl foundGreater as true
                   if(ans[i] < ans[j]){
                       ans[i] = ans[j];
                       foundGreater = true;
                       break;
                   }
               
            }
            
            //If foundGreater is false , it means there's no element greater than that at index i so put there 0 
            if(!foundGreater) ans[i]=0;
        }
        
        //Last element wouldn't have any graeter eleemnt after itself so 0 
        ans[ans.size()-1] = 0;
        
        return ans;
    */

        // O(N) Approach

        if (!head)
            return {};

        // vector array to store the data value of node in LinkedList
        vector<int> nums;

        //Creating an array of list elements
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        int size = nums.size();

        // vector to store next greater element
        vector<int> nge(size, -1);

        stack<int> st;

        // pushing last element into the stack as its the greater element currently. 
        st.push(nums[size - 1]);

        // as there will be no greater element than itself for the last element , that's why putting 0 at last index.
        nge[size - 1] = 0;

        // iterating over the rest of the array
        for (int i = size - 2; i >= 0; i--)
        {

            // while our stack is not empty and the current element is greater than top of stack we will pop out . (pop out all smaller elements from the stack) 
            while (st.size() > 0 && nums[i] >= st.top())
            {
                st.pop();
            }

            // if our stack has become that means there is no greater element on right side of it. So put 0 at that index
            if (st.size() == 0)
                nge[i] = 0;

            // else we put the top element of stack at index i , bcoz thats the next greater element on right. 
            else
                nge[i] = st.top();


            // push the current element into the stack. 
            st.push(nums[i]);
        }

        // return the next graeter array
        return nge;
    }
};
