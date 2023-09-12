class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
       vector<int> adj[n];
        vector<int> ans;
        queue<int> q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto j:graph[i])
            {
                adj[j].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(q.size())
        {
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto i:adj[f])
            {
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};