class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        rev_table = dict()
        for i in range(len(nums)):
        	second_addend = target - nums[i]
        	if second_addend in rev_table:
        		return [rev_table[second_addend], i]
        	else:
        		rev_table[nums[i]] = i
