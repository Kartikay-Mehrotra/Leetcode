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
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] && 1+dp[prev]> dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
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
        // cout<<i<<" ";
        // cout<<endl;
        
       
        return maxi;
    }
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,1);
//         for(int i=0;i<n;i++)
//         {
//             for(int prev=0;prev<i;prev++)
//             {
//                 if(nums[prev]<nums[i])
//                 {
//                     dp[i]=max(1+dp[prev],dp[i]);
//                 }
//             }
//         }
//         int maxi=1;
//         for(auto i:dp)
//         maxi=max(maxi,i);
//         return maxi;
//     }
// };