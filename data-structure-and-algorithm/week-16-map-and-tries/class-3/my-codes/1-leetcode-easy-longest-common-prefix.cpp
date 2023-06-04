// leetcode easy - https://leetcode.com/problems/longest-common-prefix/

class trie{
    public:
    char data;
    unordered_map<char,trie*> children;
    bool isTerminal;

    trie(char data){
        this->data=data;
        isTerminal=false;
    }
};

void insert_trie(trie* root, string s){
    if(s.length()==0){
        root->children['-']=new trie('-');
        return;
    }
        

    for(int i=0;i<s.length();i++){
        if(root->children.find(s[i]) == root->children.end()){
            // element not present
            root->children[s[i]]=new trie(s[i]);

        }
        root= root->children[s[i]];
    }
    root->isTerminal=true;
}

class Solution {
public:
    string longestCommonPrefix1(vector<string>& strs) { //without tree
        string ans = "";
        
        int min_len = 400;
        
        for(int i=0;i<strs.size();i++){
            int k=strs[i].length();
            min_len=min(min_len,k);
        }
        // cout<<min_len;
        for(int i=0;i<min_len;i++){
            bool isSingleCharSame=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=strs[j-1][i])
                    {
                        isSingleCharSame=false;
                        break;
                    }
            }

            if(isSingleCharSame)
                ans = ans+strs[0][i];
            else
                break;
        }
        
        return ans;   
    }


    string longestCommonPrefix2(vector<string>& strs) { // using trie
        string ans="";
        trie* root = new trie('-');

        for(int i=0;i<strs.size();i++){
            insert_trie(root,strs[i]);
        }
        // cout<<"halfway";
        // return "";

        while(root->isTerminal != true && root->children.size() == 1){
            char ch = root->children.begin()->first;
            if(ch != '-')
                ans = ans + ch;
            root=root->children.begin()->second;
        }

        return ans;

    }


        string longestCommonPrefix(vector<string>& strs) { // time -> o(n*m), space=> o(1)
            string ans="";

            // loop on first string
            for(int i=0;i<strs[0].length();i++){
                char ch = strs[0][i];
                bool match = true;

                // compare with all the other string and check at same index
                for(int j=1;j<strs.size();j++){
                    if(strs[j].length() < i || ch != strs[j][i]){
                        match=false;
                        break;
                    }
                }

                if(match){
                    ans = ans + ch;
                }
                else
                    break;
            }

            return ans;        
        }

};


//---------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------


class TrieNode{
    public:
    char data;
    TrieNode* children[26]; // array to store the children
    bool isTerminal; // to identify if it is terminal or not
    int childCount;

    TrieNode(char d){
      this->data = d;
      for(int i=0;i<26;i++)
        children[i] = NULL;
    childCount=0;
      this->isTerminal = false;
    }
};


void insertWord(TrieNode* root, string word){
// cout<<"inserting "<<word<<endl;
    // base case
    if(word.length() == 0){ // if there is no word, then mark root as terminal
      root->isTerminal = true;
      return;
    }

    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;

    if(root->children[index] != NULL){
      child = root->children[index];
    }
    else{
      // not present
      child = new TrieNode(ch);
      root->childCount++;
      root->children[index] = child;
    }

    insertWord(child,word.substr(1));

}

class Solution {
public: 

    void findLCP(string first,string& ans, TrieNode* root){
        if(root->isTerminal) // when stirng is blank
            return;

        for(int i=0;i<first.length();i++){
            char ch=first[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                int index = ch-'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal)
                break;
        }
    }

    string longestCommonPrefix(vector<string>& strs) { // time -> o(n*m), space -> o(n*m)
        TrieNode* root = new TrieNode('-');
        //insert string
        for(int i=0;i<strs.size();i++){
            insertWord(root,strs[i]);
        }

        // find longest prefix
        string ans = "";
        string first = strs[0];
        findLCP(first,ans,root);
        return ans;
    }
};