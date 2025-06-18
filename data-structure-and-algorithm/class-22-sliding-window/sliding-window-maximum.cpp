// https://leetcode.com/problems/sliding-window-maximum/description/
// // logic - 
//     1. for first window keep all the elements in set in decreasing order of elements and increasing order of indexes
//     2. process other windows, remove the left most element from set and insert current right element in set
//     3. since set is in decreasing order, so the maxium element will be present in first of set

class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if(a.first != b.first)
                return a.first > b.first;
            return a.second > b.second;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        set<pair<int,int>, cmp> st;
        for(int i = 0; i < k; i++)
            st.insert({nums[i], i});
        ans.push_back(st.begin()->first);

        for(int i = k; i < nums.size(); i++) {
            st.erase({nums[i - k], i - k});
            st.insert({nums[i], i});
            ans.push_back(st.begin()->first);
        }
        return ans;
    }
};