#https://leetcode.com/problems/3sum/description/
from typing import *

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        nums.sort()
        # print(nums)
        result = []
        
        for target_ind,n in enumerate(nums):
            print(target_ind, n)
            
            if target_ind > 0 and n == nums[target_ind-1]:
                continue

            target = -n
            mp = {}
            for ind in range(target_ind+1,len(nums)):
                    
                complement = target - nums[ind]
                if complement in mp:
                    # found the pair
                    print(n,complement, nums[ind])

                    if result and (complement != result[-1][1] or nums[ind] != result[-1][2]):
                        result.append([n,complement, nums[ind]])

                    if not result:
                        result.append([n,complement, nums[ind]])

                mp[nums[ind]] = ind

        return result