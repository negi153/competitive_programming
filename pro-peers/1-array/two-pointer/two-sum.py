# https://leetcode.com/problems/two-sum/

from typing import *

class Solution:
    def twoSum1(self, nums: List[int], target: int) -> List[int]: # time - o(n*logn) - two pointers
        nums = [(n,ind) for ind,n in enumerate(nums)]

        nums.sort(key=lambda x:x[0])

        # 2 pointers
        left = 0
        right = len(nums) -1 

        while(nums[left][0] + nums[right][0] != target):
            ss = nums[left][0] + nums[right][0]

            if ss > target:
                right -= 1
            else:
                left += 1

        return [nums[left][1], nums[right][1]]

    def twoSum(self, nums: List[int], target: int) -> List[int]: # time - o(n), space o(n) - hashmap
        mp = {}
        for ind, n in enumerate(nums):
            if target - n in mp:
                return [mp[target-n],ind]
            
            mp[n] = ind

        return []

        