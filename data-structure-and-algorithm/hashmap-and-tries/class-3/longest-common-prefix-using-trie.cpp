https://leetcode.com/problems/longest-common-prefix/
// if n is the number of strings and m is the number of characters in each string
// space complexity - o (n*m) to store all the characters in trie
// time complexity - o(n*m) for adding elements in trie  + o(m) for searching for child noddes

//approach - 
    // insert all the strings in trie data structure.
    // check in trie, untill we are getting 1 child of nodes, tthen that node will be in LCP. if child of node is more than 1, then stop or if we get any terminal node , then stop

class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    int childcount;

    TrieNode(char c){
        this->data = c;
        this->isTerminal=false;
        for(int i=0;i<26;i++)
            this->children[i]=NULL;
        this->childcount = 0;
    }
    };


class Solution {
    public:

    void insert(TrieNode* root,string word){
        //base case
        if (word.length()==0)
        {
            root->isTerminal=true;
            return;
        }   

        // find position of children
        int index = word[0]-'a';

        // if children at a particular index is not null, that means it's present
        TrieNode* child;
        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{ // children at particular index is null, means it's not present,so create children
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childcount ++;
        }

        // add next characters of string using recursion
        insert(child,word.substr(1));

    }

        void findLCP(TrieNode* root,string word, string& ans){
            
            // iterate on each character of fisrt word
            for(int i=0;i<word.length();i++)
            {
                char ch = word[i];

                int ind = ch - 'a';

                // if the root node is terminal, then break it
                if (root->isTerminal)
                    break;

                // if root node has only one child,then include in answer an move root to next child
                if (root->childcount == 1){
                    ans += ch;
                    root = root->children[ind];
                }
                else{
                    break;
                }
            }
        }

        string longestCommonPrefix(vector<string>& arr) {
            
            TrieNode* root = new TrieNode('-');
            
            // insert all the string in trie
            for(int i= 0;i<arr.size();i++)
                insert(root,arr[i]);

            string ans = "";
            findLCP(root,arr[0],ans);
            return ans;
        }
    };