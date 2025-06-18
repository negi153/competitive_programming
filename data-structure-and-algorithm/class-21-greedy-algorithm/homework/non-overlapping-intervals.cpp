// https://leetcode.com/problems/non-overlapping-intervals/

//logic - 
    // 1. sort the vector by 2nd eleemnt in ascending order
    // 2. find the count of non-overlapping intervals.
    // 3. to get the minimum inteval to delete, subtract non-overlapping count from the size of array

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort the intervals by second elemtent similar to scheduling train in ascending order
        sort(intervals.begin(),intervals.end(),cmp);

        int cnt=1; // here cnt is 1 as we already selected the first interval after the sort. cnt is the numbeer of non-overlapping intervals
        int lastSelectedEnd = intervals[0][1];// select the first interval.

        for(int i= 1;i<intervals.size();i++){
            if(intervals[i][0] >= lastSelectedEnd){
                cnt++;
                lastSelectedEnd=intervals[i][1];
            }
        }
        // 
        return intervals.size() - cnt;
    }
};