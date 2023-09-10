class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n=nums.size();
         if(n==1)
         return {nums[0]};

         sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,1);
         int maxi = -1;
    int last =-1;
        for(int i=0;i<=n-1;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
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
       
    
    // for(int i=0; i<=n-1; i++){
    //     if(dp[i]> maxi){
    //         maxi = dp[i];
    //         last = i;
    //     }
    // }
          vector<int> temp;
        temp.push_back(nums[last]);
        while(hash[last]!=last)
        {
            last=hash[last];
            temp.push_back(nums[last]);
        }
        reverse(temp.begin(),temp.end());
        for(auto i:temp)
        cout<<i<<" ";
        cout<<endl;
        return temp;
    }
};