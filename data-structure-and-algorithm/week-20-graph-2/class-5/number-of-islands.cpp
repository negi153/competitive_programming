https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    bool isValidIndex(int i,int j, vector<vector<char>>& grid){
        return (i>=0 && i< grid.size() && j>=0 && j<grid[0].size());
    }

    void visitIslandDfs(int i,int j, vector<vector<char>>& grid, map<pair<int,int>,bool>& visited){

        visited[{i,j}] = 1;

        vector<vector<int>> paths = {{i,j+1},{i,j-1},{i+1,j},{i-1,j}};

        for (auto nbr:paths){
            int newRow = nbr[0],newCol = nbr[1];
            if(isValidIndex(newRow,newCol,grid) && grid[newRow][newCol] == '1' && !visited[{newRow,newCol}])     {
                    visitIslandDfs(newRow,newCol,grid,visited);
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m = grid[0].size();
        map<pair<int,int>,bool> visited;

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[{i,j}] && grid[i][j] == '1'){
                    visitIslandDfs(i,j,grid,visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};