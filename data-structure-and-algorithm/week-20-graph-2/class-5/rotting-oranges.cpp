// https://leetcode.com/problems/rotting-oranges/
// very important question 
// logic - we can not go on each rotten cell and apply BFS and get the maximum levels  among each BFS call. it won't give correct answer.
//          here, so simultaneously each rotten cell will destroy it's neighbour cell. so we need to put all the rotten cell in queue and then add {-1,-1} (for finding the levels). then apply BFS overall, so it will destroy simultaneously .

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        queue<pair<pair<int,int>,int>> que;
        
        // insert all the rotten oranges in queue, because all rotten orantes will destroy it's neighbours simultaneously
        for(int row = 0;row<n;row++){
            for(int col =0;col<m;col++){
                if(grid[row][col] == 2)
                    {
                        que.push({{row,col},0}); // adding ({row,col},time)
                        visited[row][col] = true;
                    }
            }
        }

        // ------apply bfs and find the levels

        int ans = 0;

        while(!que.empty()){
            pair<pair<int,int>,int> front = que.front();
            que.pop();

            int frontRow = front.first.first;
            int frontCol = front.first.second;
            int time = front.second;

            vector<vector<int>> paths = {{frontRow+1,frontCol},{frontRow-1,frontCol},{frontRow,frontCol+1},{frontRow,frontCol-1}};

            //iterate on neighbour
            for(auto nbr:paths){
                int nbrRow = nbr[0],nbrCol = nbr[1];
                if(nbrRow>=0 && nbrRow <n && nbrCol>=0 && nbrCol < m ){

                    if(!visited[nbrRow][nbrCol] && grid[nbrRow][nbrCol] == 1){
                        que.push({{nbrRow,nbrCol},time+1});
                        ans = max(ans,time+1);
                        visited[nbrRow][nbrCol] = true;
                        grid[nbrRow][nbrCol] = 2; // rott the fesh fruit
                    }
                }
            }
        }

        // check if any cell has fresh oranges, if yes, then ans is -1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }

        return ans;
    }
};