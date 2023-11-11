class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(300);
        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            adj[u].push_back({v,wt});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        vector<int> dis(adj.size(),INT_MAX);
        dis[node1]=0;
        while(pq.size())
        {
            int node=pq.top().second;
            int di=pq.top().first;
            pq.pop();
            if(node==node2)
                return di;
            for(auto i:adj[node])
            {
                int ad=i.first;
                int wt=i.second;
                if(dis[ad]>dis[node]+wt)
                {
                    dis[ad]=dis[node]+wt;
                    pq.push({dis[ad],ad});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */