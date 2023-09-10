class Solution {
public:
int n;
vector<int> dp;
bool solve(int idx,vector<int>& nums)
{
    if(idx>=n-1)
    return dp[idx]=true;
   if(dp[idx]!=-1)
   return dp[idx];
  //  return true;
if(nums[idx]==0)
return dp[idx]=false;
    int c=nums[idx];
    bool t=false;
    for(int i=1;i<=c;i++)
    {
        t=solve(idx+i,nums);
        if(t)
        return dp[idx]=true;
    }
    return dp[idx]=false;
}
    bool canJump(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return solve(0,nums);
    }
};