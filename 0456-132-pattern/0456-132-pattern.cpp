class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int val=INT_MIN;
        if( nums.size()<3)
            return false;
        for(int i=nums.size()-1;i>=0 ;i--)
        {
            if(nums[i]<val)
                return true;
            while(s.size() && s.top()<nums[i])
            {
                val=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};