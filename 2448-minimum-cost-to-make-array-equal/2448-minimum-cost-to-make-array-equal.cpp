class Solution {
public:
    long long calc(int cur, vector<int>& nums, vector<int>& cost) {
        long long ans=0,n=nums.size();
        for(int i=0;i<n;i++) {
            ans+=1LL*abs(cur-nums[i])*1LL*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l=0,r=1e6,n=nums.size(),ans;
        while(l<=r) {
            int m=(l+r)/2;
            long long a1=calc(m,nums,cost), a2=calc(m+1,nums,cost);
            if(a1<=a2) {
                r=m-1;
            }
            else {
                l=m+1;
            }
        }
        long long a1=calc(l,nums,cost), a2=calc(l-1,nums,cost);
        return min(a1,a2);
    }
};