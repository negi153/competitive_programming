// https://leetcode.com/problems/reorganize-string/

class node{
    public:
        char data;
        int count;

    node(char ch,int f){
        data=ch;
        count=f;
    }
};

class compare{
    public:
    bool operator()(node a, node b){
        return a.count < b.count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        
        // create mapping -> element and frequency
        int fre[26] = {0};

        for(int i=0;i<s.length();i++){
            fre[s[i]-'a']++;
        }

        // create max heap
        priority_queue<node, vector<node>, compare > maxHeap;

        for(int i=0;i<26;i++){
            if(fre[i] != 0){
                node temp(i+'a',fre[i]);
                maxHeap.push(temp);
            }
        }

        // create string

        string ans = "";
        while(maxHeap.size() > 1) { // because we are getting 2 elements from heap
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            ans = ans + first.data + second.data;

            first.count--;
            second.count--;

            if(first.count != 0 )
                maxHeap.push(first);

            if(second.count != 0)
                maxHeap.push(second);

        }

        // case when heap has 1 element
        if(maxHeap.size() == 1){
            node temp = maxHeap.top();
            maxHeap.pop();

            if(temp.count == 1){ // it will give adjacent
                ans += temp.data;                
            }
            else
                return "";

        }

        return ans;
    }
};