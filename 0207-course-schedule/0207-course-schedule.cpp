class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto i:p)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> topo;
        while(q.size())
        {
            int f=q.front();
            q.pop();
            topo.push_back(f);
            for(auto j:adj[f])
            {
                indegree[j]--;
                if(indegree[j]==0)
                q.push(j);
            }
        }
        return topo.size()==n;
        

    }
};