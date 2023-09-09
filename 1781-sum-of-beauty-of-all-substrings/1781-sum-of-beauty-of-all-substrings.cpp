class Solution {
public:
int solve(vector<int>& f)
{
    int maxi=0;
    int mini=INT_MAX;
    for(auto i:f)
    {
        maxi=max(maxi,i);
        if(i>=1)
        mini=min(mini,i);
    }
    return maxi-mini;
}
    int beautySum(string s) {
        int ans=0;
    
    for(int i=0;i<s.size();i++)
    {
        vector<int> f(26,0);
        for(int j=i;j<s.size();j++)
        {
            f[s[j]-'a']++;
            ans+=solve(f);
        }
        
    }
        return ans;
    }
};