class Solution {
public:
vector<vector<int>> ans;
int n;
void solve(int node,vector<int> states, map<int,vector<int>> &adj)
{
    if(node==n-1)
    {
        ans.push_back(states);
        return;
    }
   vector<int> s=adj[node];
   
   for(auto i:s)
   {
       states.push_back(i);
       solve(i,states,adj);
       states.pop_back();
   }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
n=graph.size();
      map<int,vector<int>> adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        cout<<adj.size();
        vector<int> states;
        states.push_back(0);
        solve(0,states,adj);
        return ans;
        
        
    }
};