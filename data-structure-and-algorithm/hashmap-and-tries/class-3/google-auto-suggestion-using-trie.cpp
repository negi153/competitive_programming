//hard question

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class TrieNode {

    public:
    bool isTerminal;
    unordered_map<char,TrieNode*> child;

    TrieNode(char c){
        this->isTerminal = false;
    }

};

void insert(TrieNode* root, string word){
    if (word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char curr = word[0];
    TrieNode* child ;

    if (root->child.count(curr))
        child = root->child[curr];
    else{
        child = new TrieNode(curr);
        root->child[curr] = child;
    }

    insert(child,word.substr(1));
}

void get_suggestion(TrieNode* root, string curr_word, vector<string>& temp) {

    // store answer in temp whenever we get terminal
    if (root->isTerminal == true){
        temp.push_back(curr_word);
    }
    for(auto x: root->child){
        get_suggestion(x.second,curr_word+x.first,temp);
    }

}

int  main(){
    TrieNode* root = new TrieNode('-');
    insert(root, "lover");
    insert(root,"lost");
    insert(root,"lend");
    insert(root,"loving");
    insert(root,"lord");
    insert(root,"lordring");

    vector<vector<string>> sugg;

    string input = "lost";
    
    for(int i=0; i<input.size();i++){
        char ch = input[i];

        vector<string> temp;
        if(root->child.count(ch))
        {   
            // present
            root = root->child[ch];
            get_suggestion(root, input.substr(0,i+1) , temp) ;  
        }

        sugg.push_back(temp);
    }

    // show output
    string current_type_word = "";
    for(int i= 0;i<input.size();i++){
        current_type_word += input[i];

        cout<<"suggestion for "<<current_type_word<<" ->";
        for(auto y: sugg[i])
            cout<<y<<", ";
        cout<<endl;
    }

return 0;
}