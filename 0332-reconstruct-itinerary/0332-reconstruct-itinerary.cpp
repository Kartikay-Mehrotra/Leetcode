class Solution {
public:
void solve(map<string,multiset<string>>& graph,vector<string> &res,string start)
{
    
    while(graph[start].size()>0)
    {
        auto next=*graph[start].begin();
        graph[start].erase(graph[start].begin());
        solve(graph,res,next);
    }
    res.push_back(start);
    
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {

       map<string,multiset<string>> graph;
       for(auto i:tickets)
       {
           graph[i[0]].insert(i[1]);
       }
       vector<string> res;
       solve(graph,res,"JFK");
       reverse(res.begin(),res.end());
       return res;
    }
};