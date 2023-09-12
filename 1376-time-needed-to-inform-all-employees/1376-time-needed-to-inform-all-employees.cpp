class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<pair<int,int>> q;
        q.push({headID,0});
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        int ans=0;
        while(q.size())
        {
            int node=q.front().first;
            int tim=q.front().second;
            q.pop();
            ans=max(ans,tim);
            for(auto j:adj[node])
            {
                q.push({j,tim+informTime[node]});
            }
        }
        return ans;
    }
};