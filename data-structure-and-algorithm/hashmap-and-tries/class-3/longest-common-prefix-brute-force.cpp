https://leetcode.com/problems/longest-common-prefix/

// brute force approach
class Solution {
    public:
        string longestCommonPrefix(vector<string>& arr) {
    
            string lcp = "";
            for(int i=0;i<arr[0].length();i++){ // iterate on each character of first string
    
                char current_char = arr[0][i];
    
                bool char_present = true; // flag to store if current character is present in all the string or not
                for(int j=1;j<arr.size();j++){ // iterate from 2nd string to last string
                    

                    // here first condition check, if length of jth string is less than the first string, then there wont be any comparision, so again it's false
                    if(arr[j].size() <= i || arr[j][i] != current_char){
                        char_present = false;
                        break;
                    }
                        

                }
    
                if (char_present)
                    lcp += current_char;
                else
                    break;
    
            }
    
            return lcp; 
        }
    };