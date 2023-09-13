class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(n);
         vector<int> inde(n,0);
       for(auto i:prerequisites)
       {
           adj[i[1]].push_back(i[0]);
           inde[i[0]]++;
       }
     
       queue<int> q;
       for(int i=0;i<n;i++)
       {
           if(inde[i]==0)
           q.push(i);
       }
       vector<int> topo;
       while(q.size())
       {
           int curr=q.front();
           q.pop();
           topo.push_back(curr);
           for(int i:adj[curr])
           {
               inde[i]--;
               if(inde[i]==0)
               q.push(i);
           }
       }
       if(topo.size()==n)
       return topo;
       
       return {};
    }
};