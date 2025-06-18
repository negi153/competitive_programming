

// https://leetcode.com/problems/sliding-window-maximum/description/
// // logic - 
//     
class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // it stores the indexes. it will always store the maxmum element index at right most index

        // process first window
        for(int i=0;i<k;i++){
            // delete elements from right if they are less than current index
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);
        
        // process other window
        for(int i=k;i<nums.size();i++){
            // remove from left
            if(!dq.empty() && i-k>=dq.front())
                dq.pop_front();

            //add from right
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);

            // find ans
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
    
};