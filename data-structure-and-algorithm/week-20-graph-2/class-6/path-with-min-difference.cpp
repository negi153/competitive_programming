https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //applying dijkastra here using priority queue,(can also use set )
        // priority queue is max heap by default;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>> > ,greater<pair<int,pair<int,int>>> > pq;
        vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int frontNodeDiff = front.first;
            int x = front.second.first;
            int y = front.second.second;

            // check if x,and y is answre or not
            if(x==heights.size()-1 && y == heights[0].size()-1)
                return dist[x][y];

            vector<vector<int>> paths = {{x+1,y},{x-1,y},{x,y-1},{x,y+1}};
            for(auto nbr: paths){
                int newX = nbr[0],newY=nbr[1];
                if(newX >=0 && newX < heights.size() && newY >=0 && newY < heights[0].size()){
                    
                    int currDifference = abs(heights[x][y]-heights[newX][newY]);
                    int newMax = max(frontNodeDiff,currDifference);

                    if (newMax < dist[newX][newY])
                        {
                            dist[newX][newY] = newMax;
                            pq.push({newMax,{newX,newY}});
                        }
                }
            }
        }
        return 0;
    }
};