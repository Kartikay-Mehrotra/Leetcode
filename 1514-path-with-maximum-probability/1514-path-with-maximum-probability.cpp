class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dis(n,0);
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
             adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        dis[start_node]=1;
        queue<pair<int,double>> q;
        q.push({start_node,1});
        while(q.size())
        {
            int node=q.front().first;
            int prob=q.front().second;
            q.pop();
            for(auto i:adj[node])
            {
                if(dis[i.first]<dis[node]*i.second)
                {
                    dis[i.first]=dis[node]*i.second;
                    q.push({i.first,dis[i.first]});
                }
            }
        }
        return dis[end_node];
    }
};