class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int last=-1;
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                last=i;
            }
        }
        // vector<int> temp;
        // temp.push_back(nums[last]);
        // while(hash[last]!=last)
        // {
        //     last=hash[last];
        //     temp.push_back(nums[last]);
        // }
        // reverse(temp.begin(),temp.end());
        // for(auto i:temp)
        //     cout<<i<<" ";
        return maxi;
    }
};