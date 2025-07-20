// https://neetcode.io/problems/string-encode-and-decode?list=blind75
// logic - to encode the string add it's length then # and then string
    // input - ["mukesh","ram"]
    // encoding - "6#mukesh3#ram"

    // to decode it, find the integer length untill # and then after # get the string

class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto s : strs){
            res = res + to_string(s.length()) + '#' + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while(i< s.size()){
            int j = i+1;
            // look for #
            while(s[j] != '#')
                j++;
            
            int length = stoi(s.substr(i,j-i)); // get the length of string and convert into integer
            
            // bring j to the starting of string
            j++;
            res.push_back(s.substr(j,length));

            i = j+length;
        }

        return res;
    }
};
