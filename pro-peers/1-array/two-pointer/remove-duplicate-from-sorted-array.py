# https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

from typing import *

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ans_ind = 1
        curr_ind = 1

        while curr_ind < len(nums):
            # if current element doesn't match with previous element, so it's first occurance and put it in it's place
            if nums[curr_ind] != nums[curr_ind -1]:
                nums[ans_ind] = nums[curr_ind]
                ans_ind += 1
            
            curr_ind += 1
                
        return ans_ind