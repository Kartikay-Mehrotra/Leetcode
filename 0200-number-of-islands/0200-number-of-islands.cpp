class Solution {
    private:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &vis)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()|| vis[row][col]==1 || grid[row][col]=='0')
        return ;
       vis[row][col]=1;
      bfs(row+1,col,grid,vis);
      bfs(row-1,col,grid,vis);
      bfs(row,col-1,grid,vis);
      bfs(row,col+1,grid,vis);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0)); 
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,grid,vis);
                    
                }
            }
        }
        return count;
    }
};