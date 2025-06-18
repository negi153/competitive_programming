// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
// https://leetcode.com/problems/minimum-window-substring/submissions/1665132569/

// logic - 
    // 1. store the frequencies of string2 in map
    // 2. apply sliding window in string1
    // 3. for each window check if string 1 contains all the elements of string 2 or not.
    //     if yes, then update answer, 

class Solution {
  public:
  
    bool isFrequencyMatching(unordered_map<char,int>& mp1, unordered_map<char,int>& mp2){
        bool ans = true;
        for(auto item:mp2){
             char ch = item.first;
             int fre = item.second;
             if(mp1.find(ch) == mp1.end()){
                    ans = false;
                    break;
                }
             if(mp1[ch] < fre){
                 ans = false;
                 break;
             }
        }
        
        return ans;
    }
    
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        
        unordered_map<char,int> mp1,mp2;
        
        // calculate the frequency of s2;
        for(auto item:s2){
            mp2[item]++;
        }
        
        int start=0,end=0; // to iterate on string 1
        int ansLeftInd = -1,ansRightInd = -1;
        int minLen = INT_MAX;
        
        while(end < s1.length()){
            // cout<<start<< " "<<end<<" ";
            
            mp1[s1[end]]++; // increment the frequency of string 1 in map
            // cout<<isFrequencyMatching(mp1,mp2)<<endl;
            
            while(isFrequencyMatching(mp1,mp2)){
                // cout<<"inside loop"<<endl;
                if(end-start+1 < minLen){
                    minLen = end-start+1;
                    
                    ansLeftInd = start;
                    ansRightInd = end;
                }
                // cout<<" "<<end<<" matching "<<ansLeftInd<<" "<<ansRightInd<<endl;
                
                mp1[s1[start]]--;
                start++;
            }
            
            end++;
                
        }
        
        // cout<<ansLeftInd<<" "<<ansRightInd<<endl;
        
        if(minLen != INT_MAX)
            return s1.substr(ansLeftInd,minLen);
        else 
            return "";
        
    }
};


//-----------------------------------------------------
// solution 2 
// class Solution {
// public:
//     string minWindow(string s, string p) {
//         int len1 = s.length();
//         int len2 = p.length();
//         int start = 0;
//         int ansIndex = -1;
//         int ansLen = INT_MAX;
        
//         if(len1 < len2) {
//             return "";
//         }
        
//         unordered_map<char, int> strMap;
//         unordered_map<char, int> patMap;
//         //to keep track of all characters of P string
//         for(int i=0; i<p.length(); i++) {
//             char ch = p[i];
//             patMap[ch]++;
//         }
        
//         int count = 0;
//         for(int i=0; i<s.length(); i++) {
//             char ch = s[i];
            
//             strMap[ch]++;
            
//             //valid character -> jo character tumhare opattern me bhi ho 
//             if(strMap[ch] <= patMap[ch] ) {
//                 count++;
//             }
            
//             if(count == len2) {
                
//                 //window is readyv
                
//                 //minimise the window -> freq decrement, ans update , start ko aage badhana h 
                
//                 while(strMap[s[start]] > patMap[s[start]] ||patMap[s[start]] == 0 ) {
                    
//                     if(strMap[s[start]] > patMap[s[start]])
//                         strMap[s[start]]--;
                        
//                     start++;
//                 }
                
//                 //ans update
//                 int lengthOfWindow = i - start + 1;
//                 if(lengthOfWindow < ansLen ) {
//                     ansLen = lengthOfWindow;
//                     ansIndex = start;
//                 }
                
                
//             }
//         }
        
//         if(ansIndex == -1)
//             return "";
//         else
//             return s.substr(ansIndex, ansLen);
//     }
// };