class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum=0;
        int start=0;
        int end=0;
        int ans=INT_MAX;
        int n=nums.size();
        while(end<n)
        {
            sum+=nums[end];
           
            while(sum>=target)
            {
                ans=min(ans,end-start+1);
                sum-=nums[start];
                start++;
            }
            end++;
        }
        if(ans!=INT_MAX)
            return ans;
        return 0;
        
    }
};