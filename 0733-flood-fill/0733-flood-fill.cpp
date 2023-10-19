class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dx[]={-1,0,0,1};
        int dy[]={0,1,-1,0};
        int n=image.size();
        int m=image[0].size();
        int val=image[sr][sc];
        image[sr][sc]=color;
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        vis[sr][sc]=1;
        while(q.size())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(x+dx[i]>=0 && y+dy[i]>=0 && x+dx[i]<image.size() && y+dy[i]<image[0].size() && image[x+dx[i]][y+dy[i]]==val && !vis[x+dx[i]][y+dy[i]])
                {
                    if(image[x+dx[i]][y+dy[i]]==val)
                     image[x+dx[i]][y+dy[i]]=color;
                    q.push({x+dx[i],y+dy[i]});
                    vis[x+dx[i]][y+dy[i]]=1;
                }
            }
        }
        return image;
    }
};