class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int x = 0; x < nums.size(); x++)
        {
            nums[x] = pow(nums[x], 2);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};