class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1])
        return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        int dx[]={0,0,1,-1,1,-1,1,-1};
        int dy[]={1,-1,0,0,1,-1,-1,1};
        int vis[101][101]={0};
        vis[0][0]=1;
        while(q.size())
        {
            int level=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(x==n-1 && y==n-1)
            return level;
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && ny<n && nx<n && !grid[nx][ny] && !vis[nx][ny])
                {
                    vis[nx][ny]=1;
                    q.push({level+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};