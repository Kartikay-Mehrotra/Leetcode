class Solution {
public:
    void solve(int node,vector<int> adj[],vector<int> &vis)
    {
        vis[node]=1;
        for(auto i:adj[node])
            if(!vis[i])
                solve(i,adj,vis);
    }
    int findCircleNum(vector<vector<int>>& g) {
         int v=g.size();
        int count=0;
        vector<int> al[v];
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(g[i][j]==1 && i!=j)
                {
                    al[i].push_back(j);
                    al[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                ans++;
                solve(i,al,vis);
            }
        }
        return ans;
    }
};