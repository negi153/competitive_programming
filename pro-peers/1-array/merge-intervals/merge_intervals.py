# https://leetcode.com/problems/merge-intervals/
from typing import *

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda x: x[0])
        
        merged  = [intervals[0]]
        for start, end in intervals[1:]:
            prev_end = merged[-1][1] # previous end of merged

            # if current range falls in previous
            if start <= prev_end:
                merged[-1][1] =  max(prev_end,end) # update ending of last interval of merged
            else:
                merged.append([start,end])
        
        return merged