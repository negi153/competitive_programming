https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,map<pair<int,int>,bool>& visited,int old_colour) 
    {

        visited[{sr,sc}] = true;
        image[sr][sc] = color;

        vector<vector<int>> paths = {{sr+1,sc},{sr-1,sc},{sr,sc+1},{sr,sc-1}};

        for(auto nbr:paths){
            int newRow = nbr[0],newCol = nbr[1];
            if(newRow>=0 && newRow < image.size() && newCol >=0 && newCol <image[0].size()){
                if(!visited[{newRow,newCol}] && image[newRow][newCol]==old_colour)
                    dfs(image,newRow,newCol,color,visited,old_colour);
            }
        }


    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        map<pair<int,int>,bool> visited;
        int old_colour = image[sr][sc];

        vector<vector<int>> ans = image;
        dfs(ans,sr,sc,color,visited, old_colour);

        return ans;
    }
};