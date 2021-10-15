// Next Permutation Implementation 
// STL -> next_permutation(arr,arr+n); prev_permutation(arr,arr+n);
void nextPermutation(vector<int>& nums)
{
  int l = nums.size(), fd, i;
  for(i = l-2; i >= 0; i--)
  {
    if(nums[i] < nums[i+1])
    {
      fd = i;
      break;
    }
  }
  if(i < 0)
  {
    reverse(nums.begin(),nums.end());
    return;
  }
  for(i = l-1; i > fd; i--)
  {
    if(nums[fd] < nums[i])
    {
      swap(nums[i], nums[fd]);
      break;
    }
  }
  reverse(nums.begin() + fd+1, nums.end());
}