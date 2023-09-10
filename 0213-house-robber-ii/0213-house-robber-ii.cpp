class Solution {
public:
int solve(int indx,int n,vector<int> &nums,vector<int>& dp)
{
    if(indx==n)
    return nums[indx];

    if(indx>n)
    return 0;

    if(dp[indx]!=-1)
    return dp[indx];

    int p=nums[indx]+solve(indx+2,n,nums,dp);
    int np=0+solve(indx+1,n,nums,dp);

    return dp[indx]=max(p,np);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        vector<int> dp2(n+1,-1);
        
        if( n == 1 ) return nums[0];

        return max(solve(0,n-2,nums,dp),solve(1,n-1,nums,dp2));
    }
};