class Solution {
public:
int solve(int idx,vector<int>& nums1, vector<int>& nums2,int swapped, vector<vector<int>> &dp)
{
    if(idx==nums1.size())
    return 0;
    if(dp[idx][swapped]!=-1)
    return dp[idx][swapped];

    int preva=nums1[idx-1];
    int prevb=nums2[idx-1];
    int ans=INT_MAX;
    if(swapped)
    {
        swap(preva,prevb);
    }

   
    if(nums1[idx]>preva && nums2[idx]>prevb)
    ans=min(ans,solve(idx+1,nums1,nums2,0,dp));
    
    if(nums1[idx]>prevb && nums2[idx]>preva)
    {
        ans=min(ans,1+solve(idx+1,nums1,nums2,1,dp));
    }
    return dp[idx][swapped]=ans;
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
         nums2.insert(nums2.begin(),-1);
         int n=nums1.size();
         vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(1,nums1,nums2,0,dp);
        
    }
};