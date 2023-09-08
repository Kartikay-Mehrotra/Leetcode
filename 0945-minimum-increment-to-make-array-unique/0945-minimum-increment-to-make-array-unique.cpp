class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        priority_queue<int> pq;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(pq.size()==0)
            {
                pq.push(nums[i]);
            }
            else if(pq.top()==nums[i])
            {
                ans++;
                pq.push(pq.top()+1);
            }
            else if(nums[i]<pq.top())
            {
                ans+=(pq.top()-nums[i]+1);
                pq.push(pq.top()+1);
            }
            else
            pq.push(nums[i]);
        }
        return ans;
    }
};