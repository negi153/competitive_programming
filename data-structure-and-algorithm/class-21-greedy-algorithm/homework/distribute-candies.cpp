https://leetcode.com/problems/distribute-candies/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> st;
        for(auto candy:candyType)
            st.insert(candy);
        int n= candyType.size();

        if(st.size() >= n/2)
            return n/2;
        
        
        return st.size();
        
    }
};