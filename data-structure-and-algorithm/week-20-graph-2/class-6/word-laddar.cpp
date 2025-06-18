// https://leetcode.com/problems/word-ladder/
// we need to find the shortest transformaiton to reach to end word from begin word. so we apply bfs by iterating alll the possible string

class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //store words in set
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        queue<pair<string,int>> que; // stores the string and it's level
        que.push({beginWord,1});

        while(!que.empty()){
            auto front = que.front();
            que.pop();

            string currWord = front.first;
            int level = front.second;

            // check if current worrd is the last word
            if(currWord == endWord)
                return level;

            for(int i=0;i<currWord.length();i++){
                string newWord = currWord;
                for(char ch='a';ch<='z';ch++){
                    newWord[i]=ch;

                    if(st.find(newWord)!= st.end()){
                        que.push({newWord,level+1});
                        st.erase(newWord);
                    }
                }
            }

        }
        return 0;
    }
};