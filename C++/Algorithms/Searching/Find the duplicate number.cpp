class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];//we take 2 pointers at '0' index ->slow and fast
        int fast=nums[0];
        //we solve this problem by do-while loop
        do{
            //in this do loop we will find colliding point of 2 pointers and return slow or fast at output.
            slow=nums[slow];//move to next node
            fast=nums[nums[fast]];//move to next to next node
        }while(slow!=fast);
        
        //intialise slow to starting point
        slow=nums[0];
        
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
        
        
    }
};
