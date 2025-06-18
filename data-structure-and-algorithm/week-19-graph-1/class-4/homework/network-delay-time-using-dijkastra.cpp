// https://leetcode.com/problems/network-delay-time/description/?envType=problem-list-v2&envId=shortest-path
// using dijkastra algorithm, find the shortest distance of each node from source node, then find the maximum distance from the distance array


class Solution {
public:
     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create graph
        unordered_map<int,list<pair<int,int>>> g;
        for(auto edge: times){
            g[edge[0]].push_back({edge[1],edge[2]});
        }
        
     // find shortest path of all the nodes from node k using dijkastra
        vector<int> dist(n+1,INT_MAX);
        set<pair<int,int>> st;

        dist[k] = 0;
        st.insert({0,k});

        while(!st.empty()){
            auto front = *st.begin();
            int frontDist = front.first;
            int frontNode = front.second;

            st.erase(st.begin());

            for(auto nbr:g[frontNode]){
                int nbrNode = nbr.first;
                int nbrWeight = nbr.second;

                if(frontDist != INT_MAX && frontDist + nbrWeight < dist[nbrNode]){
                    
                    auto result = st.find({dist[nbrNode],nbrNode});
                    if(result != st.end()){
                        st.erase(result);
                    }
                    
                    dist[nbrNode] = frontDist + nbrWeight;
                    st.insert({ dist[nbrNode], nbrNode});
                    
                }
            }
        }


        int ans = -1;
        for(int i=1;i<=n;i++){
            // cout<<dist[i]<<" ";
            if(dist[i] == INT_MAX){
                ans = -1;
                break;
            }
            if(dist[i] != INT_MAX && i!=k)
                ans = max(ans,dist[i]);
        }
        
        return ans;
    }
};