# https://leetcode.com/problems/non-overlapping-intervals/description/
from typing import *
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

        intervals.sort()
        print(intervals)
        
        previous_end = intervals[0][1]
        cnt = 0

        for start,end in intervals[1:]:
            if start >= previous_end:
                previous_end = end
            else:
                cnt += 1
                previous_end = min(previous_end,end)
            
        return cnt
        