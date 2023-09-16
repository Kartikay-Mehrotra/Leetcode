class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        while(pq.size())
        {
            int eff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            if(r==n-1 && c==m-1)
            return eff;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nc>=0 &&nr<n && nc<m)
                {
                    int newe=max(abs(h[nr][nc]-(h[r][c])),eff);
                    if(dis[nr][nc]>newe)
                    {
                        dis[nr][nc]=newe;
                        pq.push({newe,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};