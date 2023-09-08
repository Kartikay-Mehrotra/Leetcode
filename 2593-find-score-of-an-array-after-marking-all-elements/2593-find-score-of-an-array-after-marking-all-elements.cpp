class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(n+1,0);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int ind=v[i].second;
            if(vis[ind]==0)
            {
                vis[ind]=1;
                ans+=v[i].first;
                if(ind-1>=0 && ind+1<n)
                {
                    vis[ind-1]=1;
                    vis[ind+1]=1;
                }
                else if(ind==0)
                {
                    vis[ind+1]=1;
                }
               else  if(ind==n-1)
                {
                    vis[ind-1]=1;
                }    
            }
            else
                continue;
        }
        return ans;
    }
};