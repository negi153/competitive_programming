# https://leetcode.com/problems/squares-of-a-sorted-array/description/

from typing import * 

class Solution:
    def sortedSquaresBasic(self, nums): # time - o(n* logn)
        nums = [x*x for x in nums]
        nums.sort()
        return nums
        
    def sortedSquares(self, nums: List[int]) -> List[int]: # time - o(n), approach - 2 pointer
        # idea - since array is sorted so maximum square will either come from right(positive values) or left(negative values). using 2 pointer find the max square and store in final array
        ans = []

        left = 0
        right = len(nums) - 1

        # applying  2 pointers
        while left <= right:
            if abs(nums[right]) > abs(nums[left]) : 
                ans.append(nums[right] * nums[right])
                right -= 1
            else:
                ans.append(nums[left] * nums[left])
                left += 1
                
        return ans[::-1] # since ans will be in decreasing order, reverse it