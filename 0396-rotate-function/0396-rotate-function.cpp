class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int csum=0;
        csum=accumulate(nums.begin(),nums.end(),csum);
        
        int c_val=0;
        for(int i=0;i<nums.size();i++)
        {
            c_val+=i*nums[i];
        }
        int ans=c_val;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            int nw=c_val+(csum-n*nums[n-i-1]);
            ans=max(ans,nw);
            c_val=nw;
        }return ans;
    }
};