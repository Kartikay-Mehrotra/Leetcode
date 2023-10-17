class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int> indegree(n);
        for(int i=0;i<n;i++)
        {
            if(l[i]!=-1){
                if(indegree[l[i]]>1)
                    return false;
                else
                indegree[l[i]]++;
            }
            if(r[i]!=-1){
                if(indegree[r[i]]>1)
                    return false;
                else
                indegree[r[i]]++;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                if(root!=-1)
                    return false;
                root=i;
            }
        }
        if(root==-1)
            return false;
        
        queue<int> q;
        q.push(root);
        vector<bool> vis(n,false);
        
       
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            if(vis[f])
                return false;
            vis[f]=true;
            if(l[f]!=-1)
                q.push(l[f]);
            if(r[f]!=-1)
                q.push(r[f]);
        }
       for(int i=0;i<n;i++)
       {
           if(vis[i]==false)
               return false;
       }
        return true;
    }
};