class Solution {
public:
const int mod=(int)1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        pq.push(nums[i]);
        while(k--)
        {
            int x=pq.top();
            pq.pop();
            pq.push(x+1);
        }
        long long ans=1;
        while(pq.size())
        {
            ans=ans*1LL*pq.top()%mod;
            pq.pop();
        }
        return ans;
        
    }
};