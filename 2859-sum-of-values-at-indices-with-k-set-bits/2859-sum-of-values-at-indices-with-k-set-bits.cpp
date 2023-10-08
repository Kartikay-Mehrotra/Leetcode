class Solution {
public:
    int solve(int  i)
    {
        int count=0;
        int n=i;
        while(n)
        {
            count+=n&1;
            n=n>>1;
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(solve(i)==k)
                ans+=nums[i];
        }
        return ans;
        
    }
};