typedef long long ll;
typedef pair<ll, ll> IntPr;

class Solution {
public:

    long long kSum(vector<int>& nums, int k) {
        ll sum = 0;
        for(auto& val : nums){
            if(val > 0) sum += val;
            else val = -val;
        }
        if(k == 1) return sum;
        priority_queue<IntPr> pq;
        sort(nums.begin(), nums.end());
        int cnt = 1;
        pq.push({sum-(ll)nums[0], 0});
        int n = nums.size();
      
        while(pq.empty() == false){
            ll currVal = pq.top().first, idx = pq.top().second;
            pq.pop();
            cnt++;
            if(cnt == k)
                return currVal;
            if(idx < n-1){
                pq.push({currVal-(ll)nums[idx+1], idx+1});
                pq.push({currVal+(ll)(nums[idx]-nums[idx+1]), idx+1});
            }
        }
        return 0;
    }
};