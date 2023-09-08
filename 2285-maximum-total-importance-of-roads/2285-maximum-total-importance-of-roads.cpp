class Solution {
public:
  
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       vector<int> indegree(n,0);
        for(auto i:roads)
        {
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({indegree[i],i});
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int j=n;
       for(int i=0;i<n;i++)
       {
           indegree[v[i].second]=j--;
       }
        long long ans=0;
        for(auto i:roads)
        {
            ans+=indegree[i[0]]+indegree[i[1]];
        }
        return ans;
    }
};