class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<int>> s;
        vector<int> ans;
        int i=0;
        int j=0;
        while(j<nums.size())
        {
            s.insert(nums[j]);
            if(j-i+1==k)
           {
               ans.push_back(*s.begin());
               s.erase(s.find(nums[i]));
               i++;
           }
            j++;
        }
        return ans;

    }
};