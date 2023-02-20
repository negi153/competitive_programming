// valid parenthesis
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true

class Solution {
public:
    bool isValid1(string s) { // time o(n), space-> o(n)
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.size()>0 && st.top() == '(')
                    st.pop();
                else
                    return false;                     
            }
            else if(s[i]=='}'){
                if(st.size()>0 && st.top() == '{')
                    st.pop();  
                else
                    return false;              
            }
            else if(s[i]==']'){
                if(st.size()>0 && st.top() == '[')
                    st.pop();
                else
                    return false;                
            }
        }

        if(st.size()) return false;
        else return true;
    }


    bool isValid(string s) { // time o(n), space-> o(n)
        stack<char> st;
        
        map<char,char> mp {{'(',')'}, {'[',']'}, {'{','}'}};

        for(int i=0;i<s.length();i++){ 
            
            if(s[i]=='(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else
            {
                if(st.size()>0 && mp[st.top()]==s[i])
                    st.pop();
                else
                    return false;
            }

        }

        if(st.size()) return false;
        else return true;
    }


};