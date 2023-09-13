class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int x,int y,vector<vector<int>>& grid,int n,int m,queue<pair<int,int>> &q)
    {
        grid[x][y]=2;
        q.push({x,y});
        for(auto i:dir)
        {
            int nx=x+i[0];
            int ny=y+i[1];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1)
                dfs(nx,ny,grid,n,m,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
     
        queue<pair<int,int>> q;
        int fx=-1;
        int fy=-1;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                {
                    fx=i;
                    fy=j;
                    break;
                }
        q.push({fx,fy});
        int dis=0;
        dfs(fx,fy,grid,grid.size(),grid[0].size(),q);
        while(q.size())
        {
            int sz=q.size();
            while(sz--)
            {
                int cx=q.front().first;
                int cy=q.front().second;
                q.pop();
                for(auto i:dir)
                {
                    int nx=cx+i[0];
                    int ny=cy+i[1];
                    if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==1)
                        return dis;
                    else if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==0)
                    {
                        grid[nx][ny]=-1;
                        q.push({nx,ny});
                    }
                }
            }
            dis++;
        }
        return dis;
    }
};