# https://leetcode.com/problems/search-insert-position/
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        for n in nums:
            if n == target:
                return nums.index(n)
            elif n < target:
                continue
            elif n > target:
                return nums.index(n)
            
        return len(nums)
