class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>> adj[n];
        for(int i=0;i<n-1;i++)
        {
         for(int j=i+1;j<n;j++)
         {
             int w=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
             adj[i].push_back({j,w});
             adj[j].push_back({i,w});
         }   
        }
        vector<int> vis(n+1,0);
        pq.push({0,0});
        int sum=0;
        while(pq.size())
        {
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(vis[node])
            continue;
            vis[node]=1;
            sum+=wt;
            for(auto j:adj[node])
            {
                if(!vis[j[0]])
                {
                    pq.push({j[1],j[0]});
                }
            }
        }
        return sum;
        
    }
};