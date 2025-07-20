// https://leetcode.com/problems/container-with-most-water/description
// logic - two pointer approach
// put left on 0 and right on n-1, 
// if left height is less, then increment left
// if right height is less, decrement right
// update max Area

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        int area = -1;
        while(left < right){
            int length = min(height[left],height[right]);
            int width = right - left;

            // cout<<length<<" "<<width<<endl;

            
            int new_area =  length * width;
            area = max(area, new_area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return area;
    }
};