# https://leetcode.com/problems/insert-interval/description/
from typing import *

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:  # time - o(n*logn)
        # add new interval to last        
        intervals.append(newInterval)

        # sort intervals
        intervals.sort(key=lambda x: x[0])

        # create non-overlappin intervals
        merged  = [intervals[0]]
        for start, end in intervals[1:]:
            prev_end = merged[-1][1] # previous end of merged

            # if current range falls in previous
            if start <= prev_end:
                merged[-1][1] =  max(prev_end,end) # update ending of last interval of merged
            else:
                merged.append([start,end])
        
        return merged
    
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]: # time - o(n)
        if not intervals:
            return [newInterval]

        merged = []
        for ind, curr_interval in enumerate(intervals):

            # if newInterval is coming before current interval,(we came at right position) then add new interval and remaining intervals
            if newInterval[1] < curr_interval[0]:
                merged.append(newInterval)
                return merged + intervals[ind:]

            # if new interval is coming after current interval, then add current interval
            elif newInterval[0] > curr_interval[1]:
                merged.append(curr_interval)

            # if merging is possible, then update new interval and expand it
            else:
                newInterval[0] = min(newInterval[0],curr_interval[0])  
                newInterval[1] = max(newInterval[1],curr_interval[1])  

        merged.append(newInterval)
        return merged