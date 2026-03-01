# https://leetcode.com/problems/3sum-closest/

from typing import *

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort() # sort for 2 pointers
        
        closest_sum = nums[0] + nums[1] + nums[2]
        
        for first_ind, first_num in enumerate(nums):

            # applying 2 pointer to find triplets
            left = first_ind +1
            right = len(nums) -1
            while left < right:
                ss = first_num + nums[left] + nums[right]

                if abs(ss - target) < abs(closest_sum - target):
                    closest_sum = ss

                if ss > target:
                    right -= 1
                elif ss < target:
                    left += 1
                else:
                    return target # as sum is equal to target so this is besst
        return closest_sum