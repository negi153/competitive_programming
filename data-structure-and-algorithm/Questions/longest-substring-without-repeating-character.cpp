// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:

    bool is_valid(string& s,int left,int right){ // check if the string is valid string without duplicate characters
        unordered_map<char,int> mp;
        for(int i = left;i<=right;i++){
            char ch = s[i];

            if(mp.find(ch) != mp.end())
                return false;
            
            mp[ch]++;
        }

        return true;
    }

    int brute_force(string s){
        // time - o(n^3)

        int max_len = 0;
        for( int i = 0;i< s.length();i++){
            for(int j = i; j<s.length(); j++){
                if(is_valid(s,i,j))
                    max_len = max(max_len, j-i+1);
                else
                    break;
            }
        }

        return max_len;
    }

    int optimize1(string s){

        // outer loop will be the starting of substring and inner loop will be the ending of substring
        // in inner loop update maximum length untill we don't see the duplicate
        // time - o(n^2)
        int max_len = 0;
        for( int i = 0;i< s.length();i++){
            unordered_map<char,int> mp;

            for(int j = i; j<s.length(); j++){
                char ch = s[j];

                if(mp.find(ch) != mp.end())
                    break;
                
                max_len = max(max_len,j-i+1);

                mp[ch]++;
            }

        }

        return max_len;
    }

    int sliding_window(string s){
        int left = 0, right = 0, max_len = 0;
        unordered_map<char,int> mp; // map to keep track of the elements which are prsent in window

        while( right < s.length()){
            char ch = s[right];
            
            if(mp.find(ch) != mp.end() && mp[ch] == true){
                // duplicate character came, now delele from left side, untill we delete the dupicate element
                while(s[left] != ch){
                    mp[s[left]] = false;
                    left++;
                }
                mp[s[left]] = false;
                left++;
            }

            max_len = max(max_len, right-left+1);
            mp[ch] = true;;
            right++;
        }

        return max_len;
    }

    int sliding_window_set(string s){
        // set will contain the elements present in current window
        set<char> st;
        int left = 0, max_len = 0;

        for( int right = 0; right < s.length(); right++){
            
            // delete duplicate elements from left to remove duplicate
            while(st.count(s[right])){ // delete untill right element is present in set
                st.erase(s[left]);
                left++;
            }

            max_len = max(max_len, right-left+1);
            st.insert(s[right]);
        }

        return max_len;
    }

    int lengthOfLongestSubstring(string s) {
        // brute force - time : o(n^3)
        // return brute_force(s); 

        // time - o(n^2)
        // return optimize1(s);

        // time - o(n) - sliding window using map
        // return sliding_window(s);

        // time - o(n) - sliding window using set
        return sliding_window_set(s);

    }
};